#pragma once
#include "Vector2D.h"
#include "ColorPalette.h"
#include <string>

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
	float Distance(Vector2D point, Vector2D *direction = 0);

	friend class Interact;
	friend class ProjectileList;
};
