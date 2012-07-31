/*
 * SimpleRayTracer.h
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

#ifndef SIMPLERAYTRACER_H_
#define SIMPLERAYTRACER_H_

#include "RayTracer.h"

class SimpleRayTracer: public RayTracer {
public:
	SimpleRayTracer(Scene& scene);
	virtual ~SimpleRayTracer();

	virtual void renderScene() const;

	Scene scene;

private:
	Colour traceRay(Ray ray) const;

};

#endif /* SIMPLERAYTRACER_H_ */
