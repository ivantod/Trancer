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

/*
  implement rotation around z axis:
	cos t	-sin t  0   x    x*cos t-y*sin t
	sin t	cos t	0 * y =  x*sin t+y*cos t
	0		0		1   z    z

	In the equation, t is angle in radians
 */
void Vector::rotateZAxis(double radians) {
	double newX = x*cos(radians) - y*sin(radians);
	double newY = x*sin(radians) - y*cos(radians);
	x = newX;
	y = newY;
}

// same as normalise, but also returns the normalised value back
Vector& Vector::hat() {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
	return (*this);
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}

