// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "SpeechSynthesisBP.generated.h"

UCLASS(ClassGroup=(Custom), meta = (BlueprintSpawnableComponent))
class SPEECHSYNTHESISBP_API USpeechSynthesisComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	/** Returns a string cintaining the node's title */

	UFUNCTION(BlueprintCallable, Category = "SpeechSynthesis")

	static FString GetNodeTitle()
	{
		return FString("Speech Synthesis Blueprint");
	}

	/** Returns a string containing the node's tooltip */

	UFUNCTION(BlueprintCallable, Category = "SpeechSynthesis")

	static FString GetNodeTooltip()
	{
		return FString("Speech Synthesis Blueprint");
	}

	/** Execute the node */

	UFUNCTION(BlueprintCallable, Category = "SpeechSynthesis")

	static void ExecuteNode()
	{
		UE_LOG(LogTemp, Warning, TEXT("Speech Synthesis Blueprint"));
	}

};

