
g_default_frequency = 40.0;
g_default_amplitude = -6.0;

function clamp(value, min, max) {
    return Math.min(Math.max(value, min), max);
  }

// Configuration For chart.js plugins

const crossHairPlugin = {
    id: "crossHairPlugin",
    afterDatasetsDraw: function(chart, args, opts) {
        if (chart.crosshair) {
            // Prevent the crosshair from being drawn outside the plot area
            const chartArea = chart.chartArea;
            const minX = chartArea.left;
            const maxX = chartArea.right;
            const minY = chartArea.top;
            const maxY = chartArea.bottom;

            let ctx = chart.ctx;
            let x = clamp(chart.crosshair.x, minX, maxX);
            let y = clamp(chart.crosshair.y, minY, maxY);

            const leftX = chart.scales['x-axis-frame'].left;
            const rightX = chart.scales['x-axis-frame'].right;
            const topY = chart.scales['y-axis-amplitude'].top;
            const bottomY = chart.scales['y-axis-amplitude'].bottom;

            ctx.save();
            ctx.beginPath();

            // Draw new vertical line
            ctx.moveTo(x, topY);
            ctx.lineTo(x, bottomY);
            ctx.lineWidth = 1;
            ctx.strokeStyle = 'rgba(140,140,140,0.5)';
            ctx.stroke();

            // Draw new horizontal line
            ctx.moveTo(leftX, y);
            ctx.lineTo(rightX, y);
            ctx.lineWidth = 1;
            ctx.strokeStyle = 'rgba(140,140,140,0.5)';
            ctx.stroke();

            // Draw text for X and Y values at the axes
            const xValue = chart.scales['x-axis-frame'].getValueForPixel(x);
            const yValue = chart.scales[(chart.yAxisAmplitudeVisibleFlag) ? 'y-axis-amplitude' : 'y-axis-frequency'].getValueForPixel(y);

            ctx.fillStyle = '#aaa'; // Text color
            ctx.font = '12px roboto'; // Text font and size

            // Text alignment and position adjustments as needed
            ctx.fillText(`#${xValue.toFixed(0)}`, x - 18, 64); // top-most x-axis
            ctx.fillText(`#${xValue.toFixed(0)}`, x - 18, bottomY + 18); // bottom-most x-axis

            if (chart.yAxisAmplitudeVisibleFlag){
                ctx.fillText(`${yValue.toFixed(2)} dBFS`, 19, y);
                // Draw a point at the amplitude intersection
                ctx.beginPath();
                ctx.arc(x, y, 5, 0, 2 * Math.PI); // Draw a 5px radius point
                ctx.fillStyle = 'rgba(0,0,255,0.7)';
                ctx.fill();
            } else {
                ctx.fillText(`${yValue.toFixed(2)} Hz`, rightX + 10, y);
                // Draw a point at the frequency intersection
                ctx.beginPath();
                ctx.arc(x, y, 5, 0, 2 * Math.PI); // Draw a 5px radius point
                ctx.fillStyle = 'rgba(0,255,0,0.7)';
                ctx.fill();
            }

            ctx.restore();
        }
    },
};

Chart.register(crossHairPlugin);

Chart.defaults.borderColor = '#444'; // Sets the color of the chart border (default is '#323232')

function updateCrossHair(e) {
    const rect = formant_graph_canvas.getBoundingClientRect();
    const mouseX = e.clientX - rect.left;
    const mouseY = e.clientY - rect.top;

    // Store the mouse position in a variable accessible by Chart.js plugins
    g_formantChart.crosshair = { x: mouseX, y: mouseY };

    /** 
    @details: requestAnimationFrame() A method for telling the browser that you wish to perform a refresh-synced animation,
    g_formantChart.update(): Calls the plugin's afterDatasetsDraw method; redraw the basic chart (removes old crosshairs, 
    calls the plugin's afterDatasetsDraw method) */
    requestAnimationFrame(() => g_formantChart.update());
}

class WaveShape {
    static Sine_enum = 1 << 0;
    static Cosine_enum = 1 << 1;
    static QuarterSine_enum = 1 << 2;
    static HalfSine_enum = 1 << 3;
    static Triangle_enum = 1 << 4;
    static Square_enum = 1 << 5;
    static ForwardSawtooth_enum = 1 << 6;
    static ReverseSawtooth_enum  = 1 << 7;
    static WhiteNoise_enum = 1 << 8;
    static BrownNoise_enum = 1 << 9;
    static PinkNoise_enum = 1 << 10;
    static YellowNoise_enum = 1 << 11;
    static BlueNoise_enum = 1 << 12;
    static GreyNoise_enum = 1 << 13;
    static WhiteGaussianNoise_enum = 1 << 14;
    static PurpleVioletNoise_enum = 1 << 15;
}

class POINT extends Object {
    constructor({ x = 0, y = 0 } = {}) {
        super();
        this.x = x;
        this.y = y;
    }
}

