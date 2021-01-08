#include "Platform.h"
#include "glut.h"
#include "stdio.h"
#include "stdbool.h"

Platform::Platform()
{
}
Platform::Platform(float x = -9.0f, float y = 2.0f, float width = 4.0f)
{
	this->x = x;
	this->y = y;
	depth = 0.5f;
	height = 0.25f;
	this->width = width;

	suelo.color.Brown();
	suelo.SetPos(this->x, this->y, this->x + width, this->y, depth, false);

	techo.color.Brown();
	suelo.SetPos(this->x, this->y + height, this->x + width, this->y + height, depth, false);

	pared_der.color.Brown();
	pared_der.SetPos(this->x + width, this->y, this->x + width, this->y + height, depth, false);

	pared_izq.color.Brown();
	pared_izq.SetPos(this->x, this->y, this->x, this->y + height, depth, false);

	front.color.Brown();
	front.SetPos(this->x, this->y, this->x + width, this->y + height, depth, true);

	back.color.Brown();
	back.SetPos(this->x, this->y, this->x + width, this->y + height, -depth, true);
}

void Platform::SetPos(float x = -9.0f, float y = 2.0f, float width = 4.0f)
{
	this->x = x;
	this->y = y;
	depth = 0.5f;
	height = 0.25f;
	this->width = width;

	suelo.color.Brown();
	suelo.SetPos(this->x, this->y, this->x + width, this->y, depth, false);

	techo.color.Brown();
	techo.SetPos(this->x, this->y + height, this->x + width, this->y + height, depth, false);

	pared_der.color.Brown();
	pared_der.SetPos(this->x + width, this->y, this->x + width, this->y + height, depth, false);

	pared_izq.color.Brown();
	pared_izq.SetPos(this->x, this->y, this->x, this->y + height, depth, false);

	front.color.Green();
	front.SetPos(this->x, this->y, this->x + width, this->y + height, depth, true);

	back.color.Yellow();
	back.SetPos(this->x, this->y, this->x + width, this->y + height, -depth, true);
}

Platform::~Platform(void)
{
}

void Platform::Draw()
{
	suelo.Draw();
	techo.Draw();
	pared_izq.Draw();
	pared_der.Draw();
	front.Draw();
	back.Draw();
}
