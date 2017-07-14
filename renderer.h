#pragma once
#include "vec2.h"
#include "vec3.h"

class Renderer
{
private:
	int height;
	int width;
	Vec2<int> center;
	Vec3<double> eye;
	Vec3<double> up;
	Vec3<double> dir;
public:
	Renderer::Renderer(int height, int width, Vec3<double> eye, Vec3<double> up, Vec3<double> dir) : height(height), width(width), eye(eye), up(up), dir(dir)
	{
		center.x[0] = height / 2;
		center.x[1] = width / 2;
	}
	~Renderer() {}
	virtual void render(unsigned char* buf);
};
