#pragma once
#include "Vector2D.h"
#include "MovingObject.h"
#include "ColorPalette.h"
// A shot fired by the player. It flies straight and disappears when it
// hits a wall or a sphere.
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
