#pragma once
#include "Sphere.h"
// A sphere whose radius grows and shrinks between rad_min and rad_max, at
// `pulse` units per second. It is not affected by gravity, and every split
// makes both halves pulse faster.
class PulsingSphere : public Sphere
{
private:
	float rad_min, rad_max, pulse;

public:
	PulsingSphere(float px = 0, float py = 0);
	void Move(float t);
	Sphere *Split();
	~PulsingSphere(void);
};
