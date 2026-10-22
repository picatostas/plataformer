#include "Bonus.h"
#include "glut.h"
#include "stdio.h"
#include <stdlib.h>

Bonus::Bonus(void)
{
	side = 1;
	rot = 0;
	//vel.x=5;
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
	// glutSolidCube(side);
	glutSolidIcosahedron();
	glPopMatrix();
}

void Bonus::Move(float t)
{
	rot += 3;
	pos = pos + vel * t + accel * (0.5f * t * t);
	vel = vel + accel * t;
}

void Bonus::SetPos(int mx, int my)
{
	pos.x = mx;
	pos.y = my;
}

void Bonus::SetVel(void)
{
	/*if(pos.x>=5)
	        vel.x=-5;
	   if(pos.x<=-5)
	        vel.x=5;*/
}
