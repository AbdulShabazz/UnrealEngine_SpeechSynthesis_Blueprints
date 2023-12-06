#pragma once

/**
The Perceptual Linear Prediction (PLP) algorithm is a technique used to extract formant frequencies from audio signals. 
It is based on the idea that the human auditory system is more sensitive to spectral changes at lower frequencies than at higher frequencies.

The PLP algorithm uses a liftering filter to compensate for this non-linearity. The liftering filter is a low-pass filter that is designed to attenuate the higher-order PLP coefficients. 
This helps to ensure that the PLP coefficients are more representative of the formant frequencies of the signal.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Compute the autocorrelation function (ACF) of the signal

/**
The autocorrelation function (ACF) is a measure of the similarity between a signal and a time-shifted version of itself.
@param signal The audio signal
@return The autocorrelation function*/
vector<double> acf(const vector<double>& signal) {
    int lag = signal.size() / 2;
    vector<double> acfCoefficients(lag + 1);

    for (int i = 0; i <= lag; i++) {
        double acfValue = 0.0;
        for (int j = 0; j < signal.size() - i; j++) {
            acfValue += signal[j] * signal[j + i];
        }
        acfCoefficients[i] = acfValue / signal.size();
    }

    return acfCoefficients;
}

// Compute the LPC coefficients using the Levinson-Durbin algorithm

/**
The Levinson-Durbin algorithm is an efficient method for solving the Yule-Walker equations.
@param acf The autocorrelation function (ACF) of the signal
@return The LPC coefficients*/
vector<double> lpc(const vector<double>& acf) {
    int order = acf.size() - 1;
    vector<double> reflectionCoefficients(order);
    vector<double> lpcCoefficients(order + 1, 1.0);

    for (int k = 1; k <= order; k++) {
        double reflectionCoefficient = 0.0;
        double denominator = 0.0;

        for (int i = 1; i <= k - 1; i++) {
            reflectionCoefficient += reflectionCoefficients[i - 1] * acf[k - i];
            denominator += acf[i] * acf[k - i];
        }

        reflectionCoefficient = -reflectionCoefficient / denominator;
        reflectionCoefficients[k - 1] = reflectionCoefficient;

        for (int i = 0; i < k; i++) {
            lpcCoefficients[i] = lpcCoefficients[i] + reflectionCoefficient * lpcCoefficients[k - i - 1];
        }
    }

    return lpcCoefficients;
}

// Define the PLP algorithm parameters
const int order = 26; // Order of the LPC filter
const int windowSize = 256; // Size of the analysis window
const int shift = 128; // Shift between analysis windows
const double samplingRate = 16000.0; // Sampling rate in Hz

/**The preemphasis filter is a high-pass filter that is used to emphasize the higher frequencies of the signal.
Define the PLP coefficients */
const double preemphasis[2] = {0.95, -0.85};

/**
The liftering coefficients are derived from the equal-loudness contours of the human auditory system. The equal-loudness contours are a set of curves 
that show how the perceived loudness of a sound changes with frequency.

To derive the liftering coefficients, the equal-loudness contours are first normalized to have a peak value of 1.0 at 1 kHz. Then, 
the inverse of the normalized equal-loudness contour is taken at each frequency. The result is a set of coefficients that can be used to attenuate the higher-order PLP coefficients.

The specific values of the liftering coefficients can vary depending on the application. However, 
the general principle is that the coefficients should be designed to attenuate the higher-order PLP coefficients such that 
the PLP coefficients are more representative of the formant frequencies of the signal.*/
const double liftering[27] = {0.234247, 0.260442, 0.278586, 0.288237, 0.295501, 0.300343,
                                0.302564, 0.302335, 0.300231, 0.296131, 0.290202, 0.282532,
                                0.273183, 0.262229, 0.250074, 0.237043, 0.223169, 0.208503,
                                0.193206, 0.177349, 0.161006, 0.144245, 0.126973, 0.110196,
                                0.093831, 0.077884, 0.062467}; // Liftering coefficients

