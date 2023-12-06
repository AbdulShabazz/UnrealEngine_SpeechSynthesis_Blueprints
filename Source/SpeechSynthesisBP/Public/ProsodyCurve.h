// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "ProsodyCurve.generated.h"

/**
@brief Acoustic attributes of speech that include pitch, loudness, tempo, and rhythm, which change over time.
@details Acoustic attributes of speech include pitch, loudness, tempo, and rhythm, which change over time.
*/		
UCLASS(Blueprintable)
class SPEECHSYNTHESISBP_API UProsodyCurve : public UAudioComponent
{
	GENERATED_BODY()
};
