#include "Platform.h"
#include "glut.h"
#include "stdio.h"
#include "stdbool.h"
#include "ColorPalette.h"

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

	floor.LoadTexture("wooden_floor");
	floor.color = ColorPalette::Brown();
	floor.SetPos(this->x, this->y, this->x + width, this->y, depth, false);

	roof.LoadTexture("wooden_floor");
	roof.color = ColorPalette::Brown();
	roof.SetPos(this->x, this->y + height, this->x + width, this->y + height, depth, false);

	right_side.LoadTexture("wooden_floor");
	right_side.color = ColorPalette::Brown();
	right_side.SetPos(this->x + width, this->y, this->x + width, this->y + height, depth, false);

	left_side.LoadTexture("wooden_floor");
	left_side.color = ColorPalette::Brown();
	left_side.SetPos(this->x, this->y, this->x, this->y + height, depth, false);

	front.LoadTexture("wooden_floor");
	front.color = ColorPalette::Brown();
	front.SetPos(this->x, this->y, this->x + width, this->y + height, depth, true);

	back.LoadTexture("wooden_floor");
	back.color = ColorPalette::Brown();
	back.SetPos(this->x, this->y, this->x + width, this->y + height, -depth, true);
}

void Platform::SetPos(float x = -9.0f, float y = 2.0f, float width = 4.0f)
{
	this->x = x;
	this->y = y;
	depth = 0.5f;
	height = 0.25f;
	this->width = width;

	floor.color = ColorPalette::Brown();
	floor.SetPos(this->x, this->y, this->x + width, this->y, depth, false);

	roof.color = ColorPalette::Brown();
	roof.SetPos(this->x, this->y + height, this->x + width, this->y + height, depth, false);

	right_side.color = ColorPalette::Brown();
	right_side.SetPos(this->x + width, this->y, this->x + width, this->y + height, depth, false);

	left_side.color = ColorPalette::Brown();
	left_side.SetPos(this->x, this->y, this->x, this->y + height, depth, false);

	front.color = ColorPalette::Brown();
	front.SetPos(this->x, this->y, this->x + width, this->y + height, depth, true);

	back.color = ColorPalette::Brown();
	back.SetPos(this->x, this->y, this->x + width, this->y + height, -depth, true);
}

Platform::~Platform(void)
{
}

void Platform::Draw()
{
	floor.Draw();
	roof.Draw();
	left_side.Draw();
	right_side.Draw();
	front.Draw();
	back.Draw();
}
