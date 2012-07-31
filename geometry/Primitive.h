/*
 * Primitive.h
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

#include "Shape.h"
#include "Material.h"

class Primitive {
public:
	Primitive(Shape *shape, Material material);

	virtual ~Primitive();

	// getBoundingBox ??

private:
	Shape *shape;
	Material material;

};

#endif /* PRIMITIVE_H_ */
