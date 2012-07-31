/*
 * Vector.cpp
 *
 *  Created on: 19 Jul 2012
 *      Author: ivantod
 */

#include "Vector.h"

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

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}

