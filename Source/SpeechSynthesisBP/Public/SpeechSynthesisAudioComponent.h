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
