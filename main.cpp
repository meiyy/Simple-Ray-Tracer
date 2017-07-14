#include "display.h"
#include "raytracer.h"

int height = 600, width = 800;
int main(int argc, char** argv)
{
	Raytracer renderer(height, width,Vec3<double>(0,0,-1),Vec3<double>(0,1,0),Vec3<double>(0,0,1));
	init("Ray Tracer Demo",height,width, argc, argv);
	work(&renderer);
	return 0;
}
