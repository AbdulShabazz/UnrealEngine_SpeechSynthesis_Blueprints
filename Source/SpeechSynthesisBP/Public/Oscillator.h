#pragma once

#include <cmath>
#include <memory>
#include <chrono>
#include <concepts>
#include <functional>

#include "OscillatorConfig.h"
#include "OscillatorLocalParams.h"

/**
@brief C++20 concept to check if two types are bitwise operations compatible.
@details C++20 concept to check if two types are bitwise operations compatible.
@tparam T The first type.
@tparam U The second type.*/
template <typename T, typename U>
concept bitwise_ops_compatible = requires(T t, U u) {
    static_cast<uint32_t>(t) & static_cast<uint32_t>(u);
    static_cast<uint32_t>(t) | static_cast<uint32_t>(u);
};

/**
@brief The Oscillator class is used to generate various waveforms.
@details The Oscillator class is used to generate various waveforms. The waveforms are generated using the following formulas:

Waveform Generation:

Sine Wave:
    Formula: A * sin(2 * PI * f * t + theta)

    Where:
        A is amplitude.
        f is frequency.
        t is time.
        theta is phase.

Forward Sawtooth Wave:
    Formula: A * (2 * (t * f - floor(0.5 + t * f)))

Reverse Sawtooth Wave:
    Formula: A * (1 - 2 * (t * f - floor(t * f)))

Triangle Wave:
    Formula: A * (2 * abs(2 * (t * f - floor(0.5 + t * f))) - 1)

Square Wave:
    Formula: A * sign(sin(2 * PI * f * t))

Quarter- and Half-Period signals:
    Modify t (time) in your formulas to accommodate quarter-period or half-period generation.
    For a quarter-period, use t mod (1 / (4 * f)), and for a half-period, use t mod (1 / (2 * f)).

Parameter Specification:
    Amplitude (A) is specified in the range 0.0 to 1.0.
    Frequency (f) is specified in Hertz (Hz).
    Phase (theta) is specified in the range 0.0 to 1.0.
    Time (t) is specified in seconds (s).

Output:
    Waveform signal.

Example usage:

int main() {
    Oscillator osc(1.0, 440.0, 0.0); // Example: Amplitude = 1.0, Frequency = 440 Hz, Phase = 0
    // Generate and output waveforms...
    return 0;
}*/
class Oscillator {
public:

    /**
    @brief The UpdateFunction class is used to (custom) update the oscillator parameters at time-step (t).
    @details The UpdateFunction class is used to (custom) update the oscillator parameters at time-step (t).
    @param Oscillator_sharedPtr: A shared pointer to the Oscillator class (*self).
    @param Amplitude_numericType: The amplitude of the oscillator signal.
    @param FrequencyHz_numericType: The frequency of the oscillator signal.
    @param Theta_numericType: The phase of the oscillator signal.
    @param Shape_numericType: The wave-shape of the oscillator signal.
    @param OutputShape_numericType: The output shape of the oscillator signal.
    @param TimeStepStart_numericType: The time-step (t) at which the oscillator is to be evaluated.
    @param TimeStepEnd_numericType: The time-step (tEnd) at which the oscillator is to be evaluated.
    @param TimeStepInterval_TimeIntervalType: The time-step (t) at which the oscillator is to be evaluated.
    @return OutputShape_numericType (The oscillator signal at time-step t).*/
    template <typename OutputShape_numericType = double,
        typename AmplitudeType = double,
        typename FrequencyHzType = double,
        typename ThetaType = double,
        typename ShapeType = enum class WaveShape,
        typename OutputShapeType = double,
        typename TimeStepType = double,
        typename OscillatorParameterType = OscillatorParameters<AmplitudeType
        , FrequencyHzType
        , ThetaType
        , ShapeType
        , OutputShapeType
        , TimeStepType>
    >
    using UpdateFunction = 
        std::function<OutputShape_numericType(
            std::shared_ptr<class Oscillator>
            , OscillatorParameterType
        )>;