class OSC_INTERVAL extends Object {
    constructor({ amplitude = g_default_amplitude, frequency = g_default_frequency, frame = 0, time_step = 0 } = {}) {
        super();
        this.amplitude = amplitude;
        this.frequency = frequency;
        this.frame = frame;
        this.time_step = time_step;
    }
}

class FORMANTS extends Array {
    constructor({ shape = "Sine" } = {}) {
        super(); // Calls the Array constructor
        this.shape = shape; // Adds the shape property
    }
}

Formants = [new FORMANTS({ shape: 'Sine'})];
Formants[0].push(
    new OSC_INTERVAL ({ amplitude: -6.0, frequency: 50.0, frame: 0, time_step: 0 }),
    new OSC_INTERVAL ({ amplitude: -4.5, frequency: 60.0, frame: 200, time_step: 15 }),
    new OSC_INTERVAL ({ amplitude: -4.0, frequency: 65.0, frame: 265, time_step: 30 }),
    new OSC_INTERVAL ({ amplitude: -5.5, frequency: 60.0, frame: 600, time_step: 45 }),
    new OSC_INTERVAL ({ amplitude: -5.8, frequency: 50.0, frame: 880, time_step: 60 }),
    new OSC_INTERVAL ({ amplitude: -6.0, frequency: 40.0, frame: 1040, time_step: 75 }),
    new OSC_INTERVAL ({ amplitude: -7.0, frequency: 30.0, frame: 1300, time_step: 90 }),
    new OSC_INTERVAL ({ amplitude: -11.0, frequency: 20.0, frame: 2000, time_step: 105 })
);

g_config = {
    type: 'line',
    data: {
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
                    }
                }
            },
        },
    }
};

formant_graph_canvas = document.getElementById('formant-graph');

formant_graph_canvas.addEventListener('mousemove', updateCrossHair);

const ctx = formant_graph_canvas.getContext('2d');
g_formantChart = new Chart(ctx, g_config);
g_formantChart.yAxisAmplitudeVisibleFlag = true;

function createSlider(id, label, value, min, max, step, callback) {
    var sliderContainer = document.createElement('div');

    var sliderLabel = document.createElement('label');
    sliderLabel.htmlFor = id;
    sliderLabel.textContent = label + ': ';
    sliderContainer.appendChild(sliderLabel);

    // Add min value spans
    var minValueFrameSpan = document.createElement('span');
    minValueFrameSpan.className = 'min-value';
    minValueFrameSpan.textContent = min.toFixed(2);
    sliderContainer.appendChild(minValueFrameSpan);

    var slider = document.createElement('input');
    slider.type = 'range';
    slider.id = id;
    slider.min = min;
    slider.max = max;
    slider.value = value;
    slider.step = step || '0.01'; // Set step size, eg. '1', '0.01', ... , 'any'
    slider.oninput = function() {
        callback(this.value);
    };
    sliderContainer.appendChild(slider);

    var maxValueFrameSpan = document.createElement('span');
    maxValueFrameSpan.className = 'max-value';
    maxValueFrameSpan.textContent = max.toFixed(2);
    sliderContainer.appendChild(maxValueFrameSpan);

    var output = document.createElement('span');
    output.id = id + '-output';
    output.textContent = value;
    sliderContainer.appendChild(output);

    // Update the output text when the slider value changes
    slider.addEventListener('input', function() {
        output.textContent = slider.value;
    });

    return sliderContainer;
}

function getMaxFrame(i, formant) {
    // Implement logic to determine the maximum frequency allowed based on adjacent points
    // Placeholder return value
    return formant[i + 1].frame;
}

function getMaxFrequency(i, formant) {
    // Implement logic to determine the maximum frequency allowed based on adjacent points
    // Placeholder return value
    return 500.00;
}

function getMaxAmplitude(i, formant) {
    // Implement logic to determine the maximum amplitude allowed based on adjacent points
    // Placeholder return value
    return 0.00;
}

// Function to find and remove the nearest element
function removeNearest(audio_frame, remove_element) {
    let nearestAudioFrameIndex  = 0;
    let nearestValue = audio_frame[0];
    let smallestDiff = Math.abs(audio_frame[0] - remove_element[0]);

    // Find the nearest value
    const I = audio_frame.length;
    for (let i = 1; i < I; ++i) {
        let currentDiff = Math.abs(audio_frame[i] - remove_element[0]);
        if (currentDiff < smallestDiff) {
            smallestDiff = currentDiff;
            nearestAudioFrameIndex = i;
        } else {
            nearestValue = audio_frame[nearestAudioFrameIndex];
            // Remove the nearest value from the array
            let indexToRemove = audio_frame.indexOf(nearestValue);
            if (indexToRemove !== -1) {
                audio_frame.splice(indexToRemove, 1);
            }
            break;
        }
    }
}

