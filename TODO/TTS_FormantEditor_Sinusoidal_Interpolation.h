#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <numbers>
#include <iostream>
#include <vector>

const double PI_Double = 3.14159265358979323;
const long double PI_HiRes = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196;

enum class AUDIO_COMPONENT {
	amplitude,
	frequency,
};

template<typename PRECISION = double>
struct OSC_INTERVAL {
	PRECISION frame;
	PRECISION amplitude;
	PRECISION frequency;
	PRECISION time_step;
};

template<typename PRECISION = double>
class Formant : public std::vector<std::vector<OSC_INTERVAL<PRECISION>>> {
public:
	// Forwarding constructors (optional but useful)
	using std::vector<std::vector<OSC_INTERVAL<PRECISION>>>::vector;

	enum class SHAPE : long long unsigned {
		Sine = 1 << 0,
	};

	SHAPE Shape = SHAPE::Sine;
	
	enum class PCM_RESOLUTION {
		_8_bit,
		_16_bit,
		_20_bit,
		_24_bit,
		_32_bit,
		_48_bit,
		_64_bit,
	};
	
	PCM_RESOLUTION PCM_Resolution = PCM_RESOLUTION::_32_bit;
	
	enum class PCM_SAMPLERATE {
		_44_1_kHz,
		_48_kHz,
		_88_2_kHz,
		_96_kHz,
		_192_kHz,
		_384_kHz,
		_768_kHz,
	};
	
	PCM_SAMPLERATE PCM_SampleRate = PCM_SAMPLERATE::_384_kHz;

};

/**
@brief Utility module for sinusoidal spline interpolation
@details Utility module for sinusoidal spline interpolation */
template<typename PRECISION = double>
struct InterpolationUtils {

	/**
	@brief Ensures that there are enough points for interpolation.
	@details Throws an exception if there aren't enough points for sinusoidal interpolation.
			 This is a static utility method used to validate the size of the points array
			 before performing interpolation operations.
	@param pts Pointer to the first element of an array of Formant.
	@param idx The current index within the points array to check for sufficient subsequent points.
	@throws std::runtime_error if there are not enough points for interpolation. */
	static void ensureEnoughPoints(const std::vector<OSC_INTERVAL<>>& pts
		, size_t idx) {
		if ((idx + 2) >= pts.size()) {
			throw std::runtime_error("Not enough inter-frame interpolation "
									 "steps for sinusoidal interpolation "
									 "within the specified oscillator interval: [0, 1]");
		}
	}

	/**
	@brief Calculates the sinusoidal value based on amplitude, frequency, and time.
	@details Uses the cosine function to calculate the sinusoidal value, representing
			 the value of the waveform at a given time based on its amplitude and frequency.
	@param amp The amplitude of the waveform.
	@param freq The frequency of the waveform.
	@param ts The time stamp at which to calculate the waveform's value.
	@return The calculated sinusoidal value. */
	static PRECISION calculateSinusoidalValue(PRECISION amp
		, PRECISION freq
		, PRECISION ts) {
		return amp * cos(M_PI * (freq * ts));
	}

	/**
	@brief Calculates the interpolation factor between two frames.
	@details Determines the relative position of an intermediate frame within the interval
			 defined by a starting and ending frame.
	@param frameStart The normalized start frame value.
	@param frameEnd The normalized end frame value.
	@param iframe The intermediate frame whose position is to be determined.
	@return The interpolation factor of the intermediate frame within the start and end frame interval. */
	static PRECISION getInterpolationFactor(PRECISION frameStart
		, PRECISION frameEnd
		, PRECISION iframe) {
		return std::abs((iframe - frameStart) / (frameEnd - frameStart));
	}
 
	/**
	@brief Performs linear interpolation (LERP) between two values.
	@details Calculates a value linearly interpolated between a start and end value,
			 based on a given factor that indicates the relative position between the two.
	@param start The start value for interpolation.
	@param end The end value for interpolation.
	@param factor The factor indicating the position between the start and end values.
	@return The interpolated value. */
	static PRECISION LERP(PRECISION start
		, PRECISION end
		, PRECISION factor) {
		return (1 - factor) * start + factor * end;
	}

