#pragma once
#include "Vector2D.h"
// Base class for anything that moves with a position, velocity and
// constant acceleration (gravity, for most objects).
class MovingObject
{
protected:
	Vector2D pos, vel, accel;

public:
	Vector2D GetPos();
	Vector2D GetVel();

	void SetPos(float px, float py);
	void SetVel(float vx, float vy);
	// Advance the simulation by t seconds
	virtual void Move(float t);
	MovingObject(void);
	~MovingObject(void);
};
