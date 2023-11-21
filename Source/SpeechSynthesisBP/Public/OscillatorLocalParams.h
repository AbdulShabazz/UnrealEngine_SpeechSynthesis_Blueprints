#pragma once

// forward declarations
enum class WaveShape : uint32_t;

struct TimeInterval {
    double value;
    explicit TimeInterval(double val) : value(val) {}
};

/**
@details C++20 concept to check if two types are bitwise operations compatible.
@tparam T The first type.
@tparam U The second type.*/
template <typename T>
concept bitwise_ops_compatible_shapeType = requires( T t ) {
    static_cast<uint32_t>( t ) & static_cast<uint32_t>( 1 );
    static_cast<uint32_t>( t ) | static_cast<uint32_t>( 1 );
};

/**
@brief An OscillatorParameters class used to configure formant signals chains.
@details An OscillatorParameters class used to configure formant signals chains. A C++20 concept to check if two types are bitwise operations compatible.
*/
template <
    typename AmplitudeType = double,
    typename FrequencyHzType = double,
    typename ThetaType = double,
    typename ShapeType = WaveShape,
    typename OutputShapeType = double,
    typename TimeStepType = double
>
requires ( bitwise_ops_compatible_shapeType<ShapeType> )
class OscillatorParameters {
public:
    AmplitudeType amplitude{};
    FrequencyHzType frequencyHz{};
    ThetaType theta{};
    ShapeType shape{};
    OutputShapeType outputShape{};
    TimeStepType timeStepStart{};
    TimeStepType timeStepEnd{};
    TimeInterval timeInterval{}; 
    /*bool isaComplexWaveShape_flag{};*/
    bool usesTimeInterval_flag{};
    bool advanceSample_flag{};
    int8_t formantNumber_Int8{};

    // Constructor, getters, setters, etc. as needed
};
