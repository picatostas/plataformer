#pragma once
#include "Platform.h"
#include "Interact.h"
#include <vector>
using namespace std;

class PlatformContainer
{
public:
	PlatformContainer(void);
	virtual ~PlatformContainer(void);
	bool Add(Platform *P);
	void DestruirContenido();
	void Eliminar(unsigned int index);
	void Eliminar(Platform *p);
	void Draw();
	void Colision(Hombre &h);
	void Colision(Esfera *e);
	int GetNum();
	Platform *operator[](unsigned int i);

private:
	vector<Platform *> container;
};
