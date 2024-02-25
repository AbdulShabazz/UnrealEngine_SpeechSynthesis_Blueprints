pragma once

#include <vector>
#include <unordered_map>
#include <cmath>

namespace audio {
    class AudioFile {
        // Implementation details of AudioFile
    };
}

class FormantLibrary {
    // Implementation details of FormantLibrary
public:
    int64_t _16bit_44100Hz_1channel_nextClosestAmplitude(int64_t amplitude) {
        // Implementation to find the next closest amplitude
    }

    int64_t _16bit_44100Hz_1channel(int64_t amplitude) {
        // Implementation to get frequency from amplitude
    }

    std::vector<int64_t> _16bit_44100Hz_1channel_compositeAmplitudesOf(int64_t amplitude) {
        // Implementation to get all possible composite amplitudes
    }
};

class Oscillator {
public:
    enum class WaveShape : int64_t { Sine
    , Square
    , Triangle
    , Sawtooth
    , InverseSawtooth
    , WhiteNoise
    , PinkNoise
    , BrownNoise
    , BlueNoise
    , GreyNoise
    , YellowNoise };
    WaveShape waveShape_enum;
    int64_t amplitude_int64t {};
    int64_t frequency_int64t {};
    int64_t phase_int64t {};

    explicit Oscillator(int64_t amplitude
    , int64_t frequency
    , int64_t phase
    , WaveShape waveShape = WaveShape::Sine)
        : amplitude_int64t(amplitude)
        , frequency_int64t(frequency)
        , phase_int64t(phase)
        , waveShape_enum(waveShape) {}
};

class WaveForm {
public:
    int64_t frequency_int64t {};
};

class Formant {
public:
    int64_t frequency_int64t {};

};

void processAudioFile(const audio::AudioFile& audioFile) {

    FormantLibrary formantLibrary;

    std::vector<std::vector<Oscillator>> waveShape_Oscillator2DVec{};
    std::unordered_map<int64_t, int64_t> frequencyTable_unorderedMap{};

    int64_t lastAmplitude_int64t {};
    int64_t currentAmplitude_int64t {};
    int64_t compositeAmplitude_int64t{};
    std::vector<int64_t> compositeAmplitude_int64tVec {};
    std::vector<int64_t> lastCompositeAmplitude_int64tVec {};
    int64_t currentFreq {};
    int64_t t_int64t {};

    // Iterate over audio frames
    for (const int64_t& frame : audioFile) {

        // Get current frame amplitude
        currentAmplitude_int64t = frame;

        if (t_int64t > 0) {

            int64_t& ds_Int64t = currentAmplitude_int64t - 2 * lastAmplitude_int64t; // ds should usually double per frame

            //const bool dsIncreasing_flag = ds_Int64t > 0 ? true : false;
            const bool dsFlat_flag = ds_Int64t == 0 ? true : false;
            //const bool dsDecreasing_flag = ds_Int64t < 0 ? true : false;

            if (!dsFlat_flag) { /*dsIncreasing_flag or dsDecreasing_flag */
                ds_Int64t = std::abs(ds_Int64t);
            }

            // ds_Int64t = formantLibrary._16bit_44100Hz_1channel_nextClosestAmplitude(ds_Int64t);

            if (frequencyTable_unorderedMap.find(ds_Int64t) == frequencyTable_unorderedMap.end()) {
                ds_Int64t = formantLibrary._16bit_44100Hz_1channel_nextClosestAmplitude(ds_Int64t); // Get next closest amplitude (noise-safe)

                frequencyTable_unorderedMap[ds_Int64t] = 1;

                currentFreq = formantLibrary._16bit_44100Hz_1channel[ds_Int64t];
                waveShape_Oscillator2DVec.push_back({ Oscillator(1, ds_Int64t, t_int64t, Oscillator::WaveShape::Sine) });
            }

        }

        lastAmplitude_int64t = currentAmplitude_int64t;

        ++t_int64t;
    }

    // Additional processing if required
}

int main() {
    audio::AudioFile audioFile("audio.wav");

    // reconstruct the audio file formants
    // Note: compute half-periods to improve accuracy, reduce noise, and increase performance
    processAudioFile(audioFile);

    // step 1. todo: generate an audio file spectrogram from the audio file formants

    // step 2. todo: compare the spectrogram with the original audio file spectrogram, calculate-, and try to minimize -error

    // step 3. todo: AND the result of step 2 with Gaussian noise, allowing only the frames that are also in the noise band for a more life-like presentation.

    // sep 4. todo (as required): map library formants onto the current audio file's ocillator (amplitude) curves (re-spech)

    return 0;
}
