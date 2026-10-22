#pragma once
#include "Vector2D.h"
#include "ColorPalette.h"
#include "MovingObject.h"
// The enemies: balls that fall with gravity and bounce off everything.
// Shooting one splits it in two halves until it gets too small, then it
// disappears. Touching one costs the player a life.
class Sphere : public MovingObject
{

protected:
	float rad;

public:
	ColorPalette color;
	Sphere(float r, float x = 0.0f, float y = 0.0f,
	       float vx = 0.0f, float vy = 0.0f);
	Sphere(void);
	virtual ~Sphere(void);
	// Halve this sphere and return the new other half, or 0 if it is too small to split
	virtual Sphere *Split();
	void SetColor(unsigned char r, unsigned char g, unsigned char b);

	void Draw(void);

	// Distance from the centre to point; direction receives the unit vector towards point
	float Distance(Vector2D point, Vector2D *direction = 0);

	friend class Interact;
};
