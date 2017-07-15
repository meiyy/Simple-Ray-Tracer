#pragma once
#include "vec3.h"
class Surface
{
protected:
	Vec3<double> pos;
public:
	Surface(Vec3<double> pos);
	~Surface();
	virtual void intersect(const Vec3<double>& start, const Vec3<double>& dir, double t0, double t1, double & t, Vec3<double>& n)=0;
};
