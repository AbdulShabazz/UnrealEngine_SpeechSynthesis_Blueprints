#pragma once

#include <cstdint>
#include <vector>
#include <algorithm>

class Formant {
public:
    // Assuming both amplitude and sample can be represented by an int64_t type
    int64_t amplitude;
    int64_t sample;

    Formant(int64_t amplitude, int64_t sample) : amplitude(amplitude), sample(sample) {}

    // The function build_sample_int64t() would combine amplitude and sample
    // to build a formant sample for the current timestep. The actual implementation
    // will depend on the specific application.
    int64_t build_sample_int64t() const {
        // Placeholder for actual sample building logic.
        return amplitude * sample;
    }

    // Getter for amplitude (could potentially include further logic)
    int64_t get_amplitude_int64t() const {
        return amplitude;
    }

    // Getter for sample (could potentially include further logic)
    int64_t get_sample_int64t() const {
        return sample;
    }
};
