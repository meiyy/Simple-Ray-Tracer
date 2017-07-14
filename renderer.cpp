#include <cmath>
#include "renderer.h"

void Renderer::render(unsigned char* buf)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (std::abs(i + j - t)<10)
				buf[(i*width + j) * 3] = 255;
			else
				buf[(i*width + j) * 3] = 0;
			buf[(i*width + j) * 3 + 1] = 0;
			buf[(i*width + j) * 3 + 2] = 0;
		}
	}
	t += 2;
	if (t == height + width)
		t = 0;
}