function removeDatapoint(audio_frame, remove_element) {
    // Remove the data point from the chart //
    let chart = g_formantChart;
    if (chart.crosshair) {
        // Prevent the crosshair from inserting new points outside the plot area
        const chartArea = chart.chartArea;
        const minX = chartArea.left;
        const maxX = chartArea.right;
        const minY = chartArea.top;
        const maxY = chartArea.bottom;

        let x = clamp(chart.crosshair.x, minX, maxX);
        let y = clamp(chart.crosshair.y, minY, maxY);

        // Derive points for X and Y values at the crosshair axes
        const xValue = chart.scales['x-axis-frame'].getValueForPixel(x);
        const yValue = chart.scales[(chart.yAxisAmplitudeVisibleFlag) ? 'y-axis-amplitude' : 'y-axis-frequency'].getValueForPixel(y);

        // Execute the function
        const formant = Formants[g_lastSelectedFormantIndex];
        const remove_element = [xValue, yValue];
        removeNearest(formant, remove_element);

        updateChart(formant);
    } // end if (chart.crosshair)
}

function displaySliders(i, formant) {
    // Reference to the container where sliders will be added
    var container = slider_container;

    // Clear previous sliders
    container.innerHTML = '';

    const minFrame = i - 1 in formant ? formant[i-1].frame : formant[i].frame;
    const maxFrame = i + 1 in formant ? formant[i+1].frame : formant[i].frame;

    // Create a slider for the frame index
    var frameIndexSlider = createSlider('frameIndex'
        , 'Adjust Frame Index'
        , formant[i].frame
        , minFrame
        , maxFrame
        , "1"
        , function(value) {
            // Update the chart data and re-render
            let formant = Formants[g_lastSelectedFormantIndex];
            formant[i].frame = value;
            updateChart(formant);
    });

    // Create a slider for frequency
    var frequencySlider = createSlider('frequency'
        , 'Frequency (Hz)'
        , formant[i].frequency
        , 0.00
        , 500.00
        , "0.01"
        , function(value) {
            // Update the chart data and re-render
            let formant = Formants[g_lastSelectedFormantIndex];
            formant[i].frequency = value;
            updateChart(formant);
    });

    // Create a slider for amplitude
    var amplitudeSlider = createSlider('amplitude'
        , 'Amplitude (dBFS)'
        , formant[i].amplitude
        ,-20.00
        , 0.00
        , "0.01"
        , function(value) {
            // Update the chart data and re-render
            let formant = Formants[g_lastSelectedFormantIndex];
            formant[i].amplitude = value;
            updateChart(formant);
    });

    var deleterTextOption = document.createElement('span');
    deleterTextOption.textContent = 'DELETE';
    deleterTextOption.style.color = 'red';
    deleterTextOption.style.cursor = 'pointer';
    deleterTextOption.onclick = function(e) {
        let formant = Formants[g_lastSelectedFormantIndex];
        const remove_element = formant[i].frame;
        removeNearest(formant, remove_element);
        updateChart(formant);
        hideTAElement();
    };

    // Append the sliders to the parent container
    container.appendChild(frameIndexSlider);
    container.appendChild(frequencySlider);
    container.appendChild(amplitudeSlider);
    container.appendChild(deleterTextOption);

    showTAElement({ jsonINDIR: 'slider' });
}

formant_graph_canvas.addEventListener('click', function(e) {
    // Add a point to the chart //
    let chart = g_formantChart;
    if (chart.crosshair) {
        // Prevent the crosshair from inserting new points outside the plot area
        const chartArea = chart.chartArea;
        const minX = chartArea.left;
        const maxX = chartArea.right;
        const minY = chartArea.top;
        const maxY = chartArea.bottom;

        let x = clamp(chart.crosshair.x, minX, maxX);
        let y = clamp(chart.crosshair.y, minY, maxY);

        // Derive points for X and Y values at the crosshair axes
        const xValue = chart.scales['x-axis-frame'].getValueForPixel(x);
        const yValue = chart.scales[(chart.yAxisAmplitudeVisibleFlag) ? 'y-axis-amplitude' : 'y-axis-frequency'].getValueForPixel(y);

        var formant = Formants[g_lastSelectedFormantIndex];
        var nextOSCINterval = new OSC_INTERVAL({ amplitude: yValue, frequency: g_default_frequency, frame: xValue, time_step: 0 });

        if (!chart.yAxisAmplitudeVisibleFlag) { /* Frequency */
            nextOSCINterval.amplitude = g_default_amplitude;
            nextOSCINterval.frequency = yValue;
        }

        const I = formant.length;
        for (var i = 0; i < I; ++i) {
            if (Math.abs(formant[i].frame - xValue) < 65) {
                displaySliders(i, formant);
                break;
            } else if (formant[i].frame > xValue) {
                formant.splice(i, 0, nextOSCINterval);
                break;
            }
        }

        updateChart(formant);
    } // end if (chart.crosshair)
});

formant_graph_canvas.addEventListener('mousedown', function(e) {
    // Begin Update for the selected (amplitude/frequency) data point //

});

formant_graph_canvas.addEventListener('mousemove', function(e) {
    // Realtime-Update the selected (amplitude/frequency) data point //

});

formant_graph_canvas.addEventListener('mouseup', function(e) {
    // End Update the selected (amplitude/frequency) data point //

});