	AUDIO_COMPONENT AudioComponent = AUDIO_COMPONENT::amplitude;

};

/**
@brief Calculates the ratio of an intermediate frame between two frames.
@details Determines the relative position of an intermediate frame within the intervals
		 defined by either the start to intermediate frame or the intermediate to end frame,
		 depending on the position of the intermediate frame.
@param frameStart The start frame of the interval.
@param intermediateFrame The intermediate frame whose ratio is to be calculated.
@param frameEnd The end frame of the interval.
@param iframe The frame to interpolate, normalized to the range [0.0, 1.0].
@return The calculated ratio of the intermediate frame within the specified interval.*/
template<typename PRECISION = double>
PRECISION calculateRatioBetweenFrames(PRECISION frameStart
	, PRECISION intermediateFrame
	, PRECISION frameEnd
	, PRECISION iframe) {
	return iframe >= intermediateFrame
			? InterpolationUtils<>::getInterpolationFactor(intermediateFrame, frameEnd, iframe)
			: InterpolationUtils<>::getInterpolationFactor(frameStart, intermediateFrame, iframe);
}

/**
@brief Sine interpolation function.
@details Sine interpolation function.  Using the sinusoidal approach to produce arcs between specified quadrants based on the trend of amplitude changes across three points.
@param pts  The formant object.
@param idx  The index of the formant object.
@param iframe  The frame to interpolate. Normalized to the range [0.0, 1.0].
@param amp  The amplitude of the oscillator signal.
@param freq  The frequency of the oscillator signal.
@param audio_component  The audio component to interpolate (eg. 'amplitude' or 'frequency'). 
@returns p_result: The oscillator signal at frame (frame) */
template<typename PRECISION = double>
std::pair<PRECISION, bool> sinusoidalSplineInterpolation(const std::vector<OSC_INTERVAL<PRECISION>>& pts
	, size_t idx
	, PRECISION iframe
	, PRECISION amp
	, PRECISION freq
	, const AUDIO_COMPONENT audioComponent) {

	InterpolationUtils<PRECISION>::ensureEnoughPoints(pts, idx);

	PRECISION retval = 0;
	bool saturated = false;

	const bool iframeInRange = (pts[idx].frame <= iframe) && (iframe <= pts[idx + 2].frame);

	if (!iframeInRange) {
		retval = (audioComponent == AUDIO_COMPONENT::amplitude) 
		? pts[idx + 2].amplitude 
		: pts[idx + 2].frequency;
		saturated = true;
		return { retval, saturated };
	}

	if (audioComponent == AUDIO_COMPONENT::amplitude) {

		const bool amplitudeIsMonotonicallyIncreasing =
			(pts[idx].amplitude <= pts[idx + 1].amplitude
			&& pts[idx + 1].amplitude <= pts[idx + 2].amplitude);

		const bool amplitudeIsCresting =
			(pts[idx].amplitude <= pts[idx + 1].amplitude
			&& pts[idx + 1].amplitude >= pts[idx + 2].amplitude);

		const bool amplitudeIsTroughing =
			(pts[idx].amplitude >= pts[idx + 1].amplitude
			&& pts[idx + 1].amplitude <= pts[idx + 2].amplitude);

		const bool amplitudeIsMonotonicallyDecreasing =
			(pts[idx].amplitude >= pts[idx + 1].amplitude
			&& pts[idx + 1].amplitude >= pts[idx + 2].amplitude);

		const bool iframeIsBeyondTheMidpoint = iframe > pts[idx + 1].frame;

		PRECISION tsRangeStart{}, tsRangeEnd{};

		// Interpolate the appropraite cosine interval for the amplitude value at the frame (iframe) between the range [0, pi/2]
		// Available ranges are [0, pi/4] and [pi/4, pi/2]
		if (amplitudeIsMonotonicallyIncreasing) {
			tsRangeStart = !iframeIsBeyondTheMidpoint ? M_PI : 3 * M_PI/4;
			tsRangeEnd = !iframeIsBeyondTheMidpoint ? 3 * M_PI/4: 2 * M_PI;
		} else if (amplitudeIsCresting) { // non-sign preseerving
			tsRangeStart = !iframeIsBeyondTheMidpoint ? M_PI / 2 : M_PI;
			tsRangeEnd = !iframeIsBeyondTheMidpoint ? M_PI : 2 * M_PI;
		} else if (amplitudeIsTroughing) { // sign preserving
			tsRangeStart = !iframeIsBeyondTheMidpoint ? M_PI / 2 : M_PI;
			tsRangeEnd = !iframeIsBeyondTheMidpoint ? M_PI : 2 * M_PI;
		} else if (amplitudeIsMonotonicallyDecreasing) {
			tsRangeStart = !iframeIsBeyondTheMidpoint ? 0 : M_PI / 2;
			tsRangeEnd = !iframeIsBeyondTheMidpoint ? M_PI / 2 : M_PI;
		}

		// Which frame interval? Calculate ratio between the current frame and the next frame
		const PRECISION ddf = calculateRatioBetweenFrames(pts[idx + 1].frame
			, pts[idx + 1].frame
			, pts[idx + 2].frame
			, iframe);

		// Interpolate an amplitude for the frame at iframe, between the range [0, pi/2]
		const PRECISION A = ddf <= 0.5
			? InterpolationUtils<PRECISION>::LERP(pts[idx + 0].amplitude, pts[idx + 1].amplitude, ddf)
			: InterpolationUtils<PRECISION>::LERP(pts[idx + 1].amplitude, pts[idx + 2].amplitude, ddf);

		const PRECISION ts = InterpolationUtils<PRECISION>::LERP(tsRangeStart, tsRangeEnd, ddf) / (tsRangeEnd - tsRangeStart);

		retval = InterpolationUtils<PRECISION>::calculateSinusoidalValue(A, 1, ts);

	} else if (audioComponent == AUDIO_COMPONENT::frequency) {

		const bool frequencyIsMonotonicallyIncreasing =
			(pts[idx].frequency <= pts[idx + 1].frequency
			&& pts[idx + 1].frequency <= pts[idx + 2].frequency);

		const bool frequencyIsCresting =
			(pts[idx].frequency <= pts[idx + 1].frequency
			&& pts[idx + 1].frequency >= pts[idx + 2].frequency);

		const bool frequencyIsTroughing =
			(pts[idx].frequency >= pts[idx + 1].frequency
			&& pts[idx + 1].frequency <= pts[idx + 2].frequency);

		const bool frequencyIsMonotonicallyDecreasing =
			(pts[idx].frequency >= pts[idx + 1].frequency
			&& pts[idx + 1].frequency >= pts[idx + 2].frequency);

		const bool iframeIsBeyondTheMidpoint2 = iframe > pts[idx + 1].frame;

		PRECISION tsRangeStart2{}, tsRangeEnd2{};

		// Interpolate the appropraite cosine interval for the frequency value at the frame (iframe) between the range [0, pi/2]
		// Available ranges are [0, pi/4] and [pi/4, pi/2]
		if (frequencyIsMonotonicallyIncreasing) {
			tsRangeStart2 = !iframeIsBeyondTheMidpoint2 ? M_PI : 3 * M_PI/4;
			tsRangeEnd2 = !iframeIsBeyondTheMidpoint2 ? 3 * M_PI/4: 2 * M_PI;
		} else if (frequencyIsCresting) { // non-sign preseerving
			tsRangeStart2 = !iframeIsBeyondTheMidpoint2 ? M_PI / 2 : M_PI;
			tsRangeEnd2 = !iframeIsBeyondTheMidpoint2 ? M_PI : 2 * M_PI;
		} else if (frequencyIsTroughing) { // sign preserving
			tsRangeStart2 = !iframeIsBeyondTheMidpoint2 ? M_PI / 2 : M_PI;
			tsRangeEnd2 = !iframeIsBeyondTheMidpoint2 ? M_PI : 2 * M_PI;
		} else if (frequencyIsMonotonicallyDecreasing) {
			tsRangeStart2 = !iframeIsBeyondTheMidpoint2 ? 0 : M_PI / 2;
			tsRangeEnd2 = !iframeIsBeyondTheMidpoint2 ? M_PI / 2 : M_PI;
		}

		// Which frame interval? Calculate ratio between the current frame and the next frame
		const PRECISION ddf2 = calculateRatioBetweenFrames(pts[idx + 1].frame
			, pts[idx + 1].frame
			, pts[idx + 2].frame
			, iframe);

		// Interpolate a frequency for the frame at iframe, between the range [0, pi/2]
		const PRECISION F = ddf2 <= 0.5
			? InterpolationUtils<PRECISION>::LERP(pts[idx + 0].frequency, pts[idx + 1].frequency, ddf2)
			: InterpolationUtils<PRECISION>::LERP(pts[idx + 1].frequency, pts[idx + 2].frequency, ddf2);

		const PRECISION ts2 = InterpolationUtils<PRECISION>::LERP(tsRangeStart2, tsRangeEnd2, ddf2);

		retval = InterpolationUtils<PRECISION>::calculateSinusoidalValue(F, 1, ts2);

	} else {

		throw std::runtime_error("Unsupported audio component: " + (audioComponent == AUDIO_COMPONENT::amplitude) ? "amplitude" : "frequency");

	}

	return { retval, saturated };
}

