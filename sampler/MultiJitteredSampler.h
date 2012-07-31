/*
 * MultiJitteredSampler.h
 *
 *  Created on: 29 Jul 2012
 *      Author: ivantod
 */

#ifndef MULTIJITTEREDSAMPLER_H_
#define MULTIJITTEREDSAMPLER_H_

#include "Sampler.h"

class MultiJitteredSampler: public Sampler {
public:
	MultiJitteredSampler();
	MultiJitteredSampler(const int numSamples);
	MultiJitteredSampler(const int numSamples, const int numSets);

	virtual ~MultiJitteredSampler();

private:
	virtual void generateSamples();
};

#endif /* MULTIJITTEREDSAMPLER_H_ */
