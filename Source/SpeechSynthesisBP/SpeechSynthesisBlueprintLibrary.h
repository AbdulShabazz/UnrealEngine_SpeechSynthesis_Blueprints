// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SpeechSynthesisBlueprintLibrary.generated.h"

class FVoice
{

public:

	FVoice()
	{

	};

	~FVoice()
	{

	};
};

class IPASpeechSynthesis
{

public:

	IPASpeechSynthesis()
	{

	};

	~IPASpeechSynthesis()
	{

	};
};

/**
 * 
 */
UCLASS()
class SPEECHSYNTHESISBP_API USpeechSynthesisBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/** Activates speech synthesis channel phoneme functionality 'h' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_h" ))
	IPASpeechSynthesis IPASpeechSynthesis_h(UPARAM(DisplayName = "IPASpeechSynthesis") IPASpeechSynthesis InIPASpeechSynthesisObj, 
		UPARAM(DisplayName = "Voice") FVoice InVoice)
	{
		return InIPASpeechSynthesisObj;
	};

	/** Activates speech synthesis channel phoneme functionality 'e' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_e" ))
	IPASpeechSynthesis IPASpeechSynthesis_e(UPARAM(DisplayName = "IPASpeechSynthesis") IPASpeechSynthesis InIPASpeechSynthesisObj, 
		UPARAM(DisplayName = "Voice") FVoice InVoice)
	{
		return InIPASpeechSynthesisObj;
	};

	/** Activates speech synthesis channel phoneme functionality 'l' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_l" ))
	IPASpeechSynthesis IPASpeechSynthesis_l(UPARAM(DisplayName = "IPASpeechSynthesis") IPASpeechSynthesis InIPASpeechSynthesisObj, 
		UPARAM(DisplayName = "Voice") FVoice InVoice)
	{
		return InIPASpeechSynthesisObj;
	};

	/** Activates speech synthesis channel phoneme functionality 'o' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_o" ))
	IPASpeechSynthesis IPASpeechSynthesis_o(UPARAM(DisplayName = "IPASpeechSynthesis") IPASpeechSynthesis InIPASpeechSynthesisObj, 
		UPARAM(DisplayName = "Voice") FVoice InVoice)
	{
		return InIPASpeechSynthesisObj;
	};

	/** Activates speech synthesis channel phoneme functionality 'w' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_w" ))
	IPASpeechSynthesis IPASpeechSynthesis_w(UPARAM(DisplayName = "IPASpeechSynthesis") IPASpeechSynthesis InIPASpeechSynthesisObj, 
		UPARAM(DisplayName = "Voice") FVoice InVoice)
	{
		return InIPASpeechSynthesisObj;
	};

	/** Activates speech synthesis channel phoneme functionality 'r' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_r" ))
	IPASpeechSynthesis IPASpeechSynthesis_r(UPARAM(DisplayName = "IPASpeechSynthesis") IPASpeechSynthesis InIPASpeechSynthesisObj, 
		UPARAM(DisplayName = "Voice") FVoice InVoice)
	{
		return InIPASpeechSynthesisObj;
	};

	/** Activates speech synthesis channel phoneme functionality 'd' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_d" ))
	IPASpeechSynthesis IPASpeechSynthesis_d(UPARAM(DisplayName = "IPASpeechSynthesis") IPASpeechSynthesis InIPASpeechSynthesisObj, 
		UPARAM(DisplayName = "Voice") FVoice InVoice)
	{
		return InIPASpeechSynthesisObj;
	};
	
};
