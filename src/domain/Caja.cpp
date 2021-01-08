#include "Caja.h"
#include "glut.h"
#include "stdio.h"
#include "stdbool.h"

Caja::Caja(void)
{
	suelo.color = ColorPalette::Gray();
	suelo.SetPos(-10.0f, 0, 10.0f, 0, 10, false);

	techo.color = ColorPalette::Gray();
	techo.SetPos(-10.0f, 15.0f, 10.0f, 15.0f, 10, false);

	pared_der.color = ColorPalette::Dark_Gray();
	pared_der.SetPos(-10.0f, 0, -10.0f, 15.0f, 10, false);

	pared_izq.color = ColorPalette::Dark_Gray();
	pared_izq.SetPos(10.0f, 0, 10.0f, 15.0f, 10, false);
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
