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

// Define the start value and the number of steps
let startValue = 4;
const step = 4;
const valuesPerOption = 160; // Number of values in each range
const totalValues = 20480; // Or any other end value you need

// Clear existing options
band_selector.innerHTML = '';

// Generate options
g_globalFrequencyBand = [];
for (let value = startValue; value <= totalValues; value += valuesPerOption * step) {
    // Calculate end value for the current range
    let endValue = value + valuesPerOption * step - step;

    // Ensure endValue does not exceed totalValues
    if (endValue > totalValues) {
        endValue = totalValues;
    }

    // Create the option element
    const option = document.createElement('option');
    g_globalFrequencyBand.push({ start: value, end: endValue });
    option.textContent = `${value} Hz to ${endValue} Hz`;

    // Append the option to the select element
    band_selector.appendChild(option);

    // Prepare the next startValue
    startValue = endValue + step;
}

//let isPlaying = false;

//var audioPlayer = document.getElementById('audioPlayer');
audioPlayer.addEventListener('onclick', function() {
    //var audioPlayer = document.getElementById('audioPlayer');

    // Change volume (0.0 to 1.0)
    audioPlayer.volume = 0.5;

    // Play audio
    // Toggle play/pause based on audioPlayer.paused
    // Update the audioPlayer.paused flag
    if (!audioPlayer.paused) {
        audioPlayer.pause();
        //audioPlayer.paused = false;
    } else {
        audioPlayer.play();
        //audioPlayer.paused = false;
        // Start or resume the audio context on user interaction, if necessary
        if (audioContext && audioContext.state === 'suspended') {
            audioContext.resume();
        }
    }

});

const decayRate = 0.005; // Adjust as necessary for your desired decay speed

function updatePeakAt(peak, current) {
    if (current.amplitude_rdBFS > peak.amplitude_rdBFS) {
        peak.amplitude_rdBFS = current.amplitude_rdBFS;
    } else {
        peak.amplitude_rdBFS -= decayRate;
    }
}

function populateCurrentFrequencyBandAmplitudes(currentFrequencyBandAmplitudes) {
    for (const fband of currentFrequencyBand) {
        currentFrequencyBandAmplitudes.push({ x: fband.frequency_hz, y: fband.amplitude_rdBFS });
    }
}

function swapOutFrequencyBands() {
    peakAmplitudes = [];
    for (const fband of currentFrequencyBand) {
        peakAmplitudes.push( new SpectrumSample({ amplitude_rdBFS : fband.amplitude_rdBFS, frequency_hz : fband.frequency_hz }) );
    }
}

// REM: Bitrate = Sample Rate * Bit Depth * Number of Channels
// REM: Sample Rate = Bitrate / (Bit Depth * Number of Channels)

const supportedBitDepthEncodings = [8, 16, 24, 32];

g_bitDepth = supportedBitDepthEncodings[3]; // 32-bit floating point audio (
g_audioBuffer = [];

var audioContext = new (window.AudioContext || window.webkitAudioContext)();

var analyser = audioContext.createAnalyser();
var source = audioContext.createMediaElementSource(audioPlayer);

source.connect(analyser);
analyser.connect(audioContext.destination);
// Set up the analyzer
analyser.fftSize = 2048; // default (Must be a power of 2)
var bufferLength = analyser.frequencyBinCount;

var dataArray = new Uint8Array(bufferLength);

analyser.getByteTimeDomainData(dataArray);

function updateSpectrum() {
    requestAnimationFrame(updateSpectrum);
    // Get new amplitude data and update `currentFrequencyBandAmplitudes`...
    const audioBuffer = g_audioBuffer;

    audioBuffer.bitDepth = g_bitDepth;

    const getByteFrequencyData = audioBuffer.getByteFrequencyData(audioBuffer);

    const duration = audioBuffer.duration;
    const sampleRate = audioBuffer.sampleRate;
    const numberOfChannels = audioBuffer.numberOfChannels;
    const lengthInSeconds = audioBuffer.length;

    // REM: Desired Number of Frequencies per Band or Bin(4) = number_of_bins(160) * Sample Rate(?) / FFT_Size(?); thus solve for FFT_Size -=>
    // REM: FFT_Size = number_of_bins(160) * Sample Rate(?) / number_of_frequencies_per_bin(4) => 40 * sampleRateconst fftCutOff = 40 * sampleRate;
    let fftCap = 32; // Minimum fftSize

    // Ensure fftCutOff is within a reasonable range to avoid underflow/overflow
    const maxFftCutOff = 32768; // Maximum fftSize

    const effectiveFFTCutOff = Math.min(Math.max(fftCutOff, fftCap), maxFftCutOff);

    // Find the nearest power of 2 greater than or equal to effectiveFFTCutOff
    let mantissa = Math.ceil(Math.log(effectiveFFTCutOff) / Math.log(2));

    fftCap = 1 << mantissa;

    // Ensure fftCap does not exceed the maximum allowed fftSize
    fftCap = Math.min(fftCap, maxFftCutOff);

    // Set the fftSize
    analyser.fftSize = fftCap;

    let currentFrequencyBandAmplitudes = [];
    if (peakAmplitudes[0].frequency_hz != currentFrequencyBand[0].frequency_hz) {
        swapOutFrequencyBands();
        populateFrequencyBandAmplitudes(currentFrequencyBandAmplitudes);
    } else {
        // Update peakAmplitudes and apply decay
        for (let i = 0; i < nextAmplitudes.length; ++i) {
            updatePeakAt(peakAmplitudes[i], currentFrequencyBandAmplitudes[i]);
            currentFrequencyBandAmplitudes.push({ x: nextAmplitudes[i].frequency_hz, y: nextAmplitudes[i].amplitude_rdBFS });
        }
    }

    // Update your ChartJS chart with the new `currentFrequencyBandAmplitudes` and `peakAmplitudes`
    myChart.data.datasets[0].data = currentFrequencyBandAmplitudes; // Current levels LHS
    myChart.data.datasets[1].data = currentFrequencyBandAmplitudes;  // Current levels RHS
    myChart.update();
}

