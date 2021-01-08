#pragma once
#include "ListaDisparos.h"
#include "ListaEsferas.h"
#include "PlatformContainer.h"
class ListaInteract
{
public:
	static void Interact(ListaEsferas &esferas, ListaDisparos &disparos);

	static void Interact(ListaEsferas &esferas, PlatformContainer &platforms);

	ListaInteract(void);
	~ListaInteract(void);
};
