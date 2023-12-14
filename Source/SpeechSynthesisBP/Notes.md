### SpeechSynthesis Library (Originating Pull Request URL)
- **URL**: https://github.com/EpicGames/UnrealEngine/pull/11021

### Unreal Engine and Blueprint Macros
- **Issue**: Adding Blueprint macros manually in Unreal Engine projects disrupts C++ rebuilds or gets ignored by the .INI package compiler.
- **Workaround**: Implementing custom blueprints as C++ components within the UE event graph is effective. Each blueprint class compiles into a separate implementation file.

### Speech Synthesis and Audio Processing
- **Key Observation**: Consonants and vowels carry significant information in speech audio.
- **Objective**: Develop a library capable of generating distinct consonant and vowel sounds.
- **Method**: Employ circular convolution for signal processing. This involves Fast Fourier Transform, frequency domain multiplication, inverse Fourier Transform, and scaling by bit-depth-per-frame to prevent clipping.
- **Specifications**:
  - BitDepthPerFrame: 16 (65536 amplitude values per frame)
  - FrameRate: 44100 Hz (Nyquist frequency: 22050 Hz)
- **Synthesis Methods**:
  - Preference for formant synthesis for its range and expressive capabilities.
  - Use of GANs for generating spectrograms.

### Formant Synthesis
- **Formants**: Typically spaced 25-100 Hz apart, with the first formant being the lowest.
- **Signal Deconstruction**: Involves matching amplitude, phase, frequency, wave-shape, duration, and noise-type.

### Additional Audio Processing Concepts
- **Convolution**: Viewed as a weighted moving-average or smoothing filter.
- **Energy Distribution in Speech**: Below 300 Hz, with consistent amplitude allocation across different phonemes.

### Sonic Visualizer Settings
- **Configuration**:
  - Color: Sunset
  - Scale: dB
  - Normalization: Column
  - Window: 1024
  - Window Overlap: None
  - Oversample: 1x
  - Bins: Frequencies
  - Frequency Scale: Logarithmic

### Project Tools and Resources
- **Wave-Shaper**: Utilizes Desmos Graphing Calculator.
- **Speech Corpus**: MyST children's audio speech corpus from a science education website. Details:
  - 393 hours of speech
  - Ages: 5-18 years
  - Adult Pitch Range: 75-250 Hz
  - Children Pitch Range: 200-500 Hz

### Audio Quality and Perception
- High-quality headphones and speakers with a broad frequency response enhance the detail and character of audio, impacting speech intelligibility and quality.

### Machine Learning and Wave-Shapes
- **Strategies**:
  - Neural network classification of wave-shapes for each phoneme.
  - State-machine comparison for formant synthesis.
- **Machine Learning Approach**: Treat model training like gameplay sessions, ensuring all rules are explicit and observable.

### Data Types for Precision
- **float**: 32 bits (~7 decimal digits precision)
- **double**: 64 bits (~15-16 decimal digits precision)
- **long double**: Varies, offers more precision than double

### Project Focus
- Emphasis on high-fidelity voice synthesis over processing speed.
- Interest in detailed voice attribute customization rather than real-time performance.

### Computational Model Training
- **Goals**:
  - Segment non-overlapping attributes (e.g., breathiness, nasality).
  - Group complementary attributes (e.g., masculine/feminine tones).
  - Identify effective frequency sets.
  - Understand the impact of wave shape on voice attributes.
