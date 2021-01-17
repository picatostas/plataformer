// OpenGL.cpp: implementation of the OpenGL class.
//
//////////////////////////////////////////////////////////////////////

#include "OpenGL.h"
#include <string.h>
#include "glut.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OpenGL::OpenGL()
{
}

OpenGL::~OpenGL()
{
}
void OpenGL::Print(std::string msg, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
	glColor3ub(r, g, b);
	glRasterPos3f(x, glutGet(GLUT_WINDOW_HEIGHT) - 18 - y, 0);
	for (unsigned int i = 0; i < msg.size(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[i]);

	glMatrixMode(GL_TEXTURE);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
}
