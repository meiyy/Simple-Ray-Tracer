#pragma once
#include "vec3.h"
class Pattern
{
	bool use;
public:
	Vec3<double> getPixel(double innerx, double innery);
	Pattern(bool use);
	~Pattern();
};

