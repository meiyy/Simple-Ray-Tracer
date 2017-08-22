#include "raytracer.h"
#include "display.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

Raytracer::Raytracer(int pixelsY, int pixelsX, double height, double width, double focal, Vec3<double> eye, Vec3<double> up, Vec3<double> dir) 
	: focal(focal), Renderer(pixelsY, pixelsX, height, width, eye, up, dir)
{
	
}

Raytracer::~Raytracer()
{
}

Vec3<unsigned char> Raytracer::solve(const std::vector<Surface*> &surfaces, const std::vector<LightSource> &lights, Vec3<double> curPos, Vec3<double> curDir)
{
	double t0 = curDir.module(), t1 = 1e3;
	curDir = curDir.norm();
	Vec3<double> V = curDir*-1;

	double ansT = -1;
	Vec3<double> ansN;
	int id = -1;
	for (int k = 0; k < surfaces.size(); k++) // For each object:
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
		Meterial &met = meterials[surfaces[id]->meterial];
		const int *amb = ambient.intensity.x;

		// RGB
		unsigned char colors[3];
		for (int c = 0; c < 3; c++)
		{
			colors[c] = std::min(255, (int)(met.ambient.x[c] * amb[c] ));
		}
		for (int k = 0; k < lights.size(); k++)
		{
			Vec3<double> lightdir = lights[k].pos - ansPos;
			double dis = lightdir.module();
			lightdir = lightdir.norm();
			for (int c = 0; c < 3; c++)
			{
				double tt = -1;
				for (int kk = 0; kk < surfaces.size(); kk++) // For each object:
				{
					double t;
					Vec3<double> n;
					surfaces[kk]->intersect(ansPos, lightdir, 1e-3, dis, t, n);
					tt = std::max(t, tt);
				}
				if (tt < 0)
				{
					if (lightdir.innerProduct(ansN) > 0)
					{
						colors[c] = std::min(255, (int)(colors[c] + lights[k].intensity.x[c] *
							met.diffuse.x[c] * std::fmax(0., ansN.innerProduct(lightdir))));
						colors[c] = std::min(255, (int)(colors[c] + lights[k].intensity.x[c] *
							met.specular.x[c] * std::pow(std::fmax(0, ansN.innerProduct((V + lightdir).norm())), met.pvalue)));
					}
				}
			}
		}
		return Vec3<unsigned char>(
			(unsigned char)(colors[0] ),
			(unsigned char)(colors[1] ),
			(unsigned char)(colors[2] )
			);
	}
	else
	{
		// RGB
		return bgcolor;
	}
}

void Raytracer::renderPerspective(unsigned char* buf, const std::vector<Surface*> &surfaces, const std::vector<LightSource> &lights)
{
	static const double ra = 1.0/3;
	static const double bs = 1.0/9;
	static const double offset[3][3][2] = 
	{
		{{-ra,-ra}, {-ra,0}, {-ra,ra}},
		{{0,-ra}, {0,0}, {0,ra}},
		{{ra,-ra}, {ra,0}, {ra,ra}}
	};
	static const double weight[3][3] = 
	{
		bs,bs,bs,
		bs,bs,bs,
		bs,bs,bs
	};
	Vec3<double> base = dir * focal + eye;
	for (int i = pixelsY-1, bufpos = 0; i>=0; i--)
	{
		for (int j = 0; j < pixelsX; j++) // For each pixel:
		{
			double c0 = 0, c1 = 0, c2 = 0;
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++)
			{
				double dy = height / pixelsY * (i + offset[k][l][0] - center.x[0]);
				double dx = width / pixelsX * (j + offset[k][l][1] - center.x[1]);
				Vec3<double> curPos = base + up * -dy + right * dx;
				Vec3<double> curDir = curPos - eye;
				Vec3<unsigned char> ans = solve(surfaces, lights, curPos, curDir);
				c0 += (ans.x[0] * weight[k][l]);
				c1 += (ans.x[1] * weight[k][l]);
				c2 += (ans.x[2] * weight[k][l]);
			}
			buf[bufpos + 0] = (unsigned char)c0;
			buf[bufpos + 1] = (unsigned char)c1;
			buf[bufpos + 2] = (unsigned char)c2;
			
				// RGB
			bufpos += 3;
			
		}
	}
}

