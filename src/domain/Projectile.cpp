#include "Projectile.h"
#include "glut.h"
#include "stdio.h"

Projectile::Projectile(void)
{
	rad = 0.2f;
	color = ColorPalette::Orange();
}

Projectile::~Projectile(void)
{
}

void Projectile::Draw()
{
	glColor3ub(color.r, color.g, color.b);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glutSolidSphere(rad, 100, 100);
	glPopMatrix();
}

void Projectile::SetPos(int mx, int my)
{
	pos.x = initial_pos.x = mx;
	pos.y = initial_pos.y = my;
}

float Projectile::GetRad()
{
	return rad;
}
