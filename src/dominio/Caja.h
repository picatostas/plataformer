#pragma once
#include "comun/Vector2D.h"
#include "dominio/Pared.h"
class Caja
{
private:
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
