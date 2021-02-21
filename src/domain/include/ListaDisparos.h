#pragma once
#define MAX_DISPAROS 3
#include "Disparo.h"
#include "Box.h"
#include "Interact.h"
#include "ListaEsferas.h"
#include <vector>
using namespace std;

class ListaDisparos
{
private:
	//vector <Disparo*> lista;
	Disparo *lista[MAX_DISPAROS];
	int numero;

public:
	ListaDisparos(void);
	virtual ~ListaDisparos(void);

	bool Add(Disparo *d);
	void DestruirContenido();
	void Move(float t);
	void Draw();

	void Eliminar(int index);
	void Eliminar(Disparo *d);

	void Colision(Wall p);
	void Colision(Box b);
	void Colision(Esfera *e);
	Disparo *operator[](int i);
	int GetNum();
	friend class ListaInteract;
};
