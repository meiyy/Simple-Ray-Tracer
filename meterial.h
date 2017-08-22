#pragma once
#include "vec3.h"

class Meterial
{
public:
	Vec3<double> ambient;
	Vec3<double> diffuse;
	Vec3<double> specular;
	double pvalue;
	Meterial();
	Meterial(Vec3<double> ambient, Vec3<double> diffuse, Vec3<double> specular, double pvalue);
	~Meterial();
};