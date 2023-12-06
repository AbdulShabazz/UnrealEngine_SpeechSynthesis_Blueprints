## Python Scripts

Python scripts and examples used to develop the Speech Synthesis library.

---

### FFMPEG Installation

FFMPEG is a comprehensive multimedia framework used to record, convert, and stream audio and video files.

#### Windows Installation
1. **Using pip**
   ```bash
   pip install ffmpeg-python
   ```
2. **Using Chocolatey**
   ```bash
   choco install ffmpeg-python
   ```

#### Linux Installation
```bash
sudo apt update && sudo apt install ffmpeg-python
```

---

### Core Libraries for Speech Synthesis

1. **NumPy**
   - **Installation**: `pip install numpy`
   - **Description**: A fundamental package for scientific computing with Python, used for efficient operations on arrays and matrices.
   - **Use in Speech Synthesis**: Essential for numerical computations and handling audio data as arrays.

2. **SciPy**
   - **Installation**: `pip install scipy`
   - **Description**: Used for mathematics, science, and engineering, providing tools for optimization, integration, and statistics.
   - **Use in Speech Synthesis**: Provides signal processing modules and mathematical functions relevant to audio processing.

3. **Matplotlib**
   - **Installation**: `pip install matplotlib`
   - **Description**: A plotting library for creating static, animated, and interactive visualizations.
   - **Use in Speech Synthesis**: Useful for visualizing audio data and analysis results.

4. **Wave**
   - **Installation**: `pip install wave`
   - **Description**: Provides a convenient interface to the WAV sound format.
   - **Use in Speech Synthesis**: Essential for reading and writing WAV files.

5. **Pydub**
   - **Installation**: `pip install pydub`
   - **Description**: A simple and easy-to-use library for manipulating audio with a high-level interface.
   - **Use in Speech Synthesis**: Useful for audio segmentation, concatenation, and manipulation.

6. **PyTorch**
   - **Installation**: `pip install torch`
   - **Description**: An open-source machine learning library for Python, used for applications such as natural language processing.
   - **Use in Speech Synthesis**: Core for developing deep learning models in speech synthesis.

7. **TorchAudio**
   - **Installation**: `pip install torchaudio`
   - **Description**: Provides easy access to audio processing in PyTorch.
   - **Use in Speech Synthesis**: Integral for audio data preprocessing and augmentation.

8. **TorchVision**
   - **Installation**: `pip install torchvision`
   - **Description**: Consists of popular datasets, model architectures, and common image transformations for computer vision.
   - **Use in Speech Synthesis**: Occasionally used for multimodal speech synthesis systems integrating visual data.

9. **Praat-Parselmouth**
   - **Installation**: `pip install praat-parselmouth`
   - **Description**: A Python interface to the Praat software, widely used in phonetics for speech analysis.
   - **Use in Speech Synthesis**: Enables advanced speech analysis and manipulation.

---

### Optional Library for Audio Processing

- **Librosa**
  - **Installation**: `pip install librosa`
  - **Description**: A Python package for music and audio analysis, providing the building blocks necessary to create music information retrieval systems.
  - **Use in Speech Synthesis**: Alternative to TorchAudio for audio feature extraction, analysis, and processing.

---
