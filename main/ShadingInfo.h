/*
 * ShadingInfo.h
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

#ifndef SHADINGINFO_H_
#define SHADINGINFO_H_

#include "Normal.h"
#include "Point.h"
#include "Colour.h"
#include "Material.h"
#include "Ray.h"

class Scene;

class ShadingInfo {
public:
	ShadingInfo(const Scene& scene);
	ShadingInfo(const ShadingInfo& shadingInfo);
	virtual ~ShadingInfo();

	bool objectHit;
	Point localHitPoint;
	Point hitPoint;
	Normal normal;
	Colour colour;
	const Scene& scene;

	double t;

	Ray ray; // for specular highlights
	int depth; // recursion depth
	Vector direction; // for area lights
	Material* material; // nearest object's material

};

#endif /* SHADINGINFO_H_ */
