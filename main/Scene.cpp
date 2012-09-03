/*
 * Scene.cpp
 *
 *  Created on: 7 Jul 2012
 *      Author: ivantod
 */

#include "Scene.h"
#include "TGASupport.h"
#include <iostream>

using namespace std;

Scene::Scene(ViewPlane viewPlane, RayTracer* rayTracer, double zEye, double zDist) :
	viewPlane(viewPlane), ambientLight(new AmbientLight) {
	backgroundColour.red = 0.0;
	backgroundColour.green = 0.0;
	backgroundColour.blue = 0.0;
	this->rayTracer = rayTracer;
	this->zEye = zEye;
	this->zDist = zDist;
}

ShadingInfo Scene::hitObjects(Ray& ray) {
	ShadingInfo shadingInfo(*this);
	Normal normal;
	double tMin = 999999.0;
	double t;
	int numObjects = shapes.size();
	Point localHitPoint;

	for (int j=0; j<numObjects; j++) {
		if (shapes[j]->intersect(ray, t, shadingInfo) && t<tMin) {
			shadingInfo.objectHit = true;
			tMin = t;
			//shadingInfo.material = shapes[j]->getMaterial();
			shadingInfo.hitPoint = ray.origin + ray.direction*t;
			normal = shadingInfo.normal;
			localHitPoint = shadingInfo.localHitPoint;
		}
	}

	if (shadingInfo.objectHit) {
		shadingInfo.t = tMin;
		shadingInfo.normal = normal;
		shadingInfo.localHitPoint = localHitPoint;
	}

	return shadingInfo;
}

// render scene based on parallel rays going through the pixels
void Scene::renderScene() {
	//Colour pixelColour = {0.0, 0.0, 0.0}; // black
	Ray ray;
	Point2D squarePoint; // sample point on unit square
	Point2D pixelPoint; // sample point on pixel

	ray.direction = Vector(0, 0, -1);

	TGASupport tgaSupport("/Users/ivantod/test.tga");
	tgaSupport.prepareHeader(viewPlane.hres, viewPlane.vres);

	for (int row=0; row < viewPlane.vres; row++) {
		for (int col=0; col < viewPlane.hres; col++) {
			Colour pixelColour = {0.0, 0.0, 0.0};
			if (!viewPlane.sampler) {
				// no antialiasing
				double x = viewPlane.pixelSize * (col - 0.5 * (viewPlane.hres - 1.0));
				double y = viewPlane.pixelSize * (row - 0.5 * (viewPlane.vres - 1.0));
				ray.origin = Point(x, y, viewPlane.zw);
				pixelColour = rayTracer->traceRay(ray, this);
			} else {
				// antialiasing based on sampling
				for (int j=0; j<viewPlane.numSamples; j++) {
					squarePoint = viewPlane.sampler->sampleUnitSquare();
					pixelPoint.x = viewPlane.pixelSize * (col - 0.5 * viewPlane.hres + squarePoint.x);
					pixelPoint.y = viewPlane.pixelSize * (row - 0.5 * viewPlane.vres + squarePoint.y);

					ray.origin = Point(pixelPoint.x, pixelPoint.y, viewPlane.zw);

					pixelColour += rayTracer->traceRay(ray, this);
				}

				pixelColour /= viewPlane.numSamples; // normalise colour back to values in interval [0,1]

				//cout << pixelColour.red << " " << pixelColour.green << " " << pixelColour.blue << endl;
			}
			tgaSupport.writePixel(pixelColour);
		}
	}
}

// render scene based on rays originating from a fixed 'eye point' going through the pixels
void Scene::renderPerspective() {
	Ray ray;
	Point2D squarePoint; // sample point on unit square
	Point2D pixelPoint; // sample point on pixel

	ray.origin = Point(0.0, 0.0, zEye);

	TGASupport tgaSupport("/Users/ivantod/test.tga");
	tgaSupport.prepareHeader(viewPlane.hres, viewPlane.vres);

	for (int row=0; row < viewPlane.vres; row++) {
		for (int col=0; col < viewPlane.hres; col++) {
			Colour pixelColour = {0.0, 0.0, 0.0};
			if (!viewPlane.sampler) {
				// no antialiasing
				double xd = viewPlane.pixelSize * (col - 0.5 * (viewPlane.hres - 1.0));
				double yd = viewPlane.pixelSize * (row - 0.5 * (viewPlane.vres - 1.0));
				ray.direction = Vector(xd, yd, -zDist);
				ray.direction.normalise();
				pixelColour = rayTracer->traceRay(ray, this);
			} else {
				// antialiasing based on sampling
				for (int j=0; j<viewPlane.numSamples; j++) {
					squarePoint = viewPlane.sampler->sampleUnitSquare();
					pixelPoint.x = viewPlane.pixelSize * (col - 0.5 * viewPlane.hres + squarePoint.x);
					pixelPoint.y = viewPlane.pixelSize * (row - 0.5 * viewPlane.vres + squarePoint.y);

					ray.direction = Vector(pixelPoint.x, pixelPoint.y, -zDist);
					ray.direction.normalise();

					pixelColour += rayTracer->traceRay(ray, this);
				}

				pixelColour /= viewPlane.numSamples; // normalise colour back to values in interval [0,1]

				//cout << pixelColour.red << " " << pixelColour.green << " " << pixelColour.blue << endl;
			}
			tgaSupport.writePixel(pixelColour);
		}
	}
}

void Scene::addShape(Shape* shape) {
	shapes.push_back(shape);
}

void Scene::addLight(Light* light) {
	lights.push_back(light);
}

Scene::~Scene() {
	int numShapes = shapes.size();

	for (int i = 0; i < numShapes; i++) {
		delete shapes[i];
		shapes[i] = NULL;
	}

	shapes.erase(shapes.begin(), shapes.end());
}