    enum class WaveShape : uint32_t {
        Sine_enum = 1 << 0, 
        Cosine_enum = 1 << 1, 
        QuarterSine_enum = 1 << 2, 
        HalfSine_enum = 1 << 3, 
        Triangle_enum = 1 << 4, 
        Square_enum = 1 << 5, 
        ForwardSawtooth_enum = 1 << 6, 
        ReverseSawtooth_enum  = 1 << 7,
        WhiteNoise_enum = 1 << 8,
        BrownNoise_enum = 1 << 9,
        PinkNoise_enum = 1 << 10,
        YellowNoise_enum = 1 << 11,
        BlueNoise_enum = 1 << 12,
        GreyNoise_enum = 1 << 13,
    };

    enum class ComplexWaveShape : uint32_t {};

    /**
    @brief Overloaded bitwise AND operator for the WaveShape enum class and ComplexWaveShape enum class.
    @details Overloaded bitwise AND operator for the WaveShape enum class and ComplexWaveShape enum class.
    @param a The enum class WaveShape or ComplexWaveShape.
    @param b The enum class WaveShape or ComplexWaveShape.*/
    template<typename T, typename U>
    requires(bitwise_ops_compatible<T, U>)
    ComplexWaveShape boolean_and (const T& a, const U& b) {
        return static_cast<ComplexWaveShape>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b));
    }

    /**
    @brief Overloaded bitwise OR operator for the WaveShape enum class and ComplexWaveShape enum class.
    @details Overloaded bitwise OR operator for the WaveShape enum class and ComplexWaveShape enum class.
    @param a The enum class WaveShape or ComplexWaveShape.
    @param b The enum class WaveShape or ComplexWaveShape.*/
    template<typename T, typename U>
    requires(bitwise_ops_compatible<T, U>)
    ComplexWaveShape boolean_or (const T& a, const U& b) {
        return static_cast<ComplexWaveShape>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
    }

    Oscillator() = default;
    
    /**
    @brief Generates a Sine wave.
    @param timeStep_constDouble: The time-step (t) at which the oscillator is to be evaluated.
    @return double ( The oscillator signal at time-step t).*/
    double sine(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble
        , const double theta_constDouble) const {
        return amplitude_constDouble * std::sin(2 * PI_HiRes * frequencyHz_double * timeStep_constDouble + theta_constDouble);
    }

    /**
    @brief Generates a Cosine wave.
    @param timeStep_constDouble: The time-step (t) at which the oscillator is to be evaluated.
    @return double ( The oscillator signal at time-step t).*/
    double cosine(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble
        , const double theta_constDouble) const {
        return amplitude_constDouble * std::cos(2 * PI_HiRes * frequencyHz_double * timeStep_constDouble + theta_constDouble);
    }

    /**
    @brief Generates a Quarter-Sine wave.
    @param timeStep_constDouble: The time-step (t) at which the oscillator is to be evaluated.
    @return double ( The oscillator signal at time-step t).*/
    double quarterSine(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble
        , const double theta_constDouble) const {
        const double quarterPeriod_constDouble = 1 / (4 * frequencyHz_double);
        return amplitude_constDouble * std::sin(2 * PI_HiRes * std::fmod(std::abs(timeStep_constDouble), quarterPeriod_constDouble) + theta_constDouble);
    }

    /**
    @brief Generates a Half-Sine wave.
    @param timeStep_constDouble: The time-step (t) at which the oscillator is to be evaluated.
    @return double ( The oscillator signal at time-step (t).*/
    double halfSine(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble
        , const double theta_constDouble) const {
        const double halfPeriod_constDouble = 1 / (2 * frequencyHz_double);
        return amplitude_constDouble * std::sin(2 * PI_HiRes * std::fmod(std::abs(timeStep_constDouble), halfPeriod_constDouble) + theta_constDouble);
    }

    /**
    @brief Generates a Forward Sawtooth wave.
    @param timeStep_constDouble: The time-step (t) at which the oscillator is to be evaluated.
    @return double ( The oscillator signal at time-step (t).*/
    double forwardSaw(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble) const {
        return amplitude_constDouble * (2 * (timeStep_constDouble * frequencyHz_double - std::floor(0.5 + timeStep_constDouble * frequencyHz_double)));
    }

    /**
    @brief Generates a Reverse Sawtooth wave.
    @param timeStep_constDouble: The time-step (t) at which the oscillator is to be evaluated.
    @return double ( The oscillator signal at time-step (t).*/
    double ReverseSaw(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble) const {
        return amplitude_constDouble * (1 - 2 * (timeStep_constDouble * frequencyHz_double - std::floor(timeStep_constDouble * frequencyHz_double)));
    }

    /**
    @brief Generates a Triangle wave.
    @param timeStep_constDouble: The time-step (t) at which the oscillator is to be evaluated.
    @return double (The oscillator signal at time-step t).*/
    double Triangle(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble) const {
        return amplitude_constDouble * (2 * std::abs(2 * (timeStep_constDouble * frequencyHz_double - std::floor(0.5 + timeStep_constDouble * frequencyHz_double))) - 1);
    }

    /**
    @brief Generates a Square wave.
    @param timeStep_constDouble: The time-step (t) at which the oscillator is to be evaluated.
    @return double (The oscillator signal at time-step t).*/
    double Square(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble) const {
        return amplitude_constDouble * std::signbit(std::sin(2 * PI_HiRes * frequencyHz_double * timeStep_constDouble));
    }

    /**
    @brief Generate a white noise signal.
    @param timeStep_constDouble
    @return double */
    double whiteNoise(const double amplitude_constDouble) const {
        return amplitude_constDouble * (2.0 * ((double)rand() / (double)RAND_MAX) - 1.0);
    }

    /**
    @brief Generate a brown noise signal.
    @param timeStep_constDouble
    @return double */
    double brownNoise(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble) const {
        static double brownNoiseValue_double {};
        static double lastBrownNoiseValue_double {};
        static double brownNoiseIncrement_double {};
        static double brownNoiseDecay_double {};

        if (brownNoiseIncrement_double == 0.0) {
            brownNoiseIncrement_double = 1.0 / (frequencyHz_double * 0.1);
            brownNoiseDecay_double = std::exp(-1.0 / (frequencyHz_double * 0.1));
        }

        brownNoiseValue_double = (brownNoiseValue_double + brownNoiseIncrement_double * (2.0 * ((double)rand() / (double)RAND_MAX) - 1.0)) * brownNoiseDecay_double;
        return amplitude_constDouble * (brownNoiseValue_double - lastBrownNoiseValue_double);
    }

    /**
    @brief Generate a pink noise signal.
    @param timeStep_constDouble
    @return double */
    double pinkNoise(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble) const {
        static double pinkNoiseValue_double {};
        static double lastPinkNoiseValue_double {};
        static double pinkNoiseIncrement_double {};
        static double pinkNoiseDecay_double {};

        if (pinkNoiseIncrement_double == 0.0) {
            pinkNoiseIncrement_double = 1.0 / (frequencyHz_double * 0.1);
            pinkNoiseDecay_double = std::exp(-1.0 / (frequencyHz_double * 0.1));
        }

        pinkNoiseValue_double = (pinkNoiseValue_double + pinkNoiseIncrement_double * (2.0 * ((double)rand() / (double)RAND_MAX) - 1.0)) * pinkNoiseDecay_double;
        return amplitude_constDouble * (pinkNoiseValue_double - lastPinkNoiseValue_double);
    }

    /**
    @brief Generate a yellow noise signal.
    @param timeStep_constDouble
    @return double */
    double yellowNoise(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble) const {
        static double yellowNoiseValue_double {};
        static double lastYellowNoiseValue_double {};
        static double yellowNoiseIncrement_double {};
        static double yellowNoiseDecay_double {};

        if (yellowNoiseIncrement_double == 0.0) {
            yellowNoiseIncrement_double = 1.0 / (frequencyHz_double * 0.1);
            yellowNoiseDecay_double = std::exp(-1.0 / (frequencyHz_double * 0.1));
        }

        yellowNoiseValue_double = (yellowNoiseValue_double + yellowNoiseIncrement_double * (2.0 * ((double)rand() / (double)RAND_MAX) - 1.0)) * yellowNoiseDecay_double;
        return amplitude_constDouble * (yellowNoiseValue_double - lastYellowNoiseValue_double);
    }

    /**
    @brief Generate a blue noise signal.
    @param timeStep_constDouble
    @return double */
    double blueNoise(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble) const {
        static double blueNoiseValue_double {};
        static double lastBlueNoiseValue_double {};
        static double blueNoiseIncrement_double {};
        static double blueNoiseDecay_double {};

        if (blueNoiseIncrement_double == 0.0) {
            blueNoiseIncrement_double = 1.0 / (frequencyHz_double * 0.1);
            blueNoiseDecay_double = std::exp(-1.0 / (frequencyHz_double * 0.1));
        }

        blueNoiseValue_double = (blueNoiseValue_double + blueNoiseIncrement_double * (2.0 * ((double)rand() / (double)RAND_MAX) - 1.0)) * blueNoiseDecay_double;
        return amplitude_constDouble * (blueNoiseValue_double - lastBlueNoiseValue_double);
    }

    /**
    @brief Generate a grey noise signal.
    @param timeStep_constDouble - The time-step (t) at which the oscillator is to be evaluated.
    @return double */
    double greyNoise(const double amplitude_constDouble
        , const double frequencyHz_double
        , const double timeStep_constDouble) const {
        static double greyNoiseValue_double {};
        static double lastGreyNoiseValue_double {};
        static double greyNoiseIncrement_double {};
        static double greyNoiseDecay_double {};

        if (greyNoiseIncrement_double == 0.0) {
            greyNoiseIncrement_double = 1.0 / (frequencyHz_double * 0.1);
            greyNoiseDecay_double = std::exp(-1.0 / (frequencyHz_double * 0.1));
        }

        greyNoiseValue_double = (greyNoiseValue_double + greyNoiseIncrement_double * (2.0 * ((double)rand() / (double)RAND_MAX) - 1.0)) * greyNoiseDecay_double;
        return amplitude_constDouble * (greyNoiseValue_double - lastGreyNoiseValue_double);
    }

    /**
    @brief Generates basic signal based on specific wave-shape parameters.
    @details Generates basic signal based on specific wave-shape parameters.
    @param shapes_oscilatorParamsVec: The complex wave-shapes to develop.
    @param customUpdateCallback: A lambda function that can be used to update the oscillator parameters.
    @return double (The oscillator signal at time-step t).*/
    template <
        typename AmplitudeType = double,
        typename FrequencyHzType = double,
        typename ThetaType = double,
        typename ShapeType = WaveShape,
        typename OutputShapeType = double,
        typename TimeStepType = double,
        typename OscillatorParameterType
    >
    requires ( bitwise_ops_compatible_shapeType<ShapeType> )
    double generateBasicSignal(const OscillatorParameters<AmplitudeType
        , FrequencyHzType
        , ThetaType
        , ShapeType
        , OutputShapeType
        , TimeStepType>& shape_oscillatorParams
        , UpdateFunction<OscillatorParameterType, OutputShapeType> customUpdateCallback) {

        double outShape {};

        // Custom updates using the lambda function
        if (customUpdateCallback) {
            outShape = customUpdateCallback(
                std::make_shared<Oscillator>(*this),
                shape_oscillatorParams,
                outShape);
        } else {
            switch (shape_oscillatorParams.shape) {
                case WaveShape::Sine_enum:
                    outShape = sine (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart
                        , shape_oscillatorParams.theta);
                    break;
                case WaveShape::Cosine_enum:
                    outShape = cosine (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart
                        , shape_oscillatorParams.theta );
                    break;
                case WaveShape::QuarterSine_enum:
                    outShape = quarterSine (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart
                        , shape_oscillatorParams.theta);
                    break;
                case WaveShape::HalfSine_enum:
                    outShape = halfSine (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart
                        , shape_oscillatorParams.theta);
                    break;
                case WaveShape::Triangle_enum:
                    outShape = Triangle (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    break;
                case WaveShape::Square_enum:
                    outShape = Square(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    break;
                case WaveShape::ForwardSawtooth_enum:
                    outShape = forwardSaw (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    break;
                case WaveShape::ReverseSawtooth_enum:
                    outShape = ReverseSaw (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    break;
                case WaveShape::WhiteNoise_enum:
                    outShape = whiteNoise (shape_oscillatorParams.amplitude_constDouble);
                    break;
                case WaveShape::BrownNoise_enum:
                    outShape = brownNoise (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    break;
                case WaveShape::PinkNoise_enum:
                    outShape = pinkNoise (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    break;
                case WaveShape::YellowNoise_enum:
                    outShape = yellowNoise (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    break;
                case WaveShape::BlueNoise_enum:
                    outShape = blueNoise (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    break;
                case WaveShape::GreyNoise_enum:
                    outShape = greyNoise (shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    break;
                default:
                    throw std::invalid_argument("Unexpected or Unknown wave-shape.");
            }

            return outShape;
        }
    } // End of generateBasicSignal() function

    /**
    @brief Generates basic signal based on specific wave-shape parameters.
    @details Generates basic signal based on specific wave-shape parameters.
    @param shapes_oscilatorParamsVec: The complex wave-shapes to develop.
    @param customUpdateCallback: A lambda function that can be used to update the oscillator parameters.
    @return double (The oscillator signal at time-step t).*/
    template <
        typename AmplitudeType = double,
        typename FrequencyHzType = double,
        typename ThetaType = double,
        typename ShapeType = WaveShape,
        typename OutputShapeType = double,
        typename TimeStepType = double,
        typename OscillatorParameterType
    >
    requires ( bitwise_ops_compatible_shapeType<ShapeType> )
    std::vector<double> generateComplexSignal(
        const std::vector<OscillatorParameters<AmplitudeType
        , FrequencyHzType
        , ThetaType
        , ShapeType
        , OutputShapeType
        , TimeStepType>>& shapes_oscilatorParamsVec
        , UpdateFunction<OscillatorParameterType, OutputShapeType> customUpdateCallback) {

        std::vector<double> totalOutShape{};

        for (const auto& shape_oscillatorParams : shapes_oscilatorParamsVec) {
            double outShape{};

            // Custom updates using the lambda function
            if (customUpdateCallback) {
                outShape = customUpdateCallback(
                    std::make_shared<Oscillator>(*this),
                    shape_oscillatorParams,
                    outShape);
            } else {
                switch (shape_oscillatorParams.shape) {
                case boolean_and(shape_oscillatorParams.shape, WaveShape::Sine_enum):
                    outShape += sine(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart
                        , shape_oscillatorParams.theta);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::Cosine_enum):
                    outShape += cosine(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart
                        , shape_oscillatorParams.theta);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::QuarterSine_enum):
                    outShape += quarterSine(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart
                        , shape_oscillatorParams.theta);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::HalfSine_enum):
                    outShape += halfSine(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart
                        , shape_oscillatorParams.theta);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::Triangle_enum):
                    outShape += Triangle(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::Square_enum):
                    outShape += Square(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::ForwardSawtooth_enum):
                    outShape += forwardSaw(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::ReverseSawtooth_enum):
                    outShape += ReverseSaw(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::WhiteNoise_enum):
                    outShape += whiteNoise(shape_oscillatorParams.amplitude_constDouble);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::BrownNoise_enum):
                    outShape += brownNoise(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::PinkNoise_enum):
                    outShape += pinkNoise(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::YellowNoise_enum):
                    outShape += yellowNoise(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::BlueNoise_enum):
                    outShape += blueNoise(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    [[fallthrough]]
                case boolean_and(shape_oscillatorParams.shape, WaveShape::GreyNoise_enum):
                    outShape += greyNoise(shape_oscillatorParams.amplitude
                        , shape_oscillatorParams.frequencyHz
                        , shape_oscillatorParams.timeStepStart);
                    [[fallthrough]]
                default:
                    throw std::invalid_argument("Unexpected or Unknown wave-shape.");
                } // End of switch statement
            } // End of else statement
            totalOutShape.push_back(outShape);
        } // End of for loop
        return totalOutShape;
    } // End of generateComplexSignal() function

    /**
    @brief Determines if the specified wave-shape should be present in the complex wave-shape.
    @details Determines if the specified wave-shape should be present in the complex wave-shape.
    @param shape_1: The complex wave-shape or wave-shape to check.
    @param shape_2: The complex wave-shape or wave-shape to check.
    @return bool (True if the specified wave-shape should be present in the generated complex wave-shape, false otherwise).*/
    template<typename T, typename U>
    requires (bitwise_ops_compatible<T, U>)
    bool hasShape(const T& shape_1, const U& shape_2) const {
        return ( static_cast<uint32_t>( shape_1 ) & static_cast<uint32_t>( shape_2 ) );
	}

    /**
    @brief Updates the oscillator parameters at time-step (t).
    @param shape: The wave-shape to generate.
    @param t: The time-step (t) at which the oscillator should be evaluated.*/
    void updateParameters(const WaveShape& shape, const double& t) {
        switch (shape) {
            case WaveShape::Sine_enum:
                //amplitude_double = initialAmplitude * std::exp(-decayRate * t);
                break;
            case WaveShape::Cosine_enum:
                //frequencyHz_double = initialFrequency + frequencySlope * t;
                break;
            case WaveShape::Triangle_enum:
                //frequencyHz_double = initialFrequency + frequencySlope * t;
                break;
            case WaveShape::Square_enum:
                //theta_double = initialTheta + thetaSlope * t;
                break;
            case WaveShape::ForwardSawtooth_enum:
                //theta_double = initialTheta + thetaSlope * t;
                break;
            case WaveShape::ReverseSawtooth_enum:
                //theta_double = initialTheta + thetaSlope * t;
                break;
            case WaveShape::WhiteNoise_enum:
                //theta_double = initialTheta + thetaSlope * t;
                break;
            case WaveShape::BrownNoise_enum:
                //theta_double = initialTheta + thetaSlope * t;
                break;
            case WaveShape::PinkNoise_enum: 
                //theta_double = initialTheta + thetaSlope * t;
                break;
            case WaveShape::YellowNoise_enum:
                //theta_double = initialTheta + thetaSlope * t;
                break;
            case WaveShape::BlueNoise_enum:
                //theta_double = initialTheta + thetaSlope * t;
                break;
            case WaveShape::GreyNoise_enum:
                //theta_double = initialTheta + thetaSlope * t;
                break;
            default:
                throw std::invalid_argument("Unexpected or Unknown wave-shape.");
        } // End of switch statement
    } // End of updateParameters() function

protected:
    oscillatorConfig m_oscillatorConfig;
    const double PI_LoRes = 3.14159265358979323846f;
    const long double PI_HiRes = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679f;

    /*double amplitude_double {}
    , frequencyHz_double {}
    , theta_double {}
    , outputShape_double {}
    , timeStepStart_double {}
    , timeStepEnd_double {};
    TimeInterval timeInterval_double {};*/
};
