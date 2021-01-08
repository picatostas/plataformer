#pragma once
#include "Wall.h"
#include "Interact.h"
#include <vector>
using namespace std;

class PlatformContainer
{
public:
	PlatformContainer(void);
	virtual ~PlatformContainer(void);
	bool Agregar(Wall *P);
	void DestruirContenido();
	void Eliminar(unsigned int index);
	void Eliminar(Wall *p);
	void Draw();
	void Colision(Hombre &h);
	void Colision(Esfera *e);
	int GetNum();
	Wall *operator[](unsigned int i);

private:
	vector<Wall *> container;
};
