#include <cmath>
#include <vector>
#include <iostream>
#include <concepts>
#include <cstdint>

/**
 * Calculates a smooth transition between 0 and 1 using a linear interpolation.
 * This function can be used to apply linear effects to your values.
 * 
 * @brief Usage example for a linear step algorithm
 * @param {number} x - The input value for which to calculate the smoothstep, typically time or a normalized parameter.
 * @param {number} min - The lower bound of the input range.
 * @param {number} max - The upper bound of the input range.
 * @returns {number} - The smoothly interpolated value between 0 and 1. */
template<typename PRECISION = double>
PRECISION linearStep(
      PRECISION x
    , PRECISION min
    , PRECISION max)
{
    if (x <= min) return 0;
    if (x >= max) return 1;
    
    const PRECISION stepRatio = (x - min) / (max - min);
    
    return stepRatio;
}

/**
 * Performs cubic Hermite interpolation between two values bound within an interval.
 * 
 * @param {number} t - The interpolation factor, ranging from 0.0 (start) to 1.0 (end).
 * @param {number} p0 - The starting value of the interpolation (at t=0).
 * @param {number} p1 - The ending value of the interpolation (at t=1).
 * @param {number} m0 - The tangent (slope) at the starting point.
 * @param {number} m1 - The tangent (slope) at the ending point.
 * @returns {number} - The interpolated value. */
template<typename PRECISION = double>
PRECISION cubicHermite(
      PRECISION t
    , PRECISION p0
    , PRECISION p1
    , PRECISION m0
    , PRECISION m1)
{
    const PRECISION t2 = t * t;
    const PRECISION t3 = t2 * t;
    return (2 * t3 - 3 * t2 + 1) * p0 + (t3 - 2 * t2 + t) * m0 + (-2 * t3 + 3 * t2) * p1 + (t3 - t2) * m1;
}

/**
 * Combines quartic ease-in and ease-out into a single function.
 * Accelerates from start and decelerates to stop.
 * @param {number} startValue - The starting value of the parameter to interpolate.
 * @param {number} endValue - The ending value of the parameter to interpolate.
 * @param {number} t - The interpolation factor, between 0.0 (start) and 1.0 (end).
 * @returns {number} The interpolated value. */
template<typename PRECISION = double>
PRECISION quarticEaseInOut(
      PRECISION tt
    , PRECISION startValue
    , PRECISION endValue)
{
    PRECISION t = std::max(0.0, std::min(1.0, tt)); // Clamp t to the range [0, 1] //
    
    if (t < 0.5) {
        return startValue + (endValue - startValue) * 8 * t * t * t * t;
    } else {
        t = t - 1;
        return startValue + (endValue - startValue) * (1 - 8 * t * t * t * t);
    }
}

double LERP(
      double t
    , double start
    , double end)
{
    const double result = (1-t) * start + end * t;

    return result;
}

enum class BLEND_STRATEGY
{
    LERP = 1 << 1,
    CUBIC,
    QUARTIC,
};

// Define a concept for unsigned types //
template<typename T>
concept Unsigned = std::is_unsigned_v<T>;

// Struct to encapsulate SIN parameters //
template<typename T = double, Unsigned U = unsigned long long>
struct WaveShape
{
    
};

// Struct to encapsulate SIN parameters //
template<typename T = double>
struct signalParameters
{
    T time {};
    T TIME {};
    T deltaTime {};
    T amplitude {};
    T amplitudeStart {};
    T amplitudeEnd {};
    T amplitudeBlendStartFrame {};
    T amplitudeBlendEndFrame {};
    BLEND_STRATEGY amplitudeBlendStrategy = BLEND_STRATEGY::LERP;
    T frequency {};
    T frequencyStart {};
    T frequencyEnd {};
    T frequencyBlendStartFrame {};
    T frequencyBlendEndFrame {};
    BLEND_STRATEGY frequencyBlendStrategy = BLEND_STRATEGY::LERP;
    T phase {};
    T phaseStart {};
    T phaseEnd {};
    T phaseBlendStartFrame {};
    T phaseBlendEndFrame {};
    BLEND_STRATEGY phaseBlendStrategy = BLEND_STRATEGY::LERP;
    long double cumulativePhase {};
};

