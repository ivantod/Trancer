/*
 * MultiObjectRayTracer.h
 *
 *  Created on: 23 Jul 2012
 *      Author: ivantod
 */

#ifndef MULTIOBJECTRAYTRACER_H_
#define MULTIOBJECTRAYTRACER_H_

#include "RayTracer.h"
#include "Colour.h"

class MultiObjectRayTracer: public RayTracer {
public:
	MultiObjectRayTracer();
	virtual ~MultiObjectRayTracer();

	virtual Colour traceRay(Ray ray, Scene* scene) const;
};

#endif /* MULTIOBJECTRAYTRACER_H_ */
