// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SpeechSynthesisBlueprintLibrary.generated.h"

namespace TTSSpeechSynthesis
{

	UCLASS()
	class SPEECHSYNTHESISBP_API FTTSVoice
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

	class ARPABETSpeechSynthesis
	{

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

		/** Activates speech synthesis channel phoneme functionality 'IY' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > IY ( B_ea_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'IH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > IH ( B_i_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'EH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > EH ( B_e_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'EY' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > EY ( B_ai_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'AE' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > front > AE ( B_a_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// vowels > back > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'AA' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > AA ( B_o_t )H ( B_i_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'AO' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > AO ( B_ough_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'IY' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > OW ( B_oa_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'UH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > UH ( B_oo_k )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'UW' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > back > UW ( B_oot_ )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// vowels > mid > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'ER' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > mid > ER ( B_ir_d )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'AX' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AX ( Ab_ou_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'AH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > mid > AH ( B_u_tt )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// vowels > diphthongs > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'AY' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AY ( B_ite_ )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'AW' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > AW ( B_ou_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'OY' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > OY ( B_o_y )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'IX' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: vowels > diphthongs > IX ( Rabb_i_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// stopConsonants > voiced > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'B' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > B ( _B_eat )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'D' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > D ( _D_eep )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'G' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > G ( _G_o )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// stopConsonants > voiced > > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'P' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > P ( _P_ea )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'T' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > T ( _T_ea )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'K' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: stopConsonants > voiced > K ( _K_ick )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// fricatives > voiced > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'V' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > V ( _V_ery )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'DH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > voiced > DH ( _Th_en )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// fricatives > unvoiced > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'F' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > F ( _F_ive )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'TH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > TH ( _Th_ink )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'S' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > S ( _S_ee )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'IY' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: fricatives > unvoiced > SH ( _Sh_e )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// semivowels > liquid > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'L' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > L ( _L_ove )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'EL' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > EL ( Bo_ttle_ )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'R' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > liquid > R ( _R_ed )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// semivowels > glides > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'W' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > W ( _W_ater )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'WH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > WH ( _Wh_at )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'Y' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: semivowels > glides > Y ( _Y_es )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// nasals > non vocalic > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'M' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > M ( _M_ore )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'N' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > N ( _N_ow )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'NX' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_NX(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'NG' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > non vocalic > NX or NG ( Si_ng_ )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_NG(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// nasals > vocalic > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'EM' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EM ( Butt_o_n )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'EN' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > EN ( S_o_n )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// affricates > voiced > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'CH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > CH ( _Ch_urch )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		/** Activates speech synthesis channel phoneme functionality 'JH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: nasals > vocalic > JH ( _J_ump )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// other > whisper > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'H' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: other > whisper > H ( _H_ow )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// other > vocalic > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'DX' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: other > vocalic > DX ( Ri_dd_le )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			return *this;
		};

		// other > pause or glottal_stop > ARPABET UV >

		/** Activates speech synthesis channel phoneme functionality 'Q' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: other > pause or glottal_stop > Q ( _Q_uestion )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{
			ARPABETSpeechSynthesis self = *this;
			return self;
		};

		// Setup and Activation APIs

		/** Activates speech synthesis channel phoneme functionality 'Voice' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: Voice" ))
		void Voice(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice)
		{

		};

		class FProsodyCurve;
		class FDurationCurve;
		class FEmotiveCurve;

		/** Activates speech synthesis channel phoneme functionality 'Init' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: Init" ))
		bool Init(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "FTTSVoice") FTTSVoice InVoice,
			const FProsodyCurve& ProsodyCurve_ConstObjArray,
			const FDurationCurve& DurationCurve_ConstObjArray,
			const FEmotiveCurve& EmotiveCurve_ConstObjArray)
		{
			return true;
		};


	};
}
