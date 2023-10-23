// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SpeechSynthesisBlueprintLibrary.generated.h"

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
	void IPASpeechSynthesis_h(UPARAM(DisplayName = "Channel Id") FName InChannelId)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'e' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_e" ))
	void IPASpeechSynthesis_e(UPARAM(DisplayName = "Channel Id") FName InChannelId)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'l' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_l" ))
	void IPASpeechSynthesis_l(UPARAM(DisplayName = "Channel Id") FName InChannelId)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'o' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_o" ))
	void IPASpeechSynthesis_o(UPARAM(DisplayName = "Channel Id") FName InChannelId)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'w' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_w" ))
	void IPASpeechSynthesis_w(UPARAM(DisplayName = "Channel Id") FName InChannelId)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'r' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_r" ))
	void IPASpeechSynthesis_r(UPARAM(DisplayName = "Channel Id") FName InChannelId)
	{

	};

	/** Activates speech synthesis channel phoneme functionality 'd' */
	UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( DisplayName = "IPASpeechSynthesis_d" ))
	void IPASpeechSynthesis_d(UPARAM(DisplayName = "Channel Id") FName InChannelId)
	{

	};
	
};
