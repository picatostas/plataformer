#include "Sphere.h"
#include "glut.h"
#include "stdio.h"

Sphere::Sphere(void)
{
	color.r = 255;
	color.g = 255;
	color.b = 255;
	rad = 1.0F;
	accel.y = (-9.8F);
}

Sphere::Sphere(float r, float x, float y, float vx, float vy)
{
	rad = r;
	pos.x = x;
	pos.y = y;
	vel.x = vx;
	vel.y = vy;
	accel.y = -9.8f;
	if (rad > 0.0f && rad <= 0.75f)
		color = ColorPalette::Orange();
	if (rad > 0.75f && rad <= 1.5f)
		color = ColorPalette::Pink();
	if (rad > 1.5f)
		color = ColorPalette::Lime();
}
Sphere::~Sphere(void)
{
}

void Sphere::Draw()
{
	glColor3ub(color.r, color.g, color.b);
	glTranslatef(pos.x, pos.y, 0);
	glutSolidSphere(rad, 100, 100);
	glTranslatef(-pos.x, -pos.y, 0);
}

void Sphere::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

void Sphere::SetRad(float r)
{
	rad = r;
}

// distance from a sphere to a point, in this case the position of another sphere
float Sphere::Distance(Vector2D point, Vector2D *direction)
{
	Vector2D u = (point - pos);
	float distance = u.magnitude();
	if (direction != 0)
		*direction = u.Unit();
	return distance;
}
float Sphere::GetRad()
{
	return rad;
}
Sphere *Sphere::Split()
{
	if (rad < 1.0f)
		return 0;
	rad /= 2.0f; // halve the radius
	// Create a new sphere by copying the current one
	Sphere *half = new Sphere(*this);
	// Give them velocities
	half->SetPos(pos.x + 1, pos.y + 1);
	half->SetVel(5, 8); // to the new half
	SetVel(-5, 8);	   // to the original half
	return half;
}
