#pragma once
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "ListaPlataformas.h"
class ListaInteract
{
public:
	static void Interact(ListaEsferas &esferas,ListaDisparos &disparos);
	static void Interact(ListaEsferas &esferas,ListaPlataformas &plataformas);
	ListaInteract(void);
	~ListaInteract(void);
};

