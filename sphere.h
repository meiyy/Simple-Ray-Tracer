#pragma once
#include "surface.h"
class Sphere : public Surface
{
private:
	double radius;
public:
	Sphere(Vec3<double> pos, double radius, Meterial meterial);
	~Sphere();
	void intersect(const Vec3<double> &start, const Vec3<double> &dir, double t0, double t1, double &t, Vec3<double> &n);
};
