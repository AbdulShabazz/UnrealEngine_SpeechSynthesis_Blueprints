// Configuration For chart.js
const value_pairs = [
{ amplitude: -6.0, frequency: 50.0, frame: 0, time_step: 0 },
{ amplitude: -4.5, frequency: 60.0, frame: 200, time_step: 15 },
{ amplitude: -4.0, frequency: 65.0, frame: 265, time_step: 30 },
{ amplitude: -5.5, frequency: 60.0, frame: 600, time_step: 45 },
{ amplitude: -5.8, frequency: 50.0, frame: 880, time_step: 60 },
{ amplitude: -6.0, frequency: 40.0, frame: 1040, time_step: 75 },
{ amplitude: -7.0, frequency: 30.0, frame: 1300, time_step: 90 },
{ amplitude: -11.0, frequency: 20.0, frame: 2050, time_step: 105 }
];

// Extracting time_steps, amplitudes, and frequencies
const time_steps = value_pairs.map(pair => pair.time_step);
const amplitudes = value_pairs.map(pair => pair.amplitude);
const frequencies = value_pairs.map(pair => pair.frequency);
const frames = value_pairs.map(pair => pair.frame);

const config = {
    type: 'line',
    data: {
        labels: frames,
        datasets: [{
            label: 'Amplitude (dB)',
            data: amplitudes,
            borderColor: 'blue',
            backgroundColor: 'rgb(0, 0, 255)',
            yAxisID: 'y-axis-amplitude'
        }, {
            label: 'Frequency (Hz)',
            data: frequencies,
            borderColor: 'green',
            backgroundColor: 'rgb(0, 140, 0)',
            yAxisID: 'y-axis-frequency'
        }]
    },
    options: {
        scales: {
            'y-axis-amplitude': {
                type: 'linear',
                title: { 
                    text: 'dB',
                    display: true,
                    //color: 'blue',
                },
                display: true,
                position: 'left',
                grid: {
                    drawOnChartArea: true
                },
                ticks: {
                    // Include a dollar sign in the ticks
                    callback: function(value, index, ticks) {
                          // call the default formatter, forwarding `this`
                          return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]) + ' dB';
                    }
                }
            },
            'y-axis-frequency': {
                type: 'linear',
                title: { 
                    text: 'Hz',
                    display: true,
                    //color: 'blue',
                },
                display: true,
                position: 'right',
                grid: {
                    drawOnChartArea: false
                },
                ticks: {
                    // Include a dollar sign in the ticks
                    callback: function(value, index, ticks) {
                        // call the default formatter, forwarding `this`
                        return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]) + ' Hz';
                    }
                }
            }
        },
        plugins: {
            title: {
                display: true,
                text: 'F0 Formant Editor',
                fontSize: 20 // Title font size
            },
            subtitle: {
                display: true,
                text: 'Custom Formant Editor'
            },
            legend: {
                labels: {
                    fontSize: 14 // Legend font size
                }
            },
            tooltip: {
                // Enable the on-canvas tooltip
                enabled: true,
                position: 'nearest',
                bodyFontSize: 12, // Tooltip font size
                callbacks: {
                    title: function(tooltips, data) {
                        // tooltipItems is an array of tooltip items
                        let xLabel = tooltips[0].label;
                        if (xLabel) {
                            xLabel = 'Frame ' + xLabel;
                        }
                        return xLabel;
                    }
                }
            }
        },
    }
  }; 

Chart.defaults.borderColor = '#444'; // Sets the color of the chart border (default is '#323232')
const ctx = document.getElementById('formant-graph').getContext('2d');
const formantChart = new Chart(ctx, config);

// Event listeners for dropdowns
document.getElementById('frequency-selector').addEventListener('change', function() {
  // Update chart data
});

// Event listeners for dropdowns
document.getElementById('amplitude-selector').addEventListener('change', function() {
  // Update chart data
});

// Event listeners for dropdowns
document.getElementById('motif-selector').addEventListener('change', function() {
  // Update chart data
});

// Event listeners for dropdowns
document.getElementById('samples-selector').addEventListener('change', function() {
  // Update chart data
});

document.querySelector('select[id="amplitude-selector"]').value = '0';
document.querySelector('select[id="frequency-selector"]').value = '1';
document.querySelector('select[id="motif-selector"]').value = '3';
document.querySelector('select[id="samples-selector"]').value = '2';