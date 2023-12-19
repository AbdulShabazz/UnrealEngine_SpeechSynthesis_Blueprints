// Configuration For chart.js
const labels = ['0', '15', '30', '45', '60', '75', '90', '105'];

const data = {
    labels: labels,
    datasets: [{
      label: 'Formant F0',
      data: [-6.0, -4.5, -4.0, -5.5, -5.8, -6.0, -7.0, -11.0],
      fill: false,
      borderWidth: 1,
      borderColor: 'rgb(75, 192, 192)',
      tension: 0.35,
      backgroundColor: 'rgb(75, 192, 192)' //'rgb(61, 67, 67)'
    }, {
        type: 'line',
        label: 'Frequency - Hz',
        fill: false,
        borderWidth: 1,
        borderColor: 'rgb(75, 192, 75)',
        tension: 0.0,
        backgroundColor: 'rgb(75, 192, 75)', //'rgb(61, 67, 67)'
        data: [50, 60, 65, 60, 50, 40, 30, 20]
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
      /*
      scales: {
        xAxes: [{
            ticks: {
                fontSize: 12 // Y-Axis tick font size
            },
            gridLines: {
              color: '#888' // Sets the y-axis grid lines to a shade of gray
            }
        }],
        yAxes: [{
            ticks: {
                fontSize: 12 // Y-Axis tick font size
            },
            gridLines: {
              color: '#888' // Sets the y-axis grid lines to a shade of gray
            }
        }]
      },
      */
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
      }/*
      ,scales: {
        yAxes: [{
          ticks: {
            fontSize: 12 // Y-Axis tick font size
          }
        }],
        xAxes: [{
          ticks: {
            fontSize: 12 // X-Axis tick font size
          }
        }]
      }*/
      // ... other options here
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
