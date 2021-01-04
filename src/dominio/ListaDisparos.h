#pragma once
#define MAX_DISPAROS 3
#include "Disparo.h"
#include "Caja.h"
#include "Interact.h"
#include "ListaEsferas.h"
#include "ListaInteract.h"
#include <vector>
using namespace std;
class ListaDisparos
{
private:
	//vector <Disparo*> lista;
	Disparo * lista[MAX_DISPAROS];
	int numero;

public:
	ListaDisparos(void);
	virtual ~ListaDisparos(void);

	bool Agregar(Disparo * d );
	void DestruirContenido();
	void Move(float t);
	void Draw();

	void Eliminar(int index);
	void Eliminar(Disparo *d);


	void Colision(Pared p);
	void Colision(Caja c);
	void Colision(Esfera *e);
	Disparo * operator [](int i);
	int  GetNum();
	friend class ListaInteract;

};
