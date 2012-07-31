/*
 * Normal.h
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

#ifndef NORMAL_H_
#define NORMAL_H_

#include "Vector.h"

class Normal {
public:
	Normal();
	Normal(double x, double y, double z);

	virtual ~Normal();

	Normal& operator= (const Vector& v);

private:
	double x;
	double y;
	double z;
};

#endif /* NORMAL_H_ */
