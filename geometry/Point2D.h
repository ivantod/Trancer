/*
 * Point2D.h
 *
 *  Created on: 29 Jul 2012
 *      Author: ivantod
 */

#ifndef POINT2D_H_
#define POINT2D_H_

class Point2D {
public:
	Point2D();
	Point2D(double x, double y);
	Point2D(const Point2D& p);

	Point2D operator*(const float a);

	Point2D& operator=(const Point2D& p);

	virtual ~Point2D();

	double x;
	double y;

};

inline Point2D Point2D::operator*(const float a) {
	return Point2D(x*a, y*a);
}

#endif /* POINT2D_H_ */