formant_graph_canvas.addEventListener('dblclick', function(e) {

});

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
            if (bttn.textContent != Formants[g_lastSelectedFormantIndex].shape) {
                Formants[g_lastSelectedFormantIndex].shape = bttn.textContent;
            }
        }
    });
}

const ShapeButtonMappings = {
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

// Called by the global Formants[].shape to convert its string input. The DOM calls updateActiveRadioButton directly.
function updateShapeBar(u)
{
    if (u in ShapeButtonMappings) {
        let ShapeActiveButton = ShapeButtonMappings[u];
        updateActiveRadioButton(ShapeActiveButton);
    }
}

const defaultPCMEncoding = 11; // PCM 24/192 kHz

minimum_allowed_formant_select_elements = 3;
g_lastSelectedFormantIndex = 0;
formant_selector.selectedIndex = 0;
Formants.pcm_encoding = defaultPCMEncoding;
resolution_selector.selectedIndex = defaultPCMEncoding; 
updateShapeBar(Formants[0].Shape);

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
    var tmpFormant = new FORMANTS({ shape: formant.shape });
    formant.map(osc_interval => { 
        tmpFormant.push(new OSC_INTERVAL({ amplitude: osc_interval.amplitude
            , frequency: osc_interval.frequency
            , frame: osc_interval.frame
            , time_step: osc_interval.time_step }) );
        return osc_interval;
    });
    g_lastSelectedFormantIndex = i = Formants.push(tmpFormant) - 1;
    updateFormantSelectElement(i);
    updateShapeBar(tmpFormant.shape);
    updateChart(tmpFormant);
}

function removeFormantAt(i) {
    Formants.splice(i-1, 1);
    g_lastSelectedFormantIndex = i = (i - 1 > -1) ? --i : 0;
    updateFormantSelectElement(i);
    var formant = Formants[i];
    updateShapeBar(formant.shape);
    updateChart(formant);
}

// Event listeners for dropdowns

function removeButtonEventListeners() {
    confirmYes.onclick = null; // Remove the event listener itself
    confirmNo.onclick = null; // Remove the event listener itself
}

function showConfirmBox({ message="" }={}) {
    return new Promise((resolve, reject) => {

            // Event handler for OK
            confirmYes.onclick = () => {
                confirmBox.style.display = 'none';
                removeButtonEventListeners();
                resolve(true); // Resolve the promise when OK is clicked
            };

            // Event handler for CANCEL
            confirmNo.onclick = () => {
                confirmBox.style.display = 'none';
                removeButtonEventListeners();
                reject(false); // Reject the promise when CANCEL is clicked
            };

            if (message != "") {
                messageCaption.textContent = message;
            }

            confirmBox.style.display = 'block';

        });
}

