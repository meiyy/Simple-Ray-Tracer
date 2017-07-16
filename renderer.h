#pragma once
#include "vec2.h"
#include "vec3.h"
#include "surface.h"
#include "lightsource.h"

class Renderer
{
protected:
	int pixelsY;
	int pixelsX;
	double height;
	double width;
	Vec2<int> center;
	Vec3<double> eye;
	Vec3<double> up;
	Vec3<double> dir;
	Vec3<double> right;
	Vec3<unsigned char> bgcolor;
public:
	Renderer::Renderer(int pixelsY, int pixelsX, double height, double width, Vec3<double> eye, Vec3<double> up, Vec3<double> dir)
		: pixelsY(pixelsY), pixelsX(pixelsX), height(height), width(width), eye(eye), up(up), dir(dir)
	{
		bgcolor = Vec3<unsigned char>(128, 128, 128);
		center.x[0] = pixelsY / 2;
		center.x[1] = pixelsX / 2;
		this->up = this->up.norm();
		this->dir = this->dir.norm();
		this->right = this->dir.outerProduct(this->up)*-1;
		this->up = this->right.outerProduct(this->dir)*-1;
	}
	~Renderer() {}
	virtual void renderPerspective(unsigned char * buf, Surface ** surfaces, int numOfSurface, LightSource ** lights, int numOfLights);
	virtual void renderOrtho(unsigned char * buf, Surface ** surfaces, int numOfSurface, LightSource ** lights, int numOfLights);
};