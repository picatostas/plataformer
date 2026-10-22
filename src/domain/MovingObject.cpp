#include "MovingObject.h"
#include "stdio.h"
#include <stdlib.h>

MovingObject::MovingObject(void)
{
}

MovingObject::~MovingObject(void)
{
}
void MovingObject::Move(float t)
{
	pos = pos + vel * t + accel * (0.5f * t * t);
	vel = vel + accel * t;
}
void MovingObject::SetPos(float px, float py)
{
	pos.x = px;
	pos.y = py;
}
Vector2D MovingObject::GetPos()
{
	return pos;
}
void MovingObject::SetVel(float vx, float vy)
{
	vel.x = vx;
	vel.y = vy;
}
Vector2D MovingObject::GetVel()
{
	return vel;
}
