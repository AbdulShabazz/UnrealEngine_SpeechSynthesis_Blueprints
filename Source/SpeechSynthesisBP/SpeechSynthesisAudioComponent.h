// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "Public/TTSVoice.h"
#include "Public/ProsodyCurve.h"
#include "Public/EmotiveCurve.h"
#include "Public/DurationCurve.h"
#include "Public/ARPABETAudio.h"
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

using VoiceArray = TArray<UTTSVoice>;  // Only one voice for simplicity
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

	// Other member functions:

	// vowels > front > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'IY' ( B_ea_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, IY", DisplayName = "ARPABETSpeechSynthesis: vowels > front > IY ( B_ea_t )" ))
	void ARPABETSpeechSynthesis_IY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::IY_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'IH' ( B_i_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, IH", DisplayName = "ARPABETSpeechSynthesis: vowels > front > IH ( B_i_t )" ))
	void ARPABETSpeechSynthesis_IH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::IH_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'EH' ( B_e_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EH", DisplayName = "ARPABETSpeechSynthesis: vowels > front > EH ( B_e_t )" ))
	void ARPABETSpeechSynthesis_EH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::EH_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'EY' ( B_ai_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EY", DisplayName = "ARPABETSpeechSynthesis: vowels > front > EY ( B_ai_t )" ))
	void ARPABETSpeechSynthesis_EY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::EY_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'AE' ( B_a_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AE", DisplayName = "ARPABETSpeechSynthesis: vowels > front > AE ( B_a_t )" ))
	void ARPABETSpeechSynthesis_AE(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::AE_Base());
	};

	// vowels > back > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'AA' ( B_o_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AA", DisplayName = "ARPABETSpeechSynthesis: vowels > back > AA ( B_o_t )" ))
	void ARPABETSpeechSynthesis_AA(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::AA_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'AO' ( B_ough_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AO", DisplayName = "ARPABETSpeechSynthesis: vowels > back > AO ( B_ough_t )" ))
	void ARPABETSpeechSynthesis_AO(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::AO_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'OW' ( B_oa_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, OW", DisplayName = "ARPABETSpeechSynthesis: vowels > back > OW ( B_oa_t )" ))
	void ARPABETSpeechSynthesis_OW(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::OW_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'UH' ( B_oo_k ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, UH", DisplayName = "ARPABETSpeechSynthesis: vowels > back > UH ( B_oo_k )" ))
	void ARPABETSpeechSynthesis_UH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::UH_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'UW' ( B_oot_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, UW", DisplayName = "ARPABETSpeechSynthesis: vowels > back > UW ( B_oot_ )" ))
	void ARPABETSpeechSynthesis_UW(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::UW_Base());
	};

	// vowels > mid > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'ER' ( B_ir_d ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, ER", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > ER ( B_ir_d )" ))
	void ARPABETSpeechSynthesis_ER(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::ER_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'AX' ( Ab_ou_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AX", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AX ( Ab_ou_t )" ))
	void ARPABETSpeechSynthesis_AX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::AX_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'AH' ( B_u_tt ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AH", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AH ( B_u_tt )" ))
	void ARPABETSpeechSynthesis_AH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::AH_Base());
	};

	// vowels > diphthongs > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'AY' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AY", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AY ( B_ite_ )" ))
	void ARPABETSpeechSynthesis_AY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::AY_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'AW' ( B_ite_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, AW", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AW ( B_ou_t )" ))
	void ARPABETSpeechSynthesis_AW(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::AW_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'OY' ( B_o_y ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, DY", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > OY ( B_o_y )" ))
	void ARPABETSpeechSynthesis_OY(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::OY_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'IX' ( Rabb_i_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, IX", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > IX ( Rabb_i_t )" ))
	void ARPABETSpeechSynthesis_IX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::IX_Base());
	};

	// stopConsonants > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'B' ( _B_eat ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > B ( _B_eat )" ))
	void ARPABETSpeechSynthesis_B(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::B_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'D' ( _D_eep ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > D ( _D_eep )" ))
	void ARPABETSpeechSynthesis_D(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::D_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'G' ( _G_o ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > G ( _G_o )" ))
	void ARPABETSpeechSynthesis_G(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::G_Base());
	};

	// stopConsonants > voiced > > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'P' ( _P_ea ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > P ( _P_ea )" ))
	void ARPABETSpeechSynthesis_P(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::P_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'T' ( _T_ea ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > T ( _T_ea )" ))
	void ARPABETSpeechSynthesis_T(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::T_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'K' ( _K_ick ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > K ( _K_ick )" ))
	void ARPABETSpeechSynthesis_K(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::K_Base());
	};

	// fricatives > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'V' ( _V_ery ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > V ( _V_ery )" ))
	void ARPABETSpeechSynthesis_V(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::V_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'DH' ( _Th_en ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, DH", DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > DH ( _Th_en )" ))
	void ARPABETSpeechSynthesis_DH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::DH_Base());
	};

	// fricatives > unvoiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'F' ( _F_ive ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > F ( _F_ive )" ))
	void ARPABETSpeechSynthesis_F(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::F_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'TH' ( _Th_ink ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, TH", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > TH ( _Th_ink )" ))
	void ARPABETSpeechSynthesis_TH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::TH_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'S' ( _S_ee ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > S ( _S_ee )" ))
	void ARPABETSpeechSynthesis_S(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::S_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'SH' ( _Sh_e ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, SH", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > SH ( _Sh_e )" ))
	void ARPABETSpeechSynthesis_SH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::SH_Base());
	};

	// semivowels > liquid > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'L' ( _L_ove ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > L ( _L_ove )" ))
	void ARPABETSpeechSynthesis_L(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::L_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'EL' ( Bott_le_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EL", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > EL ( Bott_le_ )" ))
	void ARPABETSpeechSynthesis_EL(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::EL_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'R' ( _R_ed ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > R ( _R_ed )" ))
	void ARPABETSpeechSynthesis_R(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::R_Base());
	};

	// semivowels > glides > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'W' ( _W_ater ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > W ( _W_ater )" ))
	void ARPABETSpeechSynthesis_W(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::W_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'WH' ( _Wh_at ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, WH", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > WH ( _Wh_at )" ))
	void ARPABETSpeechSynthesis_WH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::WH_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'Y' ( _Y_es ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > Y ( _Y_es )" ))
	void ARPABETSpeechSynthesis_Y(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::Y_Base());
	};

	// nasals > non vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'M' ( _M_ore ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > M ( _M_ore )" ))
	void ARPABETSpeechSynthesis_M(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::M_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'N' ( _N_ow ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > N ( _N_ow )" ))
	void ARPABETSpeechSynthesis_N(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::N_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'NX' ( Si_ng_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, NX", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
	void ARPABETSpeechSynthesis_NX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::NX_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'NG' ( Si_ng_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, NG", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
	void ARPABETSpeechSynthesis_NG(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::NG_Base());
	};

	// nasals > vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'EM' ( Butt_o_n ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, EM", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EM ( Butt_o_n )" ))
	void ARPABETSpeechSynthesis_EM(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::EM_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'EN' ( S_o_n ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech,EN", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EN ( S_o_n )" ))
	void ARPABETSpeechSynthesis_EN(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::EN_Base());
	};

	// affricates > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'CH' ( _Ch_urch ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, CH", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > CH ( _Ch_urch )" ))
	void ARPABETSpeechSynthesis_CH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::CH_Base());
	};

	/** Activates speech synthesis channel phoneme functionality 'JH' ( _J_ump ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, JH", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > JH ( _J_ump )" ))
	void ARPABETSpeechSynthesis_JH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::JH_Base());
	};

	// other > whisper > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'HH' ( _H_ow ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > whisper > HH ( _H_ow )" ))
	void ARPABETSpeechSynthesis_HH(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::HH_Base());
	};

	// other > vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'DX' ( Ri_dd_le ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, DX", DisplayName = "ARPABETSpeechSynthesis: other > vocalic > DX ( Ri_dd_le )" ))
	void ARPABETSpeechSynthesis_DX(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::DX_Base());
	};

	// other > pause or glottal_stop > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'Q' ( _Q_uestion ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > pause or glottal_stop > Q ( _Q_uestion )" ))
	void ARPABETSpeechSynthesis_Q(
		UPARAM(DisplayName = "Voices") const int Voices)
	{
		speechSample_VecFPhone.Add(ARPABETPhone::Q_Base());
	};

	// Setup and Activation APIs

	/** Activates speech synthesis channel functionality 'Voice' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech, Voice", DisplayName = "ARPABETSpeechSynthesis: Voice [compile]" ))
	int /*ARPABETAudio*/ Voice()
	{
		/*
		for (const auto& nextPhone : speechSample_VecFPhone) {
			currentPhone.setState(nextPhone.cloneState()); 
			currentPhone.handle();
			speechSample_VecFloat32.push_back(currentPhone.getSampleFloat32());
		}

		// Finalize the last phone
		currentPhone.handle();
		speechSample_VecFloat32.push_back(currentPhone.getSampleFloat32());
		*/
		return 1;
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

private:

	TArray<FPhone> speechSample_VecFPhone{}; 
	TArray<FPhone> speechSample_VecFloat32{};

	FPhone currentPhone{};

	//UPROPERTY()
	VoiceArray voices_FTTSVoiceArray{};

	//UPROPERTY()
	ChannelCount ChannelCount_UInt32{};

	//UPROPERTY()
	SampleWidth SampleWidth_UInt32{};

	//UPROPERTY()
	FrameRate FrameRateHz_UInt32{};

	//UPROPERTY()
	TArray<uint8> datastream_TArrayUInt8{};

};
