#pragma once

#include <random>
#include <cmath>
#include <memory>
#include <chrono>
#include <concepts>
#include <functional>
#include <vector>
#include <random>
#include <algorithm>

template<typename T = float>
class Oscillator_GaussianNoise {
private:
    std::vector<T> generateWhiteGaussianNoise(const size_t length) {
        std::vector<T> noise(length);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<T> dist(0.0, 1.0);

        std::generate(noise.begin(), noise.end(), [&]() { return dist(gen); });
        return noise;
    }

    std::vector<T> applyBandpassFilter(
	  const std::vector<T>& signal
	, const T sampleRate
	, const T lowFreq
	, const T highFreq) {
        size_t n = signal.size();
        std::vector<T> filteredSignal(n, 0.0);

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                T freq = (j / static_cast<T>(n)) * sampleRate;
                if (freq >= lowFreq && freq <= highFreq) {
                    filteredSignal[i] += signal[j] * std::cos((2.0 * M_PI * i * j) / n);
                }
            }
        }

        return filteredSignal;
    }

public:
    std::vector<T> carveSignal(
	  const std::vector<T>& phone
	, const T sampleRate
	, const T lowFreq
	, const T highFreq) {
        std::vector<T> noise = generateWhiteGaussianNoise(phone.size());
        std::vector<T> filteredNoise = applyBandpassFilter(noise, sampleRate, lowFreq, highFreq);

        std::vector<T> carvedSignal(phone.size());
        for (size_t i = 0; i < phone.size(); ++i) {
            T freq = (i / static_cast<T>(phone.size())) * sampleRate;
            if (freq >= lowFreq && freq <= highFreq) {
                carvedSignal[i] = filteredNoise[i];
            } else {
                carvedSignal[i] = phone[i];
            }
        }

        return carvedSignal;
    }
};

/*
	Example usage:  We map over each sample in the phone array and check if its corresponding frequency falls within the specified frequency range (lowFreq to highFreq). If it does, we replace the sinusoidal sample with the corresponding filtered noise sample. Otherwise, we keep the original sinusoidal sample.
This approach effectively carves the sinusoidal signal out of the filtered white Gaussian noise within the specified frequency range, similar to how diffusion models carve audio out of a Gaussian noise canvas.
Remember to adjust the frequency range (lowFreq and highFreq) based on the desired frequency bands you want to replace with the filtered noise samples. * /

int main() {
    std::vector<double> phone = {...}; // Sinusoidal signal for speech synthesis
    double sampleRate = 44100.0; // Sample rate in Hz
    double lowFreq = 300.0; // Lower frequency limit of the bandpass filter
    double highFreq = 3400.0; // Upper frequency limit of the bandpass filter

    Oscillator_GaussianNoise<double> oscillator;
    std::vector<double> carvedSignal = oscillator.carveSignal(phone, sampleRate, lowFreq, highFreq);

    // Use carvedSignal for further processing or output
    // ...

    return 0;
}
*/

//#include "OscillatorConfig.h"
//#include "OscillatorLocalParams.h"

/**
@brief C++20 concept to check if two types are bitwise operations compatible.
@details C++20 concept to check if two types are bitwise operations compatible.
@tparam T The first type.
@tparam U The second type.*/
template <typename T, typename U>
concept bitwise_ops_compatible = requires(T t, U u) {
    static_cast<uint32_t>(t) & static_cast<uint32_t>(u);
    static_cast<uint32_t>(t) | static_cast<uint32_t>(u);
};

/**
@brief The Oscillator class is used to generate various waveforms.
@details The Oscillator class is used to generate various waveforms. The waveforms are generated using the following formulas:

Waveform Generation:

Sine Wave:
    Formula: A * sin(2 * PI * f * t + theta)

    Where:
        A is amplitude.
        f is frequency.
        t is time.
        theta is phase.

Forward Sawtooth Wave:
    Formula: A * (2 * (t * f - floor(0.5 + t * f)))

Reverse Sawtooth Wave:
    Formula: A * (1 - 2 * (t * f - floor(t * f)))

Triangle Wave:
    Formula: A * (2 * abs(2 * (t * f - floor(0.5 + t * f))) - 1)

Square Wave:
    Formula: A * sign(sin(2 * PI * f * t))

Quarter- and Half-Period signals:
    Modify t (time) in your formulas to accommodate quarter-period or half-period generation.
    For a quarter-period, use t mod (1 / (4 * f)), and for a half-period, use t mod (1 / (2 * f)).

Parameter Specification:
    Amplitude (A) is specified in the range 0.0 to 1.0.
    Frequency (f) is specified in Hertz (Hz).
    Phase (theta) is specified in the range 0.0 to 1.0.
    Time (t) is specified in seconds (s).

Output:
    Waveform signal.

Example usage:

int main() {
    Oscillator osc(1.0, 440.0, 0.0); // Example: Amplitude = 1.0, Frequency = 440 Hz, Phase = 0
    // Generate and output waveforms...
    return 0;
}*/
template<typename AudioPhoneResolution = float>
class Oscillator {
private:    
    enum class BLEND_STRATEGY {
        LERP, CUBIC, QUARTIC
    };
    