template<typename PRECISION = double>
PRECISION do_Blend(
      BLEND_STRATEGY blend
    , PRECISION blendRatio
    , PRECISION startValue
    , PRECISION endValue
    , PRECISION startValueSlope = 0.0f
    , PRECISION endValueSlope = 0.0f)
{
    PRECISION value {};
    
    switch(blend)
    {
        case BLEND_STRATEGY::LERP:
        value = LERP(blendRatio, startValue, endValue);
        break;
        
        case BLEND_STRATEGY::CUBIC:
        value = cubicHermite<PRECISION>(blendRatio, startValue, endValue, 0.0f, 0.0f);
        break;
        
        case BLEND_STRATEGY::QUARTIC:
        value = quarticEaseInOut(blendRatio, startValue, endValue);
        break;
        
        default:
        value = startValue;
        break;
    }
    
    return value;
}

template<typename PRECISION = double>    
double SIN(signalParameters<PRECISION>& params)
{
    /**
    
    Adjusting the phase in your algorithm to maintain smoothness, 
    especially during frequency transitions, requires a careful approach. 
    The goal is to ensure that when the frequency changes, 
    the phase does not introduce discontinuities or abrupt changes in the waveform. 
    Here's an approach to adjust the phase dynamically to accommodate changes 
    in frequency smoothly:
    
    1. Track the cumulative phase of the signal over time.
    
    This phase needs to be updated every time you generate a sample.
    
    2. Adjust Phase During Frequency Transition

    When you change the frequency, adjust the starting phase 
    of the new frequency to match the instantaneous phase of the ongoing signal. 
    This helps in avoiding phase discontinuities.
    
    **/
    
    const double oldFrequency = params.frequency;
    params.cumulativePhase += 2 * M_PI * oldFrequency * params.deltaTime / params.TIME;

    if (static_cast<bool>(params.frequencyBlendStrategy))
    {
        // Blend factor, between the range [0,1] //
        const double t = linearStep(params.time, params.frequencyBlendStartFrame, params.frequencyBlendEndFrame);
        
        params.frequency = do_Blend(params.frequencyBlendStrategy, t, params.frequencyStart, params.frequencyEnd);

        // Adjust phase to match the instantaneous phase at the time of frequency change //
        params.phase = params.cumulativePhase - 2 * M_PI * params.frequency / params.TIME * (params.time + params.deltaTime);
    }

    if (static_cast<bool>(params.amplitudeBlendStrategy))
    {
        // Blend factor, between the range [0,1] //
        const double t = linearStep(params.time, params.amplitudeBlendStartFrame, params.amplitudeBlendEndFrame);
        
        params.amplitude = do_Blend(params.amplitudeBlendStrategy, t, params.amplitudeStart, params.amplitudeEnd);
    }

    // Generate the signal with interpolated parameters //
    const double result = params.amplitude * sin(2 * M_PI * params.frequency / params.TIME * params.time + params.phase);

    return result;
}

int main()
{
    double time = 0.0; // Example time point //
    const double TIME = 2e3;
    double blendStart = 600, blendEnd = 1500;
    double amplitudeStart = 1.0, amplitudeEnd = 2.0;
    double frequencyStart = 40.0, frequencyEnd = 5.0;
    double phaseStart = 0.0, phaseEnd = 0.0; // Assuming no phase shift, initially //
    
    std::cout << "points = [ ";
    
    signalParameters<> params
    {
        .TIME = TIME,
        .deltaTime = 1, // in our case, timesteps are measured in discrete frames //
        .amplitude = amplitudeStart,
        .amplitudeStart = amplitudeStart,
        .amplitudeEnd = amplitudeEnd,
        .amplitudeBlendStartFrame = blendStart,
        .amplitudeBlendEndFrame = blendEnd,
        .amplitudeBlendStrategy = BLEND_STRATEGY::LERP,
        .frequency = frequencyStart,
        .frequencyStart = frequencyStart,
        .frequencyEnd = frequencyEnd,
        .frequencyBlendStartFrame = blendStart,
        .frequencyBlendEndFrame = blendEnd,
        .frequencyBlendStrategy = BLEND_STRATEGY::LERP,
        .phase = phaseStart,
    };
    
    for(double time = 0; time < TIME; ++time) {

        // signalValue contains the value of the signal at time `time` with interpolated parameters //
        
        params.time = time;
        
        const double signalValue = SIN(params);
        
        std::cout << signalValue << ", " ;
    }
    
    std::cout << " ]";
    
    return EXIT_SUCCESS;
}
