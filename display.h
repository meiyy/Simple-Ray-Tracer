#pragma once
#include <string>
#include "renderer.h"
void init(std::string windowTitle, int windowHeight, int windowWidth, int argc, char** argv);
void work(Renderer *renderer);
bool addSurface(Surface *surface);