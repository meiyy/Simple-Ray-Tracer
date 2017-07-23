#include "meterial.h"



Meterial::Meterial(Vec3<double> ambient, Vec3<double> diffuse, Vec3<double> specular, double pvalue, Pattern *usePt)
	:ambient(ambient),diffuse(diffuse),specular(specular),pvalue(pvalue),pt(*usePt)
{
}


Meterial::~Meterial()
{
}
