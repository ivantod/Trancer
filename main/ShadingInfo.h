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

class Scene;

class ShadingInfo {
public:
	ShadingInfo(const Scene& scene);
	virtual ~ShadingInfo();

	bool objectHit;
	Point localHitPoint;
	Normal normal;
	Colour colour;
	const Scene& scene;
};

#endif /* SHADINGINFO_H_ */
