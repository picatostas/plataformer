#pragma once
#include "Bonus.h"
#include "Box.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Hombre.h"
#include "LevelDoor.h"
#include "Platform.h"
#include "Vector2D.h"

class Interact
{
public:
	Interact(void);
	virtual ~Interact(void);

	static void Rebote(Hombre &h, Box b);
	static bool Rebote(Esfera &e, Wall p);
	static bool Rebote(Esfera &e, Platform p);
	static void Rebote(Esfera &e, Box b);
	static void Rebote(Esfera &e1, Esfera &e2);
	static void Rebote(Esfera &e, Hombre &h);
	static void Colision(Hombre &h, Wall p);
	static bool Colision(Esfera e, Hombre h);
	static bool Colision(Disparo d, Wall p);
	static bool Colision(Disparo d, Box b);
	static bool Colision(Esfera e, Disparo d);
	static bool Colision(Hombre &h, LevelDoor p);
	static bool Colision(Hombre &h, Bonus &b);
	static void Colision(Hombre &h, Platform &p);
};
