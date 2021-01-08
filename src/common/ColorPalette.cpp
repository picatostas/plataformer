#include "ColorPalette.h"
ColorPalette::ColorPalette(void)
{
}
ColorPalette::ColorPalette(unsigned char r, unsigned char g, unsigned char b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

ColorPalette::~ColorPalette(void)
{
}
ColorPalette ColorPalette::Pink()
{
	return ColorPalette(255, 20, 147);
}

ColorPalette ColorPalette::Yellow()
{
	return ColorPalette(255, 255, 0);
}
ColorPalette ColorPalette::Orange()
{
	return ColorPalette(255, 140, 0);
}
ColorPalette ColorPalette::Red()
{
	return ColorPalette(255, 0, 0);
}
ColorPalette ColorPalette::Blue()
{
	return ColorPalette(0, 0, 255);
}
ColorPalette ColorPalette::SkyBlue()
{
	return ColorPalette(0, 165, 255);
}
ColorPalette ColorPalette::Green()
{
	return ColorPalette(0, 255, 0);
}
ColorPalette ColorPalette::Forest_Green()
{
	return ColorPalette(0, 150, 0);
}
ColorPalette ColorPalette::Deep_Green()
{
	return ColorPalette(0, 100, 0);
}
ColorPalette ColorPalette::Lime()
{
	return ColorPalette(124, 252, 0);
}
ColorPalette ColorPalette::Purple()
{
	return ColorPalette(128, 0, 128);
}
ColorPalette ColorPalette::Brown()
{
	return ColorPalette(140, 70, 20);
}
ColorPalette ColorPalette::Steel()
{
	return ColorPalette(170, 170, 170);
}
ColorPalette ColorPalette::Gold()
{
	return ColorPalette(218, 165, 32);
}
ColorPalette ColorPalette::White()
{
	return ColorPalette(255, 255, 255);
}
ColorPalette ColorPalette::Dark_Gray()
{
	return ColorPalette(51, 51, 51);
}
ColorPalette ColorPalette::Gray()
{
	return ColorPalette(120, 120, 120);
}
