/*
 * Point.cpp
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#include "Point.h"

Point::Point() {
	this->x=0;
	this->y=0;
	this->z=0;
};

Point::Point(double x, double y, double z) {
	this->x=x;
	this->y=y;
	this->z=z;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

