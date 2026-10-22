#pragma once
#include "Vector2D.h"
#include "MovingObject.h"
#include "ColorPalette.h"
class Projectile : public MovingObject
{
public:
	Projectile(void);
	virtual ~Projectile(void);

protected:
	float rad;
	Vector2D initial_pos;

public:
	ColorPalette color;
	void SetPos(int mx, int my);

	virtual void Draw(void);

	float GetRad();

	friend class Interact;
};
