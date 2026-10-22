#include "PulsingSphere.h"

PulsingSphere::PulsingSphere(float px = 0, float py = 0)
{
	pos.x = px;
	pos.y = py;
	pulse = 0.5;
	rad_max = 2;
	rad_min = 0.5;
	pos.x = 0;
	pos.y = 5;
	accel.y = 0;
	accel.x = 0;
}

PulsingSphere::~PulsingSphere(void)
{
}
void PulsingSphere::Move(float t)
{
	Sphere::Move(t);
	if (rad > rad_max)
		pulse = -pulse;
	if (rad < rad_min)
		pulse = -pulse;
	rad += pulse * t;
	color.r = rad * 255;
	color.g = 255 - rad * 100;
	color.b = 100 + rad * 50;
}
Sphere *PulsingSphere::Split()
{

	if (rad < 1.0f)
		return 0; // don't split
	rad /= 2.0f;	  // halve the radius
	// Create a new sphere by copying the current one
	pulse *= 1.1;
	if (pulse > 3)
		pulse = 3;
	Sphere *half = new PulsingSphere(*this); // give them new velocities
	half->SetPos(pos.x + 1, pos.y + 1);
	half->SetVel(5, 8); // to the new half
	pulse *= 1.5;
	SetVel(-5, 8); // to the original half
	return half;
}
void PulsingSphere::SetPulse(float t)
{
	pulse = t;
}
