# Concatenative Speech Synthesis for Unreal Engine 5
Concatenative Speech Synthesis, Text-to-Speech library and re-speecheer voice-mapping tool based on MARYTTS for Unreal Engine 5.

### Based upon MaryTTS 2.5

This is a multilingual open-source text-to-speech and speech-to-speech platform (re-speecher) suitable for use in theatrical production, based on the MaryTTS text-to-speech library,
 compatible with any platform that has a Java runtime installed, it is developed for the Unreal Engine 3D graphics game engine.

<img title='Schwa (phoneme) UE Blueprint' style='margin-top:24px;' alt='Schwa (phoneme) UE Blueprint' src='IMG/Schwa.Phoneme.BP.PNG'/><br>
<span>Schwa (phoneme) UE Blueprint</span>

<img title='Schwa.Phoneme.Synthesis.Parameters' style='margin-top:24px;' alt='Schwa.Phoneme.Synthesis.Parameters' src='IMG/Phoneme.Synthesis.Parameters.Screen.BP.png'/><br>
<span>Schwa.Phoneme.Synthesis.Parameters</span>

<img title='Schwa.Phoneme.(Formants).Synthesis.Curves' style='margin-top:24px;' alt='Schwa.Phoneme.(Formants).Synthesis.Curves' src='IMG/Phoneme.(Formants).Synthesis.Curves.Screen.PNG'/><br>
<span>Custom.Schwa.Phoneme.(Formants).Synthesis.Curves</span>

<img title='UE 5 Voice Configurator' style='margin-top:24px;' alt='UE 5 Voice Configurator (Blueprints)' src='IMG/UE_5_SpeechSynthesis_Configurator.png'/><br>
<span>UE 5 Voice Configurator</span>

<img title='Hello World!' style='margin-top:24px;' alt='Hello World! (Blueprints)' src='IMG/Hello.World.5.BP.2023.PNG'/><br>
<span>Hello World! UE Blueprint</span>

<br><br>

The library is made available under the Lesser General Public License LGPL version 3.0 -- see LICENSE.md for details.

### Available APIs

The Speech Synthesis Library uses the ARPABET phoneme alphabet set, which is a subset of the International Phonetic Alphabet (IPA), over its less ASCII-friendly standardized IPA phonetic superset. 
(Context-sensitive search may need to be disabled in your blueprint event graph editor to view the phoneme glyphs correctly.)

ARPA ARPABET - Wikipedia  
[+] Much easier to type on a computer  
[+] Only has relevant phones for American English  
[+] Has a phone for every sound in American English  
(-) No singular easy to read glyphs like those in the IPA  
  
The CMU Pronouncing Dictionary  
  
vowels > front > ARPABET UV >  
IY (Beat)  
IH (Bit)  
EH (Bet)  
EY (Bate)  
AE (Bat)  
  
vowels > back > ARPABET UV >  
AA (Bot)  
AO (Bought)  
OW (Boat)  
UH (Book)  
UW (Boot)  
  
vowels > mid > ARPABET UV >  
ER (Bird)  
AX (About)  
AH (Butt)  
  
vowels > diphthongs > ARPABET UV >  
AY (Bite)  
AW (Bout)  
OY (Boy)  
IX (Rabbit)  
  
stopConsonants > voiced > ARPABET UV >  
B (Beat)  
D (Deep)  
G (Go)  
  
stopConsonants > unvoiced > ARPABET UV >  
P (Pea)  
T (Tea)  
K (Kick)  
  
fricatives > voiced > ARPABET UV >  
V (Very)  
DH (Then)  
  
fricatives > unvoiced > ARPABET UV >  
F (Five)  
TH (Think)  
S (See)  
SH (She)  
  
semivowels > liquid > ARPABET UV >  
L (Love)  
EL (Bottle)  
R (Red)  
  
semivowels > glides > ARPABET UV >  
W (Water)  
WH (What)  
Y (Yes)  
  
nasals > non vocalic > ARPABET UV >  
M (More)  
N (Now)  
NX or NG (Sing)  
  
nasals > vocalic > ARPABET UV >  
EM (Button)  
EN (Son)  
  
affricates > voiced > ARPABET UV >  
CH (Church)  
JH (Jump)  
  
other > whisper > ARPABET UV >  
HH (How)  
  
other > vocalic > ARPABET UV >  
DX (Riddle)  
  
other > pause or glottal_stop > ARPABET UV >  
Q (Question)  


### Example:  

