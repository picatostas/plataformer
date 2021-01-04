#include "Caja.h"
#include "glut.h"
#include "stdio.h"

Caja::Caja(void) //:techo(-10,15,10,15),suelo(-10,0,10,0),pared_izq(-10,0,-10,15),pared_der(10,0,10,15)
{
	suelo.color.Gray();
	suelo.SetPos(-10.0f, 0, 10.0f, 0, 10);

	techo.color.Gray();
	techo.SetPos(-10.0f, 15.0f, 10.0f, 15.0f, 10);

	pared_der.color.Dark_Gray();
	pared_der.SetPos(-10.0f, 0, -10.0f, 15.0f, 10);

	pared_izq.color.Dark_Gray();
	pared_izq.SetPos(10.0f, 0, 10.0f, 15.0f, 10);
}

Caja::~Caja(void)
{
}

void Caja::Draw()
{
	suelo.Draw();
	techo.Draw();
	pared_izq.Draw();
	pared_der.Draw();
}
