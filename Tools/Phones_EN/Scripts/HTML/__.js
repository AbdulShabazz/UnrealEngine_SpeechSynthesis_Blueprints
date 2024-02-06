try {

/**
 Compatibility:
    // Lossless
    - .WAV
    - .FLAC
    // Lossy
    - .MP3
    - .AAC
*/

let isPlaying = false;

//var audioPlayer = document.getElementById('audioPlayer');
audioPlayer.addEventListener('onclick', function() {
    //var audioPlayer = document.getElementById('audioPlayer');

    // Change volume (0.0 to 1.0)
    audioPlayer.volume = 0.5;

    // Play audio
    // Toggle play/pause based on isPlaying
    // Update the isPlaying flag
    if (isPlaying) {
        audioPlayer.pause();
        isPlaying = false;
    } else {
        audioPlayer.play();
        isPlaying = true;
        // Start or resume the audio context on user interaction, if necessary
        if (audioContext && audioContext.state === 'suspended') {
            audioContext.resume();
        }
    }

});

audioPlayer.addEventListener('play', function() {
    isPlaying = true;
});

audioPlayer.addEventListener('pause', function() {
    isPlaying = false;
});

let dropZone = document.getElementById('drop_zone');

// Prevent default drag behaviors
['dragenter', 'dragover', 'dragleave', 'drop'].forEach(eventName => {
    dropZone.addEventListener(eventName, preventDefaults, false);
});

function preventDefaults(e) {
    e.preventDefault();
    e.stopPropagation();
}

// Highlight drop zone when item is dragged over it
['dragenter', 'dragover'].forEach(eventName => {
    dropZone.addEventListener(eventName, highlight, false);
});

['dragleave', 'drop'].forEach(eventName => {
    dropZone.addEventListener(eventName, unhighlight, false);
});

function highlight(e) {
    dropZone.classList.add('highlight');
}

function unhighlight(e) {
    dropZone.classList.remove('highlight');
}

// Handle dropped files
dropZone.addEventListener('drop', handleDrop, false);

function handleDrop(e) {
    let dt = e.dataTransfer;
    let files = dt.files;

    handleFiles(files);
}

function handleFiles(files) {
    ([...files]).forEach(uploadFile);
}

/**
@brief Compute the endianness of the operating system.
@details Compute the endianness of the operating system. */
function verifyPlatformIsLittleEndian() {
    let buffer = new ArrayBuffer(2);
    let uint8Array = new Uint8Array(buffer);
    let uint16array = new Uint16Array(buffer);
    uint8Array[0] = 0xAA; // set first byte
    uint8Array[1] = 0xBB; // set second byte
    if (uint16array[0] === 0xBBAA) {
        return true; /* 'little-endian' */;
    } else if (uint16array[0] === 0xAABB) {
        return false; /* 'big-endian' */;
    } else throw new Error( "Unknown endianness.");
}

// Custom function to read 3 bytes as 24-bit integer
DataView.prototype.getUint24 = function(offset, isLittleEndian) {
    const bytes = isLittleEndian
        ? [this.getUint8(offset), this.getUint8(offset + 1), this.getUint8(offset + 2)]
        : [this.getUint8(offset + 2), this.getUint8(offset + 1), this.getUint8(offset)];
    return (bytes[0] << 16) + (bytes[1] << 8) + bytes[2];
};

// Custom function to read 36 bits as integer (considering JavaScript Number precision)
DataView.prototype.getUint36 = function(offset, isLittleEndian) {
    const bytes = isLittleEndian
        ? [this.getUint8(offset), this.getUint8(offset + 1), this.getUint8(offset + 2), this.getUint8(offset + 3), this.getUint8(offset + 4)]
        : [this.getUint8(offset + 4), this.getUint8(offset + 3), this.getUint8(offset + 2), this.getUint8(offset + 1), this.getUint8(offset)];
    // Combine the 36 bits. Note: JavaScript bitwise operations are 32-bit, hence the separation
    return (bytes[0] * Math.pow(2, 28)) + (bytes[1] << 20) + (bytes[2] << 12) + (bytes[3] << 4) + (bytes[4] >> 4);
};

function extractFlacMetadata(arrayBuffer) {
    const isLittleEndian = verifyPlatformIsLittleEndian();
    const dataView = new DataView(arrayBuffer);
    let offset = 4; // Usually, metadata starts after the 'fLaC' marker

    // Read STREAMINFO block header (assuming it's the first block)
    const blockHeader = dataView.getUint32(offset, isLittleEndian);
    offset += 4;
    
    const blockType = blockHeader >> 24; // First byte is block type
    const blockSize = blockHeader & 0x00FFFFFF; // Last three bytes are block size

    if (blockType !== 0) { // 0 is the type for STREAMINFO
        throw new Error("First metadata block is not STREAMINFO");
    }

    // Read STREAMINFO block data
    const minBlockSize = dataView.getUint16(offset, isLittleEndian);
    offset += 2;

    const maxBlockSize = dataView.getUint16(offset, isLittleEndian);
    offset += 2;

    const minFrameSize = dataView.getUint24(offset, isLittleEndian); // Custom function needed to read 3 bytes
    offset += 3;

    const maxFrameSize = dataView.getUint24(offset, isLittleEndian); // Custom function needed to read 3 bytes
    offset += 3;

    const sampleRate = dataView.getUint24(offset, isLittleEndian);
    offset += 3;

    const channelSampleDepth = dataView.getUint8(offset);
    const channels = (channelSampleDepth >> 4) + 1;
    const bitsPerSample = ((channelSampleDepth & 0x0F) << 1) + 1;
    offset += 1;

    const totalSamples = dataView.getUint36(offset, isLittleEndian); // Custom function needed to read 36 bits (4.5 bytes)
    offset += 4.5;

    // You can calculate duration like this
    const duration = totalSamples / sampleRate;

    return {
        minBlockSize,
        maxBlockSize,
        minFrameSize,
        maxFrameSize,
        sampleRate,
        channels,
        bitsPerSample,
        totalSamples,
        duration
    };
}

// REM: Bitrate = Sample Rate * Bit Depth * Number of Channels
// REM: Sample Rate = Bitrate / (Bit Depth * Number of Channels)

function uploadFileForAnimation(file) {
    const fileSizeInKB = audioPlayer.size; /* file size in kilobytes (kB) */
    const durationInSeconds = audioElement.duration; // as obtained from the audio element

    const bitrateInKbps = (fileSizeInKB * 8) / durationInSeconds;

    // 1. Create OfflineAudioContext
    offlineAudioCtx = new OfflineAudioContext(2, 44100 * audioPlayer.duration, 44100);

    // 2. Fetch the audio file
    fetch(audioPlayer.src) //'path/to/your/audio/file.mp3'
        .then(response => response.arrayBuffer())
        .then(arrayBuffer => offlineAudioCtx.decodeAudioData(arrayBuffer))
        .then(audioBuffer => {
            // 3. Decode the audio data and create an AnalyserNode
            const source = offlineAudioCtx.createBufferSource();
            source.buffer = audioBuffer;

            const analyser = offlineAudioCtx.createAnalyser();
            analyser.fftSize = 2048;
            const bufferLength = analyser.frequencyBinCount;
            const dataArray = new Uint8Array(bufferLength);

            source.connect(analyser);
            analyser.connect(offlineAudioCtx.destination); // Connect to the destination

            source.start();

            // 4. Render the data
            offlineAudioCtx.startRendering().then(renderedBuffer => {
                // Here you can process the renderedBuffer, but you won't have real-time data
                // You might have to process the data in chunks and update the chart accordingly
            });
        });
}

function uploadFile(file) {
    let url = URL.createObjectURL(file);
    audioPlayer.src = url;
    triggerSuccessAnimation();
    file_url.textContent = `${file.name} [ ${file.size} bytes ] -- [ ${url}/${file.name} ]`;
}

function triggerSuccessAnimation() {
    let originalText = document.getElementById('original_text');
    let successMessage = document.getElementById('success_message');
  
    // Hide original text and show success message
    originalText.style.display = 'none';
    successMessage.style.display = 'block';
    successMessage.style.animation = 'successAnimation 2s forwards';
  
    // After animation, show original text and hide success message
    setTimeout(() => {
      successMessage.style.display = 'none';
      originalText.style.display = 'block';
      successMessage.style.animation = 'none'; // Reset animation
    }, 2000); // Corresponds to the animation duration
}

offlineAudioCtx = {};

const soundFloor = 0.01; // Minimum amplitude to be considered as sound
var audioContext = new (window.AudioContext || window.webkitAudioContext)();

var analyser = audioContext.createAnalyser();
var source = audioContext.createMediaElementSource(audioPlayer);

source.connect(analyser);
analyser.connect(audioContext.destination);
// Set up the analyzer
analyser.fftSize = 2048; // Change this if needed (Must be a power of 2)
var bufferLength = analyser.frequencyBinCount;

var dataArray = new Uint8Array(bufferLength);

analyser.getByteTimeDomainData(dataArray);

function linearAmplitudeFromdBFS(dBFS) {
    return Math.pow(10, dBFS / 20);
}

function dBFSTolinearAmplitude(dBFS) {
    return Math.pow(10, dBFS / 20);
}

function dBFSFromLinearAmplitude(amplitude) {
    return 20 * Math.log10(amplitude);
}

function linearAmplitudeToDBFS (amplitude) {
    return 20 * Math.log10(amplitude);
}

//const frequencyBand = [5,10,20,40,80,160,320,640,/*1280,/*2560,/*5120,10240,20480*/];
class SpectrumSample extends Object {
    constructor({ amplitude_rdBFS = soundFloor, frequency_hz = 0 }={}) {
        super();
        this.amplitude_rdBFS = amplitude_rdBFS;
        this.frequency_hz = frequency_hz;
    }
}

frequencyBand = [];
for (let i = 4; i <= 652; i += 4) {
    frequencyBand.push(new SpectrumSample({ amplitude_rdBFS : soundFloor, frequency_hz : i }));
}

// Set up the initial chart
//Chart.defaults.borderColor = '#333';
ctx = myChart.getContext('2d');
myChart = new Chart(ctx, {
    type: 'bar',
    data: {
        //labels: frequencyBand.map(u => {return u + ' Hz';}), 
        datasets: [
            {
                label: 'Left Channel - Amplitude (rdBFS)',
                data: frequencyBand.map(sample => ({ x: sample.frequency_hz, y: sample.amplitude_rdBFS })), // Initial empty data
                borderColor: 'rgb(0, 123, 247)',
                backgroundColor: 'rgb(0, 123, 247)',
                borderWidth: 1,
                yAxisID: 'y-axis-amplitude',
                xAxisID: 'x-axis-frequency',
            },
            {
                label: 'Right Channel - Amplitude (rdBFS)',
                data: frequencyBand.map(sample => ({ x: sample.frequency_hz, y: sample.amplitude_rdBFS })), // Initial empty data
                borderColor: 'rgb(255, 0, 255)',//'rgb(0,255,123)', 
                backgroundColor: 'rgb(255, 0, 255)',//'rgb(0,255,123)', //
                borderWidth: 1,
                yAxisID: 'y-axis-amplitude-duo',
                xAxisID: 'x-axis-frequency',
                hidden: true // Avoid mixing Left-/Right-Channel data
            }]
    },
    options: {
        scales: {
            'y-axis-amplitude': {
                type: 'linear',
                min: 0,
                max: 1,
                title: { 
                    text: 'rdBFS ( Decibels relative to Full Scale )',
                    display: true,
                },
                display: true,
                //beginAtzero: true,
                position: 'left',
                grid: {
                    drawOnChartArea: true,
                    drawTicks: false, // Hide grid lines offchart
                    color: '#444',
                },
                ticks: {
                    stepSize: .02,
                    // Include dimensional units in ticks
                    callback: function(value, index, ticks) {
                        // call the default formatter, forwarding `this`
                        return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]) + ' rdBFS';
                    }
                }
            },
            'y-axis-amplitude-duo': {
                type: 'linear',
                min: 0,
                max: 1,
                title: { 
                    text: 'rdBFS ( Decibels relative to Full Scale )',
                    display: true,
                },
                display: true, 
                //beginAtzero: true,
                position: 'right',
                grid: {
                    drawOnChartArea: true, 
                    drawTicks: false, // Hide grid lines offchart
                    color: '#444',
                },
                ticks: {
                    stepSize: .02,
                    // Include dimensional units in ticks
                    callback: function(value, index, ticks) {
                        // call the default formatter, forwarding `this`
                        return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]) + ' rdBFS';
                    }
                }
            },
            'x-axis-frequency': {
                type: 'linear',
                //min: 0,
                //max: 652,
                title: { 
                    text: 'Frequency Band (Hz)',
                    display: true,
                },
                display: true,
                beginAtzero: true,
                position: 'bottom',
                grid: {
                    drawOnChartArea: true,
                    drawTicks: false, // Hide grid lines offchart
                    color: '#444',
                },
                ticks: {
                    stepSize: 4, 
                    // Include dimensional units in ticks
                    callback: function(value, index, ticks) {
                        // call the default formatter, forwarding `this`
                        return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]) + ' Hz';
                    }
                }
            }
        },
        plugins: {
            legend: {
                onHover: (event, legendItem, legend) => {
                    event.native.target.style.cursor = 'pointer';
                },
                onLeave: (event, legendItem, legend) => {
                    event.native.target.style.cursor = 'default';
                }
            },
            tooltip: {
                // Enable custom tooltips
                enabled: true,
                mode: 'index',
                position: 'nearest',
                bodyFontSize: 12, // Tooltip font size
                callbacks: {
                    title: function(tooltips, data) {
                        // Assuming the first dataset is for amplitude and has complete frame and time_step data
                        //const tt = tooltips[0];
                        const tt2 = tooltips[0];
                        //const tmpTimeStep = tt.label;
                        const tmpFrame = tt2.label;
                        /*
                        const tmpAmplitude = tt.formattedValue;
                        const tmpfrequency = tt2.formattedValue;
                        */
                        return `${tmpFrame} Hz`;
                    },
                    label: function(tooltipItem, data) {
                        // tooltipItem is an object containing properties of the tooltip
                        // data is an object containing all data passed to the chart
                        let yLabel = tooltipItem.formattedValue;
                        const xLabel = tooltipItem.dataset.label;
                        //if (xLabel.match(/^Amplitude/)) {
                            yLabel = (xLabel.match(/^L/) ? '(L) ' : '(R)')  + ` - Amplitude: ${yLabel} (rdBFS)`;
                        //}
                        return yLabel;
                    }
                }
            },
        },/*
        onHover: (event, chartElement) => {
            // Change the cursor to 'pointer' if hovering over a label
            event.native.target.style.cursor = chartElement.length ? 'pointer' : 'default';
        },*/
        animation: false, // Disable animation for performance
        responsive: true,
        maintainAspectRatio: true
    }
});

