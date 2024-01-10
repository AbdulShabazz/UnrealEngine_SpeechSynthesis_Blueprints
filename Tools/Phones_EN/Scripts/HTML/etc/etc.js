
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

        /*
        showConfirmBox({ message: "Would you like to re-sample the audio?" })
        .then(res => {
            res;

            // TODO: Re-sample the audio (scale the frame property of each OSC_INTERVAL object by the new overall length)

            const nextOSCINterval_frame = lastOSCInterval.frame + dx;
            const nextOSCInterval_time_step = lastOSCInterval.time_step;
            formant.push(new OSC_INTERVAL({ amplitude: lastOSCInterval.amplitude
                , frequency: lastOSCInterval.frequency
                , frame: nextOSCINterval_frame
                , time_step: nextOSCInterval_time_step }) );
            updateChart(formant);
        })
        .catch(err => {
            err;
            const nextOSCINterval_frame = lastOSCInterval.frame + dx;
            const nextOSCInterval_time_step = lastOSCInterval.time_step;
            formant.push(new OSC_INTERVAL({ amplitude: lastOSCInterval.amplitude
                , frequency: lastOSCInterval.frequency
                , frame: nextOSCINterval_frame
                , time_step: nextOSCInterval_time_step }) );
            updateChart(formant);
        });
        */

        /*
        showConfirmBox({ message: "Would you like to re-sample the audio?" })
        .then(res => {
            res;
            // TODO: Reverse iterate through the OSC_INTERVAL objects and their frames, until the frame deltas all sum to == dx;
            //  copy the rmaining OSC_INTERVAL objects, and then replace the original objects with the new one.
            // TODO: Re-sample the audio (scale the frame property of each OSC_INTERVAL object by the new overall length)
            
            const nextOSCINterval_frame = lastOSCInterval.frame - dx;
            const nextOSCInterval_time_step = lastOSCInterval.time_step;
            formant.push(new OSC_INTERVAL({ amplitude: lastOSCInterval.amplitude
                , frequency: lastOSCInterval.frequency
                , frame: nextOSCINterval_frame
                , time_step: nextOSCInterval_time_step }) );
            updateChart(formant);
        })
        .catch(err => {
            err;
            
            const nextOSCINterval_frame = lastOSCInterval.frame - dx;
            const nextOSCInterval_time_step = lastOSCInterval.time_step;
            formant.push(new OSC_INTERVAL({ amplitude: lastOSCInterval.amplitude
                , frequency: lastOSCInterval.frequency
                , frame: nextOSCINterval_frame
                , time_step: nextOSCInterval_time_step }) );
            updateChart(formant);
            
        });
        */

if (chart.yAxisAmplitudeVisibleFlag){
    ctx.fillText(`${yValue.toFixed(2)} dBFS`, 19, y);
    // Draw a point at the amplitude intersection
    const amplitudeXPixel = chart.scales['x-axis-frame'].getPixelForValue(xValue);
    const amplitudeYPixel = chart.scales['y-axis-amplitude'].getPixelForValue(yValue);
    ctx.beginPath();
    ctx.arc(x, y, 5, 0, 2 * Math.PI); // Draw a 5px radius point
    ctx.fillStyle = 'rgba(0,0,255,0.7)';
    ctx.fill();
} else {
    ctx.fillText(`${yValue.toFixed(2)} Hz`, rightX + 10, y);
    // Draw a point at the frequency intersection
    const amplitudeXPixel = chart.scales['x-axis-frame'].getPixelForValue(xValue);
    const amplitudeYPixel = chart.scales['y-axis-frequency'].getPixelForValue(yValue);
    ctx.beginPath();
    ctx.arc(x, y, 5, 0, 2 * Math.PI); // Draw a 5px radius point
    ctx.fillStyle = 'rgba(0,255,0,0.7)';
    ctx.fill();
}

            // Text alignment and position adjustments as needed
            ctx.fillText(`Frame #${xValue.toFixed(0)}`, x - 50, 64); // top-most x-axis
            ctx.fillText(`Frame #${xValue.toFixed(0)}`, x - 50, bottomY + 18); // bottom-most x-axis

