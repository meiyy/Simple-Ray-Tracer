#include "display.h"
#include "raytracer.h"
#include "sphere.h"

int height = 600, width = 800;

void initSurfaces()
{
	addSurface(new Sphere(Vec3<double>(0, 0, 3), 1));
}
int main(int argc, char** argv)
{
	initSurfaces();
	Raytracer renderer0(height, width, 6, 8, 10, Vec3<double>(0,0,-10), Vec3<double>(0,1,0), Vec3<double>(0,0,1));
	//Renderer renderer1(height, width, 6, 8, Vec3<double>(0, 0, -1), Vec3<double>(0, 1, 0), Vec3<double>(0, 0, 1));
	init("Ray Tracer Demo",height,width, argc, argv);
	work(&renderer0);
	return 0;
}
