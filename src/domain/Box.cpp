#include "Box.h"
#include "glut.h"
#include "stdio.h"
#include "stdbool.h"

Box::Box(void)
{
	floor.LoadTexture("dungeon_wall");
	floor.color = ColorPalette::Gray();
	floor.SetPos(-10.0f, 0, 10.0f, 0, 10, false);

	roof.LoadTexture("wooden_floor");
	roof.color = ColorPalette::Gray();
	roof.SetPos(-10.0f, 15.0f, 10.0f, 15.0f, 10, false);

	right_side.LoadTexture("dungeon_wall");
	right_side.color = ColorPalette::Gray();
	right_side.SetPos(-10.0f, 0, -10.0f, 15.0f, 10, false);

	left_side.LoadTexture("dungeon_wall");
	left_side.color = ColorPalette::Gray();
	left_side.SetPos(10.0f, 0, 10.0f, 15.0f, 10, false);

	back.LoadTexture("dungeon_wall");
	back.color = ColorPalette::Gray();
	back.SetPos(-10.0f, 0.0f, 10.0f, 15.0f, -10.0f, true);
}

Box::~Box(void)
{
}

void Box::Draw()
{
	floor.Draw();
	roof.Draw();
	left_side.Draw();
	right_side.Draw();
	back.Draw();
}
