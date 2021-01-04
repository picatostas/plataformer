#include "ListaInteract.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "ListaPlataformas.h"

ListaInteract::ListaInteract(void)
{
}


ListaInteract::~ListaInteract(void)
{
}
void ListaInteract::Interact(ListaEsferas &esferas,ListaDisparos &disparos)
{

	for(int i=esferas.GetNum()-1 ;i>=0;i--)
		//for(int j=disparos.GetNum()-1;j>=0;j--)
		for(int j=0;j<disparos.GetNum();j++)
		{
			if(Interact::Colision(*esferas[i],*disparos[j]))
			{
				Esfera* e=esferas[i]->Dividir();
				if(e==0) //no division 
					esferas.Eliminar(esferas[i]); 
				else 
					esferas.Agregar(e);
					disparos.Eliminar(j);
			} 
		}

}
void ListaInteract::Interact(ListaEsferas &esferas,ListaPlataformas &plataformas)
{
	for(int i=0;i<esferas.GetNum();i++)
		for(int j=0;j<plataformas.GetNum();j++)
			Interact::Rebote(*esferas[i],*plataformas[j]);



}