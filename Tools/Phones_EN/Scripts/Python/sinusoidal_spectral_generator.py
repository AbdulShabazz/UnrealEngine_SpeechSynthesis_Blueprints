''''This file encodes discrete sinudoial formants in a .signal file'''
import numpy as np
from prime_factors import prime_factors

# Parameters
sampling_rate = 96000  # 96 kHz
sample_depth = 32  # 32 bits
min_freq = 50  # 50 Hz
max_freq = 500  # 500 Hz
file_name = f"{sampling_rate}_hz_PCM_{sample_depth}_bits_from_{min_freq}_to_{max_freq}_hz.signals"

# Function to generate a single frame of a sinusoidal wave for a given frequency
def generate_wave_frame(frequency, sampling_rate, sample_depth):
    # Time for one frame
    t = 1 / sampling_rate
    # Generate the wave value for one frame
    wave_value = np.sin(2 * np.pi * frequency * t)
    # Scale to 32-bit integer range and convert
    max_int32 = 2**(sample_depth - 1) - 1
    int_wave_value = int(wave_value * max_int32)
    return int_wave_value

# Generate and save wave frames for frequencies from 50 Hz to 500 Hz
with open(file_name, 'w', encoding="utf-8") as file:
    file.write(f" /* This file contains 1-frame sinusoidal waveform long-integer frame-encodings from {min_freq} Hz to {max_freq} Hz using {sampling_rate} Hz PCM encoding at {sample_depth} bit-depth per sample */.\n")

    for frequency in range(min_freq, max_freq + 1):  # 50 Hz to 500 Hz
        wave_frame = generate_wave_frame(frequency, sampling_rate, sample_depth)
        hex_value = format(wave_frame & 0xFFFFFFFF, 'x')
        factors = prime_factors(wave_frame)
        factors_str = ', '.join(map(str, factors))
        line = f"{wave_frame}, //0x{hex_value}h at [0 ms, {frequency} Hz] - prime_factors[ {factors_str} ]\n"
        file.write(line)
