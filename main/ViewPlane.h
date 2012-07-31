/*
 * ViewPlane.h
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

#ifndef VIEWPLANE_H_
#define VIEWPLANE_H_

#include "Sampler.h"

class ViewPlane {
public:

	ViewPlane(const ViewPlane& vp);
	ViewPlane(const int hres, const int vres, const double zw, const int pixelSize);

	virtual ~ViewPlane();

	void setHres(const int hres);
	void setVres(const int vres);
	void setPixelSize(const int pixelSize);
	void setGamma(const float gamma);
	void setNumSamples(int numSamples);

	Sampler* sampler;
	int hres;
	int vres;
	double zw; // z-coordinate of the viewing plane (positioned towards us)
	int pixelSize;
	float gamma;
	float invGamma;
	int numSamples;
};

#endif /* VIEWPLANE_H_ */
