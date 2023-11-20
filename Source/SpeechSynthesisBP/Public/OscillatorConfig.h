#pragma once

class oscillatorConfig {
public:
    // Configuration details:
    double frequencyHz_Float64 = 0.0f;
    double amplitude_Float64 = 6.0f; // range: 0.0 to 12.5 (Approx. 125 dB SPL Max; 3.0f = whisper (30 dB SPL); 6.0f = avg. speaking volume (60 dB SPL))
    double pitch_Float64 = 0.0f; // range: -12.0 to 12.0
    double phase_Float64 = 0.0f; // range: 0.0 to 1.0
    double dutyCycle_Float64 = 0.0f; // range: 0.0 to 1.0
    double offset_Float64 = 0.0f; // range: -1.0 to 1.0
    double timeStep_Float64 = 0.0f; // range: 0.0 to 1.0
    double timeStepStart_Float64 = 0.0f; 
    double timeStepEnd_Float64 = 0.0f; 
    double timeStepInterval_Float64 = 0.0f; 
    uint8_t sampleWidth_UInt8 = 4; // In bytes. 1 = 8-bit, 2 = 16-bit, 4 = 32-bit
    uint32_t sampleRateHz_UInt32 = 44100; // 44100, 48000, 88200, 96000, 176400, 192000, ...
    uint8_t channelCount_UInt8 = 2; // 1 = mono, 2 = stereo
    bool oscillatorConfigured_boolFlag = false;

    // ADSR Envelope details:
    class ADSR_ENVELOPE {
        public:
            double attack_Float64 = 0.0f; // range: 0.0 to 1.0
            double decay_Float64 = 0.0f; // range: 0.0 to 1.0
            double sustain_Float64 = 0.0f; // range: 0.0 to 1.0
            double release_Float64 = 0.0f; // range: 0.0 to 1.0
            bool ADSR_EnvelopeConfigured_boolFlag = false;
    } ADSR_envelope;
};
