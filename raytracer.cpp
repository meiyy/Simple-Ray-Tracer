#include "raytracer.h"
#include <iostream>


Raytracer::Raytracer(int pixelsY, int pixelsX, double height, double width, double focal, Vec3<double> eye, Vec3<double> up, Vec3<double> dir) 
	: focal(focal), Renderer(pixelsY, pixelsX, height, width, eye, up, dir)
{
	
}

Raytracer::~Raytracer()
{
}

void Raytracer::renderPerspective(unsigned char* buf, Surface **surfaces, int numOfSurface)
{
	Vec3<double> base = dir * focal + eye;
	for (int i = 0, bufpos = 0; i < pixelsY; i++)
	{
		for (int j = 0; j < pixelsX; j++) // For each pixel:
		{
			double dy = height / pixelsY * (i - center.x[0]);
			double dx = width / pixelsX * (j - center.x[1]);
			Vec3<double> curPos = base + up * -dy + right * dx;
			Vec3<double> curDir = curPos - eye;
			double t0 = curDir.module(), t1=1e3;
			curDir = curDir.norm();

			double ansT=-1;
			Vec3<double> ansN;
			int id=-1;
			for (int k = 0; k < numOfSurface; k++) // For each object:
			{
				double t;
				Vec3<double> n;
				surfaces[k]->intersect(eye, curDir, t0, t1, t, n);
				if (t > 0 && (id == -1 || t < ansT))
				{
					ansT = t;
					ansN = n;
					id = k;
				}
			}

			if (id >= 0) // If the nearest object exists:
			{
				// RGB
				buf[bufpos++] = 255;
				buf[bufpos++] = 0;
				buf[bufpos++] = 0;
			}
			else
			{
				// RGB
				buf[bufpos++] = bgcolor.x[0];
				buf[bufpos++] = bgcolor.x[1];
				buf[bufpos++] = bgcolor.x[2];
			}
		}
	}
}


void Raytracer::renderOrtho(unsigned char* buf, Surface **surfaces, int numOfSurface)
{
	for (int i = 0, bufpos = 0; i < pixelsY; i++)
	{
		for (int j = 0; j < pixelsX; j++) // For each pixel:
		{
			double dy = height / pixelsY * (i - center.x[0]);
			double dx = width / pixelsX * (j - center.x[1]);
			Vec3<double> curPos = eye + up * -dy + right * dx;
			double t0 = 1e-3, t1 = 1e3;

			double ansT = -1;
			Vec3<double> ansN;
			int id = -1;
			for (int k = 0; k < numOfSurface; k++) // For each object:
			{
				double t;
				Vec3<double> n;
				surfaces[k]->intersect(curPos, dir, t0, t1, t, n);
				if (t > 0 && (id == -1 || t < ansT))
				{
					ansT = t;
					ansN = n;
					id = k;
				}
			}

			if (id >= 0) // If the nearest object exists:
			{
				// RGB
				buf[bufpos++] = 255;
				buf[bufpos++] = 0;
				buf[bufpos++] = 0;
			}
			else
			{
				// RGB
				buf[bufpos++] = bgcolor.x[0];
				buf[bufpos++] = bgcolor.x[1];
				buf[bufpos++] = bgcolor.x[2];
			}
		}
	}
}
