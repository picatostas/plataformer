#pragma once
#include "Vector2D.h"
#include "Pared.h"
class Caja
{
protected:
	Pared techo;
	Pared suelo;
	Pared pared_izq;
	Pared pared_der;

public:
	Caja(void);
	virtual ~Caja(void);
	void Draw(void);

	friend class Interact;
	friend class ListaDisparos;
};
