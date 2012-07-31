/*
 * MultiObjectRayTracer.cpp
 *
 *  Created on: 23 Jul 2012
 *      Author: ivantod
 */

#include "MultiObjectRayTracer.h"
#include "ShadingInfo.h"
#include "TGASupport.h"
#include "Ray.h"
#include "Scene.h"
#include <iostream>


MultiObjectRayTracer::~MultiObjectRayTracer() {
	// TODO Auto-generated destructor stub
}

MultiObjectRayTracer::MultiObjectRayTracer() {

}


Colour MultiObjectRayTracer::traceRay(Ray ray, Scene* scene) const {

	ShadingInfo shadingInfo(*scene);
	double tMin = 999999.0;
	double t;

	int numShapes = scene->shapes.size();

	// cout << " Size of shapes is: ";
	// cout << numShapes << ". Begin for loop: ";

	for (int i = 0; i < numShapes; i++) {
		Shape *s = scene->shapes[i];
		// cout << i << ",";
		if (s->intersect(ray, t, shadingInfo) && t<tMin) {
			shadingInfo.colour = s->colour;
			shadingInfo.objectHit = true;
		}
	}

	// cout << " and for loop done " << endl;

	if (shadingInfo.objectHit) {
		return shadingInfo.colour;
	} else {
		return scene->backgroundColour;
	}

}
