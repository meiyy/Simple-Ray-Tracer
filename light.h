#pragma once
#include "vec3.h"
class Light
{
public:
	Vec3<double> start;
	Vec3<double> dir;
	Light();
	~Light();
};