resolution_selector.addEventListener('change', function() {
    Formants.pcm_encoding = resolution_selector.selectedIndex;
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
        updateShapeBar(formant.shape);
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

/** Audio Frame options */

const audioFrame_sizes = {
    "0":1,
    "1":2,
    "2":5,
    "3":10,
    "4":25,
    "5":100,
    "6":200,
    "7":400,
    "8":1000,
    "9":2500,
    "10":5000,
    "11":11025,
    "12":22050,
    "13":48000,
    "14":92025,
    "15":96000,
    "16":192000,
    "17":384000,
    "18":768000
};

add_frames_selector.addEventListener('change', function() {

});

remove_frames_selector.addEventListener('change', function() {

});

AddFramesBTN.addEventListener('click', function() {
    try {
        var formant = Formants[g_lastSelectedFormantIndex];
        const dx = audioFrame_sizes[add_frames_selector.selectedIndex];
        const I = formant.length;
        var lastOSCInterval = formant[I - 1];

        // TODO: Re-sample the audio (scale the frame property of each OSC_INTERVAL object by the new overall length)
        // TODO: Adjust te length for all formant curves

        const nextOSCINterval_frame = lastOSCInterval.frame + dx;
        const nextOSCInterval_time_step = lastOSCInterval.time_step;
        formant.push(new OSC_INTERVAL({ amplitude: g_default_amplitude
            , frequency: g_default_frequency
            , frame: nextOSCINterval_frame
            , time_step: nextOSCInterval_time_step }) );
        updateChart(formant);
    } catch (e) {
        console.info(`Frame insertion error: ${e}`);
    }
});

RemoveFramesBTN.addEventListener('click', function() {
    try {
        var formant = Formants[g_lastSelectedFormantIndex];
        const dx = audioFrame_sizes[remove_frames_selector.selectedIndex];
        const I = formant.length;
        var lastOSCInterval = formant[I - 1];

        // TODO: Re-sample the audio (scale the frame property of each OSC_INTERVAL object by the new overall length)
        // TODO: Adjust te length for all formant curves

        const lastOSCInterval_frame = lastOSCInterval.frame - dx;

        if (lastOSCInterval_frame < 0) {
            console.info('Frame removal error: Invalid frame count.');
            return;
        } else {
            var i = 0;
            var removeElementFlag = false;
            while (i < I) {
                if (!removeElementFlag && formant[i].frame > lastOSCInterval_frame) {
                    formant[i].frame = lastOSCInterval_frame;
                    removeElementFlag = true;
                } else if (removeElementFlag) {
                    formant.pop();
                }
                ++i;
            }
            updateChart(formant);
        }
    } catch (e) {
        console.info('Frame removal error: Invalid frame count for removal.');
        console.info(e);
    }
});

// Show/Hide JSON Text Area
function showTAElement({ jsonINDIR = 'out' }={})
{
    popupContainer.style.display = 'flex';
    switch (jsonINDIR) {
        case 'in':
        JsonTA.style.display = 'block';
        json_form_class.style.display = 'block';
        jsonFORM.style.display = 'inline-block';
        jsonFORM.jsonIndirection = jsonINDIR;
        break;

        case 'out':
        json_form_class.style.display = 'block';
        JsonTA.style.display = 'inline-block';
        jsonFORM.jsonIndirection = jsonINDIR;
        break;

        case 'slider':
        slider_container.style.display = 'inline-block';
        break;
    }
}

// Show/Hide JSON Text Area
function hideTAElement()
{
    popupContainer.style.display = 'none';
    json_form_class.style.display = 'none';
    jsonFORM.style.display = 'none';
    jsonFORM.jsonIndirection = 'none';
    JsonTA.style.display = 'none';
    slider_container.style.display = 'none';
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

const pcm_encoding_docstring_options = 
{
    "0": {
        "pcm_encoding_docstring": "PCM 16-bit/44 KHz",
        "bit_depth": 16,
        "sample_rate": 44.1 },
    "1": {
        "pcm_encoding_docstring": "PCM 16-bit/48 KHz",
        "bit_depth": 16,
        "sample_rate": 48 },
    "2": {
        "pcm_encoding_docstring": "PCM 16-bit/88 KHz",
        "bit_depth": 16,
        "sample_rate": 88.2 },
    "3": {
        "pcm_encoding_docstring": "PCM 16-bit/96 KHz",
        "bit_depth": 16,
        "sample_rate": 96 },
    "4": {
        "pcm_encoding_docstring": "PCM 16-bit/192 KHz",
        "bit_depth": 16,
        "sample_rate": 192 },
    "5": {
        "pcm_encoding_docstring": "PCM 16-bit/384 KHz",
        "bit_depth": 16,
        "sample_rate": 384 },
    "6": {
        "pcm_encoding_docstring": "PCM 16-bit/768 KHz",
        "bit_depth": 16,
        "sample_rate": 768 },
    "7": {
        "pcm_encoding_docstring": "PCM 24-bit/44 KHz",
        "bit_depth": 24,
        "sample_rate": 44.1 },
    "8": {
        "pcm_encoding_docstring": "PCM 24-bit/48 KHz",
        "bit_depth": 24,
        "sample_rate": 48 },
    "9": {
        "pcm_encoding_docstring": "PCM 24-bit/88 KHz",
        "bit_depth": 24,
        "sample_rate": 88.2 },
    "10": {
        "pcm_encoding_docstring": "PCM 24-bit/96 KHz",
        "bit_depth": 24,
        "sample_rate": 96 },
    "11": {
        "pcm_encoding_docstring": "PCM 24-bit/192 KHz",
        "bit_depth": 24,
        "sample_rate": 192 },
    "12": {
        "pcm_encoding_docstring": "PCM 24-bit/384 KHz",
        "bit_depth": 24,
        "sample_rate": 384 },
    "13": {
        "pcm_encoding_docstring": "PCM 24-bit/768 KHz",
        "bit_depth": 24,
        "sample_rate": 768 },
    "14": {
        "pcm_encoding_docstring": "PCM 32-bit/44 KHz",
        "bit_depth": 32,
        "sample_rate": 44.1 },
    "15": {
        "pcm_encoding_docstring": "PCM 32-bit/48 KHz",
        "bit_depth": 32,
        "sample_rate": 48 },
    "16": {
        "pcm_encoding_docstring": "PCM 32-bit/88 KHz",
        "bit_depth": 32,
        "sample_rate": 88.2 },
    "17": {
        "pcm_encoding_docstring": "PCM 32-bit/96 KHz",
        "bit_depth": 32,
        "sample_rate": 96 },
    "18": {
        "pcm_encoding_docstring": "PCM 32-bit/192 KHz",
        "bit_depth": 32,
        "sample_rate": 192 },
    "19": {
        "pcm_encoding_docstring": "PCM 32-bit/384 KHz",
        "bit_depth": 32,
        "sample_rate": 384 },
    "20": {
        "pcm_encoding_docstring": "PCM 32-bit/768 KHz",
        "bit_depth": 32,
        "sample_rate": 768 },
    "21": {
        "pcm_encoding_docstring": "PCM 64-bit/44 KHz",
        "bit_depth": 64,
        "sample_rate": 44.1 },
    "22": {
        "pcm_encoding_docstring": "PCM 64-bit/48 KHz",
        "bit_depth": 64,
        "sample_rate": 48 },
    "23": {
        "pcm_encoding_docstring": "PCM 64-bit/88 KHz",
        "bit_depth": 64,
        "sample_rate": 88.2 },
    "24": {
        "pcm_encoding_docstring": "PCM 64-bit/96 KHz",
        "bit_depth": 64,
        "sample_rate": 96 },
    "25": {
        "pcm_encoding_docstring": "PCM 64-bit/192 KHz",
        "bit_depth": 64,
        "sample_rate": 192 },
    "26": {
        "pcm_encoding_docstring": "PCM 64-bit/384 KHz",
        "bit_depth": 64,
        "sample_rate": 384 },
    "27": {
        "pcm_encoding_docstring": "PCM 64-bit/768 KHz",
        "bit_depth": 64,
        "sample_rate": 768 }
};

OutJsonBTN.addEventListener('click', function() {
    let jsonData = Formants; /*g_formantChart.data;*/
    if ( !('phoneme_name' in jsonData) ) {
        jsonData.phoneme_name = 'n/a';
    }
    jsonData.pcm_encoding_docstring = pcm_encoding_docstring_options[jsonData.pcm_encoding].pcm_encoding_docstring;
    let json = serializeCustomObject(jsonData);
    JsonTA.value = json;
    showTAElement({ jsonINDIR: 'out' });
});

/** popup window actions  */

Object.prototype.add_point = function(b) {
    return new POINT ({ x: this.x + b.x, y: this.y + b.y });
};

Object.prototype.mult_scalar = function(b) {
    return new POINT ({ x: this.x * b, y: this.y * b });
};

function linear_spline_interpolation (formant,the_interpolation_frame,audio_component)
{
    if (formant.length == 0 )
        throw ("runtime_error: Not enough frames for linear interpolation within the specified oscillator interval.");

    // Find the interval [x_i, x_i+1] that contains x
    const I = formant.length-1;
    const II = formant.length-2;
    for (let i = 0; i < II; ++i) {
        const frame_1 = formant[i].frame;
        const frame_2 = formant[i+1].frame;
        const audio_component_1 = audio_component === "amplitude" ? formant[i].amplitude : formant[i].frequency ;
        const audio_component_2 = audio_component === "amplitude" ? formant[i+1].amplitude : formant[i+1].frequency ;
        if (the_interpolation_frame > frame_1 && the_interpolation_frame < frame_2) {
            const dt = (the_interpolation_frame - audio_component_1) / (audio_component_1 - frame_2);
            return (1 - dt) * audio_component_1 + dt * audio_component_2;
        }
    }

    // Handle extrapolation cases
    const frame_1 = formant[0].frame;
    const frame_2 = formant[I].frame;
    const audio_component_1 = audio_component === "amplitude" ? formant[0].amplitude : formant[0].frequency ;
    const audio_component_2 = audio_component === "amplitude" ? formant[I].amplitude : formant[I].frequency ;
    if (the_interpolation_frame <= frame_1) {
        return  audio_component_1;
    } else if (the_interpolation_frame >= frame_2) {
        return  audio_component_2;
    }

    throw ("runtime_error: unspecfied linear spline interpolation error.");
}

function bezier_spline_interpolation (formant,the_interpolation_frame,audio_component)
{
    if (formant.length < 4 || the_interpolation_frame > 1)
        return pts;

    const p0 = pts[0].mult_scalar(Math.pow(1 - the_interpolation_frame, 3));
    const p1 = pts[1].mult_scalar(3 * Math.pow(1 - the_interpolation_frame, 2) * the_interpolation_frame);
    const p2 = pts[2].mult_scalar(3 * (1 - the_interpolation_frame) * Math.pow(the_interpolation_frame, 2));
    const p3 = pts[3].mult_scalar(Math.pow(the_interpolation_frame, 3));

    return p0.add_point(p1.add_point(p2.add_point(p3)));
}

function has_shape(a,b)
{
    return (a & b) !== 0;
}

/**
@brief Generates complex signal based on specific wave-shape parameters.
@details Generates complex signal based on specific wave-shape parameters.
@param shapes_oscilatorParamsVec: The complex wave-shapes to develop (ie. Formants[]).
@param customUpdateCallback: An (optional) lambda that can be used to update the oscillator parameters, instead.
@return The oscillator signal at frame N).*/
function generateComplexSignal(shapes_oscilatorParamsVec
    , customUpdateCallback) {

    let frame_idx = 0;
    let audioFrames_float64Vec = [];

    for (const shape_oscillatorParams of shapes_oscilatorParamsVec) {
        var outShape = 0;

        // Custom updates using the lambda function
        if (customUpdateCallback) {
            outShape = customUpdateCallback(
                this,
                shape_oscillatorParams,
                outShape);
        } else {
            const FRAME_IDX = shape_oscillatorParams.frame + 1;
            while(frame_idx < FRAME_IDX)
            {
                const startingShape = outShape;
                /*
                const hz = bezier_spline_interpolation(shape_oscillatorParams, frame_idx, "frequency");
                const db = bezier_spline_interpolation(shape_oscillatorParams, frame_idx, "amplitude");*/
                const hz = linear_spline_interpolation(shape_oscillatorParams, frame_idx, "frequency");
                const db = linear_spline_interpolation(shape_oscillatorParams, frame_idx, "amplitude");
                
                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.Sine_enum))
                    outShape += sine(db
                        , hz
                        , frame_idx
                        , shape_oscillatorParams.theta); 

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.Cosine_enum))
                    outShape += cosine(db
                        , hz
                        , frame_idx
                        , shape_oscillatorParams.theta);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.QuarterSine_enum))
                    outShape += quarterSine(db
                        , hz
                        , frame_idx
                        , shape_oscillatorParams.theta);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.HalfSine_enum))
                    outShape += halfSine(db
                        , hz
                        , frame_idx
                        , shape_oscillatorParams.theta);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.Triangle_enum))
                    outShape += Triangle(db
                        , hz
                        , frame_idx);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.Square_enum))
                    outShape += Square(db
                        , hz
                        , frame_idx);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.ForwardSawtooth_enum))
                    outShape += forwardSaw(db
                        , hz
                        , frame_idx);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.ReverseSawtooth_enum))
                    outShape += ReverseSaw(db
                        , hz
                        , frame_idx);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.WhiteNoise_enum))
                    outShape += whiteNoise(db);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.BrownNoise_enum))
                    outShape += brownNoise(db
                        , hz
                        , frame_idx);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.PinkNoise_enum))
                    outShape += pinkNoise(db
                        , hz
                        , frame_idx);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.YellowNoise_enum))
                    outShape += yellowNoise(db
                        , hz
                        , frame_idx);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.BlueNoise_enum))
                    outShape += blueNoise(db
                        , hz
                        , frame_idx);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.GreyNoise_enum))
                    outShape += greyNoise(db
                        , hz
                        , frame_idx);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.WhiteGaussianNoise_enum))
                    outShape += whiteGaussianNoise(db);

                if (has_shape(shape_oscillatorParams.shape
                    , WaveShape.PurpleVioletNoise_enum))
                    outShape += purpleVioletNoise();

                if (outShape == startingShape)
                    throw ("invalid_argument to WaveShape generator - Unexpected or Unknown WaveShape type.");
                    //console.error(`Error at audio frame ${frame_idx} - Unknown or Unexpected wave-shape: ${shape_oscillatorParams.shape}`);
                    //throw std::invalid_argument("Unexpected or Unknown wave-shape.");
                ++frame_idx;
            } // end of while statement
        } // End of else statement

        audioFrames_float64Vec.push(outShape);
    } // End of for loop

    return audioFrames_float64Vec;
}; // End of generateComplexSignal()

