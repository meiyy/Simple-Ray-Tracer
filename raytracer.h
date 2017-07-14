#pragma once
#include "renderer.h"
class Raytracer :
	public Renderer
{
public:
	Raytracer(int height,int width);
	~Raytracer();
};

