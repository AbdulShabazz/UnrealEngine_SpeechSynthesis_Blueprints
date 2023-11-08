import torchaudio
import matplotlib.pyplot as plt
import torch

# Step 1: Load the Audio File
# Replace 'path_to_file.wav' with the path to your audio file
audio_file_path = 'path_to_file.wav'
waveform, sample_rate = torchaudio.load(audio_file_path)

# Step 2: Compute the Complex Spectrogram
# 'n_fft' is the window size, 'hop_length' is the number of samples between successive frames
n_fft = 2048
hop_length = 512
spectrogram_transform = torchaudio.transforms.Spectrogram(n_fft=n_fft, hop_length=hop_length, power=None)
complex_spectrogram = spectrogram_transform(waveform)

# Split the complex spectrogram into magnitude and phase
magnitude = torch.abs(complex_spectrogram)
phase = torch.angle(complex_spectrogram)

# Step 3: Plot the Spectrogram
fig, axs = plt.subplots(2, 1, figsize=(14, 8))

# Plot Magnitude Spectrogram
axs[0].imshow(magnitude.log2()[0,:,:].numpy(), origin='lower', aspect='auto', cmap='viridis')
axs[0].set_title('Magnitude Spectrogram')
axs[0].set_xlabel('Time Frame')
axs[0].set_ylabel('Frequency Bin')
axs[0].set_xticks([])
axs[0].set_yticks([])

# Plot Phase Spectrogram
axs[1].imshow(phase[0,:,:].numpy(), origin='lower', aspect='auto', cmap='viridis')
axs[1].set_title('Phase Spectrogram')
axs[1].set_xlabel('Time Frame')
axs[1].set_ylabel('Frequency Bin')
axs[1].set_xticks([])
axs[1].set_yticks([])

plt.tight_layout()
plt.show()
