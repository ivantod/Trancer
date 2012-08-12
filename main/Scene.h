/*
 * Scene.h
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include "Shape.h"
#include "Light.h"
#include "ViewPlane.h"
#include "Colour.h"
#include "RayTracer.h"

class RayTracer;
class Scene {
public:
	Scene(ViewPlane viewPlane, RayTracer* rayTracer, double zEye, double zDist);
	virtual ~Scene();

	void renderScene();
	void renderPerspective();

	std::vector<Shape*> shapes;
	std::vector<Light*> lights;

	ViewPlane viewPlane;
	Colour backgroundColour;
	RayTracer* rayTracer;

	void addShape(Shape* shape);
	void addLight(Light* light);

private:

	double zEye; // z-coordinate of eye position;
	double zDist;

};

#endif /* SCENE_H_ */
