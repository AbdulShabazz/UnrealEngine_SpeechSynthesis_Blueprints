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
<span>Schwa.Phoneme.(Formants).Synthesis.Curves</span>

<img title='Hello World!' style='margin-top:24px;' alt='Hello World! (Blueprint)' src='IMG/Hello.World.5.BP.2023.png'/><br>
<span>Hello World! UE Blueprint</span><br><br>

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
IY (B_ea_t)  
IH (B_i_t)  
EH (B_e_t)  
EY (B_ate_)  
AE (B_a_t)  
  
vowels > back > ARPABET UV >  
AA (B_o_t)  
AO (B_ough_t)  
OW (B_oa_t)  
UH (B_oo_k)  
UW (B_oot_)  
  
vowels > mid > ARPABET UV >  
ER (B_ir_d)  
AX (Ab_ou_t)  
AH (B_u_tt)  
  
vowels > diphthongs > ARPABET UV >  
AY (B_ite_)  
AW (B_ou_t)  
OY (B_o_y)  
IX (Rabb_i_t)  
  
stopConsonants > voiced > ARPABET UV >  
B (_B_eat)  
D (_D_eep)  
G (_G_o)  
  
stopConsonants > unvoiced > ARPABET UV >  
P (_P_ea)  
T (_T_ea)  
K (_K_ick)  
  
fricatives > voiced > ARPABET UV >  
V (_V_ery)  
DH (_Th_en)  
  
fricatives > unvoiced > ARPABET UV >  
F (_F_ive)  
TH (_Th_ink)  
S (_S_ee)  
SH (_Sh_e)  
  
semivowels > liquid > ARPABET UV >  
L (_L_ove)  
EL (Bott_le_)  
R (_R_ed)  
  
semivowels > glides > ARPABET UV >  
W (_W_ater)  
WH (_Wh_at)  
Y (_Y_es)  
  
nasals > non vocalic > ARPABET UV >  
M (_M_ore)  
N (_N_ow)  
NX or NG (Si_ng_)  
  
nasals > vocalic > ARPABET UV >  
EM (Butt_o_n)  
EN (S_o_n)  
  
affricates > voiced > ARPABET UV >  
CH (_Ch_urch)  
JH (_J_ump)  
  
other > whisper > ARPABET UV >  
H (_H_ow)  
  
other > vocalic > ARPABET UV >  
DX (Ri_dd_le)  
  
other > pause or glottal_stop > ARPABET UV >  
Q (_Q_uestion)  


### Example:  

```cpp

#include "SpeechSynthesisAudioComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

using namespace TTSSpeechSynthesis;

class main {
public:

    main() {
        UTTSVoice Sara = UTTSVoice::Sara();
        Sara.SetAmplitude(6.00f); // ~60db SPL (0.00f to 12.00f); 6.00f is considered a normal speaking voice; 3.00f is considered a whisper.

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

        UProsodyCurve ProsodyCurveObjArray{};
        UDurationCurve DurationCurveObjArray{};
        UEmotiveCurve EmotiveCurveObjArray{};

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
