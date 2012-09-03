/*
 * Shape.h
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "Ray.h"
#include "Colour.h"

class ShadingInfo;

class Shape {
public:
	Shape();
	virtual ~Shape();
	virtual bool intersect(Ray& r, double& tMin, ShadingInfo& shadingInfo) const = 0;

	Colour colour;

};

#endif /* SHAPE_H_ */
