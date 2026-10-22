#pragma once
#include "Vector2D.h"
#include "ColorPalette.h"
#include "MovingObject.h"
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
	virtual Sphere *Split();
	void SetColor(unsigned char r, unsigned char g, unsigned char b);

	void Draw(void);

	// collision between spheres
	float Distance(Vector2D point, Vector2D *direction = 0);

	friend class Interact;
};
