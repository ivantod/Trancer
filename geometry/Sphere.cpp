/*
 * Sphere.cpp
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#include "Sphere.h"
#include "Ray.h"
#include "Constants.h"
#include <math.h>

Sphere::Sphere(Point centre, double r, Colour colour) :
	centre(centre), r(r){
	this->colour.red = colour.red;
	this->colour.green = colour.green;
	this->colour.blue = colour.blue;
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

bool Sphere::intersect(Ray& ray, double& tMin, ShadingInfo& shadingInfo) const {
	double t;

	Vector temp = ray.origin - centre;
	double a = ray.direction * ray.direction;
	double b = 2.0 * (temp * ray.direction);
	double c = temp * temp - r * r;

	double discriminant = b*b - 4*a*c;

	if (discriminant<0.0) {
		return false;
	} else {
		double e = sqrt(discriminant);
		double denom = 2.0 * a;
		t = (-b - e)/denom;  // smaller root
		if (t > EPSILON) {
			tMin = t;
			shadingInfo.normal = (temp + ray.direction * t) / r;
			shadingInfo.localHitPoint = ray.origin + ray.direction * t;
			return true;
		}

		t = (-b + e)/denom; // larger root
		if (t > EPSILON) {
			tMin = t;
			shadingInfo.normal = (temp + ray.direction * t) / r;
			shadingInfo.localHitPoint = ray.origin + ray.direction * t;
			return true;
		}
	}

	return false;
}

