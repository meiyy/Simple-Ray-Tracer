#include "display.h"
#include "raytracer.h"
#include "sphere.h"
#include "triangle.h"

int height = 600, width = 800;

void initSurfaces()
{
	addSurface(new Sphere(
		Vec3<double>(0, 1, 3), 
		1, 
		Meterial(
			Vec3<double>(0.2, 0., 0.), 
			Vec3<double>(0.4, 0.4, 0.4), 
			Vec3<double>(0.6, 0.6, 0.6),10)
	));
	addSurface(new Sphere(
		Vec3<double>(1.5, 0.5, 3), 
		0.5, 
		Meterial(
			Vec3<double>(0.2, 0.3, 0.), 
			Vec3<double>(0.4, 0.4, 0.4), 
			Vec3<double>(0.6, 0.6, 0.6), 10)
	));
	//addSurface(new Sphere(Vec3<double>(0, -5, 4), 5, Meterial(Vec3<double>(0.1, 0.1, 0.1), Vec3<double>(0.3, 0.3, 0.3), Vec3<double>(0.4, 0.4, 0.4), 10)));
	addSurface(new Triangle(
		Vec3<double>(-2, 0, 1),
		Vec3<double>(2, 0, 1),
		Vec3<double>(-2, 0, 5), 
		Meterial(
			Vec3<double>(0.2, 0.2, 0.2),
			Vec3<double>(0.4, 0.4, 0.4),
			Vec3<double>(0.6, 0.6, 0.6), 5)
	));
	addSurface(new Triangle(
		Vec3<double>(2, 0, 1),
		Vec3<double>(2, 0, 5),
		Vec3<double>(-2, 0, 5),
		Meterial(
			Vec3<double>(0.2, 0.2, 0.2),
			Vec3<double>(0.4, 0.4, 0.4),
			Vec3<double>(0.6, 0.6, 0.6), 5)
	));
}

void initLight()
{
	
	addLight(new LightSource(Vec3<double>(0,0,0),Vec3<double>(0,0,3),Vec3<int>(200,200,200)));
}

int main(int argc, char** argv)
{
	initLight();
	initSurfaces();
	Raytracer renderer0(height, width, 6, 8, 10, Vec3<double>(0,10,-7), Vec3<double>(0,10,0), Vec3<double>(0,-10,10));
	//Raytracer renderer0(height, width, 6, 8, 10, Vec3<double>(0, 0, -10), Vec3<double>(0, 10, 0), Vec3<double>(0, 0, 10));
	//Renderer renderer1(height, width, 6, 8, Vec3<double>(0, 0, -1), Vec3<double>(0, 1, 0), Vec3<double>(0, 0, 1));
	init("Ray Tracer Demo",height,width, argc, argv);
	work(&renderer0);
	return 0;
}
