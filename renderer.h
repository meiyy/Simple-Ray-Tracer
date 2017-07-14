#pragma once
class Renderer
{
private:
	int t;
	int height;
	int width;
public:
	Renderer::Renderer(int height, int width) :t(0), height(height), width(width) {}
	~Renderer() {}
	virtual void render(unsigned char* buf);
};
