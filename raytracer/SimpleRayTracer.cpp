/*
 * SimpleRayTracer.cpp
 *
 *  Created on: 20 Jul 2012
 *      Author: ivantod
 */

#include "SimpleRayTracer.h"
#include "ShadingInfo.h"
#include "TGASupport.h"

SimpleRayTracer::SimpleRayTracer(Scene& scene) :
	scene(scene) {
}

SimpleRayTracer::~SimpleRayTracer() {
	// TODO Auto-generated destructor stub
}

void SimpleRayTracer::renderScene() const {

	ViewPlane vp = scene.viewPlane;

	Ray ray;

	ray.direction = Vector(0, 0, -1);

	TGASupport tgaSupport("/Users/ivantod/test.tga");
	tgaSupport.prepareHeader(vp.hres, vp.vres);

	for (int row=0; row < vp.hres; row++) {
		for (int col=0; col < vp.vres; col++) {
			double x = vp.pixelSize * (col - 0.5 * (vp.hres - 1.0));
			double y = vp.pixelSize * (row - 0.5 * (vp.vres - 1.0));

			ray.origin = Point(x, y, vp.zw);
			Colour pixelColour = traceRay(ray);

			tgaSupport.writePixel(pixelColour);
		}
	}
}

Colour SimpleRayTracer::traceRay(Ray ray) const {
	Shape *s = scene.shapes[0]; // Just one object in the scene for the time being.

	ShadingInfo shadingInfo(scene);
	double tMin = 0;

	bool hit = s->intersect(ray, tMin, shadingInfo);

	if (hit) {
		return s->colour;
	} else {
		return scene.backgroundColour;
	}
}
