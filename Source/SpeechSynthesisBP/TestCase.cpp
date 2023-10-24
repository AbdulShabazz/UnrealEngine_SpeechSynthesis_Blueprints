#include "SpeechSynthesisBlueprintLibrary.h"

#if WITH_DEV_AUTOMATION_TESTS

using namespace TTSSpeechSynthesis;

class main {
public:

    main() {
        FTTSVoice Sara = FTTSVoice::Sara();
        Sara.SetAmplitude(6.00f); // ~60db (0.00f to 12.00f); 6.00f is considered a normal speaking voice; 3.00f is considered a whisper.

        // Initialize SpeechLibrary with typed and named variables

        const VoiceArray voices_FTTVoiceArray = { Sara };  // Only one voice chorus for simplicity
        const ChannelCount channel_count_uint32 = 2;
        const SampleWidth sample_width_uint32 = 2;
        const FrameRate frame_rate_hz_uint32 = 44100;  // Standard audio frame rate

        USpeechSynthesisBPLibrary SpeechLibrary;

        SpeechLibrary.SetVoices(voices_FTTVoiceArray);
        SpeechLibrary.SetChannelCount(channel_count_uint32);
        SpeechLibrary.SetSampleWidth(sample_width_uint32);
        SpeechLibrary.SetFrameRate(frame_rate_hz_uint32);

        FProsodyCurve ProsodyCurveObjArray{};
        FDurationCurve DurationCurveObjArray{};
        FEmotiveCurve EmotiveCurveObjArray{};

        // Initialize VoiceObj and proceed with speech synthesis
        // Assuming the Init method and phoneme methods are refactored to return error codes for robustness
        // For example, if SynthesisInit returns a boolean indicating success, the code could be:

        if (SpeechLibrary.Init(ProsodyCurveObjArray, DurationCurveObjArray, EmotiveCurveObjArray))
        {
            // Proceed with artificial speech synthesis: 'Hello World!'
           
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
            Voice.Save.AsFLACFile("Sara.flac");  // lossless (Linux, MAC)
            Voice.Save.AsMP3File("Sara.mp3");   // lossy 
            Voice.Save.AsAACFile("Sara.aac");   // lossy

        } else {
            // Handle initialization error
            // ...
        }

        return 0;
    }

    ~main() {
        // ...
    };
};

#endif