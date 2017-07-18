#include "display.h"
#include <gl/glut.h>
#include <ctime>
#include <iostream>

/*
* variables
*/
/* Basic variables and objects */
static std::string title;
static int height;
static int width;
static Renderer *renderer;
static GLubyte *buf;

/* Surface */
const int maxsurface = 100;
Surface *surfaces[maxsurface];
int numOfSurface = 0;

/* Frame rate */
int cntFrame = 0;
clock_t preTime = 0;

/* Light */
const int maxlight = 10;
LightSource *lightsources[maxlight];
int numoflights = 0;
LightSource ambient(Vec3<double>(0,0,0), Vec3<double>(0, 0, 0), Vec3<int>(200, 200, 200));

/*
* function implementation
*/
void setAmbientLight(LightSource light)
{
	ambient = light;
}
bool addSurface(Surface *surface)
{
	if (numOfSurface == maxsurface)
	{
		delete surface;
		return false;
	}
	surfaces[numOfSurface++] = surface;
	return true;
}

bool addLight(LightSource *light)
{
	if (numoflights == maxlight)
	{
		delete light;
		return false;
	}
	lightsources[numoflights++] = light;
	return true;
}

void Animate()
{
	static double cnt = 1.4;
	cnt+=0.01;
	Vec3<double> tmp(3 * std::sin(cnt), 1, 3 * cos(cnt) + 3);
	Vec3<double> tmp2(-std::sin(cnt), -1, -cos(cnt));
	lightsources[0]->pos = tmp;
	lightsources[0]->dir = tmp2;
	if (cntFrame == 0)
		preTime = clock();
	if (cntFrame == 10)
	{
		std::cout <<":"<< 1/((double)(clock() - preTime) / CLOCKS_PER_SEC / 10) << std::endl;
		cntFrame = 0;
		preTime = clock();
	}
	cntFrame++;
	renderer->renderPerspective(buf,surfaces,numOfSurface,lightsources,numoflights);
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, buf);
	glutSwapBuffers();
	glutPostRedisplay();
}

void init(std::string windowTitle, int windowHeight, int windowWidth, int argc, char** argv)
{
	title = windowTitle;
	height = windowHeight;
	width = windowWidth;
	buf = new GLubyte[height*width * 3];
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());
	glutDisplayFunc(Animate);
}
void work(Renderer *renderer)
{
	::renderer = renderer;
	glutMainLoop();
}
