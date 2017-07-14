#pragma once
#include "vec3.h"
class Surface
{
protected:
	Vec3<double> pos;
public:
	Surface(Vec3<double> pos);
	~Surface();
	virtual void intersect()=0;
};
