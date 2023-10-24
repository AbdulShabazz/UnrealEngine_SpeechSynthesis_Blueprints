// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "SpeechSynthesisAudioComponent.generated.h"

/**
 * 
 */
UCLASS()
class SPEECHSYNTHESISBP_API USpeechSynthesisAudioComponent : public UAudioComponent
{
	GENERATED_BODY()

	// Setter methods with input validation

	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: SetVoices" ))
	int SetVoices(UPARAM(DisplayName = "InVal (integer)") const int inVal) {
		return 0;
	}

	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: SetChannelCount" ))
	int SetChannelCount(UPARAM(DisplayName = "InVal (integer)") const int inVal) {
		return 0;
	}

	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: SetSampleWidth" ))
	int SetSampleWidth(UPARAM(DisplayName = "InVal (integer)") const int inVal) {
		return 0;
	}

	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: SetFrameRate" ))
	int SetFrameRate(UPARAM(DisplayName = "InVal (integer)") const int inVal) {
		return 0;
	}

	// Other member functions
	// vowels > front > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'IY' ( B_ea_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > front > IY ( B_ea_t )" ))
	void ARPABETSpeechSynthesis_IY(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'IH' ( B_i_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > front > IH ( B_i_t )" ))
	void ARPABETSpeechSynthesis_IH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'EH' ( B_e_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > front > EH ( B_e_t )" ))
	void ARPABETSpeechSynthesis_EH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'EY' ( B_ai_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > front > EY ( B_ai_t )" ))
	void ARPABETSpeechSynthesis_EY(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'AE' ( B_a_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > front > AE ( B_a_t )" ))
	void ARPABETSpeechSynthesis_AE(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// vowels > back > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'AA' ( B_o_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > back > AA ( B_o_t )" ))
	void ARPABETSpeechSynthesis_AA(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'AO' ( B_ough_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > back > AO ( B_ough_t )" ))
	void ARPABETSpeechSynthesis_AO(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'OW' ( B_oa_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > back > OW ( B_oa_t )" ))
	void ARPABETSpeechSynthesis_OW(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'UH' ( B_oo_k ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > back > UH ( B_oo_k )" ))
	void ARPABETSpeechSynthesis_UH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'UW' ( B_oot_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > back > UW ( B_oot_ )" ))
	void ARPABETSpeechSynthesis_UW(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// vowels > mid > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'ER' ( B_ir_d ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > ER ( B_ir_d )" ))
	void ARPABETSpeechSynthesis_ER(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'AX' ( Ab_ou_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AX ( Ab_ou_t )" ))
	void ARPABETSpeechSynthesis_AX(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'AH' ( B_u_tt ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AH ( B_u_tt )" ))
	void ARPABETSpeechSynthesis_AH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// vowels > diphthongs > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'AY' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AY ( B_ite_ )" ))
	void ARPABETSpeechSynthesis_AY(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'AW' ( B_ite_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AW ( B_ou_t )" ))
	void ARPABETSpeechSynthesis_AW(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'OY' ( B_o_y ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > OY ( B_o_y )" ))
	void ARPABETSpeechSynthesis_OY(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'IX' ( Rabb_i_t ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > IX ( Rabb_i_t )" ))
	void ARPABETSpeechSynthesis_IX(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// stopConsonants > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'B' ( _B_eat ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > B ( _B_eat )" ))
	void ARPABETSpeechSynthesis_B(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'D' ( _D_eep ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > D ( _D_eep )" ))
	void ARPABETSpeechSynthesis_D(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'G' ( _G_o ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > G ( _G_o )" ))
	void ARPABETSpeechSynthesis_G(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// stopConsonants > voiced > > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'P' ( _P_ea ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > P ( _P_ea )" ))
	void ARPABETSpeechSynthesis_P(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'T' ( _T_ea ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > T ( _T_ea )" ))
	void ARPABETSpeechSynthesis_T(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'K' ( _K_ick ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > K ( _K_ick )" ))
	void ARPABETSpeechSynthesis_K(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// fricatives > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'V' ( _V_ery ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > V ( _V_ery )" ))
	void ARPABETSpeechSynthesis_V(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'DH' ( _Th_en ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > DH ( _Th_en )" ))
	void ARPABETSpeechSynthesis_DH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// fricatives > unvoiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'F' ( _F_ive ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > F ( _F_ive )" ))
	void ARPABETSpeechSynthesis_F(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'TH' ( _Th_ink ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > TH ( _Th_ink )" ))
	void ARPABETSpeechSynthesis_TH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'S' ( _S_ee ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > S ( _S_ee )" ))
	void ARPABETSpeechSynthesis_S(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'SH' ( _Sh_e ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > SH ( _Sh_e )" ))
	void ARPABETSpeechSynthesis_SH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// semivowels > liquid > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'L' ( _L_ove ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > L ( _L_ove )" ))
	void ARPABETSpeechSynthesis_L(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'EL' ( Bott_le_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > EL ( Bott_le_ )" ))
	void ARPABETSpeechSynthesis_EL(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'R' ( _R_ed ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > R ( _R_ed )" ))
	void ARPABETSpeechSynthesis_R(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// semivowels > glides > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'W' ( _W_ater ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > W ( _W_ater )" ))
	void ARPABETSpeechSynthesis_W(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'WH' ( _Wh_at ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > WH ( _Wh_at )" ))
	void ARPABETSpeechSynthesis_WH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'Y' ( _Y_es ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > Y ( _Y_es )" ))
	void ARPABETSpeechSynthesis_Y(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// nasals > non vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'M' ( _M_ore ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > M ( _M_ore )" ))
	void ARPABETSpeechSynthesis_M(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'N' ( _N_ow ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > N ( _N_ow )" ))
	void ARPABETSpeechSynthesis_N(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'NX' ( Si_ng_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
	void ARPABETSpeechSynthesis_NX(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'NG' ( Si_ng_ ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
	void ARPABETSpeechSynthesis_NG(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// nasals > vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'EM' ( Butt_o_n ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EM ( Butt_o_n )" ))
	void ARPABETSpeechSynthesis_EM(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'EN' ( S_o_n ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EN ( S_o_n )" ))
	void ARPABETSpeechSynthesis_EN(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// affricates > voiced > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'CH' ( _Ch_urch ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > CH ( _Ch_urch )" ))
	void ARPABETSpeechSynthesis_CH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'JH' ( _J_ump ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > JH ( _J_ump )" ))
	void ARPABETSpeechSynthesis_JH(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// other > whisper > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'H' ( _H_ow ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > whisper > H ( _H_ow )" ))
	void ARPABETSpeechSynthesis_H(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// other > vocalic > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'DX' ( Ri_dd_le ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > vocalic > DX ( Ri_dd_le )" ))
	void ARPABETSpeechSynthesis_DX(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// other > pause or glottal_stop > ARPABET UV >

	/** Activates speech synthesis channel phoneme functionality 'Q' ( _Q_uestion ) */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > pause or glottal_stop > Q ( _Q_uestion )" ))
	void ARPABETSpeechSynthesis_Q(
		UPARAM(DisplayName = "Voice") int InVoice)
	{

	};

	// Setup and Activation APIs

	/** Activates speech synthesis channel phoneme functionality 'Voice' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: Voice [compile]" ))
	int Voice()
	{
		return 0;
	};

	/** Activates speech synthesis channel phoneme functionality 'Init' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords="TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: Init [Invoke]" ))
	bool Init(
		UPARAM(DisplayName = "Voice") int InVoice,
		UPARAM(DisplayName = "FProsodyCurve") const int& ProsodyCurve_ConstObjArray,
		UPARAM(DisplayName = "FDurationCurve") const int& DurationCurve_ConstObjArray,
		UPARAM(DisplayName = "FEmotiveCurve") const int& EmotiveCurve_ConstObjArray)
	{
		return true;
	};

private:

	/*VoiceArray voices_FTTSVoiceArray{};
	ChannelCount ChannelCount_UInt32{};
	SampleWidth SampleWidth_UInt32{};
	FrameRate FrameRateHz_UInt32{};
	TArray<uint8> datastream_TArrayUInt8{};*/
	
};
