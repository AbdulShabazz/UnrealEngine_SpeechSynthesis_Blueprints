// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>
#include <vector>

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "Public/TTSVoice.h"
#include "Public/ProsodyCurve.h"
#include "Public/EmotiveCurve.h"
#include "Public/DurationCurve.h"
#include "Public/ARPABETAudio.h"
#include "Public/Oscillator.h"
#include "FPhone.h"

// begin: phone libraries
#include "Public/ARPABETPhone_AA.h"
#include "Public/ARPABETPhone_AE.h"
#include "Public/ARPABETPhone_AH.h"
#include "Public/ARPABETPhone_AO.h"
#include "Public/ARPABETPhone_AW.h"
#include "Public/ARPABETPhone_AX.h"
#include "Public/ARPABETPhone_AY.h"
#include "Public/ARPABETPhone_B.h"
#include "Public/ARPABETPhone_CH.h"
#include "Public/ARPABETPhone_D.h"
#include "Public/ARPABETPhone_DH.h"
#include "Public/ARPABETPhone_DX.h"
#include "Public/ARPABETPhone_EH.h"
#include "Public/ARPABETPhone_EL.h"
#include "Public/ARPABETPhone_EM.h"
#include "Public/ARPABETPhone_EN.h"
#include "Public/ARPABETPhone_ER.h"
#include "Public/ARPABETPhone_EY.h"
#include "Public/ARPABETPhone_F.h"
#include "Public/ARPABETPhone_G.h"
#include "Public/ARPABETPhone_HH.h"
#include "Public/ARPABETPhone_IH.h"
#include "Public/ARPABETPhone_IX.h"
#include "Public/ARPABETPhone_IY.h"
#include "Public/ARPABETPhone_JH.h"
#include "Public/ARPABETPhone_K.h"
#include "Public/ARPABETPhone_L.h"
#include "Public/ARPABETPhone_M.h"
#include "Public/ARPABETPhone_N.h"
#include "Public/ARPABETPhone_NG.h"
#include "Public/ARPABETPhone_NX.h"
#include "Public/ARPABETPhone_OW.h"
#include "Public/ARPABETPhone_OY.h"
#include "Public/ARPABETPhone_P.h"
#include "Public/ARPABETPhone_Q.h"
#include "Public/ARPABETPhone_R.h"
#include "Public/ARPABETPhone_S.h"
#include "Public/ARPABETPhone_SH.h"
#include "Public/ARPABETPhone_T.h"
#include "Public/ARPABETPhone_TH.h"
#include "Public/ARPABETPhone_UH.h"
#include "Public/ARPABETPhone_UW.h"
#include "Public/ARPABETPhone_V.h"
#include "Public/ARPABETPhone_W.h"
#include "Public/ARPABETPhone_WH.h"
#include "Public/ARPABETPhone_Y.h"
#include "Public/ARPABETPhone_Z.h"
#include "Public/ARPABETPhone_ZH.h"
// end: phone libraries

#include "SpeechSynthesisAudioComponent.generated.h"

// forward declarations here

// Strong Typing for Configuration Parameters

using VoiceArray = TArray<class UTTSVoice>;  // Only one voice for simplicity
using ChannelCount = unsigned int;
using SampleWidth = unsigned int;
using FrameRate = unsigned int;

UCLASS(Blueprintable)
class SPEECHSYNTHESISBP_API USpeechSynthesisAudioComponent : public UAudioComponent
{
	GENERATED_BODY()

	// Setter methods with input validation

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

	// Other member functions:

