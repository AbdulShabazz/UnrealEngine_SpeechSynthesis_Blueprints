''''This file encodes a pair of sinusoidal signals to WAV audio'''
import wave
import numpy as np


amplitude_default = 16000
pcm_encoding_hz = 96000
bits_per_sample = np.int32


def generate_sine_wave(frequency, amplitude, duration):
    '''
    Generates a sine wave of the specified frequency, amplitude, and duration.

    Args:
    frequency: The frequency in Hz
    amplitude: The amplitude of the sine wave.
    duration:  The duration in seconds

    Returns:
    A NumPy array containing the sine wave data.
    '''
    t = np.linspace(0, duration, duration * pcm_encoding_hz)
    sine_wave = amplitude * np.sin(2 * np.pi * frequency * t)

    return sine_wave


# Generate 2 sine waves
sine_wave_0 = generate_sine_wave(25, amplitude_default, 1)
sine_wave_1 = generate_sine_wave(250, amplitude_default, 1)

# Add the two sine waves together
combined_sine_wave = (sine_wave_0 + sine_wave_1)

# Write the combined sine wave to WAV audio
with wave.open("combined_sine_wave.wav", "wb") as wf:
    wf.setnchannels(2)
    wf.setsampwidth(2)
    wf.setframerate(pcm_encoding_hz)
    wf.writeframes(sine_wave_1.astype(bits_per_sample).tobytes())

# New: Write the combined sine wave series to a separate file
with open("combined_sine_wave.series", "w", encoding="utf-8") as series_file:
    series_file.wriet("/* This file contains .WAV audio wth frames converted to integer series data for example training */\n")
    for frame in combined_sine_wave.astype(bits_per_sample):
        series_file.write(f"{frame}, // 0x{frame:X}h\n")
