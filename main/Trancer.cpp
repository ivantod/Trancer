//============================================================================
// Name        : Trancer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TGASupport.h"
#include "Colour.h"
#include "RayTracer.h"
#include "Scene.h"
#include "SimpleRayTracer.h"
#include "Sphere.h"
#include "Shape.h"

// tracers
//#include "SimpleRayTracer.h"
#include "MultiObjectRayTracer.h"


using namespace std;


void buildScene(Scene& scene) {

	Colour red = {1.0, 0.0, 0.0};
	Colour yellow = {1.0, 1.0, 0.0};

	Shape* shape = new Sphere(Point(0.0,-25.0,0.0), 80.0, red);
	scene.addShape(shape);

	shape = new Sphere(Point(20.0, 30.0, 0.0), 60, yellow);
	scene.addShape(shape);
}



int main() {

	cout << "*** Trancer starting!" << endl;

	ViewPlane viewPlane(250,250,100,1);
	viewPlane.setNumSamples(25);

	cout << "+++ ViewPlane initialised." << endl;

	RayTracer *tracer = new MultiObjectRayTracer();

	cout << "+++ RayTracer initialised." << endl;

	Scene* scene = new Scene(viewPlane, tracer);

	cout << "+++ Scene initialised." << endl;

	buildScene(*scene);

	cout << "+++ Scene built." << endl;

	scene->renderScene();

	cout << "+++ Scene rendered." << endl;

	delete tracer;

	cout << "!!! All done." << endl;

	return 0;
}