const yAxisAmplitude = chart.scales['y-axis-amplitude'];
const yAxisAmplitudeVisibleFlag = (yAxisAmplitude && yAxisAmplitude.options.display);

            //const leftXDupl = chart.scales['x-axis-frame-dupl'].left;
            //const rightXDupl = chart.scales['x-axis-frame-dupl'].right;
            //const xValueDupl = chart.scales['x-axis-frame-dupl'].getValueForPixel(x);

function updateCrossHair(e) {
    let rect = document.getElementById('formant-graph').getBoundingClientRect();
    let mouseX = e.clientX - rect.left;
    let mouseY = e.clientY - rect.top;
    /*
    // cache the previous mouse coordinates
    if (g_formantChart.crosshair) {
        g_formantChart.old_crosshair.x = g_formantChart.crosshair.x;
        g_formantChart.old_crosshair.y = g_formantChart.crosshair.y;
    }
    */
    // Store the mouse position in a variable accessible by the Chart.js plugin
    g_formantChart.crosshair = { x: mouseX, y: mouseY };

    //g_formantChart.update();

    //crossHairPlugin.afterDatasetsDraw(g_formantChart);

    g_formantChart.update();

    //requestAnimationFrame(updateCrossHair);
}

const crossHairPlugin = {
    id: "crossHairPlugin",
    afterDatasetsDraw: function(chart, args, opts) {
        if (chart.crosshair) {
        //if (chart.tooltip._active && chart.tooltip._active.length) {
            let ctx = chart.ctx;
            let x = chart.crosshair.x; //chart.tooltip._active[0].element.x;
            let y = chart.crosshair.y; //chart.tooltip._active[0].element.y;
            const topY = chart.scales['y-axis-amplitude'].top;
            const bottomY = chart.scales['y-axis-amplitude'].bottom;
            const leftX = chart.scales['x-axis-frame'].top;
            const rightX = chart.scales['x-axis-frame'].bottom;

            ctx.save();
            ctx.beginPath();

            // Draw new vertical line
            ctx.moveTo(x, topY);
            ctx.lineTo(x, bottomY);
            ctx.lineWidth = 1;
            ctx.strokeStyle = 'rgba(140,140,140,0.5)';
            ctx.stroke();

            ctx.restore();

            chart.old_crosshair = chart.crosshair;
            chart.old_crosshair.topY = topY;
            chart.old_crosshair.bottomY = bottomY;
        }
    },
};

const crossHairPlugin = {
    id: "crossHairPlugin",
    afterDatasetsDraw: function(chart, args, opts) {
        if (chart.tooltip._active && chart.tooltip._active.length) {
            let ctx = chart.ctx;
            let x = chart.tooltip._active[0].element.x;
            let y = chart.tooltip._active[0].element.y;
            const topY = chart.scales['y-axis-amplitude'].top;
            const bottomY = chart.scales['y-axis-amplitude'].bottom;
            const leftX = chart.scales['x-axis-frame'].top;
            const rightX = chart.scales['x-axis-frame'].bottom;

            ctx.save();
            ctx.beginPath();

            // Draw vertical line
            ctx.moveTo(x, topY);
            ctx.lineTo(x, bottomY);
            ctx.lineWidth = 1;
            ctx.strokeStyle = 'rgba(140,140,140,0.5)';
            ctx.stroke();

            // Draw horizontal line
            ctx.moveTo(x, leftX);
            ctx.lineTo(x, rightX);
            ctx.lineWidth = 1;
            ctx.strokeStyle = 'rgba(140,140,140,0.5)';
            ctx.stroke();

            ctx.restore();
        }
    },
};

