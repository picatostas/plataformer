#include "Hombre.h"
#include "glut.h"
#include "stdio.h"

Hombre::Hombre(void)
{
	altura = 1;
	anchura = 1;
	acelr.y = -20.8f;
	vidas = 3;
	//salto=true;
}

Hombre::~Hombre(void)
{
}
void Hombre::Draw()
{

	if (vidas >= 3)
		color.Lime();
	else if (vidas == 2)
		color.Orange();
	else if (vidas == 1)
		color.Red();
	else if (vidas == 0)
		color.Brown();
	glPushMatrix();

	color.SetColor();
	glTranslatef(pos.x, pos.y, 0);
	glTranslatef(0, altura / 2, 0);
	glutSolidCube(anchura);
	glTranslatef(0.0f, altura / 2 + 0.5f, 0);
	glutSolidSphere(0.5f, 100, 100);

	glPopMatrix();
}

float Hombre::GetAltura()
{
	return altura;
}

void Hombre::SetG(float g)
{
	acelr.y = g;
}
void Hombre::SetVidas(int vid)
{

	vidas = vid;
}
int Hombre::GetVidas()
{

	return vidas;
}
bool Hombre::GetSalto()
{
	return salto;
}
void Hombre::SetSalto(bool sal)
{
	salto = sal;
}
