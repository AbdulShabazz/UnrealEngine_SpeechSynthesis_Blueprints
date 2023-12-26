Formants = [];

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
            yAxisID: 'y-axis-amplitude',
        }, {
            label: 'Frequency (Hz)',
            data: frequencies,
            borderColor: 'green',
            backgroundColor: 'rgb(0, 140, 0)',
            yAxisID: 'y-axis-frequency',
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
                            xLabel = 'Frame: ' + xLabel;
                        }
                        return xLabel;
                    }
                }
            },
        },
    }
};

Chart.defaults.borderColor = '#444'; // Sets the color of the chart border (default is '#323232')
const ctx = document.getElementById('formant-graph').getContext('2d');
const formantChart = new Chart(ctx, config);

activeColor = 'green';

// grab thw default color of the button
const defaultColor = SineBTN.style.backgroundColor;

function updateActiveRadioButton(rButton) {
    document.querySelectorAll('.radio_button_class').forEach(bttn => {
        if (!bttn) return;
        if (bttn != rButton) {
            bttn.flag = false;
            bttn.style.backgroundColor = defaultColor;
        } else {
            bttn.flag = true;
            bttn.style.backgroundColor = activeColor;
        }
    });
}

// Event listeners for dropdowns

/* Button Actions */

SineBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

CosineBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

SquareBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

SawBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

RSawBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

TriangleBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

PinkBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

PurpleBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

BrownBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

BlueBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

GaussBTN.addEventListener('click', function() {
    updateActiveRadioButton(this);
});

/** popup window actions  */

AudioBTN.addEventListener('click', function() {
    
});

Cpp20BTN.addEventListener('click', function() {

});

CloseJsonBTN.addEventListener('click', function() {
    if(popupContainer.style.display != 'none'
    || popupContainer.style.display != '')
    {
        popupContainer.style.display = 'none';
    }
});

InJsonBTN.addEventListener('click', function() {
    if(popupContainer.style.display == 'none'
    || popupContainer.style.display == '')
    {
        popupContainer.style.display = 'flex';
        InJsonFORM.style.display = 'inline-block';
    } else {
        popupContainer.style.display = 
        InJsonFORM.style.display = 'none';
    }
});

OutJsonBTN.addEventListener('click', function() {
    if(popupContainer.style.display == 'none'
    || popupContainer.style.display == '')
    {
        popupContainer.style.display = 'flex';
        OutJsonFORM.style.display = 'inline-block';
    } else {
        popupContainer.style.display = 
        OutJsonFORM.style.display = 'none';
    }
});

InOkBTN.addEventListener('click', function(e) {
    e.preventDefault();
    try {
        //ctx.data.datasets = JSON.parse(JsonTA.value);
        InJsonBTN.click();
    } catch (err) {
        alert(err);
    }
});

InCancelBTN.addEventListener('click', function(e) {
    InJsonBTN.click();
});

OutOkBTN.addEventListener('click', function(e) {
    e.preventDefault();
    let json = JSON.stringify(2, ' ', formantChart.data)
    JsonTA.value = json;
    OutJsonBTN.click();
});

OutCancelBTN.addEventListener('click', function(e) {
    OutJsonBTN.click();
});
