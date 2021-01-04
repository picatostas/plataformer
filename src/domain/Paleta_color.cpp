#include "Paleta_color.h"
#include "glut.h"

Paleta_color::Paleta_color(void)
{
	r = g = b = 255;
}

Paleta_color::~Paleta_color(void)
{
}
void Paleta_color::SetColor()
{
	glColor3ub(r, g, b);
}
void Paleta_color::Pink()
{
	r = 255;
	g = 20;
	b = 147;
}

void Paleta_color::Yellow()
{
	r = 255;
	g = 255;
	b = 0;
}
void Paleta_color::Orange()
{
	r = 255;
	g = 140;
	b = 0;
}
void Paleta_color::Red()
{
	r = 255;
	g = 0;
	b = 0;
}
void Paleta_color::Blue()
{
	r = 0;
	g = 0;
	b = 255;
}
void Paleta_color::Green()
{
	r = 0;
	g = 255;
	b = 0;
}
void Paleta_color::Forest_Green()
{
	r = 0;
	g = 150;
	b = 0;
}
void Paleta_color::Deep_Green()
{
	r = 0;
	g = 100;
	b = 0;
}
void Paleta_color::Lime()
{
	r = 124;
	g = 252;
	b = 0;
}
void Paleta_color::Purple()
{
	r = 128;
	g = 0;
	b = 128;
}
void Paleta_color::Deep_purple()
{
	r = 255;
	g = 0;
	b = 255;
}
void Paleta_color::Brown()
{
	r = 140;
	g = 70;
	b = 20;
}
void Paleta_color::Steel()
{
	r = 170;
	g = 170;
	b = 170;
}
void Paleta_color::Gold()
{
	r = 218;
	g = 165;
	b = 32;
}
void Paleta_color::White()
{
	r = 255;
	g = 255;
	b = 255;
}
void Paleta_color::Dark_Gray()
{
	r = 51;
	g = 51;
	b = 51;
}
void Paleta_color::Gray()
{
	r = 120;
	g = 120;
	b = 120;
}
