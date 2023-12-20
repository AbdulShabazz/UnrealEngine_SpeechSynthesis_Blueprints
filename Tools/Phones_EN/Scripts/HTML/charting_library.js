// Configuration For chart.js
const labels = ['0', '15', '30', '45', '60', '75', '90', '105'];

const data = {
    labels: labels,
    datasets: [{
        label: 'Formant F0 Amplitude - dB',
        xAxisID: 'x-axis-1',
        data: [-6.0, -4.5, -4.0, -5.5, -5.8, -6.0, -7.0, -11.0],
        fill: false,
        borderWidth: 1,
        borderColor: 'rgb(75, 192, 192)',
        tension: 0.35,
        backgroundColor: 'rgb(75, 192, 192)' //'rgb(61, 67, 67)'
    }, {
        type: 'line',
        label: 'Frequency - Hz',
        yAxisID: 'y-axis-1',
        fill: false,
        borderWidth: 1,
        borderColor: 'rgb(75, 192, 75)',
        tension: 0.0,
        backgroundColor: 'rgb(75, 192, 75)', //'rgb(61, 67, 67)'
        data: [50, 60, 65, 60, 50, 40, 30, 20]
    }, {
        type: 'line',
        label: 'Sample - Frame',
        yAxisID: 'y-axis-2',
        fill: false,
        borderWidth: 1,
        borderColor: 'rgb(255, 255, 0)',
        tension: 0.0,
        backgroundColor: 'rgb(255, 255, 0)', //'rgb(61, 67, 67)'
        data: [0, 200, 265, 600, 880, 1040, 1300, 2050]
    }]
};
const config = {
    type: 'line',
    data: data,
    options: {
      plugins: {
        beforeDraw: (chart) => {
          //const ctx = chart.ctx;
          //ctx.fillStyle = 'slategrey'; // Set to your desired background color
          //ctx.fillRect(0, 0, chart.width, chart.height);
        }
      },
      scales: {
        xAxes: [{
            id: 'x-axis-1',
            position: 'bottom',
            ticks: {
                fontSize: 12, // Y-Axis tick font size
                fontColor: '#eeeeee' // Sets the color of the y-axis ticks (labels)
            },
            gridLines: {
              color: '#eee' // Sets the y-axis grid lines to a shade of gray
            }
        }],
        yAxes: [{
            id: 'y-axis-1',
            position: 'left',
            ticks: {
                fontSize: 12, // Y-Axis tick font size
                fontColor: '#ffff00' // Sets the color of the y-axis ticks (labels)
            },
            gridLines: {
              color: '#eeeeee' // Sets the y-axis grid lines to a shade of gray
            },
          }, {
            id: 'y-axis-2',
            position: 'right',
            ticks: {
                fontSize: 12, // Y-Axis tick font size
                fontColor: '#eeeeee' // Sets the color of the y-axis ticks (labels)
            },
            gridLines: {
              color: '#eee' // Sets the y-axis grid lines to a shade of gray
            }
        }]
      },
      title: {
        display: true,
        text: 'Formant Editor',
        fontSize: 20 // Title font size
      },
      legend: {
        labels: {
          fontSize: 14 // Legend font size
        }
      },
      tooltips: {
        bodyFontSize: 12 // Tooltip font size
      }
    }
};

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
