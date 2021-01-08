#include "puertaNivel.h"
#include "glut.h"

puertaNivel::puertaNivel(void)
{
}
puertaNivel::~puertaNivel(void)
{
}
void puertaNivel::Draw()
{
	glDisable(GL_LIGHTING);
	color = ColorPalette::Pink();
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(8.0f, 12.0f, 0.0f);
	glVertex3d(9.5f, 12.0f, 0.0f);
	glVertex3d(9.5f, 14.0f, 0.0f);
	glVertex3d(8.0f, 14.0f, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
}
