

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