// Function to extract range and generate value-pairs
function generateValuePairs() {
    // Extract the value from the option element
    const selectedIndex = band_selector.selectedIndex;
    const optionValue = band_selector.options[selectedIndex].value;

    // Extract the range from the option value
    const range = optionValue.match(/\[(\d+),(\d+)\]/).slice(1).map(Number);
    const [start, end] = range;

    // Initialize the array to hold the value-pairs
    const valuePairs = [];

    // Loop from start to end in steps of 4
    for (let x = start; x <= end; x += 4) {
        // Push the value-pair object to the array
        valuePairs.push({ x: x, y: soundFloor });
    }

    return valuePairs;
}

band_selector.addEventListener('change', function(e) {
    const valuePairs = generateValuePairs();
    myChart.data.datasets[0].data = valuePairs;
    myChart.data.datasets[1].data = valuePairs;
    myChart.update();
});

function updateChart() {
    requestAnimationFrame(updateChart);
    // Get the frequency data
    analyser.getByteFrequencyData(dataArray);

    // Normalize and reduce the array to 24 bands
    let step = Math.floor(dataArray.length / 24);
    for (let i = 0; i < 24; ++i) {
        let value = 0;
        for (let j = 0; j < step; j++) {
            value += dataArray[(i * step) + j];
        }
        value = value / step;
        myChart.data.datasets[0].data[i] = value;
    }

    // Update the chart
    myChart.update();
}

