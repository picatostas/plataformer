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

bool ListaEsferas::Agregar ( Esfera *e)
{
	lista.push_back(e);
	return true;

	/*if (lista.size()<MAX_ESFERAS)
	{


				lista[lista.size()++]=e;

	}
	else
		return false;
	return true;*/

}
void ListaEsferas::Draw()
{
for (int i=0;i<lista.size();i++)
	lista[i]->Draw();


}
void ListaEsferas::Mueve(float t)
{
	for (int i=0;i<lista.size();i++)
		lista[i]->Move(t);

}
void ListaEsferas::Rebote(Caja caja)
{
	for(int i=0;i<lista.size();i++)
		Interact::Rebote(*(lista[i]),caja);

}
void ListaEsferas::Rebote(Pared plataforma)
{
	for(int i=0;i<lista.size();i++)
		Interact::Rebote(*(lista[i]),plataforma);

}
void ListaEsferas::Rebote()
{

	for(int i=0;i<lista.size();i++)
		for (int j=i+1;j<lista.size();j++)
			Interact::Rebote(*(lista[i]),*(lista[j]));


}

void ListaEsferas::DestruirContenido()
{

	for(int i=0;i<lista.size();i++)
	{
		ListaEsferas::Eliminar(i);
	}
	lista.clear();
}
int  ListaEsferas::GetNum()
{
return lista.size();

}
void ListaEsferas::Eliminar(int index)
{
	if ((index<0) || (index>=lista.size()))
		return;
	delete lista[index];
	lista.erase(lista.begin()+index);
	cout<<"esfera borrada"<<endl;
	/*lista.size()--;
	for(int i=index;i<lista.size();i++)
	lista[i]=lista[i+1];*/

}
void ListaEsferas::Eliminar(Esfera *e)
{
for(int i=0;i<lista.size();i++)
	if(lista[i]==e)
	{
		cout<<"esfera para eliminar"<<endl;
		Eliminar(i);
		return;

	}


}
Esfera * ListaEsferas::Colision(Hombre &h)
{
	for(int i=0;i<lista.size();i++)
	{
		if (Interact::Colision(*(lista[i]),h))
			return lista[i];

	}
	return 0;
}
Esfera * ListaEsferas::operator[](int i)
{
	if ( i>lista.size()) // si me paso de indice, paso la ultima esfera
		i=lista.size()-1;

	if (i<0)  // si doy un indice negativo, devuelvo la primera esfera
		i=0; // de la lista

return lista[i];


}
