#pragma once
#include "comun\Vector2D.h"
class ObjetoMovil
{
protected:
	Vector2D pos, vel, acelr;

public:
	Vector2D GetPos();
	Vector2D GetVel();

	void SetPos(float px, float py);
	void SetVel(float vx, float vy);
	virtual void Move(float t);
	ObjetoMovil(void);
	~ObjetoMovil(void);
};
