#include "Colorrgb.h"
#include "glut.h"
#include "stdio.h"

Colorrgb::Colorrgb(void)
{
	rojo = verde = azul = 225;
}

Colorrgb::~Colorrgb(void)
{
}

void Colorrgb::Poncolor()
{
	rojo = 0;
	verde = 0;
	azul = 250;

	glColor3ub(rojo, verde, azul);
}

void Colorrgb::Pink()
{
	glColor3ub(255, 20, 147);
}

void Colorrgb::Violet()
{
	glColor3ub(148, 0, 221);
}

void Colorrgb::Orange()
{
	glColor3ub(255, 69, 0);
}

void Colorrgb::Lime()
{
	glColor3ub(124, 252, 0);
}

void Colorrgb::Spring()
{
	glColor3ub(0, 250, 154);
}

void Colorrgb::Steal()
{
	glColor3ub(70, 130, 180);
}

void Colorrgb::Gold()
{
	glColor3ub(255, 215, 0);
}
