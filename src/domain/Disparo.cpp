#include "Disparo.h"
#include "glut.h"
#include "stdio.h"

Disparo::Disparo(void)
{
	rad = 0.2f;
}

Disparo::~Disparo(void)
{
}

void Disparo::Draw()
{
	color = ColorPalette::Red();
	glColor3ub(color.r, color.g, color.b);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glutSolidSphere(rad, 100, 100);
	glPopMatrix();
}

void Disparo::SetPos(int mx, int my)
{
	pos.x = posinicial.x = mx;
	pos.y = posinicial.y = my;
}

float Disparo::GetRad()
{
	return rad;
}
