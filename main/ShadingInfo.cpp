/*
 * ShadingInfo.cpp
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

#include "ShadingInfo.h"

ShadingInfo::ShadingInfo(const Scene& scene) :
							localHitPoint(),
							normal(),
							scene(scene) {
	objectHit = false;
	colour.red = 0.0;
	colour.blue = 0.0;
	colour.green = 0.0;

}

ShadingInfo::~ShadingInfo() {
	// TODO Auto-generated destructor stub
}

