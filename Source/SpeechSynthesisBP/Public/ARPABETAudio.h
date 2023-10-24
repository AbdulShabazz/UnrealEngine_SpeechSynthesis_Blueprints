// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "ARPABETAudio.generated.h"

/**
 * 
 */
UCLASS()
class SPEECHSYNTHESISBP_API UARPABETAudio : public UAudioComponent
{
	GENERATED_BODY()

	TArray<uint8> datastream_TArrayUInt8{};

public:

	struct Save
	{
		// Lossless Audio Formats

		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETAudio: SaveAsWAVFile" ))
		bool AsWAVFile(UPARAM(DisplayName = "filename_FText") const FText& filename_ConstFTextRef)
		{
			/*

			// Create a FWaveFormat object

			FWaveFormat WaveFormat_FWaveFormatFile{};
			WaveFormat_FWaveFormatFile.NumChannels = 2; // Stereo
			WaveFormat_FWaveFormatFile.SampleRate = 44100; // 44.1 kHz

			// Create a FByteBulk object

			FByteBulk ByteBulk_FByteBulkObj{};
			ByteBulk_FByteBulkObj.WaveFormat = WaveFormat_FWaveFormatFile;

			// Write the datastream_TArrayUInt8 to the FByteBulk object

			ByteBulk_FByteBulkObj.Write(datastream_TArrayUInt8.GetData(), datastream_TArrayUInt8.Num());

			// Save the FByteBulk object to disk

			FFileHandle fh_FileHandle{};
			fh_FileHandle.Open(filename_ConstFTextRef, EFileWrite::FILEWRITE_Append);
			ByteBulk_FByteBulkObj.Save(fh_FileHandle);
			fh_FileHandle.Close();

			*/
			return true;
		};

		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETAudio: SaveAsFLACFile" ))
		bool AsFLACFile(UPARAM(DisplayName = "filename_FText") const FText& filename_ConstFTextRef)
		{
			/*

			// Create a FLAC Encoder from the datastream_TArrayUInt8

			FFLACEncoder Encoder{};

			// Set the FLAC Encoder's parameters

			Encoder.SetChannels(2);
			Encoder.SetBitRate(192000);
			Encoder.SetSampleRate(44100);

			// Initialize the FLAC Encoder

			Encoder.Initialize();

			// Write the data to the FLAC Encoder

			FByteStream ByteStream_FByteStream{};

			for (const uint8& byte : datastream_TArrayUInt8)
			{
				ByteStream_FByteStream.Add(byte);
			}

			ByteStream_FByteStream.Seek(0);

			Encoder.WriteData(ByteStream_FByteStream);

			TArray<uint8> EncodedData_TArrayUInt8 = Encoder.GetEncodedData();

			// Flush the FLAC Encoder

			Encoder.Flush();

			// Close the FLAC Encoder

			Encoder.Close();

			// Save the FLAC Encoder to a file

			return FFileHelper::SaveArrayToFile(EncodedData_TArrayUInt8, *filename_ConstFTextRef);

			*/
			return false;
		};

		// Lossy Audio Formats

		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETAudio: SaveAsMP3File" ))
		bool AsMP3File(UPARAM(DisplayName = "filename_FText") const FText& filename_ConstFTextRef)
		{
			/*

			// Create a ByteReader from the datastream_TArrayUInt8

			FByteReader ByteReader(filename_ConstFTextRef);

			// Create an MP3Encoder from the ByteReader

			FMP3Encoder MP3Encoder(ByteReader);

			// Encode the MP3Encoder

			MP3Encoder.Encode();

			// Get the MP3Encoder's encoded data

			TArray<uint8> EncodedData_TArrayUInt8 = MP3Encoder.GetEncodedData();

			// Write the MP3Encoder to a file

			return FFileHelper::SaveArrayToFile(EncodedData_TArrayUInt8, filename_ConstFTextRef);

			*/
			return false;
		};

		bool AsAACFile()
		{
			return true;
		};
	};

	UFUNCTION(BlueprintCallable, meta = ( DisplayName = "PlayBack",
		Keywords = "TTS, SpeechSynthesis, TextToSpeech, voice, marytts, tacotron2" ),
		Category = "TextToSpeech")
	void PlayBack()
	{

	};
	
};
