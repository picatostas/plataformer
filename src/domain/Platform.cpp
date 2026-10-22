#include "Platform.h"
#include "glut.h"
#include "ColorPalette.h"

Platform::Platform(float x, float y, float width)
{
	this->x = x;
	this->y = y;
	depth = 0.5f;
	height = 0.25f;
	this->width = width;

	floor.LoadTexture("wooden_box");
	floor.color = ColorPalette::Brown();
	floor.SetPos(this->x, this->y, this->x + width, this->y, depth, false);

	roof.LoadTexture("wooden_box");
	roof.color = ColorPalette::Brown();
	roof.SetPos(this->x, this->y + height, this->x + width, this->y + height, depth, false);

	right_side.LoadTexture("wooden_box");
	right_side.color = ColorPalette::Brown();
	right_side.SetPos(this->x + width, this->y, this->x + width, this->y + height, depth, false);

	left_side.LoadTexture("wooden_box");
	left_side.color = ColorPalette::Brown();
	left_side.SetPos(this->x, this->y, this->x, this->y + height, depth, false);

	front.LoadTexture("wooden_box");
	front.color = ColorPalette::Brown();
	front.SetPos(this->x, this->y, this->x + width, this->y + height, depth, true);

	back.LoadTexture("wooden_box");
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
