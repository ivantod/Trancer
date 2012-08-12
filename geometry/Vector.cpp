/*
 * Vector.cpp
 *
 *  Created on: 19 Jul 2012
 *      Author: ivantod
 */

#include "Vector.h"
#include <math.h>

Vector::Vector() {
	this->x=0.0;
	this->y=0.0;
	this->z=0.0;
}

Vector::Vector(double x, double y, double z) {
	this->x=x;
	this->y=y;
	this->z=z;
}

void Vector::normalise() {
	double length = sqrt(x*x + y*y + z*z);
	x /= length; y /= length; z /= length;
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}

