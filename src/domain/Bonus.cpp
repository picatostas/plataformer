#include "Bonus.h"
#include "glut.h"
#include <stdlib.h>

Bonus::Bonus(void)
{
	rot = 0;
}

Bonus::~Bonus(void)
{
}

void Bonus::Draw()
{
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(rot, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		  rand() / (float)RAND_MAX); // random color
	glutSolidIcosahedron(); // radius 1
	glPopMatrix();
}

void Bonus::SetPos(int mx, int my)
{
	pos.x = mx;
	pos.y = my;
}
