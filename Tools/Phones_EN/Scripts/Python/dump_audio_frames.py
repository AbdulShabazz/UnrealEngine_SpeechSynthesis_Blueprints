from pydub import AudioSegment


def dump_audio_frames(fn: str) -> None:
    '''Dump audio frames to a .series file.'''
        
    duration_seconds = 0
    ext = fn.split(".")[-1]
    fn_short = fn.split(".")[0]
    tags = "No metadata tags available."
    bitrate = "Bitrate information not available."
    total_frames = "Total frames not available."
    sampling_rate = "Sampling rate not available."

    # Load the audio file
    audio = AudioSegment.from_file(fn, format=ext)

    # Print each sample
    with open(f"{fn_short}__{ext}.series", "w", encoding="utf-8") as f:

        # Calculate the total number of frames
        total_frames = (len(audio) / 1000) * audio.frame_rate

        # extracr the sampling rate
        sampling_rate = audio.frame_rate

        # Calculate the bit depth
        bit_depth = audio.sample_width * 8

        # Split into channels
        channels = audio.split_to_mono()

        # Extract samples from each channel
        channel_samples = [channel.get_array_of_samples() for channel in channels]

        # Print bitrate (for MP3 files)
        if audio.frame_rate and audio.frame_width:
            bitrate = audio.frame_rate * audio.frame_width * 8
            print("Bitrate:", bitrate, "bps")
        else:
            print(bitrate)

        # Print duration
        duration_seconds = len(audio) / 1000
        print("Duration:", duration_seconds, "seconds")

        # Print other metadata tags if available
        try:
            tags = audio.tags
            # for key, value in tags.items():
            #    print(f"{key}: {value}")
        except Exception as e:
            print(tags)

        f.write(f"This .series file displays the audio frames for {fn} [ frames: {total_frames}, length (seconds): {duration_seconds}, bitrate: {bitrate}, audio channels: {len(channels)}, resolution: {bit_depth}-bit PCM @ {sampling_rate} Hz sample rate, meta tags: {tags} ]\n")
        for frame_group in zip(*channel_samples):
            # print(f"{frame_group},\n")
            f.write(f"{frame_group},\n")
