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

public:
	ColorPalette color;

	virtual void Draw(void);

	friend class Interact;
};
