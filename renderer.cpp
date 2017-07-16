#include <cmath>
#include "renderer.h"

void Renderer::renderPerspective(unsigned char* buf, Surface **surfaces, int numOfSurface,LightSource **lights,int numOfLights)
{
	static int t = 0;
	for (int i = 0; i < pixelsY; i++)
	{
		for (int j = 0; j < pixelsX; j++)
		{
			if (std::abs(i + j - t)<10)
				buf[(i*pixelsX + j) * 3] = 255;
			else
				buf[(i*pixelsX + j) * 3] = 0;
			buf[(i*pixelsX + j) * 3 + 1] = 0;
			buf[(i*pixelsX + j) * 3 + 2] = 0;
		}
	}
	t += 2;
	if (t == pixelsY + pixelsX)
		t = 0;
}
void Renderer::renderOrtho(unsigned char * buf, Surface ** surfaces, int numOfSurface, LightSource ** lights, int numOfLights)
{
	static int t = 0;
	for (int i = 0; i < pixelsY; i++)
	{
		for (int j = 0; j < pixelsX; j++)
		{
			if (std::abs(i + j - t)<10)
				buf[(i*pixelsX + j) * 3] = 255;
			else
				buf[(i*pixelsX + j) * 3] = 0;
			buf[(i*pixelsX + j) * 3 + 1] = 0;
			buf[(i*pixelsX + j) * 3 + 2] = 0;
		}
	}
	t += 2;
	if (t == pixelsY + pixelsX)
		t = 0;
}