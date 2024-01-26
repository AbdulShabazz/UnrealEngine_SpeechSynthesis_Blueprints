''' Generates WAV audio file from a sine wave '''
import wave
import numpy as np


def resolutions(pcm_bps: int=32)->np.dtype:
    if pcm_bps == 8:
        return np.int8
    elif pcm_bps == 16:
        return np.int16
    elif pcm_bps == 24:
        return np.int32
    elif pcm_bps == 32:
        return np.int32
    elif pcm_bps == 64:
        return np.int64
    else:
        return np.int32


def generate_sine_wave(frequency: float = 440,
                       amplitude: float = 0.6,
                       duration: int = 1,
                       pcm_encoding_hz: int = 96000,
                       pcm_encoding_bps: int = 32):
    '''
    Generates a sine wave of the specified frequency, amplitude, and duration.

    Args:
    frequency: The frequency (in Hz)
    amplitude: The amplitude of the sine wave ([0.0, 1.0] range))
    duration:  The duration (in seconds)
    pcm_encoding_hz: The PCM encoding sampling frequency (in Hz)
    pcm_encoding_bps: The PCM encoding bit-depth per sample (8, 16, 24, 32, 64)

    Returns:
    A NumPy array containing the sine wave data.
    '''
    # Ensure the number of samples is an integer
    dynamic_resolution = pcm_encoding_bps - 1
    t = np.linspace(0, duration, duration * pcm_encoding_hz)
    sine_wave = amplitude * \
        pow(2, dynamic_resolution) * \
        np.sin(2 * np.pi * frequency * t)

    return sine_wave
