/*
 * Point2D.cpp
 *
 *  Created on: 29 Jul 2012
 *      Author: ivantod
 */

#include "Point2D.h"

Point2D::Point2D() {
	this->x = 0.0;
	this->y = 0.0;
}

Point2D::Point2D(double x, double y) {
	this->x = x;
	this->y = y;
}

Point2D::Point2D(const Point2D& p) {
	this->x = p.x;
	this->y = p.y;
}


Point2D& Point2D::operator=(const Point2D& p) {
	if (this == &p) {
		return *this;
	} else {
		y = p.y;
		x = p.x;
		return *this;
	}
}

Point2D::~Point2D() {
	// TODO Auto-generated destructor stub
}

