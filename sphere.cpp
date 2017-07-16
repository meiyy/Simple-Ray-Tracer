#include "sphere.h"
#include <cmath>
#include <iostream>


Sphere::Sphere(Vec3<double> pos, double radius, Meterial meterial)
	:Surface(pos,meterial),radius(radius)
{
}


Sphere::~Sphere()
{

}

void Sphere::intersect(const Vec3<double> &start, const Vec3<double> &dir, double t0, double t1,
	double &t, Vec3<double> &n)
{
	Vec3<double> dis = start - pos;
	double A = dir.innerProduct(dir),
		B = dir.innerProduct(dis) * 2,
		C = (dis).innerProduct(dis) - radius * radius;
	double delta = B * B - 4 * A * C;
	if (delta < 0)
	{
		t = -1;
	}
	else
	{
		double tmp = std::sqrt(delta);
		double x1 = (-B + tmp) / (2 * A),
			x2 = (-B - tmp) / (2 * A);
		t = t1 + 1;
		if (x1 > t0)
			t = std::fmin(t, x1);
		if (x2 > t0)
			t = std::fmin(t, x2);
		if (t > t1)
		{
			t = -1;
			return;
		}
		n = (start + dir * t - pos).norm();
	}
}
