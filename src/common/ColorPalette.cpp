#include "ColorPalette.h"
#include "glut.h"

ColorPalette::ColorPalette(void)
{
	r = g = b = 255;
}

ColorPalette::~ColorPalette(void)
{
}
void ColorPalette::SetColor()
{
	glColor3ub(r, g, b);
}
void ColorPalette::Pink()
{
	r = 255;
	g = 20;
	b = 147;
}

void ColorPalette::Yellow()
{
	r = 255;
	g = 255;
	b = 0;
}
void ColorPalette::Orange()
{
	r = 255;
	g = 140;
	b = 0;
}
void ColorPalette::Red()
{
	r = 255;
	g = 0;
	b = 0;
}
void ColorPalette::Blue()
{
	r = 0;
	g = 0;
	b = 255;
}
void ColorPalette::Green()
{
	r = 0;
	g = 255;
	b = 0;
}
void ColorPalette::Forest_Green()
{
	r = 0;
	g = 150;
	b = 0;
}
void ColorPalette::Deep_Green()
{
	r = 0;
	g = 100;
	b = 0;
}
void ColorPalette::Lime()
{
	r = 124;
	g = 252;
	b = 0;
}
void ColorPalette::Purple()
{
	r = 128;
	g = 0;
	b = 128;
}
void ColorPalette::Brown()
{
	r = 140;
	g = 70;
	b = 20;
}
void ColorPalette::Steel()
{
	r = 170;
	g = 170;
	b = 170;
}
void ColorPalette::Gold()
{
	r = 218;
	g = 165;
	b = 32;
}
void ColorPalette::White()
{
	r = 255;
	g = 255;
	b = 255;
}
void ColorPalette::Dark_Gray()
{
	r = 51;
	g = 51;
	b = 51;
}
void ColorPalette::Gray()
{
	r = 120;
	g = 120;
	b = 120;
}
