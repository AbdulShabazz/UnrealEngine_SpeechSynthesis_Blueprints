#pragma once

#include <memory.h>
#include <vector>
#include "OscillatorConfig.h"

class FPhone {

public:
     FPhone() {}
    ~FPhone() {}

    std::vector<float> getSpeechSampleTensorFloat32() const {
        return speechSample_TensorFloat32;
    }

    oscillatorConfig getOscillatorConfig() const {
        return m_oscillatorConfig;
    }

    void setOscillatorConfig(const oscillatorConfig& config) {
        m_oscillatorConfig = config;
    };

    std::vector<float> speechSample_TensorFloat32{};
    oscillatorConfig m_oscillatorConfig{};
};
