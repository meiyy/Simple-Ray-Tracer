#pragma once
#include <vector>
#include <string>
#include "renderer.h"
#include "lightsource.h"
#include "surface.h"

void init(std::string windowTitle, int windowHeight, int windowWidth, int argc, char** argv);
void work(Renderer *renderer);
bool addSurface(Surface *surface);
bool addLight(LightSource *light);
extern LightSource ambient;
extern std::vector<Meterial> meterials;
void setAmbientLight(LightSource light);