/**
@brief Compute the endianness of the operating system.
@details Compute the endianness of the operating system. */
function isLittleEndian() {
    let buffer = new ArrayBuffer(2);
    let uint8Array = new Uint8Array(buffer);
    let uint16array = new Uint16Array(buffer);
    uint8Array[0] = 0xAA; // set first byte
    uint8Array[1] = 0xBB; // set second byte
    if (uint16array[0] === 0xBBAA) {
        return true; /* 'little-endian' */;
    }
    else if (uint16array[0] === 0xAABB) {
        return false; /* 'big-endian' */;
    } else throw new Error( "Unknown endianness.");
}

// Helper functions to write strings as 8-bit integers (bytes)
function writeString(view, offset, string, littleEndianFlag) {
    for (let i = 0; i < string.length; ++i) {
        // Get the UTF-16 code unit for each character
        const codeUnit = string.charCodeAt(i);

        // Write the code unit to the DataView as a 16-bit integer
        view.setUint8(offset + i, codeUnit, littleEndianFlag); // using little-endian format
    }

    // Return the new offset, which is the initial offset plus twice the string's length
    return offset + string.length;
}

const platformEndianness = isLittleEndian();
let wavHeader = new DataView(new ArrayBuffer(4), 0, 4);
let flacHeader = new DataView(new ArrayBuffer(4), 0, 4);

writeString(wavHeader, 0, 'RIFF', platformEndianness); // 0x52494646 {"46464952" little-endian}
writeString(flacHeader, 0, 'fLaC', platformEndianness); // 0x664C6143 {"664C6143" little-endian}

