try {

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

function uploadFile(file) {
    let url = URL.createObjectURL(file);
    audioPlayer.src = url;
    triggerSuccessAnimation();
    file_url.textContent = `${file.name} (${file.size} bytes) -- [${url}/${file.name}]`;
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

var audioContext = new (window.AudioContext || window.webkitAudioContext)();
var analyser = audioContext.createAnalyser();
var source = audioContext.createMediaElementSource(audioPlayer);
source.connect(analyser);
analyser.connect(audioContext.destination);

// Set up the analyzer
analyser.fftSize = 32;//2048; // Change this if needed (Must be a power of 2)
var bufferLength = analyser.frequencyBinCount;
var dataArray = new Uint8Array(bufferLength);
analyser.getByteTimeDomainData(dataArray);

// Set up the initial chart
var ctx = document.getElementById('myChart').getContext('2d');
var myChart = new Chart(ctx, {
    type: 'bar',
    data: {
        labels: [...Array(24).keys()], // 24 bands
        datasets: [{
            label: 'Amplitude (dBFS)',
            data: [], // Initial empty data
            backgroundColor: 'rgba(0, 123, 255, 0.5)',
            borderWidth: 1,
            yAxisID: 'y-axis-amplitude',
            xAxisID: 'x-axis-frequency',
            }]
        },
    options: {
        'y-axis-amplitude': {
            type: 'boxplot',
            title: { 
                text: 'dBFS ( Decibels relative to Full Scale )',
                display: true,
            },
            display: true,
            beginAtzero: true,
            position: 'left',
            grid: {
                drawOnChartArea: true
            },
            ticks: {
                // Include a dollar sign in the ticks
                callback: function(value, index, ticks) {
                      // call the default formatter, forwarding `this`
                      return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]) + ' dBFS';
                }
            }
        },
        'x-axis-frequency': {
            type: 'boxplot',
            title: { 
                text: 'Frequency (Hz)',
                display: true,
            },
            display: true,
            beginAtzero: true,
            position: 'bottom',
            grid: {
                drawOnChartArea: true
            },
            ticks: {
                // Include a dollar sign in the ticks
                callback: function(value, index, ticks) {
                      // call the default formatter, forwarding `this`
                      return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]) + ' Hz';
                }
            }
        },
        animation: false, // Disable animation for performance
        responsive: true,
        maintainAspectRatio: true
        }
});

function updateChart() {
    requestAnimationFrame(updateChart);

    // Get the frequency data
    analyser.getByteFrequencyData(dataArray);

    // Normalize and reduce the array to 24 bands
    let step = Math.floor(dataArray.length / 24);
    for (let i = 0; i < 24; i++) {
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

// Start the animation
updateChart();

} catch (e) {
    console.error(`Unexpected error: ${e}`);
}
