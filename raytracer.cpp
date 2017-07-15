#include "raytracer.h"



Raytracer::Raytracer(int pixelsY, int pixelsX, double height, double width, double focal, Vec3<double> eye, Vec3<double> up, Vec3<double> dir) 
	: focal(focal), Renderer(pixelsY, pixelsX, height, width, eye, up, dir)
{
	
}

Raytracer::~Raytracer()
{
}

void Raytracer::render(unsigned char * buf)
{
	Vec3<double> base = dir * focal + eye;
	for (int i = 0; i < pixelsY; i++)
	{
		for (int j = 0; j < pixelsX; j++)
		{
			double dy = height / pixelsY * (i - center.x[0]);
			double dx = width / pixelsX * (j - center.x[1]);
			Vec3<double> curPos = base + up * -dy + right * dx;
			Vec3<double> curDir = curPos - eye;
			double t0 = curDir.module();
			curDir = curDir.norm();

		}
	}
}