/** 
@brief: The audioPlayer object is a reference to the audio element that is currently playing.
@details: REM:: The AudioContext object is a builtin object. Its functionality can only be invoked fom within an HTML audio control element.*/
audioPlayer.addEventListener('play', function() {
    audioPlayer.paused = false;
    
    fetch(audioPlayer.src)
        .then(response => response.arrayBuffer())
        .then(arrayBuffer => {
            // Create DataViews for reading the audio (metatable) header
            const audioHeader = new DataView(arrayBuffer);

            const headerIntro = audioHeader.getUint32(0, platformEndianness)

            /*
            Get the bit depth for the supported audio frmats (eg. .WAV), assuming PCM encoding, 
            for appropriate (amplitude) dynamic range decoding of animations

            Note: The AudioContext actually reads all of these audio attributes 
            from the metatable file header, except bit-depth, 
            which we need to know in advance for the animation */
            if (headerIntro == wavHeader.getUint32(0, platformEndianness) // "RIFF"
                && (audioHeader.getUint8(20, platformEndianness) & 0x03) == 1) { // No Compression (ie. PCM)
                    g_bitDepth = audioHeader.getUint16(34, platformEndianness);
            } else if (headerIntro == flacHeader.getUint32(0, platformEndianness)) { // "fLaC"
                    /*
                    fLaC is designed for streaming, so its 3-bit (PCM) 
                    bit depth field is encoded in the frame header of the audio packet */
                    const HEADER_OFFSET = 8; // Offset for the HEADERINFO block
                    const SAMPLE_RATE_OFFSET = 18; // Offset for the sample rate portion in the HEADERINFO block

                    const BIT_FLAG_OFFSET = SAMPLE_RATE_OFFSET + 3; // Offset for the Bit flag (3 bits) after the sample rate

                    // Calculate the start position of the sample rate portion
                    let sampleRateStartPosition = HEADER_OFFSET + BIT_FLAG_OFFSET;

                    // If endiannessFlag indicates big-endian, swap the byte order
                    if (platformEndianness === false) { // (big-endian)
                        sampleRateStartPosition += 1; // Adjust the position to skip the first byte
                    }

                    // Read the 3-bit Bit flag from the calculated offset
                    const bitsPerSampleFlag = audioHeader.getUint8(sampleRateStartPosition, 
                        platformEndianness) & 0b00000111;

                    switch (bitsPerSampleFlag) {
                        case 0x01: // 8-bit
                            g_bitDepth = 8;
                            break;
                        case 0x02: // 12-bit
                            g_bitDepth = 12;
                            break;
                        case 0x04: // 16-bit
                            g_bitDepth = 16;
                            break;
                        case 0x05: // 20-bit
                            g_bitDepth = 20;
                            break;
                        case 0x06: // 24-bit
                            g_bitDepth = 24;
                            break;
                        case 0x03: // reserved
                        case 0x07: // 32-bit
                        default:
                            g_bitDepth = 32;
                            break;
                    }
            }

            // next step, decode the audio data
            return audioContext.decodeAudioData(arrayBuffer);
        })
        .then(audioBuffer => {
            //console.info(audioBuffer);
            /*
            const duration = audioBuffer.duration;
            const sampleRate = audioBuffer.sampleRate;
            const numberOfChannels = audioBuffer.numberOfChannels;
            const lengthInSeconds = audioBuffer.length;
            */
            g_audioBuffer = audioBuffer;
            //updateSpectrum();
            //const bitsPerSample = audioBuffer.bitsPerSample;
            // You now have access to the audioBuffer
            // which you can manipulate or play as needed
            //const op = parseSpectrum(audioPlayer.src);
            /*
            let op = {};
            op.spectrumAvailable = true;
            op.buffer = audioBuffer.get;
            if (op.spectrumAvailable) {
                updateSpectrum(op.buffer);
            }
            */
        })
    .catch(e => console.error(e));

});

audioPlayer.addEventListener('pause', function() {
    audioPlayer.paused = true;
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

class SpectrumSample extends Object {
    constructor({ amplitude_rdBFS = soundFloor, frequency_hz = 0 }={}) {
        super();
        this.amplitude_rdBFS = amplitude_rdBFS;
        this.frequency_hz = frequency_hz;
    }
}

// globals //
const soundFloor = 0.01; // Minimum amplitude to be considered as sound
peakAmplitudes = []; 
currentFrequencyBand = [];

for (let sample of currentFrequencyBand) {
    peakAmplitudes.push(new SpectrumSample({ amplitude_rdBFS : soundFloor, frequency_hz : sample.frequency_hz }));
}

for (let i = g_globalFrequencyBand[0].start; i < g_globalFrequencyBand[0].end; i += 4) {
    currentFrequencyBand.push(new SpectrumSample({ amplitude_rdBFS : soundFloor, frequency_hz : i }));
}

// Set up the initial chart
//Chart.defaults.borderColor = '#333';
ctx = myChart.getContext('2d');
myChart = new Chart(ctx, {
    type: 'bar',
    data: {
        //labels: currentFrequencyBand.map(u => {return u + ' Hz';}), 
        datasets: [
            {
                label: 'Left Channel - Amplitude (rdBFS)',
                data: currentFrequencyBand.map(sample => ({ x: sample.frequency_hz, y: sample.amplitude_rdBFS })), // Initial empty data
                borderColor: 'rgb(0, 123, 247)',
                backgroundColor: 'rgb(0, 123, 247)',
                borderWidth: 1,
                yAxisID: 'y-axis-amplitude',
                xAxisID: 'x-axis-frequency',
            },
            {
                label: 'Right Channel - Amplitude (rdBFS)',
                data: currentFrequencyBand.map(sample => ({ x: sample.frequency_hz, y: sample.amplitude_rdBFS })), // Initial empty data
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

    // Extract the range from the option value
    currentFrequencyBand = []
    const { start, end } = g_globalFrequencyBand[selectedIndex];

    // Initialize the array to hold the value-pairs
    const valuePairs = [];

    // Loop from start to end in steps of 4
    for (let x = start; x <= end; x += 4) {
        // Push the value-pair object to the array
        valuePairs.push({ x: x, y: soundFloor });
        currentFrequencyBand.push(new SpectrumSample({ amplitude_rdBFS : soundFloor, frequency_hz : x }));
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

// Todo: Call `updateSpectrum` at your desired frame rate

window.addEventListener('resize', () => {
    // Update the chart
    myChart.resize();
});

// Start the animation
//updateChart();

} catch (e) {
    console.info(`Unexpected error: ${e.message}\n${e.fileName}: line ${e.lineNumber}: col ${e.columnNumber}\nTrace:\n${e.stack}`);
}
