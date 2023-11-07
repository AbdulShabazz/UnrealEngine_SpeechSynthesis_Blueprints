
import torchaudio
import matplotlib.pyplot as plt
import torch

# Load the Audio File
audio_file_path = 'path_to_file.wav'
waveform, sample_rate = torchaudio.load(audio_file_path)

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

# Define a function to save the spectrogram as SVG
def save_spectrogram_as_svg(data, title, filename):
    fig, ax = plt.subplots(figsize=(14, 8))
    ax.imshow(data.numpy(), origin='lower', aspect='auto', cmap='viridis')
    ax.set_title(title)
    ax.set_xlabel('Time Frame')
    ax.set_ylabel('Frequency Bin')
    plt.tight_layout()
    plt.savefig(filename, format='svg')
    plt.close(fig)

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
