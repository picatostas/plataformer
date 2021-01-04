#include "Disparo.h"
#include "glut.h"
#include "stdio.h"

Disparo::Disparo(void)
{ //acelr.y=0.75f;
	//vel.x=10;
	rad = 0.25;
	estelas = 1;
}

Disparo::~Disparo(void)
{
}

void Disparo::Draw()
{
	color.SetColor();
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glutSolidSphere(rad, 100, 100);
	glPopMatrix();
	//codigo correspondoiente a la estela
	if (estelas == 1)
	{
		estela(0);
	}

	if (estelas == 2)
	{
		estela(-0.25);
		estela(0.25);
	}
}

void Disparo::estela(float p)
{
	glBegin(GL_LINES);
	glColor3ub(color.r, color.g, color.b);
	glVertex3f(posinicial.x + p, posinicial.y, 0.0f);
	glVertex3f(pos.x + p, pos.y, 0.0f);
	glEnd();
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
