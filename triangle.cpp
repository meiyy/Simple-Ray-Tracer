#include "triangle.h"
#include "matrix3.h"


void Triangle::intersect(const Vec3<double>& start, const Vec3<double>& dir, double t0, double t1, double & t, Vec3<double>& n)const
{
	double dataA[3][3] = {
		{ a.x[0] - b.x[0], a.x[0] - c.x[0], dir.x[0] }
		,{ a.x[1] - b.x[1], a.x[1] - c.x[1], dir.x[1] }
		,{ a.x[2] - b.x[2], a.x[2] - c.x[2], dir.x[2] }
	};
	double A = Matrix3<double>(dataA).det();
	if (A == 0)
	{
		t = -1;
		return;
	}
	double datat[3][3] = {
		{ a.x[0] - b.x[0], a.x[0] - c.x[0], a.x[0] - start.x[0] }
		,{ a.x[1] - b.x[1], a.x[1] - c.x[1], a.x[1] - start.x[1] }
		,{ a.x[2] - b.x[2], a.x[2] - c.x[2], a.x[2] - start.x[2] }
	};
	t = Matrix3<double>(datat).det()/A;
	if (t < t0 || t > t1)
	{
		t = -1;
		return;
	}
	double datagama[3][3] = {
		{ a.x[0] - b.x[0], a.x[0] - start.x[0], dir.x[0] }
		,{ a.x[1] - b.x[1], a.x[1] - start.x[1], dir.x[1] }
		,{ a.x[2] - b.x[2], a.x[2] - start.x[2], dir.x[2] }
	};
	double gama = Matrix3<double>(datagama).det() / A;
	if (gama < 0 || gama>1)
	{
		t = -1;
		return;
	}
	double databeta[3][3] = {
		{ a.x[0] - start.x[0], a.x[0] - c.x[0], dir.x[0] }
		,{ a.x[1] - start.x[1], a.x[1] - c.x[1], dir.x[1] }
		,{ a.x[2] - start.x[2], a.x[2] - c.x[2], dir.x[2] }
	};
	double beta = Matrix3<double>(databeta).det() / A;
	if (beta < 0 || beta > 1 - gama)
	{
		t = -1;
		return;
	}
	n = (a - b).outerProduct(c - b).norm();
}

Triangle::Triangle(Vec3<double> a, Vec3<double> b, Vec3<double> c, int met)
	:a(a), b(b), c(c), Surface(a,met)
{

}


Triangle::~Triangle()
{
}

