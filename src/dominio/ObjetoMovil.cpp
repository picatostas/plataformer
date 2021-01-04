#include "ObjetoMovil.h"
#include "stdio.h"
#include <stdlib.h>

ObjetoMovil::ObjetoMovil(void)
{
}


ObjetoMovil::~ObjetoMovil(void)
{
}
void ObjetoMovil::Move(float t)
{
	pos=pos+vel*t+acelr*(0.5f*t*t);
	vel=vel+acelr*t;
}
void ObjetoMovil::SetPos(float px,float py)
{
pos.x=px;
pos.y=py;

}
Vector2D ObjetoMovil::GetPos()
{
	return pos;
}
void ObjetoMovil::SetVel(float vx,float vy)
{
vel.x=vx;
vel.y=vy;
}
Vector2D ObjetoMovil::GetVel()
{
return vel;
}