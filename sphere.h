#pragma once
#include "surface.h"
class Sphere : public Surface
{
private:
	double radius;
public:
	Sphere(Vec3<double> pos, double radius);
	~Sphere();
	void intersect();
};
