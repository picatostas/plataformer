#pragma once
#include "Vector2D.h"
#include "ColorPalette.h"
#include "stdbool.h"

class Wall
{
public:
	Wall(void);
	Wall(char *texture);
	virtual ~Wall(void);
	ColorPalette color;
	char *texture;

public:
	Vector2D limit1;
	Vector2D limit2;
	bool is_front;
	float z;

public:
	Wall(float x1, float y1, float x2, float y2, float z1, bool is_front, ColorPalette color);
	void SetPos(float x1, float y1, float x2, float y2, float z1, bool is_front);
	void LoadTexture(char *texture);
	void Draw(void);
	float Distancia(Vector2D punto, Vector2D *direccion = 0);

	friend class Interact;
	friend class ListaDisparos;
};
