#pragma once
#include "Vector2D.h"
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"
#include "puertaNivel.h"
#include "Bonus.h"
#include "Platform.h"

class Interact
{
public:
	Interact(void);
	virtual ~Interact(void);

	static void Rebote(Hombre &h, Caja c);
	static bool Rebote(Esfera &e, Wall p);
	static void Rebote(Esfera &e, Caja c);
	static void Rebote(Esfera &e1, Esfera &e2);
	static void Rebote(Esfera &e, Hombre &h);
	static void Colision(Hombre &h, Wall p);
	static bool Colision(Esfera e, Hombre h);
	static bool Colision(Disparo d, Wall p);
	static bool Colision(Disparo d, Caja c);
	static bool Colision(Esfera e, Disparo d);
	static bool Colision(Hombre &h, puertaNivel p);
	static void Colision(Hombre &h, Bonus &b);
	static void Colision(Hombre &h, Platform &p);
};
