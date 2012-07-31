/*
 * Sampler.cpp
 *
 *  Created on: 29 Jul 2012
 *      Author: ivantod
 */

#include "Sampler.h"
#include "MathFunc.h"
#include "Constants.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

Sampler::Sampler() :
			numSamples(1),
			numSets(83),
			count(0),
			jump(0) {
	samples.reserve(numSamples * numSets);
	setupShuffledIndices();
}

Sampler::Sampler(const int numSamples) :
			numSamples(numSamples),
			numSets(83),
			count(0),
			jump(0) {
	samples.reserve(numSamples * numSets);
	setupShuffledIndices();
}

Sampler::Sampler(const int numSamples, const int numSets) :
			numSamples(numSamples),
			numSets(numSets),
			count(0),
			jump(0) {
	samples.reserve(numSamples * numSets);
	setupShuffledIndices();
}

void Sampler::setupShuffledIndices() {
	std::vector<int> indices;

	shuffledIndices.reserve(numSamples * numSets);

	for (int j=0; j<numSamples; j++) indices.push_back(j);

	for (int p=0; p<numSets; p++) {
		random_shuffle(indices.begin(), indices.end());

		for (int j=0; j<numSamples; j++) shuffledIndices.push_back(indices[j]);
	}

}

Point2D Sampler::sampleUnitSquare() {
	// start of a new pixel
	if (count % numSamples == 0) {
		jump = (rand_int() % numSets) * numSamples;
	}
	return samples[jump + shuffledIndices[jump + count++ % numSamples]];
}

// Maps the 2D sample points in the square [-1,1] x [-1,1] to a unit disk,
// using Peter Shirley's concentric map function
void Sampler::mapSamplesToDisk() {
	int size = samples.size();
		float r, phi; // polar coordinates
		Point2D sp; // sample point on unit disk

		diskSamples.reserve(size);

		for (int j = 0; j < size; j++) {
			 // map sample point to [-1, 1] X [-1,1]

			sp.x = 2.0 * samples[j].x - 1.0;
			sp.y = 2.0 * samples[j].y - 1.0;

			if (sp.x > -sp.y) {			// sectors 1 and 2
				if (sp.x > sp.y) {		// sector 1
					r = sp.x;
					phi = sp.y / sp.x;
				} else {					// sector 2
					r = sp.y;
					phi = 2 - sp.x / sp.y;
				}
			} else {						// sectors 3 and 4
				if (sp.x < sp.y) {		// sector 3
					r = -sp.x;
					phi = 4 + sp.y / sp.x;
				} else {					// sector 4
					r = -sp.y;
					if (sp.y != 0.0)	// avoid division by zero at origin
						phi = 6 - sp.x / sp.y;
					else
						phi  = 0.0;
				}
			}

			phi *= PI / 4.0;

			diskSamples[j].x = r * cos(phi);
			diskSamples[j].y = r * sin(phi);
		}

		// samples.erase(samples.begin(), samples.end()); // why erase the original?
}

// Maps the 2D sample points to 3D points on a unit hemisphere
// with a cosine power density distribution in the polar angle
void Sampler::mapSamplesToHemisphere(const float exp) {
	int size = samples.size();
	hemisphereSamples.reserve(numSamples * numSets);

	for (int j = 0; j < size; j++) {
		float cos_phi = cos(2.0 * PI * samples[j].x);
		float sin_phi = sin(2.0 * PI * samples[j].x);
		float cos_theta = pow((1.0 - samples[j].y), 1.0 / (exp + 1.0));
		float sin_theta = sqrt(1.0 - cos_theta * cos_theta);
		float pu = sin_theta * cos_phi;
		float pv = sin_theta * sin_phi;
		float pw = cos_theta;
		hemisphereSamples.push_back(Point(pu, pv, pw));
	}
}

// Maps the 2D sample points to 3D points on a unit sphere with a uniform density
// distribution over the surface. This is used for modelling a spherical light
void Sampler::mapSamplesToSphere() {
	float r1, r2;
	float x, y, z;
	float r, phi;

	sphereSamples.reserve(numSamples * numSets);

	for (int j = 0; j < numSamples * numSets; j++) {
		r1 = samples[j].x;
    	r2 = samples[j].y;
    	z = 1.0 - 2.0 * r1;
    	r = sqrt(1.0 - z * z);
    	phi = TWO_PI * r2;
    	x = r * cos(phi);
    	y = r * sin(phi);
		sphereSamples.push_back(Point(x, y, z));
	}
}

Sampler::~Sampler() {
	// TODO Auto-generated destructor stub
}

