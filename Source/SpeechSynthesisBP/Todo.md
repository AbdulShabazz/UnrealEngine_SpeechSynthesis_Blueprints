## TODO list

### Unreal Engine Development
1. **Blueprint Class Development**:
   - Derive a custom blueprint class to expose C++ functionality in the editor.
   - Implement an Attack-Decay-Sustain-Release (ADSR) envelope for each phone.
   - Include an AUDITION button in blueprints for pre-synthesis auditioning of phones.

2. **Voice Trait Customization**:
   - Enable user customization of voice signal's fundamental and formant frequencies, pitch, speed, and volume.
   - Support voice trait recompilation and runtime re-mapping (e.g., using Sara's traits for Bob's voice).

3. **Module Integration**:
   - Import voice libraries as separate .DLL modules for dynamic loading/unloading without recompilation.

### Audio Processing and Synthesis
1. **Synthesis Techniques**:
   - Generate the entire ARPABET phonetic alphabet from scratch using a single sine wave generator, F0, and or all short- and long- vowel and consonant sounds for best coverage.
   - Explore quarter-period synthesis for phone transition versatility and sound fidelity.
   - Use std::vector&lt;FTTSVoice::Sara::FFormants&gt; to build voice signal's fundamental and formant frequencies.
   - Provide a sine wave generator with a 10s decay envelope to simulate human lung capacity.
   - Include an ARPABETPhone::breath UE Audio blueprint activated after 5s of speech for realistic breathing simulation.
   - Integrate noise generators to mimic a speaker's breath.

2. **Signal Processing**:
   - Carve the F0 waveforms out of Gaussian noise mask filter.
   - Employ state-machine for ADSR envelope mode switching to prevent signal discontinuities.
   - Use distinct sine audio chords to simulate ADSR characteristics in lieu of formant signals.
   - Compute delta and delta-delta tangent (curve) features near transition points for smooth phone transitions.
   - Consider using a single formant F0 per phone, using ADSR Oscillator's effects for other formant characteristics.
   - Because Humans are so sensitive to speech, synthetic speech cannot be flat. One proposed solution is that
every segment of generated speech requires a parenthetical caption (ie. a wryly) preceeding which describes the tone of speech generated.
The system must also be capable of producing the tone of speech required in the caption.
   - Lock the noise color band bandwidths to faithfully follow the contours of the formant frequencies.
   - Add additional Phrase, Sentence, and Paragraph-level oscillators to better randomize effects of prosody and emotion.

### Machine Learning and Data Analysis
1. **GAN Training for Spectrogram Generation**:
   - Collect and train a GAN on male voice spectrograms saying "Bob" for novel spectrogram generation.
   - Consider the computational demands and training challenges of GANs.

2. **Spectrogram Formats for Audio Recovery**:
   - Analyze different spectrogram formats (e.g., Linear-Frequency, Complex, Mel, Log-Mel, Constant-Q Transform (CQT), Gammatone) for audio file recovery and generation.

3. **Prosody and Emotion Extraction**:
   - Extract prosody and emotional curves from audio content for the prosody library.
   - Implement feature extraction techniques for pitch, energy, duration, and emotional cues.

### Voice Library Expansion
1. **Sample Addition Process**:
   - Steps for adding new samples include reconstructing audio file formants, generating and comparing their spectrograms, and then applying Gaussian noise masks to carve out their waveforms.

2. **Dynamic Voice Traits**:
   - Adjust voice attributes like age, sex, national origin, timbre, accent, and various non-verbal attributes.
   - Support parentheticals and non-verbal cues in the SpeechSynthesis engine.

### Non-Verbal Sound Cue Integration
And support for a wide array of non-verbal cues

