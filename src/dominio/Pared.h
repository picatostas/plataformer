#pragma once
#include "comun/Vector2D.h"
#include "Paleta_color.h"

class Pared
{
public:
	Pared(void);
	virtual ~Pared(void);
	Paleta_color color;

protected:
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	float z;

public:
	Vector2D limit1;
	Vector2D limit2;

public:
	Pared(float x1, float y1, float x2, float y2, float z1);
	void SetPos(float x1, float y1, float x2, float y2, float z1);
	void Draw(void);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	float Distancia(Vector2D punto, Vector2D *direccion = 0);

	friend class Interact;
	friend class ListaDisparos;
};
