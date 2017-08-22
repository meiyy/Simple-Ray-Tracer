#include "surfacegroup.h"

SurfaceGroup::SurfaceGroup(int cnt):cnt(cnt),Surface()
{
	if(cnt>0)
		suf = new Surface*[cnt];
}

void SurfaceGroup::addSurface(Surface * suraface)
{
	if(tmp<cnt)
		suf[tmp++] = suraface;
}

void SurfaceGroup::intersect(const Vec3<double>& start, const Vec3<double>& dir, double t0, double t1, double & t, Vec3<double>& n)const
{
	t = t1 + 1;
	for (int i = 0; i < tmp; i++)
	{
		double tt = -1;
		Vec3<double> nn;
		suf[i]->intersect(start, dir, t0, t1, tt, nn);
		if (tt > t0 && tt < t)
		{
			t = tt;
			n = nn;
		}
	}
}
