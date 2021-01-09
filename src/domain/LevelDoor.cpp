#include "LevelDoor.h"
#include "glut.h"
#include "TextureLoader.h"
#include "GL/gl.h"
#include "Bitmap.h"

LevelDoor::LevelDoor(void)
{
}
LevelDoor::~LevelDoor(void)
{
}
void LevelDoor::Draw()
{
	static Bitmap texture((char *)"textures/old_door.bmp");
	glPushMatrix();
	glDisable(GL_LIGHTING);
	texture.usarTextura();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(limit1.x, limit1.y, z);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(limit1.x, limit2.y, z);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(limit2.x, limit2.y, z);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(limit2.x, limit1.y, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}
