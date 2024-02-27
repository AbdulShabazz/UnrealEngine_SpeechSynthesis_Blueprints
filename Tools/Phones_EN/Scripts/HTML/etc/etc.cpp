

// Struct to encapsulate SIN parameters //
template<typename T = double, Unsigned U = unsigned long long>
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
    U blendParams {};
};

template <typename PRECISION = unsigned long long>
PRECISION to_uLL(/*BLEND_COMPONENT*/BLEND_STRATEGY blend)
{
    return static_cast<PRECISION>(blend);
}

unsigned long long blend = to_uLL<>(BLEND_STRATEGY::amplitude_LERP) | to_uLL<>(BLEND_STRATEGY::frequency_LERP);

enum class BLEND_STRATEGY : unsigned long long
{
    // amplitude //
    amplitude_LERP = 1 << 1,
    amplitude_CUBIC = 1 << 2,
    amplitude_QUARTIC = 1 << 3,
    
    // frequency //
    frequency_LERP = 1 << 4,
    frequency_CUBIC = 1 << 5,
    frequency_QUARTIC = 1 << 6,
    
    // phase //
    phase_LERP = 1 << 7,
    phase_CUBIC = 1 << 8,
    phase_QUARTIC = 1 << 9,
};

// (global) Interpolate parameters //
//double amplitude {};
//double frequency {};
//double phase {};
//double cumulativePhase {};

/*
enum class BLEND_COMPONENT : unsigned long long
{
    amplitude = 1 << 1,
    frequency = 1 << 2,
    phase = 1 << 3,
};
*/

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
/* 
    if (blendParams == BLEND_COMPONENT::amplitude
        && time >= blendStart
        && time <= blendEnd ) 
    {
        const double b_bandwidth = blendEnd - blendStart;
        const double a_bandwidth = std::abs(amplitudeEnd - amplitudeStart);

        if (amplitudeStart >= amplitudeEnd) 
        {
            const double bl_step = a_bandwidth / b_bandwidth;

            amplitude = amplitudeStart - bl_step * (time - blendStart);
        } else {
            const double bl_step = a_bandwidth / b_bandwidth;

            amplitude = amplitudeStart + bl_step * (time - blendStart);
        }
    } else if (blendParams == BLEND_COMPONENT::amplitude
        && time >= blendEnd) {

        amplitude = amplitudeEnd;
    }
*/

//#include <unordered_map>
//#include <functional>

            /*
            const bool interval_has_3_control_points = ((idx + 2) < pts.size());
            const bool interval_has_2_control_points = ((idx + 1) < pts.size());
            
            if (interval_has_3_control_points
            && iframe >= pts[idx + 2].frame) ++iframe;

            else if (interval_has_2_control_points
            && iframe >= pts[idx + 1].frame) ++iframe;
            */
            // if (saturatedFlag_a) ++iframe;
            // if (iframe >= pts[idx].frame) ++idx;
            //if (saturatedFlag_f) ++iframe;
            //if (iframe >= pts[idx].frame) ++idx;
