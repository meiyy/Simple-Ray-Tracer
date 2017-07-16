#include "lightsource.h"



LightSource::LightSource(Vec3<double> pos, Vec3<double> dir, Vec3<int> intensity):pos(pos),dir(dir.norm()*-1),intensity(intensity)
{

}


LightSource::~LightSource()
{
}
