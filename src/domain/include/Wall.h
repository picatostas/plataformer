#pragma once
#include "Vector2D.h"
#include "ColorPalette.h"
#include <string>

// A textured rectangle. In the XY plane it is the segment limit1 -> limit2.
// - is_front: a panel facing the camera, drawn at depth z.
// - otherwise: a floor, roof or side, extruded along the segment from
//   depth z to -z.
class Wall
{
public:
	Wall(void);
	virtual ~Wall(void);
	ColorPalette color;
	std::string texture;

public:
	Vector2D limit1;
	Vector2D limit2;
	bool is_front;
	float z;

public:
	void SetPos(float x1, float y1, float x2, float y2, float z1, bool is_front);
	void LoadTexture(std::string texture);
	void Draw(void);
	// Shortest distance from point to the segment. If direction is given,
	// it receives the unit vector from the wall towards the point.
	float Distance(Vector2D point, Vector2D *direction = 0);

	friend class Interact;
	friend class ProjectileList;
};
