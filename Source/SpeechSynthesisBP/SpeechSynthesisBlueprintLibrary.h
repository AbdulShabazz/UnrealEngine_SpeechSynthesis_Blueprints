// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SpeechSynthesisBlueprintLibrary.generated.h"

namespace TTSSpeechSynthesis
{

	/**
	 *
	 */
	UCLASS()
	class SPEECHSYNTHESISBP_API FTTSVoice : public UBlueprintFunctionLibrary
	{
		GENERATED_BODY()

	public:

		FTTSVoice()
		{

		};

		~FTTSVoice()
		{

		};
	};

	/**
	 *
	 */
	UCLASS()
	class SPEECHSYNTHESISBP_API ARPABETSpeechSynthesis : public UBlueprintFunctionLibrary
	{
		GENERATED_BODY()

	public:

		ARPABETSpeechSynthesis()
		{

		};

		~ARPABETSpeechSynthesis()
		{

		};
	};

	//using FTTSVoiceArray = TArray<FTTSVoice>;

	/**
	 *
	 */
	UCLASS()
	class SPEECHSYNTHESISBP_API USpeechSynthesisBlueprintLibrary : public UBlueprintFunctionLibrary
	{
		GENERATED_BODY()

	public:
		// vowels > front > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'IY' ( B_ea_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > IY ( B_ea_t )" ))
		void ARPABETSpeechSynthesis_IY(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'IH' ( B_i_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > IH ( B_i_t )" ))
		void ARPABETSpeechSynthesis_IH(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'EH' ( B_e_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > EH ( B_e_t )" ))
		void ARPABETSpeechSynthesis_EH(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'EY' ( B_ai_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > EY ( B_ai_t )" ))
		void ARPABETSpeechSynthesis_EY(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'AE' ( B_a_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > AE ( B_a_t )" ))
		void ARPABETSpeechSynthesis_AE(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// vowels > back > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'AA' ( B_o_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > AA ( B_o_t )" ))
		void ARPABETSpeechSynthesis_AA(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'AO' ( B_ough_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > AO ( B_ough_t )" ))
		void ARPABETSpeechSynthesis_AO(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'OW' ( B_oa_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > OW ( B_oa_t )" ))
		void ARPABETSpeechSynthesis_IY(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'UH' ( B_oo_k ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > UH ( B_oo_k )" ))
		void ARPABETSpeechSynthesis_UH(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'UW' ( B_oot_ ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > UW ( B_oot_ )" ))
		void ARPABETSpeechSynthesis_UW(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// vowels > mid > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'ER' ( B_ir_d ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > mid > ER ( B_ir_d )" ))
		void ARPABETSpeechSynthesis_ER(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'AX' ( Ab_ou_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AX ( Ab_ou_t )" ))
		void ARPABETSpeechSynthesis_AX(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'AH' ( B_u_tt ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AH ( B_u_tt )" ))
		void ARPABETSpeechSynthesis_AH(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// vowels > diphthongs > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'AY' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AY ( B_ite_ )" ))
		void ARPABETSpeechSynthesis_AY(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'AW' ( B_ite_ ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AW ( B_ou_t )" ))
		void ARPABETSpeechSynthesis_AW(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'OY' ( B_o_y ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > OY ( B_o_y )" ))
		void ARPABETSpeechSynthesis_OY(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'IX' ( Rabb_i_t ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > IX ( Rabb_i_t )" ))
		void ARPABETSpeechSynthesis_IX(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// stopConsonants > voiced > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'B' ( _B_eat ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > B ( _B_eat )" ))
		void ARPABETSpeechSynthesis_B(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'D' ( _D_eep ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > D ( _D_eep )" ))
		void ARPABETSpeechSynthesis_D(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'G' ( _G_o ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > G ( _G_o )" ))
		void ARPABETSpeechSynthesis_G(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// stopConsonants > voiced > > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'P' ( _P_ea ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > P ( _P_ea )" ))
		void ARPABETSpeechSynthesis_P(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'T' ( _T_ea ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > T ( _T_ea )" ))
		void ARPABETSpeechSynthesis_T(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'K' ( _K_ick ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > K ( _K_ick )" ))
		void ARPABETSpeechSynthesis_K(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// fricatives > voiced > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'V' ( _V_ery ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > V ( _V_ery )" ))
		void ARPABETSpeechSynthesis_V(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'DH' ( _Th_en ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > DH ( _Th_en )" ))
		void ARPABETSpeechSynthesis_DH(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// fricatives > unvoiced > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'F' ( _F_ive ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > F ( _F_ive )" ))
		void ARPABETSpeechSynthesis_F(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'TH' ( _Th_ink ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > TH ( _Th_ink )" ))
		void ARPABETSpeechSynthesis_TH(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'S' ( _S_ee ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > S ( _S_ee )" ))
		void ARPABETSpeechSynthesis_S(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'IY' ( _Sh_e ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > SH ( _Sh_e )" ))
		void ARPABETSpeechSynthesis_IY(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// semivowels > liquid > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'L' ( _L_ove ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > L ( _L_ove )" ))
		void ARPABETSpeechSynthesis_L(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'EL' ( Bott_le_ ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > EL ( Bott_le_ )" ))
		void ARPABETSpeechSynthesis_EL(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'R' ( _R_ed ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > R ( _R_ed )" ))
		void ARPABETSpeechSynthesis_R(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// semivowels > glides > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'W' ( _W_ater ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > W ( _W_ater )" ))
		void ARPABETSpeechSynthesis_W(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'WH' ( _Wh_at ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > WH ( _Wh_at )" ))
		void ARPABETSpeechSynthesis_WH(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'Y' ( _Y_es ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > Y ( _Y_es )" ))
		void ARPABETSpeechSynthesis_Y(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// nasals > non vocalic > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'M' ( _M_ore ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > M ( _M_ore )" ))
		void ARPABETSpeechSynthesis_M(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'N' ( _N_ow ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > N ( _N_ow )" ))
		void ARPABETSpeechSynthesis_N(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'NX' ( Si_ng_ ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
		void ARPABETSpeechSynthesis_NX(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'NG' ( Si_ng_ ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
		void ARPABETSpeechSynthesis_NG(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// nasals > vocalic > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'EM' ( Butt_o_n ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EM ( Butt_o_n )" ))
		void ARPABETSpeechSynthesis_EM(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'EN' ( S_o_n ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EN ( S_o_n )" ))
		void ARPABETSpeechSynthesis_EN(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// affricates > voiced > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'CH' ( _Ch_urch ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > CH ( _Ch_urch )" ))
		void ARPABETSpeechSynthesis_CH(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		/** Activates speech synthesis channel phoneme functionality 'JH' ( _J_ump ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > JH ( _J_ump )" ))
		void ARPABETSpeechSynthesis_JH(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// other > whisper > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'H' ( _H_ow ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: other > whisper > H ( _H_ow )" ))
		void ARPABETSpeechSynthesis_H(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// other > vocalic > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'DX' ( Ri_dd_le ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: other > vocalic > DX ( Ri_dd_le )" ))
		void ARPABETSpeechSynthesis_DX(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// other > pause or glottal_stop > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'Q' ( _Q_uestion ) */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: other > pause or glottal_stop > Q ( _Q_uestion )" ))
		void ARPABETSpeechSynthesis_Q(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		// Setup and Activation APIs

		/** Activates speech synthesis channel phoneme functionality 'Voice' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: Voice" ))
		void Voice()
		{

		};

		class FProsodyCurve;
		class FDurationCurve;
		class FEmotiveCurve;

		/** Activates speech synthesis channel phoneme functionality 'Init' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: Init" ))
		bool Init(
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice,
			UPARAM(DisplayName = "FProsodyCurve") const FProsodyCurve& ProsodyCurve_ConstObjArray,
			UPARAM(DisplayName = "FDurationCurve") const FDurationCurve& DurationCurve_ConstObjArray,
			UPARAM(DisplayName = "FEmotiveCurve") const FEmotiveCurve& EmotiveCurve_ConstObjArray)
		{
			return true;
		};

	};
}
