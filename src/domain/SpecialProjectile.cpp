#include "SpecialProjectile.h"

SpecialProjectile::SpecialProjectile(void)
{
	accel.y = 0.75f;
	vel.y = 10;
	color.Gold();
	rad *= 2;
}

SpecialProjectile::~SpecialProjectile(void)
{
}
