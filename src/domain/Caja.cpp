#include "Caja.h"
#include "glut.h"
#include "stdio.h"
#include "stdbool.h"

Caja::Caja(void)
{
	floor.LoadTexture((char *)"dungeon_wall");
	floor.color = ColorPalette::Gray();
	floor.SetPos(-10.0f, 0, 10.0f, 0, 10, false);

	roof.LoadTexture((char *)"wooden_floor");
	roof.color = ColorPalette::Gray();
	roof.SetPos(-10.0f, 15.0f, 10.0f, 15.0f, 10, false);

	right_side.LoadTexture((char *)"dungeon_wall");
	right_side.color = ColorPalette::Gray();
	right_side.SetPos(-10.0f, 0, -10.0f, 15.0f, 10, false);

	left_side.LoadTexture((char *)"dungeon_wall");
	left_side.color = ColorPalette::Gray();
	left_side.SetPos(10.0f, 0, 10.0f, 15.0f, 10, false);

	back.LoadTexture((char *)"dungeon_wall");
	back.color = ColorPalette::Gray();
	back.SetPos(-10.0f, 0.0f, 10.0f, 15.0f, -10.0f, true);
}

Caja::~Caja(void)
{
}

void Caja::Draw()
{
	floor.Draw();
	roof.Draw();
	left_side.Draw();
	right_side.Draw();
	back.Draw();
}