1. **Sniffle:** Indicating sadness or a cold.
2. **Huff:** Showing irritation or exasperation.
3. **Laugh:** Expressing amusement or joy.
4. **Sneer:** Conveying contempt or disdain.
5. **Sigh:** Signifying relief, tiredness, or disappointment.
6. **Gasp:** Indicating shock or surprise.
7. **Cough:** Clearing the throat or indicating illness.
8. **Yawn:** Showing tiredness or boredom.
9. **Giggle:** A light, often nervous laugh.
10. **Grunt:** Expressing effort or disapproval.
11. **Groan:** Indicating pain, despair, or annoyance.
12. **Hum:** Showing contentment or filling silence.
13. **Whistle:** Expressing cheerfulness or signaling.
14. **Chuckle:** A soft, suppressed laugh.
15. **Sob:** Indicating deep sorrow or crying.
16. **Moan:** Suggesting pain or pleasure.
17. **Murmur:** A soft, indistinct sound.
18. **Stammer:** Showing hesitation or nervousness in speech.
19. **Shriek:** Indicating terror or excitement.
20. **Whimper:** A soft cry indicating fear or sadness.
21. **Chortle:** A joyful, chuckling laugh.
22. **Squeal:** High-pitched sound of excitement or fear.
23. **Screech:** Harsh, high-pitched scream.
24. **Cluck:** Expressing disapproval or [tsk-tsk] sound.
25. **Mutter:** Speaking in a low, barely audible manner.
26. **Bellow:** Loud, powerful shout.
27. **Roar:** Deep, loud sound of anger or laughter.
28. **Pant:** Indicating exertion or excitement.
29. **Snarl:** Showing anger or hostility.
30. **Rasp:** Harsh, grating sound.
31. **Guffaw:** A loud, boisterous laugh.
32. **Snicker:** A suppressed or half-contained laugh.
33. **Wail:** A prolonged high-pitched cry of distress.
34. **Titter:** A nervous, restrained laugh.
35. **Purr:** Indicating contentment or pleasure.
36. **Whine:** A complaining or pitiful tone.
37. **Whoop:** A loud cry of excitement or joy.
38. **Splutter:** Confused or excited speech.
39. **Hiccup:** Involuntary sound from diaphragm spasms.
40. **Burp:** Releasing air from the stomach through the mouth.
41. **Slurp:** Loud sucking noise while drinking or eating.
42. **Chew:** Sound of food being masticated.
43. **Gurgle:** Bubbling sound, often from the throat.
44. **Crunch:** Sound of hard food being bitten.
45. **Swallow:** Audible gulping sound.
46. **Snort:** A sound of contempt or derision.
47. **Mumble:** Speaking softly and indistinctly.
48. **Cackle:** A loud, raucous laugh.
49. **Babble:** Incoherent or rapid talking.
50. **Yelp:** A short, sharp cry of pain or alarm.
51. **Squeak:** A short, high-pitched sound or voice.
52. **Bark:** Sharp, loud call (not only for dogs).
53. **Croak:** A rough, harsh voice or sound.
54. **Bawl:** To cry loudly, often in distress.
55. **Growl:** A low guttural sound of hostility.
56. **Breathe Heavily:** Indicating exertion or stress.
57. **Shout:** To yell or call loudly.
58. **Cry:** Emotional shedding of tears.
59. **Exclaim:** Speaking suddenly and emphatically.
60. **Whisper:** Soft, hushed speaking.
61. **Rattle:** A rapid succession of short sounds.
62. **Clear Throat:** Signaling readiness to speak or discomfort.
63. **Sneeze:** An involuntary expulsion of air from the nose.
64. **Sniff:** Drawing air audibly up the nose.
65. **Spit:** Expelling saliva forcefully from the mouth.
66. **Snore:** A loud breathing sound during sleep.
67. **Sputter:** Making spitting or exploding noises.
68. **Wheeze:** A breathy, whistling sound from the lungs.
69. **Howl:** A prolonged, mournful cry.
70. **Grovel:** Indicating obsequiousness or humility.
71. **Squawk:** A loud, harsh, screeching sound.
72. **Chirp:** A short, sharp sound.
73. **Warble:** A melodious, trilling sound.
74. **Trill:** A quavering or vibratory sound.
75. **Peal:** A loud, ringing sound (like laughter).
76. **Chime:** A musical, ringing sound.
77. **Drone:** A continuous low humming sound.
78. **Buzz:** A humming or murmuring sound.
79. **Chime in:** To join or interrupt a conversation.
80. **Bruxism:** Clenching of the teeth.
81. **Gnash:** Grinding the teeth together.
82. **Raspberries:** A sound made by blowing air through relaxed but constricted lips.
83. **Rustle:** A soft, whispering sound, such as that caused by the hand brushing against a groom or beard.
84. **Click:** A short, sharp sound.
85. **Tick:** A light, repetitive sound.
86. **Blare:** A loud, harsh sound.
87. **Honk:** A loud, trumpet-like sound.
88. **Smack:** A loud kissing or hitting sound.
89. **Bang:** A loud, abrupt sound.
90. **Slap:** A sharp striking sound.
91. **Pop:** A sudden, sharp sound made by plucking the thumb against the inner cheek. 
92. **Fizz:** A soft, sizzling sound.
93. **Thump:** A heavy, dull sound.
94. **Clap:** A sharp slapping sound, often of hands.
95. **Stamp:** A heavy, thudding sound.
96. **Clink:** A light, sharp ringing sound against a gold metal tooth or set of braces or retainer.
97. **Slam:** A loud, forceful sound.
98. **Crack:** A sharp, snapping sound such as with tooth enamel.
99. **Tinkle:** A light, clear dripping sound such as fluid landing on the skin.
100. **Toot:** A supportive short groan, resembling the sound from a horn.
101. **Beep:** A short, high-pitched Shriek, resembling the short sound from a horn.
102. **skeptical Sigh or Hum:** A continuous Hum.
