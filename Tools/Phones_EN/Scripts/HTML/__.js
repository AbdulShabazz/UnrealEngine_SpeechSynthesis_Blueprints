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

g_audioBuffer = [];

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

function updateSpectrum() {
    requestAnimationFrame(updateSpectrum);
    // Get new amplitude data and update `currentFrequencyBandAmplitudes`...
    const audioBuffer = g_audioBuffer;

    const getByteFrequencyData = audioBuffer.getByteFrequencyData(audioBuffer);

    const duration = audioBuffer.duration;
    const sampleRate = audioBuffer.sampleRate;
    const numberOfChannels = audioBuffer.numberOfChannels;
    const lengthInSeconds = audioBuffer.length;

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

/** 
@brief: The audioPlayer object is a reference to the audio element that is currently playing.
@details: REM:: The AudioContext object is a builtin object. Its functionality can only be invoked fom within an HTML audio control element.*/
audioPlayer.addEventListener('play', function() {
    audioPlayer.paused = false;
    
    fetch(audioPlayer.src)
        .then(response => response.arrayBuffer())
        .then(arrayBuffer => {
            const platformIsLittleEndian = isLittleEndian();
            // Create a DataView for reading the MetaData
            const view = new DataView(arrayBuffer);

            // decode the audio data
            audioContext.decodeAudioData(arrayBuffer);
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
            updateSpectrum();
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
    console.error(`Unexpected error: ${e}`);
}
