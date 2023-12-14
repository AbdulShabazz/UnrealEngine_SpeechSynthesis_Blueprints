// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory.h>
#include <vector>
#include "ARPABETPhones.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpeechSynthesisAudioComponent.generated.h"

/**
 * 
 */
UCLASS()
class SPEECHSYNTHESISBP_API USpeechSynthesisAudioComponent : public UObject
{
	GENERATED_BODY()

	// forward declarations
	class UTTSVoice;

	// Strong Typing for Configuration Parameters
	using VoiceArray = TArray<UTTSVoice>;  // Only one voice for simplicity
	using ChannelCount = unsigned int;
	using SampleWidth = unsigned int;
	using FrameRate = unsigned int;

	class UARPABETAudio {
	public:

		//UPROPERTY(VisibleAnywhere, Category = "TextToSpeech")
		//TArray<TArray<float>> speechSample_TensorFloat32{};

		//UPROPERTY(VisibleAnywhere, Category = "TextToSpeech")
		std::vector<std::vector<float>> speechSample_TensorFloat32{};

		/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
		bool toWAVFile(const FText& filename_ConstFTextRef)
		{
			bool retval{};
			/*
			// Create a FWaveFormat object

			FWaveFormat WaveFormat_FWaveFormatFile{};
			WaveFormat_FWaveFormatFile.NumChannels = 2; // Stereo
			WaveFormat_FWaveFormatFile.SampleRate = 44100; // 44.1 kHz

			// Create a FByteBulk object

			FByteBulk ByteBulk_FByteBulkObj{};
			ByteBulk_FByteBulkObj.WaveFormat = WaveFormat_FWaveFormatFile;

			// Write the speechSample_TensorFloat32 to the FByteBulk object

			ByteBulk_FByteBulkObj.Write(speechSample_TensorFloat32.GetData(), speechSample_TensorFloat32.Num());

			// Save the FByteBulk object to disk

			FFileHandle fh_FileHandle{};
			fh_FileHandle.Open(filename_ConstFTextRef, EFileWrite::FILEWRITE_Append);
			retval = ByteBulk_FByteBulkObj.Save(fh_FileHandle);
			fh_FileHandle.Close();
			*/
			return retval;
		};

		/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
		bool toFLACFile(const FText& filename_ConstFTextRef)
		{
			bool retval{};
			/*
			// Create a FLAC Encoder from the speechSample_TensorFloat32

			FFLACEncoder Encoder{};

			// Set the FLAC Encoder's parameters

			Encoder.SetChannels(2);
			Encoder.SetBitRate(192000);
			Encoder.SetSampleRate(44100);

			// Initialize the FLAC Encoder

			Encoder.Initialize();

			// Write the data to the FLAC Encoder

			FByteStream ByteStream_FByteStream{};

			for (const uint8& byte : speechSample_TensorFloat32)
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

			retval = FFileHelper::SaveArrayToFile(EncodedData_TArrayUInt8, *filename_ConstFTextRef);
			*/
			return retval;
		};

		/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
		bool toVoiceFile(const FText& filename_ConstFStringRef)
		{
			bool retval{};

			/*

				VoiceFile.WavParams.SampleRateInHz_UInt64 = 44100;
				VoiceFile.WavParams.FrequencyInHz_UInt64T = 440;
				VoiceFile.WavParams.DurationInSeconds_UInt64T = 5;
				VoiceFile.WavParams.Amplitude_UIn64T = 16000;
				VoiceFile.WavParams.BitsPerSample_UInt64T = 32;

				// Populate VoiceFile.AudioData from the en vivo (WAV) file buffer or generated audio data

				TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&filename_ConstFStringRef);

				FJsonSerializer::Serialize(Writer, FJsonObjectConverter::UStructToJsonObject(FVoiceFile::StaticStruct(), &VoiceFile));

				FString SaveDirectory = FPaths::ProjectSavedDir();
				FString FileName = filename_ConstFStringRef; // "MyVoiceFile.voice";
				FString FilePath = SaveDirectory + "/" + FileName;

				FFileHelper::SaveStringToFile(OutputString, *FilePath);

			*/

			return retval;
		};

		// Lossy Audio Formats

		/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
		bool toMP3File(const FText& filename_ConstFTextRef)
		{
			bool retval{};
			/*
			// Create a ByteReader from the speechSample_TensorFloat32

			FByteReader ByteReader(filename_ConstFTextRef);

			// Create an MP3Encoder from the ByteReader

			FMP3Encoder MP3Encoder(ByteReader);

			// Encode the MP3Encoder

			MP3Encoder.Encode();

			// Get the MP3Encoder's encoded data

			TArray<uint8> EncodedData_TArrayUInt8 = MP3Encoder.GetEncodedData();

			// Write the MP3Encoder to a file

			retval = FFileHelper::SaveArrayToFile(EncodedData_TArrayUInt8, filename_ConstFTextRef);
			*/
			return retval;
		};

		/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
		bool toAACFile(const FText& filename_ConstFTextRef)
		{
			bool retval{};
			/*
			// Create a new USoundWave object

			TSharedPtr<USoundWave>() SoundWave_Ptr = NewObject<USoundWave>();
			SoundWave_Ptr->SetFormat(EAC_AAC);

			// Create a new FByteReader object

			TSharedPtr<FByteBulkData>() ByteBulkData_Ptr = NewObject< FByteBulkData>();
			ByteBulkData_Ptr->SetData(ByteStream);

			// Set the USoundWaves's asset to disk

			retval = SounWave_Ptr->SaveToFile(filename_ConstFTextRef);
			*/
			return retval;
		};

