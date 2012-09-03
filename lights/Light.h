/*
 * Light.h
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "Vector.h"
#include "Colour.h"
#include "ShadingInfo.h"

class Light {
public:
	Light();
	virtual ~Light();

	virtual Vector getDirection(ShadingInfo& shadingInfo) = 0;
	virtual Colour getLuminance(ShadingInfo& shadingInfo) = 0;

	bool shadows;
};

#endif /* LIGHT_H_ */
