
class OSC_INTERVAL extends Object {
    constructor({ amplitude = -6.0, frequency = 250, frame = 0, time_step = 0 } = {}) {
        super();
        this.amplitude = amplitude;
        this.frequency = frequency;
        this.frame = frame;
        this.time_step = time_step;
    }
}

class FORMANTS extends Array {
    constructor({ motif = "Sine" } = {}) {
        super(); // Calls the Array constructor
        this.motif = motif; // Adds the motif property
    }
}

/*
// Creating an instance
const myArray = new ArrayWithMotif('myMotif');

// Example usage
console.log(myArray.motif); // Outputs: 'myMotif'
myArray.push(1, 2, 3); // Works like an array
console.log(myArray.length); // Outputs: 3
*/

Formants = [new FORMANTS({ motif: 'Sine'})];
Formants[0].push(
    new OSC_INTERVAL ({ amplitude: -6.0, frequency: 50.0, frame: 0, time_step: 0 }),
    new OSC_INTERVAL ({ amplitude: -4.5, frequency: 60.0, frame: 200, time_step: 15 }),
    new OSC_INTERVAL ({ amplitude: -4.0, frequency: 65.0, frame: 265, time_step: 30 }),
    new OSC_INTERVAL ({ amplitude: -5.5, frequency: 60.0, frame: 600, time_step: 45 }),
    new OSC_INTERVAL ({ amplitude: -5.8, frequency: 50.0, frame: 880, time_step: 60 }),
    new OSC_INTERVAL ({ amplitude: -6.0, frequency: 40.0, frame: 1040, time_step: 75 }),
    new OSC_INTERVAL ({ amplitude: -7.0, frequency: 30.0, frame: 1300, time_step: 90 }),
    new OSC_INTERVAL ({ amplitude: -11.0, frequency: 20.0, frame: 2050, time_step: 105 })
);

// Configuration For chart.js
// Extracting time_steps, amplitudes, and frequencies
const g_time_steps = Formants[0].map(osc_interval => osc_interval.time_step);
const g_amplitudes = Formants[0].map(osc_interval => osc_interval.amplitude);
const g_frequencies = Formants[0].map(osc_interval => osc_interval.frequency);
const g_frames = Formants[0].map(osc_interval => osc_interval.frame);

/*
// Combine your data into a single array
const combinedData = Formants[0].map(osc_interval => ({
    frame: osc_interval.frame,
    timeStep: osc_interval.time_step,
    amplitude: osc_interval.amplitude,
    frequency: osc_interval.frequency
}));
*/

/*
function getFormantData(formant) {
    const time_steps = formant.map(osc_interval => osc_interval.time_step);
    const amplitudes = formant.map(osc_interval => osc_interval.amplitude);
    const frequencies = formant.map(osc_interval => osc_interval.frequency);
    const frames = formant.map(osc_interval => osc_interval.frame);
    return { time_steps, amplitudes, frequencies, frames };
}
*/

