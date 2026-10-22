#include "Projectile.h"
#include "glut.h"

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
