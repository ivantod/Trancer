/*
 * Ray.cpp
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#include "Ray.h"
#include "Point.h"
#include "Vector.h"

Ray::Ray() {
	this->origin=Point();
	this->direction=Vector();
}

Ray::Ray(Point origin, Vector direction) {
	this->origin=origin;
	this->direction=direction;
}

Ray::~Ray() {
	// TODO Auto-generated destructor stub
}

