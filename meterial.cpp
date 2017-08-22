#include "meterial.h"

Meterial::Meterial(Vec3<double> ambient, Vec3<double> diffuse, Vec3<double> specular, double pvalue)
	:ambient(ambient),diffuse(diffuse),specular(specular),pvalue(pvalue)
{

}

Meterial::~Meterial()
{

}

Vec3<double> white(255, 255, 255);
Meterial::Meterial():ambient(white),diffuse(white),specular(white),pvalue(5)
{

}