'''Generate log mel spectrogram from .WAV audio file'''
import audio as whisper_audio
import matplotlib.pyplot as plt
import torch
import numpy as np
import wave

# returns a numpy array of the audio file of float32 type
audio_data_np_array_float32 = whisper_audio.load_audio_basic("combined_sine_waves.wav")

# returns a torch tensor that contains the log mel spectrogram of the audio file
audio_file_log_mel_spectrogram_torch_tensor = whisper_audio.log_mel_spectrogram(audio_data_np_array_float32, n_mels=80, padding=0, device=None)

plt.figure(figsize=(10, 4))

# Display Log-Mel Spectrogram
plt.imshow(audio_file_log_mel_spectrogram_torch_tensor, aspect="auto", cmap="inferno", origin="lower")
plt.colorbar(format="%+2.0f dB")
plt.title("Log-Mel Spectrogram")
plt.xlabel("Time (s)")
plt.ylabel("Mel-frequency bins")

# Show Plot
plt.tight_layout()
plt.show()

