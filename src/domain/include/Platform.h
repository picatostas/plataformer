#pragma once
#include "Vector2D.h"
#include "Box.h"
// A thin box the player can stand on and spheres bounce off.
// It spans x .. x+width horizontally, with its bottom at y.
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
