/*
 * RegularSampler.h
 *
 *  Created on: 29 Jul 2012
 *      Author: ivantod
 */

#ifndef REGULARSAMPLER_H_
#define REGULARSAMPLER_H_

#include "Sampler.h"

class RegularSampler: public Sampler {
public:
	RegularSampler();
	RegularSampler(const int numSamples);

	void virtual generateSamples();

	virtual ~RegularSampler();
};

#endif /* REGULARSAMPLER_H_ */
