#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

template<typename AudioPhoneResolution = float>
struct OscillatorStep {
	int64_t frame{};
	AudioPhoneResolution amplitude{-6.0f};
	AudioPhoneResolution frequency{400.0f};
};

template<typename AudioPhoneResolution = float>
struct Formant : public std::vector<OscillatorStep<AudioPhoneResolution>> {
	bool isPhaseSensitive{};
	bool amplitude_as_bezierCurve_flag{};
	bool frequency_as_bezierCurve_flag{};
	std::string shape = "Sine"; // "Half-Sine"; // "Quarter-Sine"; // "quasiPeriodicNoise"; // "Cosine"; // "Square"; // "F. Sawtooth"; // "R. Sawtooth"; // "Triangle"; // "Pink Noise"; // "Purple Noise"; // "Brown Noise"; // "Blue Noise";
};
