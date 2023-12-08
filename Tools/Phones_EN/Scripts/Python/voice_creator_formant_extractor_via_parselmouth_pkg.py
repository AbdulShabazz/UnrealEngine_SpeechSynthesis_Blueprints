import parselmouth

# Extract formants from an audio file
snd = parselmouth.Sound("combined_sine_waves.wav")
formants = snd.to_formant_burg()
formants.save_as_text_file("combined_sine_waves.formants")
