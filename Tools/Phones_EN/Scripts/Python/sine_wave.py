import numpy as np
import wave
import struct

# Define Parameters
sample_rate = 44100
frequency = 1440.0
duration = 1.0
amplitude = 16000

# Generate Time Array
t = np.linspace(0, duration, int(sample_rate * duration), endpoint=False)

# Generate Sinusoidal Wave
y = amplitude * np.sin(2 * np.pi * frequency * t)

# Convert to 16-bit PCM Format
y = np.int32(y)

# Create WAV File
with wave.open("sine_wave.wav", "w") as f:
    nchannels = 2
    sampwidth = 2
    nframes = len(y)
    comptype = "NONE"
    compname = "not compressed"

    f.setparams((nchannels, sampwidth, sample_rate, nframes, comptype, compname))

    for sample in y:
        f.writeframes(struct.pack("h", int(sample)))
