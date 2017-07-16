#pragma once
#include "vec3.h"

class LightSource
{
public:
	Vec3<double> pos;
	Vec3<double> dir;
	Vec3<int> intensity;//RGB
	LightSource(Vec3<double> pos, Vec3<double> dir, Vec3<int> intensity);
	~LightSource();
};