audioContext = new AudioContext();
gainNode = audioContext.createGain();
gainNode.gain.value = 1.00; //  range [0,2] step size 0.01

function setInt24(view, offset, value) {
    this.setUint8(offset, (value & 0xFF0000) >> 16);
    this.setUint16(offset + 1, value & 0x00FFFF);
}

/*
function setInt32(view, offset, value) {
    this.setUint8(offset, (value & 0xFF0000) >> 16);
    this.setUint16(offset + 1, value & 0x00FFFF);
}
*/

function setInt64(view, offset, value) {
    /* 64-bit integers cannot natively be represented in (53-bit) javascript, see BigInt */
    // Check if the environment supports BigInt
    if (typeof BigInt === 'undefined') {
        throw new Error('BigInt is not supported for this environment.');
    }

    // Ensure the value is a BigInt
    const bigValue = BigInt(value);

    // Mask to extract lower 32 bits
    const lowerMask = BigInt(0xFFFFFFFF);

    // Extract lower 32 bits and upper 32 bits
    const lowerPart = bigValue & lowerMask;
    const upperPart = (bigValue >> BigInt(32)) & lowerMask;

    // Write the lower and upper parts into the DataView
    // Assuming little-endian format
    this.setUint32(offset, Number(lowerPart), true);
    this.setUint32(offset + 4, Number(upperPart), true);
}

