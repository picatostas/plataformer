#pragma once
#include "Vector2D.h"
#include "Wall.h"
class Caja
{
protected:
	Wall roof, floor, left_side, right_side, back;

public:
	Caja(void);
	virtual ~Caja(void);
	void Draw(void);

	friend class Interact;
	friend class ListaDisparos;
};