/*

The `liftering` coefficients array provided is part of a Perceptual Linear Prediction (PLP) filter implementation in C++20
PLP is a technique used in speech signal processing, and it applies a set of transformations to the linear prediction coefficients 
(LPCs) of the speech signal to better match the human auditory system's response. The purpose of the `liftering` coefficients in PLP 
is to perform liftering on the cepstral coefficients.

Here's a detailed breakdown of the purpose and function 
of these specific liftering coefficients:

1. **Cepstral Liftering**:
   - Cepstral coefficients are derived from the LPCs and provide a representation of the speech signal.
   - Liftering is a process applied to the cepstral coefficients. It's used to emphasize or de-emphasize certain cepstral components.

2. **Human Auditory System Modeling**:
   - The human ear perceives frequencies in a logarithmic manner rather than linear. PLP incorporates this perceptual characteristic.
   - Liftering coefficients are designed to weight the cepstral coefficients in a way that matches human hearing sensitivity.

3. **Function of Specific Coefficients**:
   - Each value in the `liftering` array corresponds to a different cepstral coefficient.
   - The pattern of values suggests an emphasis on certain frequency components over others.
   - The values generally decrease as the index increases, which typically indicates less emphasis on higher cepstral coefficients. 
   This aligns with the fact that higher frequency components have less perceptual importance in human hearing.

4. **Values Analysis**:
   - The first few coefficients (e.g., `0.234247`, `0.260442`, etc.) are relatively low, indicating a lesser emphasis on the lowest cepstral coefficients.
   - The middle range coefficients (around `0.302564` to `0.302335`) reach a peak, suggesting a greater emphasis on these mid-range cepstral coefficients.
   - Towards the end (e.g., `0.077884`, `0.062467`), the values decrease again, indicating a reduction in emphasis on higher cepstral components.

5. **Practical Impact**:
   - These specific values affect the quality and characteristics of the processed speech signal.
   - The liftering process can impact speech recognition accuracy, speaker identification, and overall speech signal quality.

6. **Customization**:
   - These coefficients are often fine-tuned based on specific requirements or characteristics of the speech processing task at hand.

In summary, the `liftering` coefficients in a PLP filter implementation play a crucial role in modifying cepstral coefficients 
to align with human auditory perception. The specific values provided are designed to differentially weight these coefficients, 
reflecting the perceptual significance of different frequency components in human hearing.

*/

// PLP algorithm function
/**
The PLP algorithm is a technique used to extract formant frequencies from audio signals. 
It is based on the idea that the human auditory system is more sensitive to spectral changes 
at lower frequencies than at higher frequencies.
@param signal The audio signal
@return The PLP coefficients*/
vector<double> plp(const vector<double>& signal) {
    // Check if the signal length is valid
    if (signal.size() < windowSize) {
        cerr << "Error: Signal length must be at least " << windowSize << endl;
        return {};
    }

    // Initialize the PLP coefficients vector
    vector<double> plpCoefficients(order + 1);

    // Compute the PLP coefficients for each frame
    for (int i = 0; i < signal.size() - windowSize + shift; i += shift) {
        // Pre-emphasize the signal
        vector<double> preemphasizedSignal(windowSize);
        for (int j = 0; j < windowSize; j++) {
            preemphasizedSignal[j] = signal[i + j] * preemphasis[0] + signal[i + j - 1] * preemphasis[1];
        }

        // Compute the LPC coefficients
        vector<double> lpcCoefficients = lpc(preemphasizedSignal);

        // Convert the LPC coefficients to PLP coefficients
        for (int j = 0; j <= order; j++) {
            plpCoefficients[j] = lpcCoefficients[j] * pow(2.0 * M_PI * j / order, -0.5);
        }

        // Apply the liftering filter
        for (int j = 0; j <= order; j++) {
            plpCoefficients[j] *= liftering[j];
        }

        // Compute the PLP energy
        double plpEnergy = 0.0;
        for (int j = 1; j <= order; j++) {
            plpEnergy += plpCoefficients[j] * plpCoefficients[j];
        }

        // Normalize the PLP energy
        plpEnergy = sqrt(plpEnergy) / (order - 1);

        // Combine the PLP coefficients and PLP energy into a single feature vector
        vector<double> featureVector(order + 2);
        for (int j = 0; j <= order; j++) {
            featureVector[j] = plpCoefficients[j];
        }
        featureVector[order + 1] = plpEnergy;
    }

    return plpCoefficients;
}

/*
// Main function
int main() {
    // Read the audio signal from a file
    vector<double> signal;
    // ...

    // Compute the PLP coefficients
    vector<double> plpCoefficients = plp(signal);

    // Print the PLP coefficients
    for (double plpCoefficient : plpCoefficients) {
        cout << plpCoefficient << " ";
    }
    cout << endl;

    return 0;
}
*/
