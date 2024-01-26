import numpy as np
import wave
import sys
import generate_wav_audio_sine as gsw
import argparse

# Function to parse command-line arguments
def parse_arguments():
    parser = argparse.ArgumentParser(description="Generate a WAV file from sine wave.")
    parser.add_argument("--filename", type=str, help="Output WAV file name.")
    parser.add_argument("--freq", default=440, type=float, help="Fundamental Frequency of the sine wave in Hz (1 to 768000).")
    parser.add_argument("--amplitude", type=float, default=0.6, help="Amplitude of the sine wave (0.0 to 1.0, default 0.6).")
    parser.add_argument("--duration", type=int, default=1, help="Duration of the sine wave (in seconds).")
    parser.add_argument("--pcm_hz", type=int, default=96000, help="PCM Sampling Frequency (in Hz [11000, 22000 44100 48000 88200 96000 192000 384000 768000]).")
    parser.add_argument("--pcm_bit_depth", type=int, default=32, help="PCM bits per sample (8, 16, 24, 32, 64)")
    return parser

# Parse the command-line arguments
ARGS = parse_arguments() # input("Press Enter to continue...")

if len(sys.argv) == 1:  # No additional arguments were provided with the module name
    ARGS.print_help()
    sys.exit(1)

args = ARGS.parse_args()

# Generate 2 sine waves based on the provided arguments
sine_wave_0 = gsw.generate_sine_wave(args.freq,
                                     args.amplitude,
                                     args.duration,
                                     args.pcm_hz,
                                     args.pcm_bit_depth)


duration_default = 1.0
frequency_default = 440
amplitude_default = 0.6
pcm_encoding_hz = 48000
bits_per_sample = np.int32  # 8 16 24 32 64
pcm_bps = 24

# Add the sine waves together
combined_sine_wave = (sine_wave_0)

fn = f'-{((1-amplitude_default)*10)}_dBFS_signal_encoded_using_PCM_{pcm_encoding_hz}_Hz_{pcm_bps}_bits_per_sample_at_{frequency_default}_Hz_{duration_default}s_duration.wav'

if args.filename is not None:
    fn = args.filename

# Write the combined sine wave to WAV audio
with wave.open(fn, "wb") as wf:
    wf.setnchannels(2)
    wf.setsampwidth(pcm_bps // 8) # Integer divide by 8 converts bits to bytes
    wf.setframerate(pcm_encoding_hz)
    wf.writeframes(combined_sine_wave.tobytes())
