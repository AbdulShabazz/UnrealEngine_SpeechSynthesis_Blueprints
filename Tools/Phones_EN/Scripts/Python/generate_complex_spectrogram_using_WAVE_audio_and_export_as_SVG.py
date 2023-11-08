
import torchaudio
import matplotlib.pyplot as plt
import numpy as np
import torch
import wave


# Define a function to save the spectrogram as SVG
def save_spectrogram_as_svg(data, title : str, filename : str):
    fig, ax = plt.subplots(figsize=(14, 8))
    ax.imshow(data.numpy(), origin='lower', aspect='auto', cmap='viridis')
    ax.set_title(title)
    ax.set_xlabel('Time Frame - milliseconds')
    ax.set_ylabel('Frequency Bin - Hz')
    plt.tight_layout()
    plt.savefig(filename, format='svg')
    plt.close(fig)

# Load the Audio File
audio_file_path = 'combined_sine_waves.wav'

with wave.open(audio_file_path, 'rb') as audio_file:
    nchannels = audio_file.getnchannels()
    nframes = audio_file.getnframes()
    framerate = audio_file.getframerate()
    audio_data = audio_file.readframes(nframes)
    
    # Convert buffer to float32 using NumPy
    audio_data_np = np.frombuffer(audio_data, dtype=np.int16).astype(np.float32)
    # Normalize data to [-1, 1]
    audio_data_np /= np.iinfo(np.int16).max
    
    # Reshape the data to channels x samples if stereo
    if nchannels == 2:
        waveform = torch.from_numpy(audio_data_np).view(nframes, nchannels).t()
    else:
        waveform = torch.from_numpy(audio_data_np).view(1, -1)

    # Compute the Complex Spectrogram
    n_fft = 2048
    hop_length = 512
    spectrogram_transform = torchaudio.transforms.Spectrogram(
        n_fft=n_fft,
        hop_length=hop_length,
        power=None
    )
    complex_spectrogram = spectrogram_transform(waveform)

    # Split the complex spectrogram into magnitude and phase
    magnitude = torch.abs(complex_spectrogram)
    phase = torch.angle(complex_spectrogram)

    # Convert magnitude to log scale for better visualization
    magnitude_log = torch.log1p(magnitude)

    # Save Magnitude Spectrogram as SVG
    save_spectrogram_as_svg(
        data=magnitude_log[0],  # Taking the first channel if stereo
        title='Magnitude Spectrogram',
        filename='magnitude_spectrogram.svg'
    )

    # Save Phase Spectrogram as SVG
    save_spectrogram_as_svg(
        data=phase[0],  # Taking the first channel if stereo
        title='Phase Spectrogram',
        filename='phase_spectrogram.svg'
    )
