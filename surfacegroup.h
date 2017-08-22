#pragma once
#include "surface.h"
class SurfaceGroup:public Surface
{
	int cnt;
	int tmp;
	Surface **suf;
public:
	SurfaceGroup(int cnt=0);
	~SurfaceGroup() {}
	void addSurface(Surface *suraface);
	void intersect(const Vec3<double>& start, const Vec3<double>& dir, double t0, double t1, double & t, Vec3<double>& n);
};