// Extracting time_steps, amplitudes, and frequencies
const g_time_steps = Formants[0].map(osc_interval => osc_interval.time_step);
const g_amplitudes = Formants[0].map(osc_interval => osc_interval.amplitude);
const g_frequencies = Formants[0].map(osc_interval => osc_interval.frequency);
const g_frames = Formants[0].map(osc_interval => osc_interval.frame);

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

// reafactor pcm_encoding_docstring_options to include resolution and sample_rate
for (const [key, value] of Object.entries(pcm_encoding_docstring_options)) {
    if (typeof value === 'string') {
        // Extract resolution and sample rate from the string
        const [resolution, sampleRate] = value.match(/\d+.?\d*/)[0].split(/\//);
        const pcmString = `PCM ${resolution}/${sampleRate}`;

        // Update the dictionary entry
        pcm_encoding_docstring_options[key] = {
            pcm_string: pcmString,
            resolution: resolution,
            sample_rate: sampleRate
        };
    }
}

confirmYes.addEventListener("click", function() {
    showHideConfirmBox();
});

confirmNo.addEventListener("click", function() {
    showHideConfirmBox();
});

addFramesBTN.addEventListener('click', function() {
    var formant = Formants[g_lastSelectedFormantIndex];
    const I = audioFrame_sizes[a_frames_selector.selectedIndex];
    const lastOSCInterval = formant[formant.length - 1];
    const lastFrame = lastOSCInterval.frame;
    const lastTimestep = lastOSCInterval.time_step;
    for (var i = 0; i < I; i++) {
        formant.push( new OSC_INTERVAL ({ amplitude: -6.0
            , frequency: 50.0
            , frame: lastFrame + i + 1
            , time_step: lastTimestep }) );
    }
});

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

settings_button.addEventListener("click", function() {
    settingsBox.style.display = "block";
});

g_config = {
    type: 'line',
    data: {
        /*labels: g_frames,*/
        datasets: [{
            label: 'Amplitude (dB)',
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
            xAxisID: 'x-axis-frame',
        }]
    },
    options: {
        scales: {
            'y-axis-amplitude': {
                type: 'linear',
                title: { 
                    text: 'dB',
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
                          return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]) + ' dB';
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
                    text: 'Audio ( Frame ) ',
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
                            yLabel = `Amplitude: ${yLabel} dB`;
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

tooltip: {
    // Enable custom tooltips
    enabled: true,
    mode: 'index',
    position: 'nearest',
    bodyFontSize: 12, // Tooltip font size
    callbacks: {
        title: function(tooltips, data) {
            // Assuming the first dataset is for amplitude and has complete frame and time_step data
            /*
            tooltips.map(tt => {
                return tt;
            });*/
            const tt = tooltips[0];
            const tt2 = tooltips[1];
            const tmpTimeStep = tt.label;
            const tmpFrame = tt2.label;
            /*
            const tmpAmplitude = tt.formattedValue;
            const tmpfrequency = tt2.formattedValue;
            */
            return `Frame: ${tmpFrame}\nTimestep: ${tmpTimeStep} ms`;
        },
        label: function(tooltipItem, data) {
            // tooltipItem is an object containing properties of the tooltip
            // data is an object containing all data passed to the chart
            let yLabel = tooltipItem.formattedValue;
            if (tooltipItem.dataset.label == 'Amplitude (dB)') {
                yLabel = 'Amplitude: ' + yLabel + ' dB';
            } else if (tooltipItem.dataset.label == 'Frequency (Hz)') {
                yLabel = 'Frequency: ' + yLabel + ' Hz';
            }
            return yLabel;
        }
    }
},

'x-axis-frame': {
    type: 'linear',
    title: { 
        text: 'Audio ( Frame ) ',
        display: true,
    },
    display: true,
    position: 'bottom',
    grid: {
        drawOnChartArea: false
    },
    ticks: {
        min: 0, // Set the minimum value
        max: 2050, // Set the maximum value (adjust according to your data)
        stepSize: 292, // Set the stepSize
        // Include a dollar sign in the ticks
        callback: function(value, index, ticks) {
            // call the default formatter, forwarding `this`
            return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]);
        }
    }
},
'x-axis-timestep': {
    type: 'linear',
    title: { 
        text: 'Timestep ( milliseconds ) ',
        display: true,
    },
    display: true,
    position: 'top',
    grid: {
        drawOnChartArea: false
    },
    ticks: {
        min: 0, // Set the minimum value
        max: 105, // Set the maximum value (adjust according to your data)
        stepSize: 15, // Set the stepSize
        // Include a dollar sign in the ticks
        callback: function(value, index, ticks) {
            // call the default formatter, forwarding `this`
            return Chart.Ticks.formatters.numeric.apply(this, [value, index, ticks]);
        }
    }
},

'x-axis-frames': {
    type: 'linear',
    title: { 
        text: 'Audio ( Frame ) ',
        display: true,
    },
    display: true,
    position: 'bottom',
    scaleLabel:{
        display: true,
        labelString: 'Audio ( Frame )'
    },
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
'x-axis-timestep': {
    type: 'linear',
    title: { 
        text: 'Timestep ( milliseconds ) ',
        display: true,
    },
    display: true,
    position: 'top',
    scaleLabel:{
        display: true,
        labelString: 'Audio ( Frame )'
    },
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

Q:Is there any way to simplify this .js pseudo-code call stack,
```
after selecting an option in formant_selector
    const formant_selector.selectedIndex << the current option's value is cached to 
    an onchange handler is then called
        const current_formant_count = this.options.length;
        const selectedOptionClassList = formant_selector.options[formant_selector.selectedIndex].classList;
        const selectedIndex = formant_selector.selectedIndex;
        if selectedOptionClassList.contains('insert_formant_class')
            insertNewFormant(g_lastSelectedFormantIndex);
                const formant = Formant[g_lastSelectedFormantIndex];
                var tmpFormant = new FORMANTS({ motif: formant.motif });
                formant.map(osc_interval => { 
                    tmpFormant.push(new OSC_INTERVAL({ amplitude: osc_interval.amplitude
                        , frequency: osc_interval.frequency
                        , frame: osc_interval.frame
                        , time_step: osc_interval.time_step }) );
                    return osc_interval;
                });
                g_lastSelectedFormantIndex = Formant.push(tmpFormant) - 1;
                updateFormantSelectElement(i);
                updateMotifBar(tmpFormant.motif);
                updateChart(tmpFormant);
                    config.data.labels = formant.map(osc_interval => osc_interval.frame);
                    config.data.datasets[0].data = formant.map(osc_interval => osc_interval.amplitude);
                    config.data.datasets[1].data = formant.map(osc_interval => osc_interval.frequency);
                    g_formantChart = new Chart(ctx, config);
        else if selectedOptionClassList.contains('remove_current_formant_class') && current_formant_count > minimum_allowed_select_element_count
            removeFormantAt(g_lastSelectedFormantIndex);
                Formants.splice(i-1, 1);
                g_lastSelectedFormantIndex = i = (i - 1 > -1) ? --i : 0;
                updateFormantSelectElement(i);
                const formant = Formants[i];
                updateMotifBar(formant.motif);
                updateChart(formant);
                    config.data.labels = formant.map(osc_interval => osc_interval.frame);
                    config.data.datasets[0].data = formant.map(osc_interval => osc_interval.amplitude);
                    config.data.datasets[1].data = formant.map(osc_interval => osc_interval.frequency);
                    g_formantChart = new Chart(ctx, config);
        else
            g_lastSelectedFormantIndex = selectedIndex;
            const formant = Formant[g_lastSelectedFormantIndex];
            updateChart(formant);
                config.data.labels = formant.map(osc_interval => osc_interval.frame);
                config.data.datasets[0].data = formant.map(osc_interval => osc_interval.amplitude);
                config.data.datasets[1].data = formant.map(osc_interval => osc_interval.frequency);
                g_formantChart = new Chart(ctx, config);
``` ?


    /*
    let formantSelectElement = document.getElementById('formant-select');
    let formantSelectElementOptions = formantSelectElement.options;
    let formantSelectElementOptionsLength = formantSelectElementOptions.length;
    let formantSelectElementOptionsLastIndex = formantSelectElementOptionsLength - 1;
    let lastOption = formantSelectElementOptions[formantSelectElementOptionsLastIndex];
    let lastOptionText = lastOption.text;
    let lastOptionValue = lastOption.value;
    let lastOptionClass = lastOption.classList;

    if (lastOptionText == 'Insert Formant') {
        formantSelectElement.remove(formantSelectElementOptionsLastIndex);
    } else {
        formantSelectElementOptions[formantSelectElementOptionsLastIndex].text = 'Insert Formant';
        formantSelectElementOptions[formantSelectElementOptionsLastIndex].value = 'insert_formant';
        formantSelectElementOptions[formantSelectElementOptionsLastIndex].classList.add('insert_formant_class');
    }
    */
   
// out
okBTN.addEventListener('click', function(e) {
    e.preventDefault();
    let json = JSON.stringify(2, ' ', g_formantChart.data)
    JsonTA.value = json;
    OutJsonBTN.click();
});

cancelBTN.addEventListener('click', function(e) {
    OutJsonBTN.click();
});

plugins: {/*
    title: {
        display: true,
        text: 'F0 Formant Editor',
        fontSize: 20 // Title font size
    },
    subtitle: {
        display: true,
        text: 'Custom Formant Editor'
    },*/
    legend: {
        labels: {
            fontSize: 14 // Legend font size
        }
    },
}

const rotateYAxisTitle_Plugin = {
  beforeDraw: (chart) => {
      const ctx = chart.ctx;
      const yAxis = chart.scales['y-axis-amplitude']; // Adjust for your specific y-axis ID
      const text = "Amplitude (dB)"; // Your y-axis title here
      const x = yAxis.left / 2; // X position
      const y = (chart.height + chart.chartArea.top) / 2; // Y position
      const rotation = -90 * Math.PI / 180; // Rotation angle in radians (-90 degrees)
  
      ctx.save();
      ctx.translate(x, y);
      ctx.rotate(rotation);
      ctx.textAlign = "center";
      ctx.fillText(text, 0, 0);
      ctx.restore();
  }
};

const rotateYAxisTitle_Plugin = {
    beforeDraw: (chart) => {
        const ctx = chart.ctx;
        const yAxis = chart.scales['y-axis-amplitude']; // Adjust for your specific y-axis ID
        const text = "Amplitude (dB)"; // Your y-axis title here
        const x = yAxis.left / 2; // X position
        const y = (chart.height + chart.chartArea.top) / 2; // Y position
        const rotation = -90 * Math.PI / 180; // Rotation angle in radians (-90 degrees)
    
        ctx.save();
        ctx.translate(x, y);
        ctx.rotate(rotation);
        ctx.textAlign = "center";
        ctx.fillText(text, 0, 0);
        ctx.restore();
    }
};

// rotateYAxisTitle_Plugin
callbacks:{
    afterDraw: (chart) => {
        const ctx = chart.ctx;
        //const yAxis = chart.scales['y-axis-amplitude']; // Adjust for your specific y-axis ID
        //const text = "Your Y-Axis Title"; // Your y-axis title here
        //const x = yAxis.left / 2; // X position
        //const y = (chart.height + chart.chartArea.top) / 2; // Y position
        const rotation = -90 * Math.PI / 180; // Rotation angle in radians (-90 degrees)
    
        ctx.save();
        //ctx.translate(x, y);
        ctx.rotate(rotation);
        //ctx.textAlign = "center";
        //ctx.fillText(text, 0, 0);
        ctx.restore();
        //ctx.update();
    }},

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
