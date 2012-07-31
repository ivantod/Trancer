/*
 * RayTracer.h
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include "Ray.h"
#include "Scene.h"

class Scene;
class RayTracer {
public:
	RayTracer();
	virtual ~RayTracer();

	virtual Colour traceRay(Ray ray, Scene* scene) const = 0;
};

#endif /* RAYTRACER_H_ */