g_config = {
    type: 'line',
    data: {
        /*labels: g_frames,*/
        datasets: [{
            label: 'Amplitude (dBFS)',
            data: Formants[0].map(osc_interval => ({y:osc_interval.amplitude, x:osc_interval.frame})),
            borderColor: 'blue',
            backgroundColor: 'rgb(0, 0, 255)',
            yAxisID: 'y-axis-amplitude',
            xAxisID: 'x-axis-frame',
        }, {
            label: 'Frequency (Hz)',
            data: Formants[0].map(osc_interval => ({y:osc_interval.frequency, x:osc_interval.frame})),
            borderColor: 'green',
            backgroundColor: 'rgb(0, 140, 0)',
            yAxisID: 'y-axis-frequency',
            xAxisID: 'x-axis-frame-dupl',
        }]
    },
    options: {
        scales: {
            'y-axis-amplitude': {
                type: 'linear',
                title: { 
                    text: 'dBFS ( Decibels relative to Full Scale )',
                    display: true,
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
                          return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]) + ' dBFS';
                    }
                }
            },
            'y-axis-frequency': {
                type: 'linear',
                title: { 
                    text: 'Hz',
                    display: true,
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
            },
            'x-axis-frame': {
                type: 'linear',
                title: { 
                    text: 'Audio Sample ( Frame ) ',
                    display: true,
                },
                display: true,
                position: 'bottom',
                grid: {
                    drawOnChartArea: false
                },
                ticks: {
                    // Include a dollar sign in the ticks
                    callback: function(value, index, ticks) {
                        // call the default formatter, forwarding `this`
                        return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]);
                    }
                }
            },
            'x-axis-frame-dupl': {
                type: 'linear',
                title: { 
                    text: 'Audio Sample ( Frame ) ',
                    display: true,
                },
                display: true,
                position: 'top',
                grid: {
                    drawOnChartArea: false
                },
                ticks: {
                    // Include a dollar sign in the ticks
                    callback: function(value, index, ticks) {
                        // call the default formatter, forwarding `this`
                        return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]);
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
                // Enable custom tooltips
                enabled: true,
                mode: 'index',
                position: 'nearest',
                bodyFontSize: 12, // Tooltip font size
                callbacks: {
                    title: function(tooltips, data) {
                        // Assuming the first dataset is for amplitude and has complete frame and time_step data
                        //const tt = tooltips[0];
                        const tt2 = tooltips[1];
                        //const tmpTimeStep = tt.label;
                        const tmpFrame = tt2.label;
                        /*
                        const tmpAmplitude = tt.formattedValue;
                        const tmpfrequency = tt2.formattedValue;
                        */
                        return `Frame: ${tmpFrame}`;
                    },
                    label: function(tooltipItem, data) {
                        // tooltipItem is an object containing properties of the tooltip
                        // data is an object containing all data passed to the chart
                        let yLabel = tooltipItem.formattedValue;
                        const xLabel = tooltipItem.dataset.label;
                        if (xLabel.match(/^Amplitude/)) {
                            yLabel = `Amplitude: ${yLabel} dBFS`;
                        } else if (xLabel.match(/^Frequency/)) {
                            yLabel = `Frequency: ${yLabel} Hz`;
                        }
                        return yLabel;
                    },
                }
            },
        },
    }
};

Chart.defaults.borderColor = '#444'; // Sets the color of the chart border (default is '#323232')

const ctx = document.getElementById('formant-graph').getContext('2d');
g_formantChart = new Chart(ctx, g_config);

activeColor = 'green';

// grab the default color of the button
const defaultColor = SineBTN.style.backgroundColor;

function updateActiveRadioButton(rButton) {
    document.querySelectorAll('.radio_button_class').forEach(bttn => {
        if (!bttn) return;
        if (bttn != rButton) {
            bttn.activeFlag = false;
            bttn.style.backgroundColor = defaultColor;
        } else {
            bttn.activeFlag = true;
            bttn.style.backgroundColor = activeColor;
            if (bttn.textContent != Formants[g_lastSelectedFormantIndex].motif) {
                Formants[g_lastSelectedFormantIndex].motif = bttn.textContent;
            }
        }
    });
}

/**
 * Object Mapping for Button Identifiers.
 * 
 * This mapping links the waveform or noise type options to their corresponding
 * button elements. Each key represents the text value of an option from an HTML
 * select element, and the corresponding value is the identifier for the button
 * element that should be activated for that option.
 * 
 * Usage: 
 * The `buttonMappings` object is used in the `updateMotifBar` function to 
 * determine which button should be made active based on the user's selection.
 * 
 * Structure:
 * - Key: String - The name of the waveform or noise type.
 * - Value: Object - The button element identifier associated with that type.
 *
 * Example:
 * To add a new mapping, simply add a new key-value pair to this object.
 * For instance, if you have a new type 'XYZ', and the corresponding button
 * identifier is 'XYZBTN', add it as:
 * 'XYZ': XYZBTN
 *
 * Note:
 * Ensure that the keys in this object exactly match the option values in the
 * HTML select element and that the button identifiers are correctly defined
 * in the HTML or JavaScript.
 */
