#pragma once

class oscillatorConfig {
public:
    // Configuration details
    float frequencyHz_Float32 = 0.0f;
    float amplitude_Float32 = 6.0f; // range: 0.0 to 12.5 (Approx. 125 dB SPL Max; 3.0f = whisper (30 dB SPL); 6.0f = avg. speaking volume (60 dB SPL))
    float pitch_Float32 = 0.0f; // range: -12.0 to 12.0
    float phase_Float32 = 0.0f; // range: 0.0 to 1.0
    float dutyCycle_Float32 = 0.0f; // range: 0.0 to 1.0
    float offset_Float32 = 0.0f; // range: -1.0 to 1.0
    uint8_t sampleWidth_UInt8 = 4; // In bytes. 1 = 8-bit, 2 = 16-bit, 4 = 32-bit
    uint32_t sampleRateHz_UInt32 = 44100; // 44100, 48000, 88200, 96000, 176400, 192000, ...
    uint8_t channelCount_UInt8 = 2; // 1 = mono, 2 = stereo
};
