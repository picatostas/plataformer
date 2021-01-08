#include "LevelDoor.h"
#include "glut.h"

LevelDoor::LevelDoor(void)
{
}
LevelDoor::~LevelDoor(void)
{
}
void LevelDoor::Draw()
{
	glDisable(GL_LIGHTING);
	color = ColorPalette::Pink();
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(8.0f, 11.25f, 0.0f);
	glVertex3d(9.5f, 11.25f, 0.0f);
	glVertex3d(9.5f, 13.0f, 0.0f);
	glVertex3d(8.0f, 13.0f, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
}
