#include "raytracer.h"
#include "display.h"
#include <iostream>
#include <algorithm>


Raytracer::Raytracer(int pixelsY, int pixelsX, double height, double width, double focal, Vec3<double> eye, Vec3<double> up, Vec3<double> dir) 
	: focal(focal), Renderer(pixelsY, pixelsX, height, width, eye, up, dir)
{
	
}

Raytracer::~Raytracer()
{
}

void Raytracer::renderPerspective(unsigned char* buf, Surface **surfaces, int numOfSurface, LightSource **lights, int numOfLights)
{
	Vec3<double> base = dir * focal + eye;
	for (int i = pixelsY-1, bufpos = 0; i>=0; i--)
	{
		for (int j = 0; j < pixelsX; j++) // For each pixel:
		{
			double dy = height / pixelsY * (i - center.x[0]);
			double dx = width / pixelsX * (j - center.x[1]);
			Vec3<double> curPos = base + up * -dy + right * dx;
			Vec3<double> curDir = curPos - eye;
			double t0 = curDir.module(), t1=1e3;
			curDir = curDir.norm();
			Vec3<double> V = curDir*-1;

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
			Vec3<double> ansPos = eye + curDir*ansT;
			if (id >= 0) // If the nearest object exists:
			{
				Meterial &met = surfaces[id]->meterial;
				const int *amb = ambient.intensity.x;

				// RGB
				for (int c = 0; c < 3; c++)
				{
					buf[bufpos + c] = std::min(255, (int)(met.ambient.x[c] * amb[c]));
				}
				for (int k = 0; k < numOfLights; k++)
				{
					Vec3<double> lightdir = lights[k]->pos - ansPos;
					double dis = lightdir.module();
					lightdir = lightdir.norm();
					for (int c = 0; c < 3; c++)
					{
						double tt=-1;
						for (int kk = 0; kk < numOfSurface; kk++) // For each object:
						{
							double t;
							Vec3<double> n;
							surfaces[kk]->intersect(ansPos, lightdir, 1e-3, dis, t, n);
							tt = std::max(t, tt);
						}
						if (tt < 0)
						{
							buf[bufpos + c] = std::min(255, (int)(buf[bufpos + c] + lights[k]->intensity.x[c] *
								met.diffuse.x[c] * std::fmax(0., ansN.innerProduct(lightdir))));
							if (lightdir.innerProduct(ansN) > 0)
								buf[bufpos + c] = std::min(255, (int)(buf[bufpos + c] + lights[k]->intensity.x[c] *
									met.specular.x[c] * std::pow(std::fmax(0, ansN.innerProduct((V + lightdir).norm())), met.pvalue)));
						}
					}
				}
				bufpos += 3;
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


void Raytracer::renderOrtho(unsigned char* buf, Surface **surfaces, int numOfSurface, LightSource **lights, int numOfLights)
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
