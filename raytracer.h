#pragma once
#include "renderer.h"
#include "surface.h"

class Raytracer :
	public Renderer
{
private:
	double focal;
public:
	Raytracer(int pixelsY, int pixelsX, double height, double width, double focal, Vec3<double> eye, Vec3<double> up, Vec3<double> dir);
	~Raytracer();
	void renderPerspective(unsigned char* buf, Surface **surfaces, int numOfSurface);
	void renderOrtho(unsigned char * buf, Surface ** surfaces, int numOfSurface);
};
