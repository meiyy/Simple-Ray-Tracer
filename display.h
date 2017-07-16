#pragma once
#include <string>
#include "renderer.h"
#include "lightsource.h"
#include "surface.h"

void init(std::string windowTitle, int windowHeight, int windowWidth, int argc, char** argv);
void work(Renderer *renderer);
bool addSurface(Surface *surface);
bool addLight(LightSource *light);
extern LightSource ambient;
void setAmbientLight(LightSource light);