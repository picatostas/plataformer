#pragma once
#include "Vector2D.h"
#include "Caja.h"
class Platform : public Caja
{
private:
	Wall front, back;
	float height, width, depth;
	float x, y;

public:
	Platform();
	Platform(float x, float y, float width);
	void SetPos(float x, float y, float width);
	virtual ~Platform(void);
	void Draw(void);

	friend class Interact;
	friend class ListaDisparos;
};
