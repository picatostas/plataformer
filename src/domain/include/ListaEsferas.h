#pragma once

#define MAX_ESFERAS 100
#include "Esfera.h"
#include "Interact.h"
#include <vector>
using namespace std;
class ListaEsferas
{
public:
	ListaEsferas(void);
	~ListaEsferas(void);
	void Draw();
	void Mueve(float t);
	void Rebote();
	void Rebote(Caja caja);
	void Rebote(Wall plataforma);
	bool Add(Esfera *e);
	void DestruirContenido();
	void Eliminar(unsigned int index);
	void Eliminar(Esfera *e);
	int GetNum();
	Esfera *Colision(Hombre &e);
	Esfera *operator[](unsigned int i);
	friend class ListaInteract;

private:
	vector<Esfera *> lista;
};
