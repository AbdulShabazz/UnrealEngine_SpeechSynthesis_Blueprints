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
			return InOutARPABETSpeechSynthesisObjRef;
		};

		IH ( B_i_t )
		EH ( B_e_t )
		EY ( B_ate_ )
		AE ( B_a_t )

		// vowels > back > ARPABET UV >
		AA ( B_o_t )
		AO ( B_ough_t )
		OW ( B_oa_t )
		UH ( B_oo_k )
		UW ( B_oot_ )

		// vowels > mid > ARPABET UV >
		ER ( B_ir_d )
		AX ( Ab_ou_t )
		AH ( B_u_tt )

		// vowels > diphthongs > ARPABET UV >
		AY ( B_ite_ )
		AW ( B_ou_t )
		OY ( B_o_y )
		IX ( Rabb_i_t )

		// stopConsonants > voiced > ARPABET UV >
		B ( _B_eat )
		D ( _D_eep )
		G ( _G_o )

		// stopConsonants > unvoiced > ARPABET UV >
		P ( _P_ea )
		T ( _T_ea )
		K ( _K_ick )

		// fricatives > voiced > ARPABET UV >
		V ( _V_ery )
		DH ( _Th_en )

		// fricatives > unvoiced > ARPABET UV >
		F ( _F_ive )
		TH ( _Th_ink )
		S ( _S_ee )
		SH ( _Sh_e )

		// semivowels > liquid > ARPABET UV >
		L ( _L_ove )
		EL ( Bo_ttle_ )
		R ( _R_ed )

		// semivowels > glides > ARPABET UV >
		W ( _W_ater )
		WH ( _Wh_at )
		Y ( _Y_es )

		// nasals > non vocalic > ARPABET UV >
		M ( _M_ore )
		N ( _N_ow )
		NX or NG ( Si_ng_ )

		// nasals > vocalic > ARPABET UV >
		EM ( Butt_o_n )
		EN ( S_o_n )

		// affricates > voiced > ARPABET UV >
		CH ( _Ch_urch )
		JH ( _J_ump )

		// other > whisper > ARPABET UV >
		H ( _H_ow )

		// other > vocalic > ARPABET UV >
		DX ( Ri_dd_le )

		// other > pause or glottal_stop > ARPABET UV >
		Q ( _Q_uestion )

		/** Activates speech synthesis channel phoneme functionality 'H' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: H ( _H_ow )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_H(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "Voice") FTTSVoice InVoice)
		{
			return InOutARPABETSpeechSynthesisObjRef;
		};

		/** Activates speech synthesis channel phoneme functionality 'EH' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis: EH ( B_e_t )" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_e(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "Voice") FTTSVoice InVoice)
		{
			return InOutARPABETSpeechSynthesisObjRef;
		};

		/** Activates speech synthesis channel phoneme functionality 'l' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis_l" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_l(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "Voice") FTTSVoice InVoice)
		{
			return InOutARPABETSpeechSynthesisObjRef;
		};

		/** Activates speech synthesis channel phoneme functionality 'o' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis_o" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_o(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "Voice") FTTSVoice InVoice)
		{
			return InOutARPABETSpeechSynthesisObjRef;
		};

		/** Activates speech synthesis channel phoneme functionality 'w' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis_w" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_w(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "Voice") FTTSVoice InVoice)
		{
			return InOutARPABETSpeechSynthesisObjRef;
		};

		/** Activates speech synthesis channel phoneme functionality 'r' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis_r" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_r(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "Voice") FTTSVoice InVoice)
		{
			return InOutARPABETSpeechSynthesisObjRef;
		};

		/** Activates speech synthesis channel phoneme functionality 'd' */
		UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "ARPABETSpeechSynthesis_d" ))
		ARPABETSpeechSynthesis& ARPABETSpeechSynthesis_d(UPARAM(DisplayName = "ARPABETSpeechSynthesis") ARPABETSpeechSynthesis& InOutARPABETSpeechSynthesisObjRef,
			UPARAM(DisplayName = "Voice") FTTSVoice InVoice)
		{
			return InOutARPABETSpeechSynthesisObjRef;
		};

	};
}
