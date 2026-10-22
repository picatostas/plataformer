#pragma once
#include "Sphere.h"
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