    // playback params //
    struct oscillatorConfig {
        int64_t TIME;
        int64_t deltaTime;
        AudioPhoneResolution sampleRate;
        BLEND_STRATEGY amplitudeBlendStrategy = BLEND_STRATEGY::LERP;
        BLEND_STRATEGY frequencyBlendStrategy = BLEND_STRATEGY::LERP;
        AudioPhoneResolution phase;
        AudioPhoneResolution cumulativePhase;
        int64_t time;
        AudioPhoneResolution amplitude = -6.0f;;
        AudioPhoneResolution amplitudeStart = -6.0f;
        AudioPhoneResolution amplitudeEnd = -6.0f;
        int64_t amplitudeBlendStartFrame;
        int64_t amplitudeBlendEndFrame;
        AudioPhoneResolution frequencyStart = 400.0f;
        AudioPhoneResolution frequencyEnd = 400.0f;
        int64_t frequencyBlendStartFrame;
        int64_t frequencyBlendEndFrame;
        bool isPhaseSensitive;
        
        AudioPhoneResolution shape_func(const oscillatorConfig& config) { return config.amplitude; }
    };

public:
    Oscillator() : RAND_MAX(0x7fff) {}

    /**
     * @brief Generates a Sine wave.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double (The oscillator signal at time-step t).
     */
    AudioPhoneResolution SIN(const oscillatorConfig& params) {
        const AudioPhoneResolution amplitude = params.amplitude;
        const AudioPhoneResolution frequencyHz = params.frequency;
        const AudioPhoneResolution timeStep = params.time;
        const AudioPhoneResolution theta = params.phase;

        // Generate the signal with interpolated parameters
        const AudioPhoneResolution result = amplitude * std::sin(2 * M_PI * frequencyHz / params.TIME * timeStep + theta);

        return result;
    }

    /**
     * @brief Generates a Sine wave.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double (The oscillator signal at time-step t).
     */
    AudioPhoneResolution sine(const oscillatorConfig& params) {
        const AudioPhoneResolution amplitude = params.amplitude;
        const AudioPhoneResolution frequencyHz = params.frequency;
        const AudioPhoneResolution timeStep = params.time;
        const AudioPhoneResolution theta = params.phase;

        const AudioPhoneResolution result = amplitude * std::sin(2 * M_PI * frequencyHz / params.TIME * timeStep + theta);

        return result;
    }

    /**
     * @brief Generates a Quarter-Sine wave.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double (The oscillator signal at time-step t).
     */
    AudioPhoneResolution quarterSine(const oscillatorConfig& params) {
        const AudioPhoneResolution amplitude = params.amplitude;
        const AudioPhoneResolution frequencyHz = params.frequency;
        const AudioPhoneResolution timeStep = params.time;
        const AudioPhoneResolution theta = params.phase;

        const AudioPhoneResolution quarterPeriod = 1 / (4 * frequencyHz);

        const AudioPhoneResolution result = amplitude * std::sin(
            2 * M_PI * std::fmod(
                std::abs(frequencyHz / params.TIME * timeStep),
                quarterPeriod)
            + theta);

        return result;
    }

    /**
     * @brief Generates a Half-Sine wave.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double (The oscillator signal at time-step, t).
     */
    AudioPhoneResolution halfSine(const oscillatorConfig& params) {
        const AudioPhoneResolution amplitude = params.amplitude;
        const AudioPhoneResolution frequencyHz = params.frequency;
        const AudioPhoneResolution timeStep = params.time;
        const AudioPhoneResolution theta = params.phase;

        const AudioPhoneResolution halfPeriod = 1 / (2 * frequencyHz);

        const AudioPhoneResolution result = amplitude * std::sin(
            2 * M_PI * std::fmod(
                std::abs(frequencyHz / params.TIME * timeStep),
                halfPeriod)
            + theta);

        return result;
    }