function bufferToWave(buffer) {
    let numberOfChannels = buffer.length;
    let sampleRate = buffer[0].sampleRate;
    let frameLength = buffer[0].length;
    let byteOffset = 2; // 16-bit data, 2 bytes (default)

    switch (buffer[0].bitsPerSample) {
    case 24:
        byteOffset = 3; // 24-bit data, 3 bytes
        break;
    case 32:
        byteOffset = 4; // 32-bit data, 4 bytes
        break;
    case 64:
        byteOffset = 8; // 64-bit data, 8 bytes
        break;
    }

    // Create a buffer to hold the WAV file data
    let wavBuffer = new ArrayBuffer(44 + length * numberOfChannels * byteOffset);
    let view = new DataView(wavBuffer);

    // Write WAV container headers
    // ... (code to write the 'RIFF', 'WAVE', 'fmt ', 'data' chunk headers, etc.)

    // Write PCM data
    let pcm_wav_header = 44;

    view.setInt24 = setInt24;
    //view.setInt32 = setInt32;
    view.setInt64 = setInt64;

    view.setIntN = view.setInt16;
    switch (buffer[0].bitsPerSample) {
        case 24:
            view.setIntN = view.setInt24;
            break;
        case 32:
            //view.setIntN = view.setInt32;
            break;
        case 64:
            view.setIntN = view.setInt64;
            break;
    }

    for (let i = 0; i < frameLength; i++) {
        for (let channel = 0; channel < numberOfChannels; channel++) {
            let sample = Math.max(-1, Math.min(1, buffer[channel][i])); // clamp
            view.setIntN(pcm_wav_header, sample < 0 ? sample * 0x8000 : sample * 0x7FFF, true);
            pcm_wav_header += byteOffset;
        }
    }

    return wavBuffer;
}

