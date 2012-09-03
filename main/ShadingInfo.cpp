/*
 * ShadingInfo.cpp
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

// Below header needed for definition of NULL!
#include <cstddef>
#include "ShadingInfo.h"

ShadingInfo::ShadingInfo(const Scene& scene) :
							localHitPoint(),
							hitPoint(),
							normal(),
							scene(scene),
							depth(0),
							material(NULL)
							{
	objectHit = false;
	colour.red = 0.0;
	colour.blue = 0.0;
	colour.green = 0.0;
	t = 0;
}

ShadingInfo::ShadingInfo(const ShadingInfo& shadingInfo) :
			localHitPoint(shadingInfo.localHitPoint),
			hitPoint(shadingInfo.hitPoint),
			normal(shadingInfo.normal),
			scene(shadingInfo.scene),
			t(shadingInfo.t),
			depth(shadingInfo.depth),
			material(shadingInfo.material)
			 {
	objectHit = shadingInfo.objectHit;
	colour.red = shadingInfo.colour.red;
	colour.blue = shadingInfo.colour.blue;
	colour.green = shadingInfo.colour.green;
}

ShadingInfo::~ShadingInfo() {
	// TODO Auto-generated destructor stub
}