    /**
     * @brief Generates a sawtooth signal.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @param indirection: The indirection of the sawtooth wave ('forwards' or 'backwards').
     * @return double (The value of the sawtooth wave at the current time).
     */
    AudioPhoneResolution sawtooth(const oscillatorConfig& params, const std::string& indirection = "forwards") {
        const AudioPhoneResolution t = params.time;
        const AudioPhoneResolution min = params.amplitudeStart;
        const AudioPhoneResolution max = params.amplitudeEnd;
        const AudioPhoneResolution period = 1 / params.frequency;

        const AudioPhoneResolution normalizedTime = std::fmod(t, period) / period;

        const AudioPhoneResolution value = (indirection == "forwards")
            ? min + (max - min) * normalizedTime
            : max - (max - min) * normalizedTime;

        return value;
    }

    /**
     * @brief Generates a triangle wave signal.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double (The value of the triangle wave at the current time).
     */
    AudioPhoneResolution triangle(const oscillatorConfig& params) {
        const AudioPhoneResolution t = params.time;
        const AudioPhoneResolution min = params.amplitudeStart;
        const AudioPhoneResolution max = params.amplitudeEnd;
        const AudioPhoneResolution period = 1 / params.frequency;

        const AudioPhoneResolution normalizedTime = std::fmod(t, period) / period;

        const AudioPhoneResolution slope = (max - min) * 4 / period;

        AudioPhoneResolution value{};

        if (normalizedTime < 0.5) {
            value = max - slope * std::fmod(t, period / 2);
        } else {
            value = min + slope * std::fmod(t, period / 2);
        }

        return value;
    }

    /**
     * @brief Generates a square wave signal.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double (The value of the square wave at the current time).
     */
    AudioPhoneResolution square(const oscillatorConfig& params) {
        const AudioPhoneResolution t = params.time;
        const AudioPhoneResolution min = params.amplitudeStart;
        const AudioPhoneResolution max = params.amplitudeEnd;
        const AudioPhoneResolution period = 1 / params.frequency;

        const AudioPhoneResolution normalizedTime = std::fmod(t, period) / period;

        const AudioPhoneResolution value = (normalizedTime >= 0.5) ? max : min;

        return value;
    }

    /**
     * @brief Generates white Gaussian noise.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double (A random number following a Gaussian distribution).
     */
    AudioPhoneResolution whiteGaussianNoise(const oscillatorConfig& params) {
        const AudioPhoneResolution amplitude = params.amplitude;

        constexpr AudioPhoneResolution epsilon = 0.0001;

        AudioPhoneResolution u = rand() / static_cast<double>(RAND_MAX);
        AudioPhoneResolution v = rand() / static_cast<double>(RAND_MAX);

        u = (u == 0) ? epsilon : u;
        v = (v == 0) ? epsilon : v;

        const AudioPhoneResolution z = std::sqrt(-2.0 * std::log(u)) * std::cos(2.0 * M_PI * v);

        return z * amplitude;
    }

    /**
     * @brief Generates the next value of quasi periodic (pink) noise signal.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double (The next value in the generated noise signal).
     */
    AudioPhoneResolution quasiPeriodicNoise(const oscillatorConfig& params) {
        static AudioPhoneResolution quasiPeriodicTime = 0;
        static AudioPhoneResolution prevNoiseValue = 0;
        static AudioPhoneResolution nextPeriodChangeTime = 0;
        static AudioPhoneResolution currentPeriod = basePeriod * (1 + periodVariation * (2 * rand() / RAND_MAX - 1));

        const AudioPhoneResolution sampleRate = params.sampleRate;

        if (quasiPeriodicTime >= nextPeriodChangeTime) {
            currentPeriod = basePeriod * (1 + periodVariation * (2 * rand() / RAND_MAX - 1));
            nextPeriodChangeTime += currentPeriod;
        }

        AudioPhoneResolution output{};
        if (std::fmod(quasiPeriodicTime, currentPeriod) < pulseWidth * currentPeriod) {
            AudioPhoneResolution noiseValue = 2 * rand() / RAND_MAX - 1;
            noiseValue = (noiseValue + prevNoiseValue) * 0.5;
            prevNoiseValue = noiseValue;
            output = noiseValue;
        } else {
            output = 0;
        }

        quasiPeriodicTime += 1 / sampleRate;

        return output;
    }