AudioBTN.addEventListener('click', function() {

    // Bard: Here's the JavaScript code to generate a sinusoidal audio of 1s duration at PCM 24 bit/48 kHz sampling:

    // Define desired wave parameters
    const sampleRate = 48000; // 48 kHz
    const bitsPerSample = 24; // 24-bit audio
    const frequency = 440; // Hz (e.g., 440 Hz for A4)
    const duration = 1; // 1 second
    const amplitude = 0.4; // 0.5 for a comfortable volume

    // Create an audio buffer with appropriate settings
    const audioBuffer = audioContext.createBuffer(2, duration * sampleRate, sampleRate);

    let channelData = audioBuffer.getChannelData(0);
    let channelDataRight = audioBuffer.getChannelData(0);

    channelData.sampleRate = sampleRate;
    channelData.bitsPerSample = bitsPerSample;

    channelDataRight.sampleRate = sampleRate;
    channelDataRight.bitsPerSample = bitsPerSample;

    // Generate the sine wave data
    const I = channelData.length;
    for (let i = 0; i < I; ++i) {
        const time = i / sampleRate;
        const value = Math.sin(2 * Math.PI * frequency * time) * amplitude;

        // Ensure the value is positive for dBFS conversion
        const absValue = Math.abs(value);

        // Convert to dBFS and consider the case when the value is 0
        const dBFS = absValue > 0 ? 20 * Math.log10(absValue) : -Infinity;

        const nsample = value * (2 ** (bitsPerSample - 1) - 1); // Scale for 24-bit audio

        channelData[i] = nsample;
        channelDataRight[i] = i > 0 ? channelData[i-1] : 0;  // offset channel samples by 1 to create a perceived stereo channel
    }

    const channelDataLeft = channelData;

    // Example usage
    let wavBuffer = bufferToWave([/*yourLeftChannelData*/channelDataLeft, /*yourRightChannelData*/channelDataRight]);
    let blob = new Blob([wavBuffer], {type: 'audio/wav'});
    let url = URL.createObjectURL(blob);

    // Create an audio element and set its source to the blob URL
    let audio = new Audio(url);
    audio.controls = true;
    audio.classList.add('audioPlaybackControls_class');
    audioPlaybackControls.innerHTML = '';
    audioPlaybackControls.appendChild(audio);

    /*
    // Optionally, create a download link
    let downloadLink = document.createElement('a');
    downloadLink.href = url;
    downloadLink.download = 'synthesized_speech.wav';
    downloadLink.textContent = 'Download Synthesized Speech';
    document.body.appendChild(downloadLink);
    */

    /*
    // For API generated audio
    const osc = audioContext.createOscillator();
    osc.type = "sine";
    osc.frequency.value = 440; // 440 Hz
    gainNode.gain.value = 0.5
    osc.connect(gainNode);
    osc.start();
    */

    // For artificially generated audio
    const source = audioContext.createBufferSource();
    source.buffer = audioBuffer;
    gainNode.connect(audioContext.destination); //source.connect(audioContext.destination);
    source.connect(gainNode);
    source.start(0);

    /*
    // For MP3 audio
    const audioBufferMP3 = await fetch('audio.mp3')
        .then( response => response.arrayBuffer() );
    const audioBufferSourceNode = audioContext.createBufferSource();
    audioBufferSourceNode.buffer = await audioContext.decodeAudioData(audioBufferMP3);
    gainNode.gain.value = 0.5;
    audioBufferSourceNode.connect(gainNode);
    audioBufferSourceNode.start(0);*/

    const audio_frames = generateComplexSignal(Formants, null);
});

Cpp20BTN.addEventListener('click', function() {
    OutJsonBTN.click();
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

amplitudeBtn.addEventListener('click', function() {
    this.classList.add('selected');
    frequencyBtn.classList.remove('selected');
    g_formantChart.yAxisAmplitudeVisibleFlag = true;
});

frequencyBtn.addEventListener('click', function() {
    this.classList.add('selected');
    amplitudeBtn.classList.remove('selected');
    g_formantChart.yAxisAmplitudeVisibleFlag = false;
});
