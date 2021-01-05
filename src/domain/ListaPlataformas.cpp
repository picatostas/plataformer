#include "ListaPlataformas.h"
#include <iostream>
#include "Mundo.h"

ListaPlataformas::ListaPlataformas(void)
{
	/*lista.size()=0;
	for( unsigned int i=0;i<MAX_PLATAFORMAS;i++)
		lista[i]=0;*/
}
ListaPlataformas::~ListaPlataformas(void)
{
}

bool ListaPlataformas::Agregar(Pared *p)
{
	lista.push_back(p);
	return true;
	/*if (lista.size()<MAX_PLATAFORMAS)
		lista[lista.size()++]=p;
	else
		return false;
	return true;*/
}
void ListaPlataformas::Draw()
{
	for (unsigned int i = 0; i < lista.size(); i++)
		lista[i]->Draw();
}
void ListaPlataformas::DestruirContenido()
{
	for (unsigned int i = 0; i < lista.size(); i++)
		delete lista[i];
	lista.clear();
}
void ListaPlataformas::Eliminar(unsigned int index)
{
	if (index >= lista.size())
		return;
	delete lista[index];
	lista.erase(lista.begin() + index);
	cout << "plataforma eliminada" << endl;
	/*lista.size()--;
	for(unsigned int i=index;i<lista.size();i++)
	lista[i]=lista[i+1];*/
}
void ListaPlataformas::Eliminar(Pared *p)
{
	for (unsigned int i = 0; i < lista.size(); i++)
		if (lista[i] == p)
		{
			cout << "plataforma para eliminar" << endl;
			Eliminar(i);
			return;
		}
}
void ListaPlataformas::Colision(Hombre &h)
{
	for (unsigned int i = 0; i < lista.size(); i++)
	{
		Interact::Colision(h, *(lista[i]));
	}
}

int ListaPlataformas::GetNum()
{

	return lista.size();
}
Pared *ListaPlataformas::operator[](unsigned int i)
{
	if (i > lista.size()) // si me paso de indice, paso la ultima esfera
	{
		i = lista.size() - 1;
	}

	// if (i < 0)     // si doy un indice negativo, devuelvo la primera esfera
	// 	i = 0; // de la lista

	return lista[i];
}
