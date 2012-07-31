/*
 * Sphere.h
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Shape.h"
#include "Ray.h"
#include "Point.h"
#include "ShadingInfo.h"

class Sphere: public Shape {
public:
	Sphere(Point centre, double r, Colour colour);
	virtual ~Sphere();
	virtual bool intersect(Ray& r, double& tMin, ShadingInfo& shadingInfo) const;
private:
	Point centre;
	double r;

};

#endif /* SPHERE_H_ */
