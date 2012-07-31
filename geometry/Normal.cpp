/*
 * Normal.cpp
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

#include "Normal.h"

Normal::Normal() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Normal::Normal(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

// assignment from a vector to a normal (they are the same thing really)
Normal& Normal::operator= (const Vector& v) {
	x = v.x; y = v.y; z = v.z;
	return *this;
}

Normal::~Normal() {
	// TODO Auto-generated destructor stub
}

