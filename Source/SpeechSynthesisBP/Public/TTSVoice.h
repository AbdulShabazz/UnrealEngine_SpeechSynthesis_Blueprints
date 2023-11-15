// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OscillatorConfig.h"
#include "Components/AudioComponent.h"
#include "FPhone.h"
#include <vector>
#include <memory>
#include "TTSVoice.generated.h"


// Context class
/*
 * The context class maintains a reference to one of the state objects.
 * It delegates the state-specific requests from the client to the current state object.
 *
 * There are three (3) possible sequences expected in the context class:
 * 1. setPhone w/ m_currentPhone uninitialized > process > getSampleFloat32 --
        this is the expected startup sequence to ramp-up the signal.
 * 2. setPhone > process > getSampleFloat32 -- this is the expected next sequence
        for subsequent transition-states after the first call to setPhone
 * 3. process > getSampleFloat32 -- this is the expected sequence outside the loop, after the final call to setPhone;
        this terminates the state machine and ramps-down the signal.
 *
*/
UCLASS(Blueprintable)
class SPEECHSYNTHESISBP_API UTTSVoice : public UAudioComponent
{
	GENERATED_BODY()

public:
    
    //UFUNCTION(BlueprintCallable, Category = "TextToSpeech")
    //static std::unique_ptr<UTTSVoice> Sara() {
    //    // ...initialization specific to Sara... //
    //    return std::make_unique<UTTSVoice>();
    //}
    
    void setPhone(const FPhone& phone)
    {
        m_currentPhone = phone;
    };

    void process()
    {
        // ...generate voice-specific samples... //
    };

    std::vector<float> getSpeechSampleTensorFloat32()
    {
        return m_currentPhone.getSpeechSampleTensorFloat32();
    };

    oscillatorConfig getOscillatorConfig()
    {
        return m_currentPhone.getOscillatorConfig();
    };

    void setOscillatorConfig(const oscillatorConfig& config)
    {
        m_currentPhone.setOscillatorConfig(config);
    };

    FPhone m_currentPhone{};
    oscillatorConfig m_oscillatorConfig;

};
