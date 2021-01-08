#include "Esfera.h"
#include "glut.h"
#include "stdio.h"

Esfera::Esfera(void)
{
	color.r = 255;
	color.g = 255;
	color.b = 255;
	rad = 1.0F;
	acelr.y = (-9.8F);
}

Esfera::Esfera(float r, float x, float y, float vx, float vy)
{
	rad = r;
	pos.x = x;
	pos.y = y;
	vel.x = vx;
	vel.y = vy;
	acelr.y = -9.8f;
	if (rad > 0.0f && rad <= 0.75f)
		color = ColorPalette::Orange();
	if (rad > 0.75f && rad <= 1.5f)
		color = ColorPalette::Pink();
	if (rad > 1.5f)
		color = ColorPalette::Lime();
}
Esfera::~Esfera(void)
{
}

void Esfera::Draw()
{
	glColor3ub(color.r, color.g, color.b);
	glTranslatef(pos.x, pos.y, 0);
	glutSolidSphere(rad, 100, 100);
	glTranslatef(-pos.x, -pos.y, 0);
}

void Esfera::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	color.r = r;
	color.g = v;
	color.b = a;
}

void Esfera::SetRad(float r)
{
	rad = r;
}

//calculo de la distancia de una esfera a un ponto, en este caso la pos de otra esfera
float Esfera::Distancia(Vector2D punto, Vector2D *direccion)
{
	Vector2D u = (punto - pos);
	float distancia = u.modulo();
	*direccion = u.Unitario();
	return distancia;
}
float Esfera::Getrad()
{
	return rad;
}
Esfera *Esfera::Dividir()
{
	if (rad < 1.0f)
		return 0;
	rad /= 2.0f; // dividimos el radio por 2
	// Creamos una esfera nueva copiando la actual
	Esfera *aux = new Esfera(*this);
	// Les damos velocidades
	aux->SetPos(pos.x + 1, pos.y + 1);
	aux->SetVel(5, 8); // a la nueva mitad
	SetVel(-5, 8);	   // a la mitad original
	return aux;
}
