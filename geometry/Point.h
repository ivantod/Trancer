/*
 * Point.h
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#ifndef POINT_H_
#define POINT_H_

#include "Vector.h"

class Point {
public:
	Point();
	Point(double x, double y, double z);

	virtual ~Point();

	Vector operator-(const Point& p) const;

	Point operator+(const Vector& v) const;

private:
	double x;
	double y;
	double z;
};

// Operator "-" makes a vector from first point to the second.
inline Vector Point::operator-(const Point& p) const {
	return Vector(x-p.x, y-p.y, z-p.z);
}

inline Point Point::operator+(const Vector& v) const {
	return Point(x+v.x, y+v.y, z+v.z);
}

#endif /* POINT_H_ */
