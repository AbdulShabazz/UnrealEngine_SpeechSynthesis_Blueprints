''''This file encodes a pair of sinusoidal signals to WAV audio'''
import wave
import numpy as np


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
sine_wave_0 = generate_sine_wave(25, 0.5, 1)
sine_wave_1 = generate_sine_wave(250, 0.25, 1)

# Add the two sine waves together
combined_sine_wave = (sine_wave_0 + sine_wave_1)

# Write the combined sine wave to WAV audio
with wave.open("combined_sine_wave.wav", "wb") as wf:
    wf.setnchannels(2)
    wf.setsampwidth(2)
    wf.setframerate(pcm_encoding_hz)
    wf.writeframes(sine_wave_1.astype(bits_per_sample).tobytes())
