#pragma once

// FPhone.h //

#include <memory.h>
#include <vector>
#include <string>
#include <functional>
#include <cmath>
#include <limits>
#include <map>
#include <unordered_map>
#include <numbers>
#include <stdexcept>

#include "Formant.h"
#include "Oscillator.h"
#include "OscillatorConfig.h"

using AudioPhoneResolution = float;

template<typename AudioPhoneResolution = AudioPhoneResolution>
class FPhone {
private:
    
	using Formants = std::vector<Formant<AudioPhoneResolution>>;
    
    const AudioPhoneResolution FPhone_PI_LoRes = std::numbers::pi_v<AudioPhoneResolution>;    
    const long double FPhone_PI_HiRes = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196;
    
public:

	Formants shapes_oscillatorParamsVec {}; // Note: These are phomeme parameterizations! And are used to generate preconfigured audio phones.

	std::function<void(Formants)> customUpdateCallback; //= NULL;
    
    const AudioPhoneResolution Infinity = std::numeric_limits<AudioPhoneResolution>::infinity();
    const AudioPhoneResolution Negative_Infinity = -std::numeric_limits<AudioPhoneResolution>::infinity();

    /**
    @brief Generates complex signal based on specific wave-shape parameters.
    @details Generates complex signal based on specific wave-shape parameters.
    @param shapes_oscillatorParamsVec: (IMPLICIT) The complex wave-shapes to develop (ie. Formants[]).
    @param customUpdateCallback: An (optional IMPLICIT) lambda that can be used to update the oscillator parameters, instead.
    @return The oscillator signal at frames 0 to K for Formant_N). */
    std::vector<AudioPhoneResolution> getSpeechSampleTensorFloat32() const {
        
        class ChannelData : public std::vector<AudioPhoneResolution> {
            public:
            
        	int bitsPerSample = 24;
        	AudioPhoneResolution duration = 0.0f;
        	AudioPhoneResolution sampleRate = 44100.0f;
            
        };
    
    	Oscillator waveform;
    	ChannelData channelDataLeft{};
    	AudioPhoneResolution maxAmplitude = 0.0f;
    	auto defaultInterpolationMethod = LERP;
    	auto smoothInterpolationMethod = quarticEaseInOut; // cubicHermite; //sineArcInterpolation; 
    	const int pcm_encoding = shapes_oscillatorParamsVec.pcm_encoding;
    
    	const AudioPhoneResolution hz_pcm_encoding = pcm_encoding_docstring_options[pcm_encoding].sample_rate * 1000.0f; // to Khz //
    
    	const AudioPhoneResolution const_inv_hz_pcm_encoding = 1/hz_pcm_encoding;
    	int bit_depth_pcm_encoding_int32 = 24; // default bit-depth //
    	const std::string bit_depth_pcm_encoding = pcm_encoding_docstring_options[pcm_encoding].bit_depth;
    	const std::string default_16BitDepthEncoding = "16";
    
    	const AudioPhoneResolution dBFS_Saturation_Minimum = 
    	    pcm_bit_depth_encoding_recommended_dBFS_saturation_values.find(bit_depth_pcm_encoding) 
    	        != pcm_bit_depth_encoding_recommended_dBFS_saturation_values.end()
            		? pcm_bit_depth_encoding_recommended_dBFS_saturation_values[bit_depth_pcm_encoding].saturation_value_dBFS
            		: pcm_bit_depth_encoding_recommended_dBFS_saturation_values[default_16BitDepthEncoding].saturation_value_dBFS;
    		
    	switch (bit_depth_pcm_encoding) {
    	    case "16": bit_depth_pcm_encoding_int32 = 16; break;
    	    case "32": bit_depth_pcm_encoding_int32 = 32; break;
    	    case "64": bit_depth_pcm_encoding_int32 = 64; break;
    	    case "24":
    	    default: bit_depth_pcm_encoding_int32 = 24; break;
    	}
    
    	const AudioPhoneResolution amplitude_pcm_encoding_resolution = std::pow(2, bit_depth_pcm_encoding_int32 - 1) - 1; // preserve the sign bit //
    
    	const AudioPhoneResolution amplitude_pcm_encoding_dynamic_range = amplitude_pcm_encoding_resolution / 2.0f;
    
    	assignWaveShapeFuncs(shapes_oscillatorParamsVec, waveform);
    		
    	for (const Formants& shape_oscillatorParams : shapes_oscillatorParamsVec) {
    
    		const int64_t I = shape_oscillatorParams.size() - 1;
    
    		const int64_t TIME = shape_oscillatorParams.last().frame + 1;
    	
    		// init waveshape params //
    		oscillatorConfig<AudioPhoneResolution> params{};
    		// time characteristics //
    		params.TIME = TIME; // END // 
    		params.deltaTime = 1; // ie. 1 frame per time increment //
    		params.sampleRate = hz_pcm_encoding;
    		// amplitude lerp targets //
    		params.amplitudeBlendStrategy = shape_oscillatorParams.amplitude_as_bezierCurve_flag
    			? BLEND_STRATEGY::QUARTIC
    			: BLEND_STRATEGY::LERP;
    		// frequency lerp targets //
    		params.frequencyBlendStrategy = shape_oscillatorParams.frequency_as_bezierCurve_flag
    			? BLEND_STRATEGY::QUARTIC
    			: BLEND_STRATEGY::LERP;
    		// phase charactersitics //
    		params.phase = 0;
    		params.cumulativePhase = 0;
    
            for (int64_t i = 0; i <= I; ++i) {
                const oscillatorConfig<AudioPhoneResolution>& from = shape_oscillatorParams[i];
    
    			if (i>=I) break;
    
    			const oscillatorConfig<AudioPhoneResolution>& to = shape_oscillatorParams[i+1];
    	
    			const int64_t start_frame_idx = from.frame;
    			const int64_t end_frame_idx = to.frame;
    			const AudioPhoneResolution db_start = from.amplitude > dBFS_Saturation_Minimum ? from.amplitude : Negative_Infinity; // amplitude < dBFS_Saturation_Minimum ? (Audio Silence) //
    			const AudioPhoneResolution db_end = to.amplitude > dBFS_Saturation_Minimum ? to.amplitude : Negative_Infinity; // amplitude < dBFS_Saturation_Minimum ? (Audio Silence) //
    			const AudioPhoneResolution hz_start = from.frequency;
    			const AudioPhoneResolution hz_end = to.frequency;
    
    			// Update next interval waveshape params //
    
    			// time characteristics //
    			params.time = from.frame; 
    			// amplitude characteristics //
    			params.amplitude = db_start;
    			params.amplitudeStart = db_start;
    			params.amplitudeEnd = db_end;
    			// amplitude lerp targets //
    			params.amplitudeBlendStartFrame = start_frame_idx;
    			params.amplitudeBlendEndFrame = end_frame_idx;
    			// frequency characteristics //
    			params.frequency = hz_start;
    			params.frequencyStart = hz_start;
    			params.frequencyEnd = hz_end;
    			// frequency lerp targets //
    			params.frequencyBlendStartFrame = start_frame_idx;
    			params.frequencyBlendEndFrame = end_frame_idx;
    
    			// frame interval targets //
    			int64_t t = from.frame;
    			const int64_t FRAME_IDX = to.frame + 1;
    
    			while(t < FRAME_IDX){
    
    				params.time = t;
    				
    				const AudioPhoneResolution hz_stepRatio = linearStep(t, params.frequencyBlendStartFrame, params.frequencyBlendEndFrame);
    				const AudioPhoneResolution db_stepRatio = linearStep(t, params.amplitudeBlendStartFrame, params.amplitudeBlendEndFrame);
    
    				/**
    				
    				NOTE: (For Sinusoidals)
    
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
    
    				if (params.isPhaseSensitive) {
    					// 1. Track the cumulative phase of the signal over time. //
    					const AudioPhoneResolution oldFrequency = params.frequency;
    					
    					params.cumulativePhase += 2 * FPhone_PI_LoRes * oldFrequency * params.deltaTime / params.TIME;
    				}
    				
    				params.frequency = 
    				    const_inv_hz_pcm_encoding * from.frequency_as_bezierCurve_flag 
        					? smoothInterpolationMethod(hz_stepRatio, hz_start, hz_end)
        					: defaultInterpolationMethod(hz_stepRatio, hz_start, hz_end) ;
    
    				if (params.isPhaseSensitive) {
    					// 2. Adjust phase to match the instantaneous phase at the time of frequency change //
    					params.phase = params.cumulativePhase - 2 * FPhone_PI_LoRes * params.frequency / params.TIME * (params.time + params.deltaTime);
    				}
    				
    				params.amplitude = from.amplitude_as_bezierCurve_flag 
    					? smoothInterpolationMethod(hz_stepRatio, db_start, db_end)
    					: defaultInterpolationMethod(db_stepRatio, db_start, db_end);
    
    				const AudioPhoneResolution outShape = shape_oscillatorParams.shape_func(params);
    
    				if (outShape != NULL){
    					while (channelDataLeft.size() < (t + 1))
    						channelDataLeft.push_back(0.0f);
    
    					const AudioPhoneResolution dBFS = outShape;
    
    					// Convert dBFS to linear scale //
    					// Handle -Infinity case explicitly //
    					const AudioPhoneResolution linearScale = (dBFS == Negative_Infinity) ? 0 : std::pow(10, dBFS / 20);
    
    					// Scale up N-bit PCM range to utilize full dynamic range //
    					const AudioPhoneResolution linearScaleUpscaledSampleValue = 
    					    linearScale 
    					        * amplitude_pcm_encoding_dynamic_range; 
    
    					channelDataLeft[t] += linearScaleUpscaledSampleValue;
    
    					// Careful not to saturate the audio //
    					maxAmplitude = std::max(maxAmplitude, std::abs(linearScaleUpscaledSampleValue));					 
    
    					++t;
    
    				} else {
    					//throw (`generateComplexSignal > Error: Formant [${i}], frame [${frame_idx}] - Processing Error.`);
    				}
    
    			} // end while (...)
    
    		} // end for (...)
    
    	} // End for (shape_oscillatorParams : shapes_oscillatorParamsVec)
    	
    	// Normalize the audio to avoid saturation- or required clamping, and subsequent clipping //
        if (maxAmplitude > amplitude_pcm_encoding_dynamic_range) {
    		//console.info(`Signal amplitude exceeds preset PCM ${bit_depth_pcm_encoding}-bit dynamic range; clipping has occurred! Normalizing audio...`);
            const AudioPhoneResolution normalizationFactor = amplitude_pcm_encoding_dynamic_range / maxAmplitude;
    
            for (int64_t i = 0; i < channelDataLeft.size(); ++i) {
                channelDataLeft[i] *= normalizationFactor;
            }
    
    		//console.info("Done.");
        }
    
    	// encode .WAV headers //
    	//const int channelLength = channelDataLeft.size();
    	//const AudioPhoneResolution sampleRate = hz_pcm_encoding; // Unlimited Rate support (default 192000), though Javascript supports up to PCM 384000 Hz Max decodable @ 32-bit ...most of the time.
    	//const int bitsPerSample = bit_depth_pcm_encoding; // (default 24-bit)
    
    	//const AudioPhoneResolution duration = channelLength * sampleRate; // (default 1 second) //
    
    	// Left Channel //
    	//channelDataLeft.sampleRate = sampleRate;
    	//channelDataLeft.bitsPerSample = bitsPerSample;
    	//channelDataLeft.duration = duration;
    
    	speechSample_TensorFloat32 = channelDataLeft;
    
        return speechSample_TensorFloat32;
        
    } // End getSpeechSampleTensorFloat32 //

    oscillatorConfig<AudioPhoneResolution> getOscillatorConfig() const {
        return m_oscillatorConfig;
    }

    void setOscillatorConfig(const oscillatorConfig<AudioPhoneResolution>& config) {
        m_oscillatorConfig = config;
    };

    std::vector<AudioPhoneResolution> speechSample_TensorFloat32 {};
    oscillatorConfig<AudioPhoneResolution> m_oscillatorConfig{}; // params //
    
private:    
    
	struct PCMEncodingOptions {
	    std::string pcm_encoding_docstring {"PCM 32-bit/192 KHz"};
	    int bit_depth {32};
	    AudioPhoneResolution sample_rate {192.0};
	    AudioPhoneResolution dynamic_range_dBFS{ 192.64};
	    int saturation_value_dBFS {-193};
	};

	// Define pcm_encoding_docstring_options as a map of pcm encoding options
	std::unordered_map<std::string, PCMEncodingOptions> pcm_encoding_docstring_options = {
	    {"0", {"PCM 16-bit/44.1 KHz", 16, 44.1, 96.32, -96}},
	    {"1", {"PCM 16-bit/48 KHz", 16, 48.0, 96.32, -96}},
	    {"2", {"PCM 16-bit/88.2 KHz", 16, 88.2, 96.32, -96}},
	    {"3", {"PCM 16-bit/96 KHz", 16, 96.0, 96.32, -96}},
	    {"4", {"PCM 16-bit/192 KHz", 16, 192.0, 96.32, -96}},
	    {"5", {"PCM 16-bit/384 KHz", 16, 384.0, 96.32, -96}},
	    {"6", {"PCM 16-bit/768 KHz", 16, 768.0, 96.32, -96}},
	    {"7", {"PCM 24-bit/44.1 KHz", 24, 44.1, 144.48, -144}},
	    {"8", {"PCM 24-bit/48 KHz", 24, 48.0, 144.48, -144}},
	    {"9", {"PCM 24-bit/88.2 KHz", 24, 88.2, 144.48, -144}},
	    {"10", {"PCM 24-bit/96 KHz", 24, 96.0, 144.48, -144}},
	    {"11", {"PCM 24-bit/192 KHz", 24, 192.0, 144.48, -144}},
	    {"12", {"PCM 24-bit/384 KHz", 24, 384.0, 144.48, -144}},
	    {"13", {"PCM 24-bit/768 KHz", 24, 768.0, 144.48, -144}},
	    {"14", {"PCM 32-bit/44.1 KHz", 32, 44.1, 192.64, -193}},
	    {"15", {"PCM 32-bit/48 KHz", 32, 48.0, 192.64, -193}},
	    {"16", {"PCM 32-bit/88.2 KHz", 32, 88.2, 192.64, -193}},
	    {"17", {"PCM 32-bit/96 KHz", 32, 96.0, 192.64, -193}},
	    {"18", {"PCM 32-bit/192 KHz", 32, 192.0, 192.64, -193}},
	    {"19", {"PCM 32-bit/384 KHz", 32, 384.0, 192.64, -193}},
	    {"20", {"PCM 32-bit/768 KHz", 32, 768.0, 192.64, -193}},
	    {"21", {"PCM 64-bit/44.1 KHz", 64, 44.1, 385.28, -385}},
	    {"22", {"PCM 64-bit/48 KHz", 64, 48.0, 385.28, -385}},
	    {"23", {"PCM 64-bit/88.2 KHz", 64, 88.2, 385.28, -385}},
	    {"24", {"PCM 64-bit/96 KHz", 64, 96.0, 385.28, -385}},
	    {"25", {"PCM 64-bit/192 KHz", 64, 192.0, 385.28, -385}},
	    {"26", {"PCM 64-bit/384 KHz", 64, 384.0, 385.28, -385}},
	    {"27", {"PCM 64-bit/768 KHz", 64, 768.0, 385.28, -385}}
	};

	struct PCMBitDepthEncodingOptions {
	    AudioPhoneResolution dynamic_range_dBFS {192.64};
	    int saturation_value_dBFS {-193};
	};

    // Define pcm_bit_depth_encoding_recommended_dBFS_saturation_values as a map of pcm bit depth encoding recommended dBFS saturation values
	std::unordered_map<std::string, PCMBitDepthEncodingOptions> pcm_bit_depth_encoding_recommended_dBFS_saturation_values = {
	    {"16", {96.32, -96}},
	    {"24", {144.48, -144}},
	    {"32", {192.64, -193}},
	    {"64", {385.28, -385}}
	};
    
    AudioPhoneResolution LERP(
          AudioPhoneResolution t // [0,1] //
        , AudioPhoneResolution start
        , AudioPhoneResolution end) {
        return start + t * (end - start);
    };
    
    AudioPhoneResolution quarticEaseInOut(
          AudioPhoneResolution t // [0,1] //
        , AudioPhoneResolution v1
        , AudioPhoneResolution v2) {
        t -= 1;
        return v1 + t * t * t * (t * (v2 - v1) + v1);
    };
    
    AudioPhoneResolution cubicHermite (
          AudioPhoneResolution t // [0,1] //
        , AudioPhoneResolution start
        , AudioPhoneResolution end) {
        return 0.0f;
    };
        
    AudioPhoneResolution sineArcInterpolation (
          AudioPhoneResolution t // [0,1] //
        , AudioPhoneResolution start
        , AudioPhoneResolution end) {
        return 0.0f;
    };
    
    AudioPhoneResolution linearStep (
          int64_t t
        , int64_t start
        , int64_t end) {
        if (t < start) return 0.0f;
        else if (t > end) return 1.0f;
        else return (t - start) / (end - start);
    };
    
    void assignWaveShapeFuncs(Formants& fmt, const Oscillator& wfm) {
	    for (auto& fmt_temp : fmt) {
	        switch (fmt_temp.shape) {
	            // case "Half-Sine":
	            // case "Quarter-Sine":
	            // case "quasiPeriodicNoise":
	            case "Sine":
	                fmt_temp.shape_func = wfm.SIN;
	                fmt_temp.isPhaseSensitive = true;
	                break;
	            case "Cosine":
	                fmt_temp.shape_func = wfm.cos;
	                fmt_temp.isPhaseSensitive = true;
	                break;
	            case "Square":
	                fmt_temp.shape_func = wfm.square;
	                break;
	            case "F. Sawtooth":
	                fmt_temp.shape_func = [&wfm](const auto& params) { return wfm.sawtooth(params, "forward"); };
	                break;
	            case "R. Sawtooth":
	                fmt_temp.shape_func = [&wfm](const auto& params) { return wfm.sawtooth(params, "reverse"); };
	                break;
	            case "Triangle":
	                fmt_temp.shape_func = wfm.triangle;
	                break;
	            case "Pink Noise":
	                fmt_temp.shape_func = wfm.pinkNoise;
	                break;
	            case "Purple Noise":
	                fmt_temp.shape_func = wfm.purpleVioletNoise;
	                break;
	            case "Brown Noise":
	                fmt_temp.shape_func = wfm.brownNoise;
	                break;
	            case "Blue Noise":
	                fmt_temp.shape_func = wfm.blueNoise;
	                break;
	            case "White Gaussian Noise":
	                fmt_temp.shape_func = wfm.whiteGaussianNoise;
	                break;
	            default:
	                throw std::runtime_error("Error: FPhone > GenerateComplexSignal > assignWaveShapeFuncs: Unknown wave shape encountered - (" + fmt_temp.shape + ")! Aborting.");
	        }
	    }
	}; // end assignWaveShapeFuncs
    
}; // end class FPhone 
