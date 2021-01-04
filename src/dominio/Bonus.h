#pragma once
#include "comun/Vector2D.h"

class Bonus
{
public:
	Bonus(void);
	virtual ~Bonus(void);

private:
	float lado, rot;
	Vector2D pos;
	Vector2D vel;
	Vector2D acelr;

public:
	void SetPos(int mx, int my);

	void SetVel(void);

	void Draw(void);

	void Move(float);

	friend class Interact;
};
