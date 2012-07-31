/*
 * MathFunc.h
 *
 *  Created on: 29 Jul 2012
 *      Author: ivantod
 */

#ifndef MATHFUNC_H_
#define MATHFUNC_H_

#include "Constants.h"

inline int rand_int() {
	return rand();
}

inline float rand_float(void) {
	return((float)rand_int() * INV_RAND_MAX);
}

inline float rand_float(int l, float h) {
	return (rand_float() * (h - l) + l);
}

inline int rand_int(int l, int h) {
	return ((int) (rand_float(0, h - l + 1) + l));
}


#endif /* MATHFUNC_H_ */