const MotifButtonMappings = {
    'Sine': SineBTN,
    'Cosine': CosineBTN,
    'Square': SquareBTN,
    'F. Sawtooth': SawBTN,
    'R. Sawtooth': RSawBTN,
    'Triangle': TriangleBTN,
    'Pink Noise': PinkBTN,
    'Purple Noise': PurpleBTN,
    'Brown Noise': BrownBTN,
    'Blue Noise': BlueBTN,
    'White Gaussian Noise': GaussBTN,
};

// Called by the global Formants[].motif to convert its string input. The DOM calls updateActiveRadioButton directly.
function updateMotifBar(u)
{
    if (u in MotifButtonMappings) {
        let motifActiveButton = MotifButtonMappings[u];
        updateActiveRadioButton(motifActiveButton);
    }
}

minimum_allowed_formant_select_elements = 3;
g_lastSelectedFormantIndex = 0;
formant_selector.selectedIndex = 0;
resolution_selector.selectedIndex = 0;
updateMotifBar(Formants[0].motif);

function updateChart(formant) {
    var tmpConfig = g_config;

    tmpConfig.data.labels = formant.map(osc_interval => osc_interval.frame);
    tmpConfig.data.datasets[0].data = formant.map(osc_interval => osc_interval.amplitude);
    tmpConfig.data.datasets[1].data = formant.map(osc_interval => osc_interval.frequency);

    if (tmpConfig != g_config) {
        g_formantChart = new Chart(ctx, tmpConfig);
        g_config = tmpConfig;
    }

}

function updateFormantSelectElement(ii) {
    const I = Formants.length;
    formant_selector.innerHTML = '';

    // Reconstruct the regular options
    for (var i = 0; i < I; i++) {
        let option = document.createElement('option');
        option.value = i;
        option.textContent = 'F' + i;
        formant_selector.appendChild(option);
    }

    // Add the 'Insert New Formant' option
    let insertOption = document.createElement('option');
    insertOption.classList.add('insert_formant_class');
    insertOption.value = I;
    insertOption.textContent = 'Insert New Formant';
    formant_selector.appendChild(insertOption);

    // Add the 'Remove (Current) Formant' option
    let removeOption = document.createElement('option');
    removeOption.classList.add('remove_current_formant_class');
    removeOption.value = I + 1;
    removeOption.textContent = 'Remove (Current) Formant';
    formant_selector.appendChild(removeOption);

    try {
        formant_selector.selectedIndex = ii;  /* ii = g_lastSelectedFormantIndex */
    } catch (e) {
        console.info(e);
        formant_selector.selectedIndex = 0;
        g_lastSelectedFormantIndex = 0;
    }

}

function insertNewFormant(i) {
    const formant = Formants[i];
    var tmpFormant = new FORMANTS({ motif: formant.motif });
    formant.map(osc_interval => { 
        tmpFormant.push(new OSC_INTERVAL({ amplitude: osc_interval.amplitude
            , frequency: osc_interval.frequency
            , frame: osc_interval.frame
            , time_step: osc_interval.time_step }) );
        return osc_interval;
    });
    g_lastSelectedFormantIndex = i = Formants.push(tmpFormant) - 1;
    updateFormantSelectElement(i);
    updateMotifBar(tmpFormant.motif);
    updateChart(tmpFormant);
}

function removeFormantAt(i) {
    Formants.splice(i-1, 1);
    g_lastSelectedFormantIndex = i = (i - 1 > -1) ? --i : 0;
    updateFormantSelectElement(i);
    var formant = Formants[i];
    updateMotifBar(formant.motif);
    updateChart(formant);
}

// Event listeners for dropdowns

// script.js

