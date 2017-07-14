#include "display.h"
#include "raytracer.h"

int height = 600, width = 800;
int main(int argc, char** argv)
{
	Raytracer renderer(height, width);
	init("Ray Tracer Demo",height,width, argc, argv);
	work(&renderer);
	return 0;
}
