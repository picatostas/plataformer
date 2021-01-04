#include "ListaDisparos.h"
#include <iostream>
using namespace std;


ListaDisparos::ListaDisparos(void)
{
	numero=0;
	for( int i=0;i<MAX_DISPAROS;i++)
		lista[i]=0;
}


ListaDisparos::~ListaDisparos(void)
{
}

bool ListaDisparos::Agregar(Disparo *d)
{
	/*lista.push_back(d);
	return true;*/
	if (numero<MAX_DISPAROS)
		lista[numero++]=d;
	else
		return false;
	return true;


}
void ListaDisparos::Draw()
{
	for (int i=0;i<numero;i++)
		lista[i]->Draw();

}
void ListaDisparos::Move(float t)
{
	for(int i=0;i<numero;i++)
		lista[i]->Move(t);



}
void ListaDisparos::DestruirContenido()
{
	for(int i=0;i<numero;i++)
		delete lista[i];
	//lista.clear();

}
void ListaDisparos::Colision(Pared p)
{
	for(int i=0;i<numero;i++)
	{
		if (Interact::Colision(*(lista[i]),p))
			Eliminar(i);
	}


}
void ListaDisparos::Colision(Caja c)
{
	ListaDisparos::Colision(c.techo);
	ListaDisparos::Colision(c.suelo);
	ListaDisparos::Colision(c.pared_izq);
	ListaDisparos::Colision(c.pared_der);


}
int ListaDisparos::GetNum()
{
	return numero;

}

void ListaDisparos::Eliminar(int index)
{
	if ((index<0) || (index>=numero))
		return;
	delete lista[index];
	//lista.erase(lista.begin()+index);
	cout<<"disparo borrado"<<endl;
	//lista.erase(lista.begin()+index);
	numero--;
	for(int i=index;i<numero;i++)
	lista[i]=lista[i+1];

}
void ListaDisparos::Eliminar(Disparo *d)
{
for(int i=0;i<numero;i++)
	if(lista[i]==d)
	{
		cout<<"disparo para eliminar"<<endl;
		Eliminar(i);
		return;

	}


}

Disparo * ListaDisparos::operator[](int i)
{
	if ( i>numero) // si me paso de indice, paso la ultima esfera
		i=numero-1;

	if (i<0)  // si doy un indice negativo, devuelvo la primera esfera
		i=0; // de la lista

return lista[i];


}
