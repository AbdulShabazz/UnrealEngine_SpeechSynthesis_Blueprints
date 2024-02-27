
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