    /**
     * @brief Generate a brownian noise signal.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double
     */
    AudioPhoneResolution brownNoise(const oscillatorConfig& params) {
        static AudioPhoneResolution brownNoiseValue = 0;
        static AudioPhoneResolution lastBrownNoiseValue = 0;
        static AudioPhoneResolution brownNoiseIncrement = 0;
        static AudioPhoneResolution brownNoiseDecay = 0;

        const AudioPhoneResolution amplitude = params.amplitude;
        const AudioPhoneResolution frequencyHz = params.frequency;

        if (brownNoiseIncrement == 0.0) {
            brownNoiseIncrement = 1.0 / (frequencyHz * 0.1);
            brownNoiseDecay = std::exp(-1.0 / (frequencyHz * 0.1));
        }

        brownNoiseValue = (brownNoiseValue + brownNoiseIncrement * (2.0 * (rand() / RAND_MAX) - 1.0)) * brownNoiseDecay;

        const AudioPhoneResolution result = amplitude * (brownNoiseValue - lastBrownNoiseValue);

        return result;
    }

    /**
     * @brief Generates pink noise.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double (The generated pink noise value).
     */
    AudioPhoneResolution pinkNoise(const oscillatorConfig& params) {
        static AudioPhoneResolution pinkNoiseValue = 0;
        static AudioPhoneResolution lastPinkNoiseValue = 0;
        static AudioPhoneResolution pinkNoiseIncrement = 0;
        static AudioPhoneResolution pinkNoiseDecay = 0;

        const AudioPhoneResolution amplitude = params.amplitude;
        const AudioPhoneResolution frequencyHz = params.frequency;

        if (pinkNoiseIncrement == 0) {
            pinkNoiseIncrement = 1.0 / (frequencyHz * 0.1);
            pinkNoiseDecay = std::exp(-1.0 / (frequencyHz * 0.1));
        }

        const AudioPhoneResolution randomFactor = 2.0 * rand() / RAND_MAX - 1.0;

        pinkNoiseValue = (pinkNoiseValue + pinkNoiseIncrement * randomFactor) * pinkNoiseDecay;

        const AudioPhoneResolution retPinkNoiseValue = amplitude * (pinkNoiseValue - lastPinkNoiseValue);

        lastPinkNoiseValue = pinkNoiseValue;

        return retPinkNoiseValue;
    }

    /**
     * @brief Generate a blue noise signal.
     * @param params: The oscillatorConfig object containing the necessary parameters.
     * @return double
     */
    AudioPhoneResolution blueNoise(const oscillatorConfig& params) {
        static AudioPhoneResolution blueNoiseValue = 0;
        static AudioPhoneResolution lastBlueNoiseValue = 0;
        static AudioPhoneResolution blueNoiseIncrement = 0;
        static AudioPhoneResolution blueNoiseDecay = 0;

        const AudioPhoneResolution amplitude = params.amplitude;
        const AudioPhoneResolution frequencyHz = params.frequency;
        const AudioPhoneResolution timeStep = params.time;

        if (blueNoiseIncrement == 0.0) {
            blueNoiseIncrement = 1.0 / (frequencyHz * 0.1);
            blueNoiseDecay = std::exp(-1.0 / (frequencyHz * 0.1));
        }

        blueNoiseValue = (blueNoiseValue + blueNoiseIncrement * (2.0 * (rand() / RAND_MAX) - 1.0)) * blueNoiseDecay;

        const AudioPhoneResolution result = amplitude * (blueNoiseValue - lastBlueNoiseValue);

        return result;
    }

    /**
     * @brief Generate a purple (violet) noise signal.
     * @return double
     */
    AudioPhoneResolution purpleVioletNoise() {
        static AudioPhoneResolution lastWhite = 0;

        const AudioPhoneResolution newWhite = (rand() / static_cast<double>(RAND_MAX) * 2 - 1);

        const AudioPhoneResolution violet = newWhite - lastWhite;

        lastWhite = newWhite;

        return violet;
    }
    
public:

	//const float PI_LoRes = 3.14159265358979323;
	//const long double PI_HiRes = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196;

private:
    const int RAND_MAX;
    static inline constexpr AudioPhoneResolution basePeriod = 0.01;
    static inline constexpr AudioPhoneResolution periodVariation = 0.1;
    static inline constexpr AudioPhoneResolution pulseWidth = 0.2;
};
