#include "display.h"
#include "surface.h"
#include <gl/glut.h>
#include <ctime>
#include <iostream>

/*
* variables
*/

static std::string title;
static int height;
static int width;
static Renderer *renderer;
static GLubyte *buf;
const int maxnum = 100;
Surface *surfaces[maxnum];
int numOfSurface = 0;
int cntFrame = 0;
clock_t preTime = 0;
/*
* function implementation
*/
bool addSurface(Surface *surface)
{
	if (numOfSurface == maxnum)
	{
		delete surface;
		return false;
	}
	surfaces[numOfSurface++] = surface;
	return true;
}

void Animate()
{
	if (cntFrame == 0)
		preTime = clock();
	if (cntFrame == 10)
	{
		std::cout <<":"<< 1/((double)(clock() - preTime) / CLOCKS_PER_SEC / 10) << std::endl;
		cntFrame = 0;
		preTime = clock();
	}
	cntFrame++;
	renderer->renderPerspective(buf,surfaces,numOfSurface);
	/*
	for (int i = 0; i < 10; i++)
		std::cout << (int)buf[i+1000] << " ";
	std::cout << std::endl << "!!!!!!!!!!!!!!!!!" << std::endl;
	*/
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
