#pragma once
#include "Vector2D.h"
#include "Box.h"
class Platform : public Box
{
private:
	Wall front;
	float height, width, depth;
	float x, y;

public:
	Platform(float x, float y, float width);
	virtual ~Platform(void);
	void Draw(void);

	friend class Interact;
	friend class ProjectileList;
};
