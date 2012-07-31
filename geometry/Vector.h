/*
 * Vector.h
 *
 *  Created on: 19 Jul 2012
 *      Author: ivantod
 */

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
public:
	Vector();
	Vector(double x, double y, double z);
	virtual ~Vector();

	Vector operator-() const;

	Vector operator*(const double a) const;

	Vector operator/(const double a) const;

	Vector operator+(const Vector& v) const;

	Vector operator-(const Vector& v) const;

	Vector& operator+=(const Vector& v);

	double operator*(const Vector& b) const;

	Vector operator^(const Vector& v) const;

	double x;
	double y;
	double z;
};

inline Vector Vector::operator-() const {
	return Vector(-x, -y, -z);
}

inline Vector Vector::operator*(const double a) const {
	return Vector(x*a, y*a, z*a);
}

inline Vector Vector::operator/(const double a) const {
	return Vector(x/a, y/a, z/a);
}

inline Vector Vector::operator+(const Vector& v) const {
	return Vector(x+v.x, y+v.y, z+v.z);
}

inline Vector Vector::operator-(const Vector& v) const {
	return Vector(x-v.x, y-v.y, z-v.z);
}

inline Vector& Vector::operator+=(const Vector& v) {
	x+=v.x; y+=v.y; z+=v.z;
	return *this;
}

inline double Vector::operator*(const Vector& v) const {
	return x*v.x + y*v.y + z*v.z;
}

inline Vector Vector::operator^(const Vector& v) const {
	return Vector(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
}

#endif /* VECTOR_H_ */
