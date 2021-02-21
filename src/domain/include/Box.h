#pragma once
#include "Vector2D.h"
#include "Wall.h"
class Box
{
protected:
	Wall roof, floor, left_side, right_side, back;

public:
	Box(void);
	virtual ~Box(void);
	void Draw(void);

	friend class Interact;
	friend class ListaDisparos;
};
