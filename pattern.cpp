#include "pattern.h"
#include <iostream>


Vec3<double> Pattern::getPixel(double innerx, double innery)
{
	if(!use)
		return Vec3<double>(1., 1., 1.);
	bool bx = (unsigned int)(innerx*30+100) % 10 < 5;
	bool by = (unsigned int)(innery*30+100) % 10 < 5;
	double va = bx^by;
	//std::cout << bx << "," << by << "," << va << std::endl;
	return Vec3<double>(va,va,va);
}

Pattern::Pattern(bool use):use(use)
{
}


Pattern::~Pattern()
{
}
