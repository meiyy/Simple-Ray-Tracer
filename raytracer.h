#pragma once
#include "renderer.h"
class Raytracer :
	public Renderer
{
private:
	double focal;
public:
	Raytracer(int pixelsY, int pixelsX, double height, double width, double focal, Vec3<double> eye, Vec3<double> up, Vec3<double> dir);
	~Raytracer();
	void render(unsigned char* buf);
};
