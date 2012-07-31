/*
 * ViewPlane.cpp
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

#include <iostream>
#include "ViewPlane.h"
#include "MultiJitteredSampler.h"
#include "RegularSampler.h"

using namespace std;

ViewPlane::ViewPlane(const int hres, const int vres, const double zw, const int pixelSize) {
	this->hres = hres;
	this->vres = vres;
	this->pixelSize = pixelSize;
	this->zw = zw;
	numSamples = 0;
	gamma=1;
	invGamma=1/gamma;
	sampler = NULL;
}

ViewPlane::ViewPlane(const ViewPlane& vp) {
	this->hres = vp.hres;
	this->vres = vp.vres;
	this->pixelSize = vp.pixelSize;
	this->gamma = vp.gamma;
	this->invGamma = vp.invGamma;
	this->zw = vp.zw;
	this->numSamples = vp.numSamples;
	this->sampler = vp.sampler;
}

void ViewPlane::setHres(const int hres) {
	this->hres = hres;
}

void ViewPlane::setVres(const int vres) {
	this->vres = vres;
}

void ViewPlane::setPixelSize(const int pixelSize) {
	this->pixelSize = pixelSize;
}

void ViewPlane::setGamma(const float gamma) {
	this->gamma = gamma;
	this->invGamma = 1.0/gamma;
}

void ViewPlane::setNumSamples(int numSamples) {
	if (sampler) {
		delete sampler;
		sampler = NULL;
	}

	this->numSamples = numSamples;

	if (this->numSamples>1) {
		cout << "    Setting MultiJitteredSampler with " << numSamples << endl;
		sampler = new MultiJitteredSampler(this->numSamples);
	} else {
		cout << "    Setting RegularSampler with " << numSamples << endl;
		sampler = new RegularSampler(1);
	}
}

ViewPlane::~ViewPlane() {
	// TODO Auto-generated destructor stub
}