	// vowels > front > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'IY' ( B_ea_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, IY", DisplayName = "ARPABETSpeechSynthesis: vowels > front > IY ( B_ea_t )" ))
	void ARPABETSpeechSynthesis_IY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_IY());
	};

	/** Activates speech synthesis channel phoneme functionality 'IH' ( B_i_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, IH", DisplayName = "ARPABETSpeechSynthesis: vowels > front > IH ( B_i_t )" ))
	void ARPABETSpeechSynthesis_IH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_IH());
	};

	/** Activates speech synthesis channel phoneme functionality 'EH' ( B_e_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EH", DisplayName = "ARPABETSpeechSynthesis: vowels > front > EH ( B_e_t )" ))
	void ARPABETSpeechSynthesis_EH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EH());
	};

	/** Activates speech synthesis channel phoneme functionality 'EY' ( B_ai_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EY", DisplayName = "ARPABETSpeechSynthesis: vowels > front > EY ( B_ai_t )" ))
	void ARPABETSpeechSynthesis_EY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EY());
	};

	/** Activates speech synthesis channel phoneme functionality 'AE' ( B_a_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AE", DisplayName = "ARPABETSpeechSynthesis: vowels > front > AE ( B_a_t )" ))
	void ARPABETSpeechSynthesis_AE(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AE());
	};

	// vowels > back > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'AA' ( B_o_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AA", DisplayName = "ARPABETSpeechSynthesis: vowels > back > AA ( B_o_t )" ))
	void ARPABETSpeechSynthesis_AA(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AA());
	};

	/** Activates speech synthesis channel phoneme functionality 'AO' ( B_ough_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AO", DisplayName = "ARPABETSpeechSynthesis: vowels > back > AO ( B_ough_t )" ))
	void ARPABETSpeechSynthesis_AO(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AO());
	};

	/** Activates speech synthesis channel phoneme functionality 'OW' ( B_oa_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, OW", DisplayName = "ARPABETSpeechSynthesis: vowels > back > OW ( B_oa_t )" ))
	void ARPABETSpeechSynthesis_OW(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_OW());
	};

	/** Activates speech synthesis channel phoneme functionality 'UH' ( B_oo_k ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, UH", DisplayName = "ARPABETSpeechSynthesis: vowels > back > UH ( B_oo_k )" ))
	void ARPABETSpeechSynthesis_UH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_UH());
	};

	/** Activates speech synthesis channel phoneme functionality 'UW' ( B_oot_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, UW", DisplayName = "ARPABETSpeechSynthesis: vowels > back > UW ( B_oot_ )" ))
	void ARPABETSpeechSynthesis_UW(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_UW());
	};

	// vowels > mid > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'ER' ( B_ir_d ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, ER", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > ER ( B_ir_d )" ))
	void ARPABETSpeechSynthesis_ER(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_ER());
	};

	/** Activates speech synthesis channel phoneme functionality 'AX' ( Ab_ou_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AX", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AX ( Ab_ou_t )" ))
	void ARPABETSpeechSynthesis_AX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AX());
	};

	/** Activates speech synthesis channel phoneme functionality 'AH' ( B_u_tt ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AH", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AH ( B_u_tt )" ))
	void ARPABETSpeechSynthesis_AH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AH());
	};

	// vowels > diphthongs > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'AY' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AY", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AY ( B_ite_ )" ))
	void ARPABETSpeechSynthesis_AY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AY());
	};

	/** Activates speech synthesis channel phoneme functionality 'AW' ( B_ite_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AW", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AW ( B_ou_t )" ))
	void ARPABETSpeechSynthesis_AW(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_AW());
	};

	/** Activates speech synthesis channel phoneme functionality 'OY' ( B_o_y ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, DY", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > OY ( B_o_y )" ))
	void ARPABETSpeechSynthesis_OY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_OY());
	};

	/** Activates speech synthesis channel phoneme functionality 'IX' ( Rabb_i_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, IX", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > IX ( Rabb_i_t )" ))
	void ARPABETSpeechSynthesis_IX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_IX());
	};

	// stopConsonants > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'B' ( _B_eat ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > B ( _B_eat )" ))
	void ARPABETSpeechSynthesis_B(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_B());
	};

	/** Activates speech synthesis channel phoneme functionality 'D' ( _D_eep ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > D ( _D_eep )" ))
	void ARPABETSpeechSynthesis_D(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_D());
	};

	/** Activates speech synthesis channel phoneme functionality 'G' ( _G_o ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > G ( _G_o )" ))
	void ARPABETSpeechSynthesis_G(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_G());
	};

	// stopConsonants > voiced > > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'P' ( _P_ea ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > P ( _P_ea )" ))
	void ARPABETSpeechSynthesis_P(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_P());
	};

	/** Activates speech synthesis channel phoneme functionality 'T' ( _T_ea ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > T ( _T_ea )" ))
	void ARPABETSpeechSynthesis_T(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_T());
	};

	/** Activates speech synthesis channel phoneme functionality 'K' ( _K_ick ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > K ( _K_ick )" ))
	void ARPABETSpeechSynthesis_K(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_K());
	};

	// fricatives > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'V' ( _V_ery ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > V ( _V_ery )" ))
	void ARPABETSpeechSynthesis_V(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_V());
	};

	/** Activates speech synthesis channel phoneme functionality 'DH' ( _Th_en ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, DH", DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > DH ( _Th_en )" ))
	void ARPABETSpeechSynthesis_DH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_DH());
	};

	// fricatives > unvoiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'F' ( _F_ive ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > F ( _F_ive )" ))
	void ARPABETSpeechSynthesis_F(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_F());
	};

	/** Activates speech synthesis channel phoneme functionality 'TH' ( _Th_ink ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, TH", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > TH ( _Th_ink )" ))
	void ARPABETSpeechSynthesis_TH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_TH());
	};

	/** Activates speech synthesis channel phoneme functionality 'S' ( _S_ee ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > S ( _S_ee )" ))
	void ARPABETSpeechSynthesis_S(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_S());
	};

	/** Activates speech synthesis channel phoneme functionality 'SH' ( _Sh_e ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, SH", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > SH ( _Sh_e )" ))
	void ARPABETSpeechSynthesis_SH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_SH());
	};

	// semivowels > liquid > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'L' ( _L_ove ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > L ( _L_ove )" ))
	void ARPABETSpeechSynthesis_L(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_L());
	};

	/** Activates speech synthesis channel phoneme functionality 'EL' ( Bott_le_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EL", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > EL ( Bott_le_ )" ))
	void ARPABETSpeechSynthesis_EL(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EL());
	};

	/** Activates speech synthesis channel phoneme functionality 'R' ( _R_ed ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > R ( _R_ed )" ))
	void ARPABETSpeechSynthesis_R(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_R());
	};

	// semivowels > glides > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'W' ( _W_ater ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > W ( _W_ater )" ))
	void ARPABETSpeechSynthesis_W(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_W());
	};

	/** Activates speech synthesis channel phoneme functionality 'WH' ( _Wh_at ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, WH", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > WH ( _Wh_at )" ))
	void ARPABETSpeechSynthesis_WH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_WH());
	};

	/** Activates speech synthesis channel phoneme functionality 'Y' ( _Y_es ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > Y ( _Y_es )" ))
	void ARPABETSpeechSynthesis_Y(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_Y());
	};

	// nasals > non vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'M' ( _M_ore ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > M ( _M_ore )" ))
	void ARPABETSpeechSynthesis_M(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_M());
	};

	/** Activates speech synthesis channel phoneme functionality 'N' ( _N_ow ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > N ( _N_ow )" ))
	void ARPABETSpeechSynthesis_N(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_N());
	};

	/** Activates speech synthesis channel phoneme functionality 'NX' ( Si_ng_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, NX", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
	void ARPABETSpeechSynthesis_NX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_NX());
	};

	/** Activates speech synthesis channel phoneme functionality 'NG' ( Si_ng_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, NG", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
	void ARPABETSpeechSynthesis_NG(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_NG());
	};

	// nasals > vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'EM' ( Butt_o_n ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EM", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EM ( Butt_o_n )" ))
	void ARPABETSpeechSynthesis_EM(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EM());
	};

	/** Activates speech synthesis channel phoneme functionality 'EN' ( S_o_n ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech,EN", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EN ( S_o_n )" ))
	void ARPABETSpeechSynthesis_EN(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_EN());
	};

	// affricates > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'CH' ( _Ch_urch ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, CH", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > CH ( _Ch_urch )" ))
	void ARPABETSpeechSynthesis_CH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_CH());
	};

	/** Activates speech synthesis channel phoneme functionality 'JH' ( _J_ump ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, JH", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > JH ( _J_ump )" ))
	void ARPABETSpeechSynthesis_JH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_JH());
	};

	// other > whisper > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'HH' ( _H_ow ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > whisper > HH ( _H_ow )" ))
	void ARPABETSpeechSynthesis_HH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_HH());
	};

	// other > vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'DX' ( Ri_dd_le ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, DX", DisplayName = "ARPABETSpeechSynthesis: other > vocalic > DX ( Ri_dd_le )" ))
	void ARPABETSpeechSynthesis_DX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_DX());
	};

	// other > pause or glottal_stop > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'Q' ( _Q_uestion ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > pause or glottal_stop > Q ( _Q_uestion )" ))
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
	//VoiceArray voices_UTTSVoiceArray{};

	//UPROPERTY()
	ChannelCount ChannelCount_UInt32{};

	//UPROPERTY()
	SampleWidth SampleWidth_UInt32{};

	//UPROPERTY()
	FrameRate FrameRateHz_UInt32{};

	//UPROPERTY()
	std::vector<uint8> datastream_UInt8Vec{};

	//UPROPERTY()
	//std::unique_ptr<UTTSVoice> voice_UTTSVoice{};
	
	//UPROPERTY
	UARPABETAudio m_UARPABETAudio{};

	UTTSVoice currentPhone{};
	std::vector<FPhone> speechSample_FPhoneVec{};

};
