#pragma once
#define MAX_PLATAFORMAS 30
#include "Pared.h"
//#include "Interact.h"
#include "Interact.h"
#include <vector>
using namespace std;

class ListaPlataformas
{
public:
	ListaPlataformas(void);
	virtual ~ListaPlataformas(void);
	bool Agregar(Pared *P);
	void DestruirContenido();
	void Eliminar(unsigned int index);
	void Eliminar(Pared *p);
	void Draw();
	void Colision(Hombre &h);
	void Colision(Esfera *e);
	int GetNum();
	Pared *operator[](unsigned int i);

private:
	vector<Pared *> lista;
};
