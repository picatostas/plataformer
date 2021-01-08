#pragma once
#include "Vector2D.h"
#include "ColorPalette.h"
#include "stdbool.h"

class Wall
{
public:
	Wall(void);
	virtual ~Wall(void);
	ColorPalette color;

public:
	Vector2D limit1;
	Vector2D limit2;
	bool is_front;
	float z;

public:
	Wall(float x1, float y1, float x2, float y2, float z1, bool is_front);
	void SetPos(float x1, float y1, float x2, float y2, float z1, bool is_front);
	void Draw(void);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	float Distancia(Vector2D punto, Vector2D *direccion = 0);

	friend class Interact;
	friend class ListaDisparos;
};
