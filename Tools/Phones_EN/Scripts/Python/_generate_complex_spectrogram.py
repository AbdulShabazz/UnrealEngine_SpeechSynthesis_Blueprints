import librosa
import librosa.display
import matplotlib.pyplot as plt
import numpy as np

# Step 1: Load the Audio File
# Replace 'path_to_file.wav' with the path to your audio file
audio_file_path = 'path_to_file.wav'
y, sr = librosa.load(audio_file_path, sr=None)  # 'sr=None' loads the file with its original sampling rate

# Step 2: Compute the STFT
# 'n_fft' is the window size, 'hop_length' is the number of samples between successive frames
n_fft = 2048
hop_length = 512
stft = librosa.stft(y, n_fft=n_fft, hop_length=hop_length)

# Step 3: Plot the Magnitude Spectrogram
plt.figure(figsize=(12, 8))

# Magnitude plot
plt.subplot(2, 1, 1)
mag = librosa.amplitude_to_db(np.abs(stft), ref=np.max)  # Convert the magnitude to decibel
librosa.display.specshow(mag, sr=sr, hop_length=hop_length, x_axis='time', y_axis='log', cmap='viridis')
plt.colorbar(format='%+2.0f dB')
plt.title('Magnitude Spectrogram')

# Phase plot
plt.subplot(2, 1, 2)
phase = np.angle(stft)  # Extract the phase information
librosa.display.specshow(phase, sr=sr, hop_length=hop_length, x_axis='time', y_axis='log', cmap='viridis')
plt.colorbar()
plt.title('Phase Spectrogram')

plt.tight_layout()
plt.show()