		/** Playback .voice data from USpeechSynthesisBPLibrary to loudspeakers */
		void PlayBack()
		{

		};

	};
	/*
    class oscillatorConfig {
    public:
        // Configuration details:
        double frequencyHz_Float64 = 0.0f;
        double amplitude_Float64 = 6.0f; // range: 0.0 to 12.5 (Approx. 125 dB SPL Max; 3.0f = whisper (30 dB SPL); 6.0f = avg. speaking volume (60 dB SPL))
        double pitch_Float64 = 0.0f; // range: -12.0 to 12.0
        double phase_Float64 = 0.0f; // range: 0.0 to 1.0
        double dutyCycle_Float64 = 0.0f; // range: 0.0 to 1.0
        double offset_Float64 = 0.0f; // range: -1.0 to 1.0
        double timeStep_Float64 = 0.0f; // range: 0.0 to 1.0
        double timeStepStart_Float64 = 0.0f;
        double timeStepEnd_Float64 = 0.0f;
        double timeStepInterval_Float64 = 0.0f;
        uint8_t sampleWidth_UInt8 = 4; // In bytes. 1 = 8-bit, 2 = 16-bit, 4 = 32-bit
        uint32_t sampleRateHz_UInt32 = 44100; // 44100, 48000, 88200, 96000, 176400, 192000, ...
        uint8_t channelCount_UInt8 = 2; // 1 = mono, 2 = stereo
        bool oscillatorConfigured_boolFlag = false;

        // ADSR Envelope details:
        class ADSR_ENVELOPE {
        public:
            double attack_Float64 = 0.0f; // range: 0.0 to 1.0
            double decay_Float64 = 0.0f; // range: 0.0 to 1.0
            double sustain_Float64 = 0.0f; // range: 0.0 to 1.0
            double release_Float64 = 0.0f; // range: 0.0 to 1.0
            bool ADSR_EnvelopeConfigured_boolFlag = false;
        } ADSR_envelope;
    };

    class FPhone {
    public:
        FPhone() {}
        ~FPhone() {}

        std::vector<float> getSpeechSampleTensorFloat32() const {
            return speechSample_TensorFloat32;
        }

        oscillatorConfig getOscillatorConfig() const {
            return m_oscillatorConfig;
        }

        void setOscillatorConfig(const oscillatorConfig& config) {
            m_oscillatorConfig = config;
        };

        std::vector<float> speechSample_TensorFloat32{};
        oscillatorConfig m_oscillatorConfig{};
    };
	*/
    class UTTSVoice {
    public:

        //UFUNCTION(BlueprintCallable, Category = "TextToSpeech")
        //static std::unique_ptr<UTTSVoice> Sara() {
        //    // ...initialization specific to Sara... //
        //    return std::make_unique<UTTSVoice>();
        //}

        void setPhone(const FPhone& phone)
        {
            m_currentPhone = phone;
        };

        void process()
        {
            // ...generate voice-specific samples... //
        };

        std::vector<float> getSpeechSampleTensorFloat32()
        {
            return m_currentPhone.getSpeechSampleTensorFloat32();
        };

        oscillatorConfig getOscillatorConfig()
        {
            return m_currentPhone.getOscillatorConfig();
        };

        void setOscillatorConfig(const oscillatorConfig& config)
        {
            m_currentPhone.setOscillatorConfig(config);
        };

        FPhone m_currentPhone{};
        oscillatorConfig m_oscillatorConfig;

    };

	/** Activates speech synthesis channel functionality: SetVoices */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: SetVoices" ))
	int SetVoices(UPARAM(DisplayName = "Voices") const int Voices)
	{
		return 0;
	}

	/** Activates speech synthesis channel functionality: SetChannelCount */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: SetChannelCount" ))
	int SetChannelCount(UPARAM(DisplayName = "ChannelCount (eg. 2)") const int inVal)
	{
		return 0;
	}

	/** Activates speech synthesis channel functionality: SetSampleWidth */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: SetSampleWidth" ))
	int SetSampleWidth(UPARAM(DisplayName = "SampleWidth (eg. 2)") const int inVal)
	{
		return 0;
	}

	/** Activates speech synthesis channel functionality: SetFrameRate */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: SetFrameRate" ))
	int SetFrameRate(UPARAM(DisplayName = "FrameRate (eg. 44100)") const int inVal)
	{
		return 0;
	}

	// re-speecher file-loading utilities //