// Assuming you have an array `currentAmplitudes` with your amplitude data
let peakAmplitudes = []; 
const decayRate = 0.005; // Adjust as necessary for your desired decay speed

for (let sample of frequencyBand) {
    peakAmplitudes.push(new SpectrumSample({ amplitude_rdBFS : soundFloor, frequency_hz : sample.frequency_hz }));
}

function updateSpectrum() {
    // Get new amplitude data and update `currentAmplitudes`...

    // Update peakAmplitudes and apply decay
    for (let i = 0; i < currentAmplitudes.length; ++i) {
        // If current amplitude is higher than peak, update peak
        if (currentAmplitudes[i] > peakAmplitudes[i]) {
            peakAmplitudes[i] = currentAmplitudes[i];
        } else {
            // Else, apply decay to the peak value
            peakAmplitudes[i] = Math.max(0, peakAmplitudes[i] - decayRate);
        }
    }

    // Update your ChartJS chart with the new `currentAmplitudes` and `peakAmplitudes`
    myChart.data.datasets[0].data = currentAmplitudes; // Current levels
    myChart.data.datasets[1].data = peakAmplitudes; // Peak levels
    myChart.update();
}

// Todo: Call `updateSpectrum` at your desired frame rate

window.addEventListener('resize', () => {
    // Update the chart
    myChart.resize();
});

// Start the animation
//updateChart();

} catch (e) {
    console.error(`Unexpected error: ${e}`);
}