```cpp

#include "SpeechSynthesisAudioComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

using namespace TTSSpeechSynthesis;

class main {
public:

    main() {
        UTTSVoice Sara = UTTSVoice::Sara();
        Sara.SetAmplitude(6.0f); // ~60dB SPL (Range: 0.0f to 12.5f); 6.0f = normal speaking voice; 3.0f = a whisper.

        // Initialize SpeechLibrary with typed and named variables

        const VoiceArray voices_UTTSVoiceArray = { Sara };  // Only one voice chorus for simplicity
        const ChannelCount channel_count_uint32 = 2;
        const SampleWidth sample_width_uint32 = 2;
        const FrameRate frame_rate_hz_uint32 = 44100;  // Standard audio frame rate

        USpeechSynthesisBPLibrary SpeechLibrary;

        SpeechLibrary.SetVoices(voices_UTTSVoiceArray);
        SpeechLibrary.SetChannelCount(channel_count_uint32);
        SpeechLibrary.SetSampleWidth(sample_width_uint32);
        SpeechLibrary.SetFrameRate(frame_rate_hz_uint32);

        // Optional: re-speecher functionality
        /*
        SpeechLibrary.fromWAVFile("Sara.wav");   // lossless (Windows)
        SpeechLibrary.fromFLACFile("Sara.flac");  // lossless (Linux, MAC)
        SpeechLibrary.fromVOICEFile("Sara.voice");  // lossless
        SpeechLibrary.fromMP3File("Sara.mp3");   // lossy
        SpeechLibrary.fromAACFile("Sara.aac");   // lossy

        // Compile ...

        UARPABETAudio Voice = SpeechLibrary.Voice();

        // Play back the synthesized speech

        Voice.PlayBack();

        Voice.toWAVFile("Sara.wav");   // lossless (Windows)
        Voice.toFLACFile("Sara.flac");  // lossless (Linux, MAC)
        Voice.toVOICEFile("Sara.voice");  // lossless 
        Voice.toMP3File("Sara.mp3");   // lossy 
        Voice.toAACFile("Sara.aac");   // lossy
        */

        UProsodyCurve ProsodyCurveObjArray{};
        UDurationCurve DurationCurveObjArray{};
        UEmotiveCurve EmotiveCurveObjArray{};

        // Initialize VoiceObj and proceed with speech synthesis
        // Assuming the Init method and phoneme methods are refactored to return error codes for robustness
        // For example, if SynthesisInit returns a boolean indicating success, the code could be:

        if (SpeechLibrary.Init(ProsodyCurveObjArray, DurationCurveObjArray, EmotiveCurveObjArray))
        {
            // Proceed with artificial speech synthesis: 'Hello World!'
           
            SpeechLibrary.ARPABETSpeechSynthesis_HH();
            SpeechLibrary.ARPABETSpeechSynthesis_EH();
            SpeechLibrary.ARPABETSpeechSynthesis_L();
            SpeechLibrary.ARPABETSpeechSynthesis_OW();
            SpeechLibrary.ARPABETSpeechSynthesis_W();
            SpeechLibrary.ARPABETSpeechSynthesis_ER();
            SpeechLibrary.ARPABETSpeechSynthesis_L();
            SpeechLibrary.ARPABETSpeechSynthesis_D();

            // Compile ...

            UARPABETAudio Voice = SpeechLibrary.Voice();

            // Play back the synthesized speech

            Voice.PlayBack();

            Voice.toWAVFile("Sara.wav");   // lossless (Windows)
            Voice.toFLACFile("Sara.flac");  // lossless (Linux, MAC)
            Voice.toVOICEFile("Sara.voice");  // lossless 
            Voice.toMP3File("Sara.mp3");   // lossy 
            Voice.toAACFile("Sara.aac");   // lossy

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
```
### New Audio File Format

The library also institutes a custom open audio file format called **.voice** that resembles JSON which allows the file to be created, viewed and edited in any text editor, 
along with the ability for it to be searched, indexed, scripted and compressed. Encoding is utf-8, little-endian.

```javascript
{ // .Voice
    "nChannels": 2,
    "sampleWidth": 2, /* Stereo */
    "sampleRate": 192000,
    "bitsPerSample": 32,
    "byteCount": 16,
    "checksum": 0x20,
    "data": [
        [21/*HH*/, 13/*EH*/, 27/*l*/, 31/*OW*/, 42/*W*/, 17/*ER*/, 27/*L*/, 10/*D*/], // channel 1
        [21/*HH*/, 13/*EH*/, 27/*l*/, 31/*OW*/, 42/*W*/, 17/*ER*/, 27/*L*/, 10/*D*/]  // channel 2
    ]
}

{ // .VOICE
    "nChannels": N,
    "sampleWidth": 2, /* Stereo */
    "sampleRate": 192000,
    "bitsPerSample": 32,
    "byteCount": 16,
    "checksum": 0x20,
    "data": [
        [byte 0 (channel 1), byte 0 (channel 2), ... , (channel N], // subchunk 1
        [byte 1 (channel 1), byte 1 (channel 2), ... , (channel N], // subchunk 2
        .
        .
    ]
}
```
