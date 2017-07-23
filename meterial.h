#pragma once
#include "vec3.h"
#include "pattern.h"

class Meterial
{
public:
	Pattern &pt;
	Vec3<double> ambient;
	Vec3<double> diffuse;
	Vec3<double> specular;
	double pvalue;
	Meterial(Vec3<double> ambient, Vec3<double> diffuse, Vec3<double> specular, double pvalue, Pattern *Pt);
	~Meterial();
};