#pragma once
#include "renderer.h"
#include "surface.h"

class Raytracer :
	public Renderer
{
private:
	double focal;
public:
	Raytracer(int pixelsY, int pixelsX, double height, double width, double focal, Vec3<double> eye, Vec3<double> up, Vec3<double> dir);
	~Raytracer();
	Vec3<unsigned char> solve(const std::vector<Surface*> &surfaces, const std::vector<LightSource> &lights, Vec3<double> curPos, Vec3<double> curDir);
	void renderPerspective(unsigned char* buf, const std::vector<Surface*> &surfaces, const std::vector<LightSource> &lights);
};
