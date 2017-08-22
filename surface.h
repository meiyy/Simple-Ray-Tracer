#pragma once
#include "vec3.h"
#include "meterial.h"
 
class Surface
{
protected:
	Vec3<double> pos;
public:
	int meterial;
	Surface(Vec3<double> pos = Vec3<double>(0, 0, 0), int meterial = 0);
	~Surface();
	virtual void intersect(const Vec3<double>& start, const Vec3<double>& dir, double t0, double t1, double & t, Vec3<double>& n)=0;
};
