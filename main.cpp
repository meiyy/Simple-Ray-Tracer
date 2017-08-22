#include "display.h"
#include "raytracer.h"
#include "sphere.h"
#include "triangle.h"

int height = 600, width = 800;

void initMeterial()
{
	meterials.push_back(Meterial());
	meterials.push_back(
		Meterial(
			Vec3<double>(0.2, 0., 0.),
			Vec3<double>(0.4, 0.4, 0.4),
			Vec3<double>(0.6, 0.6, 0.6), 10)
	);
	meterials.push_back(
		Meterial(
			Vec3<double>(0.2, 0.3, 0.),
			Vec3<double>(0.4, 0.4, 0.4),
			Vec3<double>(0.6, 0.6, 0.6), 10)
	);
	meterials.push_back(
		Meterial(
			Vec3<double>(0.2, 0.2, 0.2),
			Vec3<double>(0.4, 0.4, 0.4),
			Vec3<double>(0.6, 0.6, 0.6), 5)
	);
	meterials.push_back(
		Meterial(
			Vec3<double>(0.2, 0.2, 0.2),
			Vec3<double>(0.4, 0.4, 0.4),
			Vec3<double>(0.6, 0.6, 0.6), 5)
	);

}

void initSurfaces()
{
	surfaces.push_back(new Sphere(
		Vec3<double>(0, 1, 3), 
		1, 
		1
	));
	
	surfaces.push_back(new Sphere(
		Vec3<double>(1.5, 0.5, 3), 
		0.5, 
		2
	));
	surfaces.push_back(new Triangle(
		Vec3<double>(-2, 0, 1),
		Vec3<double>(2, 0, 1),
		Vec3<double>(-2, 0, 5), 
		3
	));
	surfaces.push_back(new Triangle(
		Vec3<double>(2, 0, 1),
		Vec3<double>(2, 0, 5),
		Vec3<double>(-2, 0, 5),
		4
	));
}

void initLight()
{
	lightsources.push_back(LightSource(
		Vec3<double>(0,0,0),
		Vec3<double>(0,0,3),
		Vec3<int>(200,200,200))
	);
}

int main(int argc, char** argv)
{
	initLight();
	initMeterial();
	initSurfaces();
	Raytracer renderer0(height, width, 6, 8, 10, Vec3<double>(0,10,-7), Vec3<double>(0,10,0), Vec3<double>(0,-10,10));
	init("Ray Tracer Demo",height,width, argc, argv);
	work(&renderer0);
	return 0;
}
