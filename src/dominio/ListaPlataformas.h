#pragma once
#define MAX_PLATAFORMAS 30
#include "dominio\Pared.h"
//#include "dominio\Interact.h"
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
		void Eliminar(int index);
		void Eliminar(Pared *p);
		void Draw();
		void Colision(Hombre &h);
		void Colision(Esfera *e);
		int GetNum();
		Pared * operator[](int i);
	private:
		vector <Pared *> lista;
		//Disparo * lista[MAX_PLATAFORMAS];
		//int numero;
};

