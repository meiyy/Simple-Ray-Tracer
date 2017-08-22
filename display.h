#pragma once
#include <vector>
#include <string>
#include "renderer.h"
#include "lightsource.h"
#include "surface.h"

void init(std::string windowTitle, int windowHeight, int windowWidth, int argc, char** argv);
void work(Renderer *renderer);
extern LightSource ambient;
extern std::vector<Meterial> meterials;
extern std::vector<LightSource> lightsources;
extern std::vector<Surface*> surfaces;
void setAmbientLight(LightSource light);
