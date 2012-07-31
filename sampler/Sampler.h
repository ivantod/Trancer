/*
 * Sampler.h
 *
 *  Created on: 29 Jul 2012
 *      Author: ivantod
 */

#ifndef SAMPLER_H_
#define SAMPLER_H_

#include "Point2D.h"
#include "Point.h"
#include <vector>

class Sampler {
public:
	Sampler();
	Sampler(const int numSamples);
	Sampler(const int numSamples, const int numSets);
	virtual ~Sampler();

	virtual void generateSamples() = 0;

	void setupShuffledIndices();
//	void shuffleSamples();
	Point2D sampleUnitSquare();
	void mapSamplesToDisk();
	void mapSamplesToHemisphere(const float exp);
	void mapSamplesToSphere();

protected:
	int numSamples;
	int numSets;
	std::vector<Point2D> samples; // sample points on a unit square
	std::vector<Point2D> diskSamples; // sample points on a unit disk
	std::vector<Point> hemisphereSamples; // sample points on a unit hemisphere
	std::vector<Point> sphereSamples;
	std::vector<int> shuffledIndices;
	unsigned long count; // the current number of sample points used
	int jump; // random jump
};

#endif /* SAMPLER_H_ */
