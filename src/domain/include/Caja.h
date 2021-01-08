#pragma once
#include "Vector2D.h"
#include "Wall.h"
class Caja
{
protected:
	Wall techo;
	Wall suelo;
	Wall pared_izq;
	Wall pared_der;

public:
	Caja(void);
	virtual ~Caja(void);
	void Draw(void);

	friend class Interact;
	friend class ListaDisparos;
};
