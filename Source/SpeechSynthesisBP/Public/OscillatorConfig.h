#pragma once

class oscillatorConfig {
public:
    // Configuration details
    float frequencyHz_Float32 = 0.0f;
    float amplitude_Float32 = 0.0f; // range: 0.0 to 12.5 (ie. 125 dB SPL)
    float pitch_Float32 = 0.0f; 
    float phase_Float32 = 0.0f;
    float dutyCycle_Float32 = 0.0f;
    float offset_Float32 = 0.0f;
    float sampleRate_Float32 = 0.0f;    
};
