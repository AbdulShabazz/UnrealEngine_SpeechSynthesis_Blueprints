#include <cmath>
#include <vector>
#include <iostream>

double LERP(double start
    , double end
    , double t)
{
    const double result = (1-t) * start + end * t;

    return result;
}

enum class BLEND_COMPONENT : unsigned long long {
    amplitude = 1 << 1,
    frequency = 1 << 2,
    phase = 1 << 3,
};

template <typename PRECISION = unsigned long long>
PRECISION to_uLL(BLEND_COMPONENT blend)
{
    return static_cast<PRECISION>(blend);
}

// (global) Interpolate parameters
double amplitude {};
double frequency {};
double phase {};
double cumulativePhase {};
    
double Sin(double time
    , double TIME
    , double amplitudeStart
    , double amplitudeEnd
    , double frequencyStart
    , double frequencyEnd
    , double phaseStart
    , double phaseEnd
    , double blendStart
    , double blendEnd
    , unsigned long long blendParams)
{

    //double amplitude = interpolate(amplitudeStart, amplitudeEnd, t);
    //const double frequency = interpolate(frequencyStart, frequencyEnd, t);
    //double phase = interpolate(phaseStart, phaseEnd, t);
/* 
    if (blendParams == BLEND_COMPONENT::frequency
        && blendStart <= time
        && blendEnd >= time ) 
    {
        const double b_bandwidth = blendEnd - blendStart;

        if (frequencyStart >= frequencyEnd) 
        {
            const double f_bandwidth = frequencyEnd - frequencyStart;

            const double bl_step = f_bandwidth / b_bandwidth;

            frequency = frequencyStart - bl_step * (time - blendStart);
        } else {
            const double f_bandwidth = frequencyStart - frequencyEnd;

            const double bl_step = f_bandwidth / b_bandwidth;

            frequency = frequencyStart + bl_step * (time - blendStart);
        }
    }
*/
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
    const double deltaTime = 1; // in our case, timesteps are measured in individual frames
    const double oldFrequency = frequency;
    cumulativePhase += 2 * M_PI * oldFrequency * deltaTime / TIME;

    if (blendParams & to_uLL<>(BLEND_COMPONENT::frequency))
    {
        if (time >= blendStart
            && time <= blendEnd ) 
        {
            // Blend factor, between the range [0,1] //
            const double t = (time - blendStart + 1) / (blendEnd - blendStart + 1); // LERP factor, avoid division by zero
            frequency = LERP(frequencyStart, frequencyEnd, t);

            // Adjust phase to match the instantaneous phase at the time of frequency change //
            phase = cumulativePhase - 2 * M_PI * frequency / TIME * (time + deltaTime);
        } else if (time >= blendEnd) {
            frequency = frequencyEnd;
        }
    }

    if (blendParams & to_uLL<>(BLEND_COMPONENT::amplitude))
    {
        if (time >= blendStart
            && time <= blendEnd ) 
        {
            // Blend factor, between the range [0,1] //
            const double t = (time - blendStart) / (blendEnd - blendStart);
            amplitude = LERP(amplitudeStart, amplitudeEnd, t);
        } else if (time >= blendEnd) {
            amplitude = amplitudeEnd;
        }
    }

    // Generate the signal with interpolated parameters
    const double result = amplitude * sin(2 * M_PI * frequency / TIME * time + phase);

    return result;
}

int main()
{
    double time = 0.0; // Example time point
    const double TIME = 2e3;
    double blendStart = 600, blendEnd = 1500;
    double amplitudeStart = 1.0, amplitudeEnd = 2.0;
    double frequencyStart = 40.0, frequencyEnd = 5.0;
    double phaseStart = 0.0, phaseEnd = 0.0; // Assuming no phase shift, initially
    
    unsigned long long blend = to_uLL<>(BLEND_COMPONENT::amplitude) | to_uLL<>(BLEND_COMPONENT::frequency);
    
    std::cout << "points = [ ";
    
    // (global) Interpolate parameters
    amplitude = amplitudeStart;
    frequency = frequencyStart;
    phase = phaseStart;
    
    for(double time = 0; time < TIME; ++time) {

        // signalValue contains the value of the signal at time `time` with interpolated parameters
        const double signalValue = Sin(time
            , TIME
            , amplitudeStart
            , amplitudeEnd
            , frequencyStart
            , frequencyEnd
            , phaseStart
            , phaseEnd
            , blendStart
            , blendEnd
            , blend);
        
        std::cout << signalValue << (time + 1 < TIME ? ", " : "") ;
    }
    
    std::cout << " ]";
    
    return 0;
}
