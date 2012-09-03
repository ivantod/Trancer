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
#include "AmbientLight.h"

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

	Light* ambientLight;


	Colour backgroundColour;
	RayTracer* rayTracer;

	void addShape(Shape* shape);
	void addLight(Light* light);

	ShadingInfo hitObjects(Ray& ray);

private:

	double zEye; // z-coordinate of eye position;
	double zDist; // distance between eye position and projection (view) plane

};

#endif /* SCENE_H_ */
