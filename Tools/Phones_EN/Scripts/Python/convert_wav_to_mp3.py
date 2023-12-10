from pydub import AudioSegment

# convert_wav_to_mp3

# Load an audio file (change the path-to-your-file)
audio = AudioSegment.from_file("combined_sine_waves.wav")

# Export to MP3 (change the path-and-filename, as needed)
audio.export("combined_sine_waves.mp3", format="mp3", bitrate="192k")

# convert_mp3_to_wav

# Load an audio file (change the path-to-your-file)
# audio = AudioSegment.from_file("combined_sine_waves.mp3")

# Export to WAV (change the path-and-filename, as needed)
# audio.export("combined_sine_waves.wav", format="wav", bitrate="192k")