int main()
{

	Formant<> Formants;

	Formants.Shape = Formant<>::SHAPE::Sine;
	Formants.PCM_Resolution = Formant<>::PCM_RESOLUTION::_32_bit; // example
	Formants.PCM_SampleRate = Formant<>::PCM_SAMPLERATE::_384_kHz; // example

	// Ensure there's a vector to add your OSC_INTERVALs to
	Formants.emplace_back(); // Adds a new vector<OSC_INTERVAL<>>

	// Adding OSC_INTERVAL objects to the first vector in Formants using designated initializers
	Formants[0].push_back({ .frame=0,	.amplitude=-6.0,	.frequency=50.0 });
	Formants[0].push_back({ .frame=200,  .amplitude=-4.5,	.frequency=60.0 });
	Formants[0].push_back({ .frame=265,  .amplitude=-4.0,	.frequency=65.0 });
	Formants[0].push_back({ .frame=600,  .amplitude=-5.5,	.frequency=60.0 });
	Formants[0].push_back({ .frame=880,  .amplitude=-5.8,	.frequency=50.0 });
	Formants[0].push_back({ .frame=1040, .amplitude=-6.0,	.frequency=40.0 });
	Formants[0].push_back({ .frame=1300, .amplitude=-7.0,	.frequency=30.0 });
	Formants[0].push_back({ .frame=2000, .amplitude=-11.0,   .frequency=20.0 });

	double idx {};
	double iframe {};
	const double fs = 1/384e3;
	std::cout << "[ ";

	for (const std::vector<OSC_INTERVAL<>>& pts : Formants)
	{
		const size_t IDX = pts.size();
		while (idx < IDX)
		{
			const auto& [amp, saturatedFlag_a] = sinusoidalSplineInterpolation<>(pts
				, idx
				, iframe
				, pts[idx].amplitude // default value
				, pts[idx].frequency
				, AUDIO_COMPONENT::amplitude);

			if (saturatedFlag_a) ++idx;

			const auto& [freq, saturatedFlag_f] = sinusoidalSplineInterpolation<>(pts
				, idx
				, iframe
				, pts[idx].amplitude
				, pts[idx].frequency // default value
				, AUDIO_COMPONENT::frequency);

			if (saturatedFlag_f) ++idx;

			std::cout << amp * cos(2 * M_PI * freq * iframe * fs ) << ", ";
			
			++iframe;

		}
	}
		
	std::cout << "];";

	return 0;
}
