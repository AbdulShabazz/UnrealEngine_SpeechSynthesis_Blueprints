Concatenative speech synthesis text-to-speech (TTS) library implemented in Blueprints.

Concatenative speech synthesis library suitable for use in theatrical production, implemented in Blueprints and C++23 based on the MaryTTS repo for Unreal Engine 5.

This library expands the current state-of-the-art text-to-speech synthesis library in Unreal Engine 5, which is based on the Tacotron 2 voice model. 

The Tacotron 2 model is a neural network that takes text as input and outputs a spectrogram, which is then converted to audio using a vocoder. 
The Tacotron 2 model is trained on a large dataset of speech recordings, and is able to produce speech that sounds natural and human-like. 
However, the Tacotron 2 model is not able to produce natural speech that sounds like a live performance, 
and is not able to produce speech having a specific character attribute such as a whisper, non-verbal cue, mechatron or chorus.

The concatenative natural speech synthesis library based upon MaryTTS is able to produce natural speech that sounds like a live performance, 
and can support many other character performance aspects such as a whisper, non-verbal cues, mechatron and chorus, etc. After building its transition-states internally via state-machine, 
the concatenative speech synthesis then generates the requisite (sine) signals for the entire duration of speech for all formants in parallel, including the fundamental, and then combines them with the aid of an Artificial Neural Network (ANN) which as a sort of DSP signal processor also incorporates other natural aspects and voice cues such as jitter and shimmer before combining the waveforms into a single output signal. 
The concatenative speech synthesis library is implemented in Blueprints and C++23, and is intended for use in theatrical production.

Example:

```cpp

#include "SpeechSynthesisBlueprintLibrary.h"

#if WITH_DEV_AUTOMATION_TESTS

using namespace TTSSpeechSynthesis;

// Strong Typing for Configuration Parameters

using VoiceArray = TArray<FTTSVoice>;
using ChannelCount = unsigned int;
using SampleWidth = unsigned int;
using FrameRate = unsigned int;

class main {
public:

    main() {

        FTTSVoice Sara = FTTSVoice::Sara();
        Sara.SetAmplitude(6.00f); // ~60db (0.00f to 12.00f); 6.00f is considered a normal speaking voice; 3.00f is considered a whisper.

        // Initialize SpeechLibrary with typed and named variables

        const VoiceArray voices_FTTVoiceArray = { Sara };  // Only one voice chorus for simplicity
        const ChannelCount channel_count_uint32 = 2;
        const SampleWidth sample_width_uint32 = 2; // 16-bit
        const FrameRate frame_rate_hz_uint32 = 44100;  // Standard audio frame rate

        USpeechSynthesisBPLibrary SpeechLibrary;

        SpeechLibrary.SetVoices(voices_FTTVoiceArray);
        SpeechLibrary.SetChannelCount(channel_count_uint32);
        SpeechLibrary.SetSampleWidth(sample_width_uint32);
        SpeechLibrary.SetFrameRate(frame_rate_hz_uint32);

        FProsodyCurve ProsodyCurveObjArray{};
        FDurationCurve DurationCurveObjArray{};
        FEmotiveCurve EmotiveCurveObjArray{};

        // Initialize VoiceObj and proceed with speech synthesis:
        // Proceed with artificial speech synthesis: 'Hello World!'

        if (SpeechLibrary.Init(ProsodyCurveObjArray, DurationCurveObjArray, EmotiveCurveObjArray))
        {
            // Spell 'Hello World' in ARPAbet phonetic alphabet: H EH1 L OW1 W ER1 L D
           
            SpeechLibrary.ARPABETSpeechSynthesis_H();
            SpeechLibrary.ARPABETSpeechSynthesis_EH();
            SpeechLibrary.ARPABETSpeechSynthesis_L();
            SpeechLibrary.ARPABETSpeechSynthesis_OW();
            SpeechLibrary.ARPABETSpeechSynthesis_W();
            SpeechLibrary.ARPABETSpeechSynthesis_ER();
            SpeechLibrary.ARPABETSpeechSynthesis_L();
            SpeechLibrary.ARPABETSpeechSynthesis_D();

            // Compile ...

            ARPABETAudio Voice = SpeechLibrary.Voice();

            // Play back the synthesized speech

            Voice.PlayBack();

            Voice.Save.AsWAVFile("Sara.wav");   // lossless (Windows)
            Voice.Save.AsFLACFile("Sara.flac"); // lossless (Linux, MAC)
            Voice.Save.AsMP3File("Sara.mp3");   // lossy
            Voice.Save.AsAACFile("Sara.aac");   // lossy
            Voice.Save.AsVOICEFile("Sara.voice");   // open lossless audio file format

        } else {
            // Handle initialization errors
            // ...
        }

        return 0;
    }

    ~main() {
        // ...
    };
};

#endif
```

The library also institutes a custom .voice open audio file format that resembles JSON which allows the file to be created, viewed and edited in any text editor, 
along with the ability for it to be searched, indexed, scripted and compressed. Encoding is utf-8, little-endian.

```json
{
    "nChannels": N,
    "sampleWidth": 2,
    "sampleRate": 192000,
    "bitsPerSample": 32,
    "data": [
        [channel 1, channel 2, ..., N], // sub chunk 1
        [channel 1, channel 2, ..., N], // sub chunk 2
        .
        .
        .
    ]
}
```
