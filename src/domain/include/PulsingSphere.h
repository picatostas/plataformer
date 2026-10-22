#pragma once
#include "Sphere.h"
class PulsingSphere : public Sphere
{
private:
	float rad_min, rad_max, pulse;

public:
	PulsingSphere(float px, float py);
	void Move(float t);
	Sphere *Split();
	PulsingSphere();
	~PulsingSphere(void);
	void SetPulse(float t);
};
