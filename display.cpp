#include "display.h"

#include <gl/glut.h>


/*
* variables
*/

static std::string title;
static int height;
static int width;
static Renderer *renderer;
static GLubyte *buf;

/*
* function implementation
*/
void Animate()
{
	renderer->render(buf);
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
