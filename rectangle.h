#pragma once
#include "surfacegroup.h"
class Rectangle : public SurfaceGroup
{
	double width;
	double height;
public:
	Rectangle(double width, double height, Vec3<double> pos, int met);
	~Rectangle();
};

