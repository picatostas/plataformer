#include "ListaPlataformas.h"
#include <iostream>
#include "Mundo.h"

ListaPlataformas::ListaPlataformas(void)
{
}
ListaPlataformas::~ListaPlataformas(void)
{
}

bool ListaPlataformas::Agregar(Wall *p)
{
	lista.push_back(p);
	return true;
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
}
void ListaPlataformas::Eliminar(Wall *p)
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
Wall *ListaPlataformas::operator[](unsigned int i)
{
	if (i > lista.size()) // si me paso de indice, paso la ultima esfera
	{
		i = lista.size() - 1;
	}

	return lista[i];
}
