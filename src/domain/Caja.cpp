#include "Caja.h"
#include "glut.h"
#include "stdio.h"
#include "stdbool.h"

Caja::Caja(void)
{
	floor.color = ColorPalette::Gray();
	floor.SetPos(-10.0f, 0, 10.0f, 0, 10, false);

	roof.color = ColorPalette::Gray();
	roof.SetPos(-10.0f, 15.0f, 10.0f, 15.0f, 10, false);

	right_side.color = ColorPalette::Dark_Gray();
	right_side.SetPos(-10.0f, 0, -10.0f, 15.0f, 10, false);

	left_side.color = ColorPalette::Dark_Gray();
	left_side.SetPos(10.0f, 0, 10.0f, 15.0f, 10, false);

	back.color = ColorPalette::SkyBlue();
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
