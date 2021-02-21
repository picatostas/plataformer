#include "ListaEsferas.h"
#include <iostream>
using namespace std;

ListaEsferas::ListaEsferas(void)
{
	/*lista.size()=0;
	for (int i=0;i<MAX_ESFERAS;i++)
		lista[i]=0;*/
}

ListaEsferas::~ListaEsferas(void)
{
}

bool ListaEsferas::Add(Esfera *e)
{
	lista.push_back(e);
	return true;
}
void ListaEsferas::Draw()
{
	for (unsigned int i = 0; i < lista.size(); i++)
		lista[i]->Draw();
}
void ListaEsferas::Mueve(float t)
{
	for (unsigned int i = 0; i < lista.size(); i++)
		lista[i]->Move(t);
}
void ListaEsferas::Rebote(Box box)
{
	for (unsigned int i = 0; i < lista.size(); i++)
		Interact::Rebote(*(lista[i]), box);
}
void ListaEsferas::Rebote(Wall plataforma)
{
	for (unsigned int i = 0; i < lista.size(); i++)
		Interact::Rebote(*(lista[i]), plataforma);
}
void ListaEsferas::Rebote()
{

	for (unsigned int i = 0; i < lista.size(); i++)
		for (unsigned int j = i + 1; j < lista.size(); j++)
			Interact::Rebote(*(lista[i]), *(lista[j]));
}

void ListaEsferas::DestruirContenido()
{

	for (unsigned int i = 0; i < lista.size(); i++)
	{
		ListaEsferas::Eliminar(i);
	}
	lista.clear();
}
int ListaEsferas::GetNum()
{
	return lista.size();
}
void ListaEsferas::Eliminar(unsigned int index)
{
	if (index >= lista.size())
		return;
	delete lista[index];
	lista.erase(lista.begin() + index);
	cout << "esfera borrada" << endl;
	/*lista.size()--;
	for(int i=index;i<lista.size();i++)
	lista[i]=lista[i+1];*/
}
void ListaEsferas::Eliminar(Esfera *e)
{
	for (unsigned int i = 0; i < lista.size(); i++)
		if (lista[i] == e)
		{
			cout << "esfera para eliminar" << endl;
			Eliminar(i);
			return;
		}
}
Esfera *ListaEsferas::Colision(Hombre &h)
{
	for (unsigned int i = 0; i < lista.size(); i++)
	{
		if (Interact::Colision(*(lista[i]), h))
			return lista[i];
	}
	return 0;
}
Esfera *ListaEsferas::operator[](unsigned int i)
{
	if (i > lista.size()) // si me paso de indice, paso la ultima esfera
	{
		i = lista.size() - 1;
	}

	// if (i < 0)     // si doy un indice negativo, devuelvo la primera esfera
	// 	i = 0; // de la lista

	return lista[i];
}
