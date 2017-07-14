#pragma once
#include "renderer.h"
class Raytracer :
	public Renderer
{
public:
	
	Raytracer(int height, int width, Vec3<double> eye, Vec3<double> up, Vec3<double> dir);
	~Raytracer();
};
