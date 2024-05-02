#pragma once

#include <functional>

enum class BLEND_STRATEGY {
	LERP, CUBIC, QUARTIC
};

// params //
template<typename AudioPhoneResolution = float>
struct oscillatorConfig {

	// time //
	int64_t time {}; // start
	int64_t TIME {}; // end
	int64_t deltaTime {1}; // step
	AudioPhoneResolution sampleRate {192.0f};

	// amplitude //
	AudioPhoneResolution amplitude = -6.0f;;
	AudioPhoneResolution amplitudeStart = -6.0f;
	AudioPhoneResolution amplitudeEnd = -6.0f;
	int64_t amplitudeBlendStartFrame {};
	int64_t amplitudeBlendEndFrame {};
	BLEND_STRATEGY amplitudeBlendStrategy = BLEND_STRATEGY::LERP;

	// frequency //
	AudioPhoneResolution frequency = 400.0f;
	AudioPhoneResolution frequencyStart = 400.0f;
	AudioPhoneResolution frequencyEnd = 400.0f;
	int64_t frequencyBlendStartFrame {};
	int64_t frequencyBlendEndFrame {};
	BLEND_STRATEGY frequencyBlendStrategy = BLEND_STRATEGY::LERP;

	// phase //
	AudioPhoneResolution phase {};
	AudioPhoneResolution cumulativePhase {};
	bool isPhaseSensitive {};

	// shape //
	AudioPhoneResolution shape_func(const oscillatorConfig<AudioPhoneResolution>& config) { return config.amplitude; }
};
