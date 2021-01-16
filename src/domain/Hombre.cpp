#include "Hombre.h"
#include "glut.h"

Hombre::Hombre(void)
{
	altura = 1;
	anchura = 0.75f;
	acelr.y = -20.8f;
	vidas = 3;
	model.Load("models/birdman.obj");
	rot = 0;
}

Hombre::~Hombre(void)
{
}
void Hombre::Draw()
{

	if (vidas >= 3)
		color = ColorPalette::Lime();
	else if (vidas == 2)
		color = ColorPalette::Orange();
	else if (vidas == 1)
		color = ColorPalette::Red();
	else if (vidas == 0)
		color = ColorPalette::Brown();

	glPushMatrix();

	glColor3ub(color.r, color.g, color.b);
	glTranslatef(pos.x, pos.y, 0);
	glScalef(0.06f, 0.06f, 0.06f);
	glRotatef(-180, 0, 1, 0);
	if (vidas == 0)
	{
		// If player died, turn its body as if it fell
		glTranslatef(0, 12, 0);
		glRotatef(-90, 0, 0, 1);
	}
	if (rot != 0)
	{
		glRotatef(90, 0, 1 * rot, 0);
	}
	model.Draw();
	// float cumulative_hieght = 0.0f;
	// static GLUquadric *gluQuadric = NULL;
	// if (gluQuadric == NULL)
	// 	gluQuadric = gluNewQuadric();
	// glRotatef(-90, 1, 0, 0);
	// cumulative_hieght += altura / 5;
	// glTranslatef(-anchura / 5, 0, 0);
	// // Legs
	// gluCylinder(gluQuadric, anchura / 6, anchura / 7, cumulative_hieght, 20, 20);
	// glTranslatef(2 * anchura / 5, 0, 0);
	// gluCylinder(gluQuadric, anchura / 6, anchura / 7, cumulative_hieght, 20, 20);
	// glTranslatef(-anchura / 5, 0, 0);
	// glTranslatef(0, 0, cumulative_hieght);
	// cumulative_hieght += altura / 2;
	// // Body
	// gluCylinder(gluQuadric, anchura / 2, anchura / 2, cumulative_hieght, 20, 20);
	// cumulative_hieght += altura / 4;
	// glTranslatef(0, 0, cumulative_hieght);
	// // Head
	// glutSolidSphere(altura / 4, 100, 100);

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
void Hombre::SetRot(int rot)
{
	if (rot >= -1 && rot <= 1)
		this->rot = rot;
}
