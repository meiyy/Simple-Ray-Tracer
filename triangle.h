#pragma once
#include "surface.h"
#include "meterial.h"
#include "vec3.h"
class Triangle : public Surface
{
public:
	Vec3<double> a;
	Vec3<double> b;
	Vec3<double> c;
	
	virtual void intersect(const Vec3<double>& start, const Vec3<double>& dir, double t0, double t1, double & t, Vec3<double>& n)const;
	Triangle(Vec3<double> a, Vec3<double> b, Vec3<double> c, int met);
	~Triangle();
};
