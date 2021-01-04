#pragma once
#include "comun/Vector2D.h"
#include "dominio/Hombre.h"
#include "dominio/Caja.h"
#include "dominio/Esfera.h"
#include "Disparo.h"
#include "puertaNivel.h"
#include "Bonus.h"
//#include "pang\Mundo.h"

class Interact
{
public:
	Interact(void);
	virtual~Interact(void);

	static void Rebote(Hombre &h, Caja c);
	static bool Rebote(Esfera &e, Pared p);
	static void Rebote(Esfera &e, Caja c);
	static void Rebote(Esfera &e1, Esfera &e2);
	static void Rebote(Esfera &e ,Hombre &h);
	static void Colision(Hombre &h, Pared p);
	static bool Colision(Esfera e,Hombre h);
	static bool Colision(Disparo d, Pared p);
	static bool Colision(Disparo d,Caja c);
	static bool Colision(Esfera e, Disparo d);
	static bool Colision(Hombre &h, puertaNivel p);
	static void Colision(Hombre &h, Bonus &b);
};
