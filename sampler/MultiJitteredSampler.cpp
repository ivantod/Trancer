/*
 * MultiJitteredSampler.cpp
 *
 *  Created on: 29 Jul 2012
 *      Author: ivantod
 */

#include "MultiJitteredSampler.h"
#include "MathFunc.h"
#include <cmath>

MultiJitteredSampler::MultiJitteredSampler() {
	// TODO Auto-generated constructor stub
}


MultiJitteredSampler::MultiJitteredSampler(const int numSamples) : Sampler(numSamples) {
	generateSamples();
}

MultiJitteredSampler::MultiJitteredSampler(const int numSamples, const int numSets) : Sampler(numSamples, numSets) {
	generateSamples();
}

void MultiJitteredSampler::generateSamples() {
	// num_samples needs to be a perfect square

	int n = (int)sqrt((float) numSamples);
	float subcellWidth = 1.0 / ((float) numSamples);

	// fill the samples array with dummy points to allow us to use the [ ] notation when we set the
	// initial patterns

	Point2D fillPoint;
	for (int j = 0; j < numSamples * numSets; j++) samples.push_back(fillPoint);

	// distribute points in the initial patterns

	for (int p = 0; p < numSets; p++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				samples[i * n + j + p * numSamples].x = (i * n + j) * subcellWidth + rand_float(0, subcellWidth);
				samples[i * n + j + p * numSamples].y = (j * n + i) * subcellWidth + rand_float(0, subcellWidth);
			}
		}
	}

	// shuffle x coordinates

	for (int p = 0; p < numSets; p++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int k = rand_int(j, n - 1);
				float t = samples[i * n + j + p * numSamples].x;
				samples[i * n + j + p * numSamples].x = samples[i * n + k + p * numSamples].x;
				samples[i * n + k + p * numSamples].x = t;
			}
		}
	}


	// shuffle y coordinates

	for (int p = 0; p < numSets; p++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int k = rand_int(j, n - 1);
				float t = samples[j * n + i + p * numSamples].y;
				samples[j * n + i + p * numSamples].y = samples[k * n + i + p * numSamples].y;
				samples[k * n + i + p * numSamples].y = t;
			}
		}
	}
}

MultiJitteredSampler::~MultiJitteredSampler() {
	// TODO Auto-generated destructor stub
}

