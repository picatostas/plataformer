#pragma once
#include "Vector2D.h"
class MovingObject
{
protected:
	Vector2D pos, vel, accel;

public:
	Vector2D GetPos();
	Vector2D GetVel();

	void SetPos(float px, float py);
	void SetVel(float vx, float vy);
	virtual void Move(float t);
	MovingObject(void);
	~MovingObject(void);
};