confirmYes.addEventListener("click", function() {
    document.getElementById("confirmBox").style.display = "none";
    let formant = Formants[g_lastSelectedFormantIndex];
    formant.pcm_encoding = resolution_selector.selectedIndex;
});

confirmNo.addEventListener("click", function() {
    document.getElementById("confirmBox").style.display = "none";
});

resolution_selector.addEventListener('change', function() {
    confirmBox.style.display = "block";
});

formant_selector.addEventListener('change', function() {

    const selectedIndex = this.selectedIndex;
    const current_formant_count = this.options.length;
    const selectedOptionClassList = this.options[this.selectedIndex].classList;

    if (selectedOptionClassList.contains('insert_formant_class')) {
        insertNewFormant(g_lastSelectedFormantIndex);
    } else if (
        selectedOptionClassList.contains('remove_current_formant_class') 
        && current_formant_count > minimum_allowed_formant_select_elements) {
        removeFormantAt(g_lastSelectedFormantIndex);
    } else {
        g_lastSelectedFormantIndex = selectedIndex;
        const formant = Formants[g_lastSelectedFormantIndex];
        updateChart(formant);
        updateMotifBar(formant.motif);
    }

});

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

// Show/Hide JSON Text Area
function showTAElement({ jsonINDIR = 'out' }={})
{
    popupContainer.style.display = 'flex';
    jsonFORM.style.display = 'inline-block';
    jsonFORM.jsonIndirection = jsonINDIR;
}

// Show/Hide JSON Text Area
function hideTAElement()
{
    popupContainer.style.display = 'none';
    jsonFORM.style.display = 'none';
    jsonFORM.jsonIndirection = 'none';
}

CloseJsonBTN.addEventListener('click', function() {
    hideTAElement();
});

InJsonBTN.addEventListener('click', function() {
    JsonTA.value = '';
    showTAElement({ jsonINDIR: 'in' });
});

function serializeCustomObject(obj) {
    let result = "{";
    let properties = [];

    for (let property in obj) {
        if (obj.hasOwnProperty(property)) {
            let value = obj[property];

            // Handling non-primitive types (like another object)
            if (typeof value === 'object' && value !== null) {
                value = serializeCustomObject(value); // Recursive call
            } else if (typeof value === 'string') {
                value = `"${value}"`; // Add quotes for strings
            }

            properties.push(`"${property}": ${value}`);
        }
    }

    result += properties.join(", ");
    result += "}";
    return result;
}

OutJsonBTN.addEventListener('click', function() {
    let jsonData = Formants; /*g_formantChart.data;*/
    if ( !('phoneme' in jsonData) ) {
        jsonData.phoneme_name = '-';
    }
    let json = serializeCustomObject(jsonData); //JSON.stringify(jsonData, ' ', 2)
    JsonTA.value = json;
    showTAElement({ jsonINDIR: 'out' });
});

okBTN.addEventListener('click', function(e) {
    e.preventDefault();
    try {
        hideTAElement();
        switch(jsonFORM.jsonIndirection) {
            case 'in':
                const tmpData = JSON.parse(JsonTA.value);
                //g_formantChart.data/*.datasets*/ = tmpData;
                break;
            case 'out':
            case 'none':
            default:
                break;
        }
    } catch (err) {
        console.info(err);
    }
});

cancelBTN.addEventListener('click', function(e) {
    e.preventDefault();
    try {
        hideTAElement();
        switch(jsonFORM.jsonIndirection) {
            case 'in':
            case 'out':
            case 'none':
            default:
                break;
        }
    } catch (err) {
        console.info(err);
    }
});

function updateProgress(progress) {
    progressBar.style.width = progress.toString() + '%';

    if (progress == 100) {
        setTimeout(function() {
            progressBar.style.display = 'none';
        }, 500); // 500 milliseconds = 0.5 seconds
    } else if (progress > 0 
        && progressBar.style.display != 'block') {
            progressBar.style.display = 'block';
    }
}
