/*
 * Ray.h
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#ifndef RAY_H_
#define RAY_H_

#include "Point.h"
#include "Vector.h"

class Ray {
public:
	Ray();
	Ray(Point origin, Vector direction);
	virtual ~Ray();
	Point origin;
	Vector direction;

};

#endif /* RAY_H_ */