	/** Load .WAV data for USpeechSynthesisBPLibrary from persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETAudio: fromWAVFile" ))
	bool fromWAVFile(UPARAM(DisplayName = "filename") const FText& filename_ConstFTextRef)
	{
		bool retval{};
		/*
		// Create a FWaveFormat object

		FWaveFormat WaveFormat_FWaveFormatFile{};
		WaveFormat_FWaveFormatFile.NumChannels = 2; // Stereo
		WaveFormat_FWaveFormatFile.SampleRate = 44100; // 44.1 kHz

		// Create a FByteBulk object

		FByteBulk ByteBulk_FByteBulkObj{};
		ByteBulk_FByteBulkObj.WaveFormat = WaveFormat_FWaveFormatFile;

		// Write the speechSample_TensorFloat32 to the FByteBulk object

		ByteBulk_FByteBulkObj.Write(speechSample_TensorFloat32.GetData(), speechSample_TensorFloat32.Num());

		// Save the FByteBulk object to disk

		FFileHandle fh_FileHandle{};
		fh_FileHandle.Open(filename_ConstFTextRef, EFileWrite::FILEWRITE_Append);
		retval = ByteBulk_FByteBulkObj.Save(fh_FileHandle);
		fh_FileHandle.Close();
		*/
		return retval;
	};

	/** Load .FLAC data for USpeechSynthesisBPLibrary from persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "Speech Synthesis: fromFLACFile" ))
	bool fromFLACFile(UPARAM(DisplayName = "filename") const FText& filename_ConstFTextRef)
	{
		bool retval{};
		/*
		// Create a FLAC Encoder from the speechSample_TensorFloat32

		FFLACEncoder Encoder{};

		// Set the FLAC Encoder's parameters

		Encoder.SetChannels(2);
		Encoder.SetBitRate(192000);
		Encoder.SetSampleRate(44100);

		// Initialize the FLAC Encoder

		Encoder.Initialize();

		// Write the data to the FLAC Encoder

		FByteStream ByteStream_FByteStream{};

		for (const uint8& byte : speechSample_TensorFloat32)
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

		retval = FFileHelper::SaveArrayToFile(EncodedData_TArrayUInt8, *filename_ConstFTextRef);
		*/
		return retval;
	};

	/** Load .voice data for USpeechSynthesisBPLibrary from persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "Speech Synthesis: fromVoiceFile" ))
	bool fromVoiceFile(UPARAM(DisplayName = "filename") const FText& filename_ConstFStringRef)
	{
		bool retval{};

		/*

			VoiceFile.WavParams.SampleRateInHz_UInt64 = 44100;
			VoiceFile.WavParams.FrequencyInHz_UInt64T = 440;
			VoiceFile.WavParams.DurationInSeconds_UInt64T = 5;
			VoiceFile.WavParams.Amplitude_UIn64T = 16000;
			VoiceFile.WavParams.BitsPerSample_UInt64T = 32;

			// Populate VoiceFile.AudioData from the en vivo (WAV) file buffer or generated audio data

			TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&filename_ConstFStringRef);

			FJsonSerializer::Serialize(Writer, FJsonObjectConverter::UStructToJsonObject(FVoiceFile::StaticStruct(), &VoiceFile));

			FString SaveDirectory = FPaths::ProjectSavedDir();
			FString FileName = filename_ConstFStringRef; // "MyVoiceFile.voice";
			FString FilePath = SaveDirectory + "/" + FileName;

			FFileHelper::SaveStringToFile(OutputString, *FilePath);

		*/

		return retval;
	};

	// Lossy Audio Formats

	/** Load .MP3 voice data for USpeechSynthesisBPLibrary from persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "Speech Synthesis: fromMP3File" ))
	bool fromMP3File(UPARAM(DisplayName = "filename") const FText& filename_ConstFTextRef)
	{
		bool retval{};
		/*
		// Create a ByteReader from the speechSample_TensorFloat32

		FByteReader ByteReader(filename_ConstFTextRef);

		// Create an MP3Encoder from the ByteReader

		FMP3Encoder MP3Encoder(ByteReader);

		// Encode the MP3Encoder

		MP3Encoder.Encode();

		// Get the MP3Encoder's encoded data

		TArray<uint8> EncodedData_TArrayUInt8 = MP3Encoder.GetEncodedData();

		// Write the MP3Encoder to a file

		retval = FFileHelper::SaveArrayToFile(EncodedData_TArrayUInt8, filename_ConstFTextRef);
		*/
		return retval;
	};

	/** Load .AAC voice data for USpeechSynthesisBPLibrary from persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "Speech Synthesis: fromAACFile" ))
	bool fromAACFile(UPARAM(DisplayName = "filename") const FText& filename_ConstFTextRef)
	{
		bool retval{};
		/*
		// Create a new USoundWave object

		TSharedPtr<USoundWave>() SoundWave_Ptr = NewObject<USoundWave>();
		SoundWave_Ptr->SetFormat(EAC_AAC);

		// Create a new FByteReader object

		TSharedPtr<FByteBulkData>() ByteBulkData_Ptr = NewObject< FByteBulkData>();
		ByteBulkData_Ptr->SetData(ByteStream);

		// Set the USoundWaves's asset to disk

		retval = SounWave_Ptr->SaveToFile(filename_ConstFTextRef);
		*/
		return retval;
	};

	/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETAudio: toWAVFile" ))
	bool toWAVFile(UPARAM(DisplayName = "filename") const FText& filename_ConstFTextRef)
	{
		bool retval{};
		/*
		// Create a FWaveFormat object

		FWaveFormat WaveFormat_FWaveFormatFile{};
		WaveFormat_FWaveFormatFile.NumChannels = 2; // Stereo
		WaveFormat_FWaveFormatFile.SampleRate = 44100; // 44.1 kHz

		// Create a FByteBulk object

		FByteBulk ByteBulk_FByteBulkObj{};
		ByteBulk_FByteBulkObj.WaveFormat = WaveFormat_FWaveFormatFile;

		// Write the speechSample_TensorFloat32 to the FByteBulk object

		ByteBulk_FByteBulkObj.Write(speechSample_TensorFloat32.GetData(), speechSample_TensorFloat32.Num());

		// Save the FByteBulk object to disk

		FFileHandle fh_FileHandle{};
		fh_FileHandle.Open(filename_ConstFTextRef, EFileWrite::FILEWRITE_Append);
		retval = ByteBulk_FByteBulkObj.Save(fh_FileHandle);
		fh_FileHandle.Close();
		*/
		return retval;
	};

	/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETAudio: toFLACFile" ))
	bool toFLACFile(UPARAM(DisplayName = "filename") const FText& filename_ConstFTextRef)
	{
		bool retval{};
		/*
		// Create a FLAC Encoder from the speechSample_TensorFloat32

		FFLACEncoder Encoder{};

		// Set the FLAC Encoder's parameters

		Encoder.SetChannels(2);
		Encoder.SetBitRate(192000);
		Encoder.SetSampleRate(44100);

		// Initialize the FLAC Encoder

		Encoder.Initialize();

		// Write the data to the FLAC Encoder

		FByteStream ByteStream_FByteStream{};

		for (const uint8& byte : speechSample_TensorFloat32)
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

		retval = FFileHelper::SaveArrayToFile(EncodedData_TArrayUInt8, *filename_ConstFTextRef);
		*/
		return retval;
	};

	/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETAudio: toVoiceFile" ))
	bool toVoiceFile(UPARAM(DisplayName = "filename") const FText& filename_ConstFStringRef)
	{
		bool retval{};

		/*

			VoiceFile.WavParams.SampleRateInHz_UInt64 = 44100;
			VoiceFile.WavParams.FrequencyInHz_UInt64T = 440;
			VoiceFile.WavParams.DurationInSeconds_UInt64T = 5;
			VoiceFile.WavParams.Amplitude_UIn64T = 16000;
			VoiceFile.WavParams.BitsPerSample_UInt64T = 32;

			// Populate VoiceFile.AudioData from the en vivo (WAV) file buffer or generated audio data

			TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&filename_ConstFStringRef);

			FJsonSerializer::Serialize(Writer, FJsonObjectConverter::UStructToJsonObject(FVoiceFile::StaticStruct(), &VoiceFile));

			FString SaveDirectory = FPaths::ProjectSavedDir();
			FString FileName = filename_ConstFStringRef; // "MyVoiceFile.voice";
			FString FilePath = SaveDirectory + "/" + FileName;

			FFileHelper::SaveStringToFile(OutputString, *FilePath);

		*/

		return retval;
	};

	// Lossy Audio Formats

	/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETAudio: toMP3File" ))
	bool toMP3File(UPARAM(DisplayName = "filename") const FText& filename_ConstFTextRef)
	{
		bool retval{};
		/*
		// Create a ByteReader from the speechSample_TensorFloat32

		FByteReader ByteReader(filename_ConstFTextRef);

		// Create an MP3Encoder from the ByteReader

		FMP3Encoder MP3Encoder(ByteReader);

		// Encode the MP3Encoder

		MP3Encoder.Encode();

		// Get the MP3Encoder's encoded data

		TArray<uint8> EncodedData_TArrayUInt8 = MP3Encoder.GetEncodedData();

		// Write the MP3Encoder to a file

		retval = FFileHelper::SaveArrayToFile(EncodedData_TArrayUInt8, filename_ConstFTextRef);
		*/
		return retval;
	};

	/** Save .voice data from USpeechSynthesisBPLibrary to persistent disk */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETAudio: toAACFile" ))
	bool toAACFile(UPARAM(DisplayName = "filename") const FText& filename_ConstFTextRef)
	{
		bool retval{};
		/*
		// Create a new USoundWave object

		TSharedPtr<USoundWave>() SoundWave_Ptr = NewObject<USoundWave>();
		SoundWave_Ptr->SetFormat(EAC_AAC);

		// Create a new FByteReader object

		TSharedPtr<FByteBulkData>() ByteBulkData_Ptr = NewObject< FByteBulkData>();
		ByteBulkData_Ptr->SetData(ByteStream);

		// Set the USoundWaves's asset to disk

		retval = SounWave_Ptr->SaveToFile(filename_ConstFTextRef);
		*/
		return retval;
	};

	/** Playback .voice data from USpeechSynthesisBPLibrary to loudspeakers */
	UFUNCTION(BlueprintCallable, meta = ( DisplayName = "PlayBack",
		Keywords = "TTS, SpeechSynthesis, TextToSpeech, voice, marytts, tacotron2" ),
		Category = "TextToSpeech")
	void PlayBack()
	{

	};

	// Other member functions:

	// vowels > front > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'IY' ( Beat ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, IY", DisplayName = "ARPABETSpeechSynthesis: vowels > front > IY ( Beat )" ))
	void ARPABETSpeechSynthesis_IY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_IY());
	};

	/** Activates speech synthesis channel phoneme functionality 'IH' ( Bit ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, IH", DisplayName = "ARPABETSpeechSynthesis: vowels > front > IH ( Bit )" ))
	void ARPABETSpeechSynthesis_IH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_IH());
	};

	/** Activates speech synthesis channel phoneme functionality 'EH' ( Bet ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EH", DisplayName = "ARPABETSpeechSynthesis: vowels > front > EH ( Bet )" ))
	void ARPABETSpeechSynthesis_EH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EH());
	};

	/** Activates speech synthesis channel phoneme functionality 'EY' ( Bait ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EY", DisplayName = "ARPABETSpeechSynthesis: vowels > front > EY ( Bait )" ))
	void ARPABETSpeechSynthesis_EY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EY());
	};

	/** Activates speech synthesis channel phoneme functionality 'AE' ( Bat ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AE", DisplayName = "ARPABETSpeechSynthesis: vowels > front > AE ( Bat )" ))
	void ARPABETSpeechSynthesis_AE(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AE());
	};

	// vowels > back > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'AA' ( Bot ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AA", DisplayName = "ARPABETSpeechSynthesis: vowels > back > AA ( Bot )" ))
	void ARPABETSpeechSynthesis_AA(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AA());
	};

	/** Activates speech synthesis channel phoneme functionality 'AO' ( Bought ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AO", DisplayName = "ARPABETSpeechSynthesis: vowels > back > AO ( Bought )" ))
	void ARPABETSpeechSynthesis_AO(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AO());
	};

	/** Activates speech synthesis channel phoneme functionality 'OW' ( Boat ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, OW", DisplayName = "ARPABETSpeechSynthesis: vowels > back > OW ( Boat )" ))
	void ARPABETSpeechSynthesis_OW(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_OW());
	};

	/** Activates speech synthesis channel phoneme functionality 'UH' ( Book ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, UH", DisplayName = "ARPABETSpeechSynthesis: vowels > back > UH ( Book )" ))
	void ARPABETSpeechSynthesis_UH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_UH());
	};

	/** Activates speech synthesis channel phoneme functionality 'UW' ( Boot ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, UW", DisplayName = "ARPABETSpeechSynthesis: vowels > back > UW ( Boot )" ))
	void ARPABETSpeechSynthesis_UW(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_UW());
	};

	// vowels > mid > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'ER' ( Bird ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, ER", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > ER ( Bird )" ))
	void ARPABETSpeechSynthesis_ER(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_ER());
	};

	/** Activates speech synthesis channel phoneme functionality 'AX' ( About ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AX", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AX ( About )" ))
	void ARPABETSpeechSynthesis_AX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AX());
	};

	/** Activates speech synthesis channel phoneme functionality 'AH' ( Butt ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AH", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AH ( Butt )" ))
	void ARPABETSpeechSynthesis_AH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AH());
	};

	// vowels > diphthongs > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'AY (Bite)' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AY", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AY ( Bite )" ))
	void ARPABETSpeechSynthesis_AY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AY());
	};

	/** Activates speech synthesis channel phoneme functionality 'AW' ( Bout ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AW", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AW ( Bout )" ))
	void ARPABETSpeechSynthesis_AW(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AW());
	};

	/** Activates speech synthesis channel phoneme functionality 'OY' ( Boy ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, DY", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > OY ( Boy )" ))
	void ARPABETSpeechSynthesis_OY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_OY());
	};

	/** Activates speech synthesis channel phoneme functionality 'IX' ( Rabbit ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, IX", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > IX ( Rabbit )" ))
	void ARPABETSpeechSynthesis_IX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_IX());
	};

	// stopConsonants > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'B' ( Beat ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > B ( Beat )" ))
	void ARPABETSpeechSynthesis_B(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_B());
	};

	/** Activates speech synthesis channel phoneme functionality 'D' ( Deep ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > D ( Deep )" ))
	void ARPABETSpeechSynthesis_D(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_D());
	};

	/** Activates speech synthesis channel phoneme functionality 'G' ( Go ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > G ( Go )" ))
	void ARPABETSpeechSynthesis_G(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_G());
	};

	// stopConsonants > voiced > > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'P' ( Pea ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > P ( Pea )" ))
	void ARPABETSpeechSynthesis_P(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_P());
	};

	/** Activates speech synthesis channel phoneme functionality 'T' ( Tea ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > T ( Tea )" ))
	void ARPABETSpeechSynthesis_T(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_T());
	};

	/** Activates speech synthesis channel phoneme functionality 'K' ( Kick ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > K ( Kick )" ))
	void ARPABETSpeechSynthesis_K(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_K());
	};

	// fricatives > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'V' ( Very ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > V ( Very )" ))
	void ARPABETSpeechSynthesis_V(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_V());
	};

	/** Activates speech synthesis channel phoneme functionality 'DH' ( Then ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, DH", DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > DH ( Then )" ))
	void ARPABETSpeechSynthesis_DH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_DH());
	};

	// fricatives > unvoiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'F' ( Five ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > F ( Five )" ))
	void ARPABETSpeechSynthesis_F(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_F());
	};

	/** Activates speech synthesis channel phoneme functionality 'TH' ( Think ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, TH", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > TH ( Think )" ))
	void ARPABETSpeechSynthesis_TH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_TH());
	};

	/** Activates speech synthesis channel phoneme functionality 'S' ( See ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > S ( See )" ))
	void ARPABETSpeechSynthesis_S(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_S());
	};

	/** Activates speech synthesis channel phoneme functionality 'SH' ( She ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, SH", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > SH ( She )" ))
	void ARPABETSpeechSynthesis_SH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_SH());
	};

	// semivowels > liquid > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'L' ( Love ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > L ( Love )" ))
	void ARPABETSpeechSynthesis_L(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_L());
	};

	/** Activates speech synthesis channel phoneme functionality 'EL' ( Bottle ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EL", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > EL ( Bottle )" ))
	void ARPABETSpeechSynthesis_EL(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EL());
	};

	/** Activates speech synthesis channel phoneme functionality 'R' ( Red ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > R ( Red )" ))
	void ARPABETSpeechSynthesis_R(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_R());
	};

	// semivowels > glides > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'W' ( Water ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > W ( Water )" ))
	void ARPABETSpeechSynthesis_W(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_W());
	};

	/** Activates speech synthesis channel phoneme functionality 'WH' ( What ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, WH", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > WH ( What )" ))
	void ARPABETSpeechSynthesis_WH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_WH());
	};

	/** Activates speech synthesis channel phoneme functionality 'Y' ( Yes ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > Y ( Yes )" ))
	void ARPABETSpeechSynthesis_Y(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Y());
	};

	// nasals > non vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'M' ( More ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > M ( More )" ))
	void ARPABETSpeechSynthesis_M(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_M());
	};

	/** Activates speech synthesis channel phoneme functionality 'N' ( Now ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > N ( Now )" ))
	void ARPABETSpeechSynthesis_N(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_N());
	};

	/** Activates speech synthesis channel phoneme functionality 'NX' ( Sing ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, NX", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Sing )" ))
	void ARPABETSpeechSynthesis_NX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_NX());
	};

	/** Activates speech synthesis channel phoneme functionality 'NG' ( Sing ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, NG", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Sing )" ))
	void ARPABETSpeechSynthesis_NG(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_NG());
	};

	// nasals > vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'EM' ( Button ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EM", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EM ( Button )" ))
	void ARPABETSpeechSynthesis_EM(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EM());
	};

	/** Activates speech synthesis channel phoneme functionality 'EN' ( Son ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech,EN", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EN ( Son )" ))
	void ARPABETSpeechSynthesis_EN(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EN());
	};

	// affricates > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'CH' ( Church ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, CH", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > CH ( Church )" ))
	void ARPABETSpeechSynthesis_CH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_CH());
	};

	/** Activates speech synthesis channel phoneme functionality 'JH' ( Jump ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, JH", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > JH ( Jump )" ))
	void ARPABETSpeechSynthesis_JH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_JH());
	};

	// other > whisper > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'HH' ( How ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > whisper > HH ( How )" ))
	void ARPABETSpeechSynthesis_HH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_HH());
	};

	// other > vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'DX' ( Riddle ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, DX", DisplayName = "ARPABETSpeechSynthesis: other > vocalic > DX ( Riddle )" ))
	void ARPABETSpeechSynthesis_DX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_DX());
	};

	// other > pause or glottal_stop > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'Q' ( Question ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > pause or glottal_stop > Q ( Question )" ))
	void ARPABETSpeechSynthesis_Q(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Q());
	};

	// Setup and Activation APIs

	/** Activates speech synthesis channel functionality 'Voice' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, Voice", DisplayName = "ARPABETSpeechSynthesis: Voice [compile]" ))
	int /*UARPABETAudio*/ Voice()
	{

		for (const auto& nextPhone : speechSample_FPhoneVec) {
			currentPhone.setPhone(nextPhone);
			currentPhone.process();
			m_UARPABETAudio.speechSample_TensorFloat32.push_back(currentPhone.getSpeechSampleTensorFloat32());
		}

		// Finalize the last phone
		currentPhone.process();
		m_UARPABETAudio.speechSample_TensorFloat32.push_back(currentPhone.getSpeechSampleTensorFloat32());

		return 1; // m_UARPABETAudio; //
	};

	/** Activates speech synthesis channel functionality 'Init' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, Init", DisplayName = "ARPABETSpeechSynthesis: Init [Invoke]" ))
	bool Init(
		UPARAM(DisplayName = "Voices") const int Voices,
		UPARAM(DisplayName = "FProsodyCurve") const int& ProsodyCurve_ConstObjArray,
		UPARAM(DisplayName = "FDurationCurve") const int& DurationCurve_ConstObjArray,
		UPARAM(DisplayName = "FEmotiveCurve") const int& EmotiveCurve_ConstObjArray)
	{
		return true;
	};

	// Other > non verbals > ARPABET UV

	/** Activates speech synthesis channel phoneme functionality 'Babble' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Babble" ))
	void ARPABETSpeechSynthesis_Babble(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Babble());
	};

	/** Activates speech synthesis channel phoneme functionality 'Bang' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Bang" ))
	void ARPABETSpeechSynthesis_Bang(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Bang());
	};

	/** Activates speech synthesis channel phoneme functionality 'Bark' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Bark" ))
	void ARPABETSpeechSynthesis_Bark(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Bark());
	};

	/** Activates speech synthesis channel phoneme functionality 'Bawl' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Bawl" ))
	void ARPABETSpeechSynthesis_Bawl(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Bawl());
	};

	/** Activates speech synthesis channel phoneme functionality 'Beep' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Beep" ))
	void ARPABETSpeechSynthesis_Beep(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Beep());
	};

	/** Activates speech synthesis channel phoneme functionality 'Bellow' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Bellow" ))
	void ARPABETSpeechSynthesis_Bellow(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Bellow());
	};

	/** Activates speech synthesis channel phoneme functionality 'Blare' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Blare" ))
	void ARPABETSpeechSynthesis_Blare(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Blare());
	};

	/** Activates speech synthesis channel phoneme functionality 'Breathe_Heavily' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Breathe_Heavily" ))
	void ARPABETSpeechSynthesis_Breathe_heavily(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Breathe_heavily());
	};

	/** Activates speech synthesis channel phoneme functionality 'Bruxism' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Bruxism" ))
	void ARPABETSpeechSynthesis_Bruxism(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Bruxism());
	};

	/** Activates speech synthesis channel phoneme functionality 'Burp' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Burp" ))
	void ARPABETSpeechSynthesis_Burp(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Burp());
	};

	/** Activates speech synthesis channel phoneme functionality 'Buzz' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Buzz" ))
	void ARPABETSpeechSynthesis_Buzz(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Buzz());
	};

	/** Activates speech synthesis channel phoneme functionality 'Cackle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Cackle" ))
	void ARPABETSpeechSynthesis_Cackle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Cackle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Chew' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Chew" ))
	void ARPABETSpeechSynthesis_Chew(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Chew());
	};

	/** Activates speech synthesis channel phoneme functionality 'Chime' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Chime" ))
	void ARPABETSpeechSynthesis_Chime(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Chime());
	};

	/** Activates speech synthesis channel phoneme functionality 'Chime_in' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Chime_in" ))
	void ARPABETSpeechSynthesis_Chime_in(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Chime_in());
	};

	/** Activates speech synthesis channel phoneme functionality 'Chirp' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Chirp" ))
	void ARPABETSpeechSynthesis_Chirp(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Chirp());
	};

	/** Activates speech synthesis channel phoneme functionality 'Chortle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Chortle" ))
	void ARPABETSpeechSynthesis_Chortle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Chortle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Chuckle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Chuckle" ))
	void ARPABETSpeechSynthesis_Chuckle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Chuckle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Clap' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Clap" ))
	void ARPABETSpeechSynthesis_Clap(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Clap());
	};

	/** Activates speech synthesis channel phoneme functionality 'Clear_Throat' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Clear_Throat" ))
	void ARPABETSpeechSynthesis_Clear_throat(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Clear_throat());
	};

	/** Activates speech synthesis channel phoneme functionality 'Click' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Click" ))
	void ARPABETSpeechSynthesis_Click(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Click());
	};

	/** Activates speech synthesis channel phoneme functionality 'Clink' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Clink" ))
	void ARPABETSpeechSynthesis_Clink(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Clink());
	};

	/** Activates speech synthesis channel phoneme functionality 'Cluck' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Cluck" ))
	void ARPABETSpeechSynthesis_Cluck(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Cluck());
	};

	/** Activates speech synthesis channel phoneme functionality 'Cough' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Cough" ))
	void ARPABETSpeechSynthesis_Cough(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Cough());
	};

	/** Activates speech synthesis channel phoneme functionality 'Crack' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Crack" ))
	void ARPABETSpeechSynthesis_Crack(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Crack());
	};

	/** Activates speech synthesis channel phoneme functionality 'Croak' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Croak" ))
	void ARPABETSpeechSynthesis_Croak(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Croak());
	};

	/** Activates speech synthesis channel phoneme functionality 'Crunch' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Crunch" ))
	void ARPABETSpeechSynthesis_Crunch(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Crunch());
	};

	/** Activates speech synthesis channel phoneme functionality 'Cry' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Cry" ))
	void ARPABETSpeechSynthesis_Cry(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Cry());
	};

	/** Activates speech synthesis channel phoneme functionality 'Drone' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Drone" ))
	void ARPABETSpeechSynthesis_Drone(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Drone());
	};

	/** Activates speech synthesis channel phoneme functionality 'Exclaim' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Exclaim" ))
	void ARPABETSpeechSynthesis_Exclaim(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Exclaim());
	};

	/** Activates speech synthesis channel phoneme functionality 'Fizz' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Fizz" ))
	void ARPABETSpeechSynthesis_Fizz(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Fizz());
	};

	/** Activates speech synthesis channel phoneme functionality 'Gasp' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Gasp" ))
	void ARPABETSpeechSynthesis_Gasp(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Gasp());
	};

	/** Activates speech synthesis channel phoneme functionality 'Giggle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Giggle" ))
	void ARPABETSpeechSynthesis_Giggle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Giggle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Gnash' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Gnash" ))
	void ARPABETSpeechSynthesis_Gnash(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Gnash());
	};

	/** Activates speech synthesis channel phoneme functionality 'Groan' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Groan" ))
	void ARPABETSpeechSynthesis_Groan(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Groan());
	};

	/** Activates speech synthesis channel phoneme functionality 'Grovel' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Grovel" ))
	void ARPABETSpeechSynthesis_Grovel(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Grovel());
	};

	/** Activates speech synthesis channel phoneme functionality 'Growl' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Growl" ))
	void ARPABETSpeechSynthesis_Growl(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Growl());
	};

	/** Activates speech synthesis channel phoneme functionality 'Grunt' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Grunt" ))
	void ARPABETSpeechSynthesis_Grunt(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Grunt());
	};

	/** Activates speech synthesis channel phoneme functionality 'Guffaw' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Guffaw" ))
	void ARPABETSpeechSynthesis_Guffaw(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Guffaw());
	};

	/** Activates speech synthesis channel phoneme functionality 'Gurgle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Gurgle" ))
	void ARPABETSpeechSynthesis_Gurgle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Gurgle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Hiccup' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Hiccup" ))
	void ARPABETSpeechSynthesis_Hiccup(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Hiccup());
	};

	/** Activates speech synthesis channel phoneme functionality 'Honk' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Honk" ))
	void ARPABETSpeechSynthesis_Honk(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Honk());
	};

	/** Activates speech synthesis channel phoneme functionality 'Howl' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Howl" ))
	void ARPABETSpeechSynthesis_Howl(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Howl());
	};

	/** Activates speech synthesis channel phoneme functionality 'Huff' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Huff" ))
	void ARPABETSpeechSynthesis_Huff(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Huff());
	};

	/** Activates speech synthesis channel phoneme functionality 'Hum' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Hum" ))
	void ARPABETSpeechSynthesis_Hum(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Hum());
	};

	/** Activates speech synthesis channel phoneme functionality 'Laugh' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Laugh" ))
	void ARPABETSpeechSynthesis_Laugh(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Laugh());
	};

	/** Activates speech synthesis channel phoneme functionality 'Moan' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Moan" ))
	void ARPABETSpeechSynthesis_Moan(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Moan());
	};

	/** Activates speech synthesis channel phoneme functionality 'Mumble' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Mumble" ))
	void ARPABETSpeechSynthesis_Mumble(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Mumble());
	};

	/** Activates speech synthesis channel phoneme functionality 'Murmur' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Murmur" ))
	void ARPABETSpeechSynthesis_Murmur(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Murmur());
	};

	/** Activates speech synthesis channel phoneme functionality 'Mutter' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Mutter" ))
	void ARPABETSpeechSynthesis_Mutter(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Mutter());
	};

	/** Activates speech synthesis channel phoneme functionality 'Pant' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Pant" ))
	void ARPABETSpeechSynthesis_Pant(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Pant());
	};

	/** Activates speech synthesis channel phoneme functionality 'Peal' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Peal" ))
	void ARPABETSpeechSynthesis_Peal(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Peal());
	};

	/** Activates speech synthesis channel phoneme functionality 'Pop' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Pop" ))
	void ARPABETSpeechSynthesis_Pop(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Pop());
	};

	/** Activates speech synthesis channel phoneme functionality 'Purr' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Purr" ))
	void ARPABETSpeechSynthesis_Purr(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Purr());
	};

	/** Activates speech synthesis channel phoneme functionality 'Rasp' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Rasp" ))
	void ARPABETSpeechSynthesis_Rasp(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Rasp());
	};

	/** Activates speech synthesis channel phoneme functionality 'Raspberries' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Raspberries" ))
	void ARPABETSpeechSynthesis_Raspberries(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Raspberries());
	};

	/** Activates speech synthesis channel phoneme functionality 'Rattle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Rattle" ))
	void ARPABETSpeechSynthesis_Rattle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Rattle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Roar' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Roar" ))
	void ARPABETSpeechSynthesis_Roar(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Roar());
	};

	/** Activates speech synthesis channel phoneme functionality 'Rustle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Rustle" ))
	void ARPABETSpeechSynthesis_Rustle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Rustle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Screech' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Screech" ))
	void ARPABETSpeechSynthesis_Screech(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Screech());
	};

	/** Activates speech synthesis channel phoneme functionality 'Shout' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Shout" ))
	void ARPABETSpeechSynthesis_Shout(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Shout());
	};

	/** Activates speech synthesis channel phoneme functionality 'Shriek' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Shriek" ))
	void ARPABETSpeechSynthesis_Shriek(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Shriek());
	};

	/** Activates speech synthesis channel phoneme functionality 'Sigh' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Sigh" ))
	void ARPABETSpeechSynthesis_Sigh(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Sigh());
	};

	/** Activates speech synthesis channel phoneme functionality 'Skeptical_Sigh_or_Hum' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Skeptical_Sigh_or_Hum" ))
	void ARPABETSpeechSynthesis_Skeptical_sigh_or_hum(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Skeptical_sigh_or_hum());
	};

	/** Activates speech synthesis channel phoneme functionality 'Slam' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Slam" ))
	void ARPABETSpeechSynthesis_Slam(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Slam());
	};

	/** Activates speech synthesis channel phoneme functionality 'Slap' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Slap" ))
	void ARPABETSpeechSynthesis_Slap(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Slap());
	};

	/** Activates speech synthesis channel phoneme functionality 'Slurp' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Slurp" ))
	void ARPABETSpeechSynthesis_Slurp(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Slurp());
	};

	/** Activates speech synthesis channel phoneme functionality 'Smack' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Smack" ))
	void ARPABETSpeechSynthesis_Smack(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Smack());
	};

	/** Activates speech synthesis channel phoneme functionality 'Snarl' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Snarl" ))
	void ARPABETSpeechSynthesis_Snarl(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Snarl());
	};

	/** Activates speech synthesis channel phoneme functionality 'Sneer' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Sneer" ))
	void ARPABETSpeechSynthesis_Sneer(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Sneer());
	};

	/** Activates speech synthesis channel phoneme functionality 'Sneeze' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Sneeze" ))
	void ARPABETSpeechSynthesis_Sneeze(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Sneeze());
	};

	/** Activates speech synthesis channel phoneme functionality 'Snicker' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Snicker" ))
	void ARPABETSpeechSynthesis_Snicker(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Snicker());
	};

	/** Activates speech synthesis channel phoneme functionality 'Sniff' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Sniff" ))
	void ARPABETSpeechSynthesis_Sniff(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Sniff());
	};

	/** Activates speech synthesis channel phoneme functionality 'Sniffle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Sniffle" ))
	void ARPABETSpeechSynthesis_Sniffle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Sniffle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Snore' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Snore" ))
	void ARPABETSpeechSynthesis_Snore(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Snore());
	};

	/** Activates speech synthesis channel phoneme functionality 'Snort' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Snort" ))
	void ARPABETSpeechSynthesis_Snort(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Snort());
	};

	/** Activates speech synthesis channel phoneme functionality 'Sob' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Sob" ))
	void ARPABETSpeechSynthesis_Sob(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Sob());
	};

	/** Activates speech synthesis channel phoneme functionality 'Spit' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Spit" ))
	void ARPABETSpeechSynthesis_Spit(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Spit());
	};

	/** Activates speech synthesis channel phoneme functionality 'Splutter' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Splutter" ))
	void ARPABETSpeechSynthesis_Splutter(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Splutter());
	};

	/** Activates speech synthesis channel phoneme functionality 'Sputter' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Sputter" ))
	void ARPABETSpeechSynthesis_Sputter(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Sputter());
	};

	/** Activates speech synthesis channel phoneme functionality 'Squawk' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Squawk" ))
	void ARPABETSpeechSynthesis_Squawk(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Squawk());
	};

	/** Activates speech synthesis channel phoneme functionality 'Squeak' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Squeak" ))
	void ARPABETSpeechSynthesis_Squeak(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Squeak());
	};

	/** Activates speech synthesis channel phoneme functionality 'Squeal' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Squeal" ))
	void ARPABETSpeechSynthesis_Squeal(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Squeal());
	};

	/** Activates speech synthesis channel phoneme functionality 'Stammer' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Stammer" ))
	void ARPABETSpeechSynthesis_Stammer(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Stammer());
	};

	/** Activates speech synthesis channel phoneme functionality 'Stamp' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Stamp" ))
	void ARPABETSpeechSynthesis_Stamp(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Stamp());
	};

	/** Activates speech synthesis channel phoneme functionality 'Swallow' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Swallow" ))
	void ARPABETSpeechSynthesis_Swallow(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Swallow());
	};

	/** Activates speech synthesis channel phoneme functionality 'Thump' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Thump" ))
	void ARPABETSpeechSynthesis_Thump(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Thump());
	};

	/** Activates speech synthesis channel phoneme functionality 'Tick' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Tick" ))
	void ARPABETSpeechSynthesis_Tick(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Tick());
	};

	/** Activates speech synthesis channel phoneme functionality 'Tinkle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Tinkle" ))
	void ARPABETSpeechSynthesis_Tinkle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Tinkle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Titter' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Titter" ))
	void ARPABETSpeechSynthesis_Titter(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Titter());
	};

	/** Activates speech synthesis channel phoneme functionality 'Toot' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Toot" ))
	void ARPABETSpeechSynthesis_Toot(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Toot());
	};

	/** Activates speech synthesis channel phoneme functionality 'Trill' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Trill" ))
	void ARPABETSpeechSynthesis_Trill(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Trill());
	};

	/** Activates speech synthesis channel phoneme functionality 'Wail' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Wail" ))
	void ARPABETSpeechSynthesis_Wail(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Wail());
	};

	/** Activates speech synthesis channel phoneme functionality 'Warble' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Warble" ))
	void ARPABETSpeechSynthesis_Warble(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Warble());
	};

	/** Activates speech synthesis channel phoneme functionality 'Wheeze' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Wheeze" ))
	void ARPABETSpeechSynthesis_Wheeze(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Wheeze());
	};

	/** Activates speech synthesis channel phoneme functionality 'Whimper' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Whimper" ))
	void ARPABETSpeechSynthesis_Whimper(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Whimper());
	};

	/** Activates speech synthesis channel phoneme functionality 'Whine' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Whine" ))
	void ARPABETSpeechSynthesis_Whine(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Whine());
	};

	/** Activates speech synthesis channel phoneme functionality 'Whisper' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Whisper" ))
	void ARPABETSpeechSynthesis_Whisper(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Whisper());
	};

	/** Activates speech synthesis channel phoneme functionality 'Whistle' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Whistle" ))
	void ARPABETSpeechSynthesis_Whistle(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Whistle());
	};

	/** Activates speech synthesis channel phoneme functionality 'Whoop' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Whoop" ))
	void ARPABETSpeechSynthesis_Whoop(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Whoop());
	};

	/** Activates speech synthesis channel phoneme functionality 'Yawn' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Yawn" ))
	void ARPABETSpeechSynthesis_Yawn(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Yawn());
	};

	/** Activates speech synthesis channel phoneme functionality 'Yelp' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > Yelp" ))
	void ARPABETSpeechSynthesis_Yelp(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Yelp());
	};


	//UPROPERTY()
	VoiceArray voices_UTTSVoiceArray{};

	//UPROPERTY()
	ChannelCount ChannelCount_UInt32{};

	//UPROPERTY()
	SampleWidth SampleWidth_UInt32{};

	//UPROPERTY()
	FrameRate FrameRateHz_UInt32{};

	//UPROPERTY()
	std::vector<uint8> datastream_UInt8Vec{};

	//UPROPERTY()
	std::unique_ptr<UTTSVoice> voice_UTTSVoice{};

	//UPROPERTY()
	UARPABETAudio m_UARPABETAudio{};

	UTTSVoice currentPhone{};
	std::vector<FPhone> speechSample_FPhoneVec{}; 
	
};
