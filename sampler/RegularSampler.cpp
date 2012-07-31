/*
 * RegularSampler.cpp
 *
 *  Created on: 29 Jul 2012
 *      Author: ivantod
 */

#include "RegularSampler.h"
#include <cmath>

RegularSampler::RegularSampler() : Sampler() {
	generateSamples();
}

RegularSampler::RegularSampler(const int numSamples) : Sampler(numSamples) {
	generateSamples();
}

void RegularSampler::generateSamples() {
	int n = (int) sqrt((float) numSamples);

	for (int j = 0; j < numSets; j++) {
		for (int p = 0; p < n; p++)	{
			for (int q = 0; q < n; q++) {
				samples.push_back(Point2D((q + 0.5) / n, (p + 0.5) / n));
			}
		}
	}
}

RegularSampler::~RegularSampler() {
	// TODO Auto-generated destructor stub
}

