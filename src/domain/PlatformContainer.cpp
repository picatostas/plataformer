#include "PlatformContainer.h"
#include <iostream>
#include "Mundo.h"

PlatformContainer::PlatformContainer(void)
{
}
PlatformContainer::~PlatformContainer(void)
{
}

bool PlatformContainer::Agregar(Wall *p)
{
	container.push_back(p);
	return true;
}
void PlatformContainer::Draw()
{
	for (unsigned int i = 0; i < container.size(); i++)
		container[i]->Draw();
}
void PlatformContainer::DestruirContenido()
{
	for (unsigned int i = 0; i < container.size(); i++)
		delete container[i];
	container.clear();
}
void PlatformContainer::Eliminar(unsigned int index)
{
	if (index >= container.size())
		return;
	delete container[index];
	container.erase(container.begin() + index);
	cout << "plataforma eliminada" << endl;
}
void PlatformContainer::Eliminar(Wall *p)
{
	for (unsigned int i = 0; i < container.size(); i++)
		if (container[i] == p)
		{
			cout << "plataforma para eliminar" << endl;
			Eliminar(i);
			return;
		}
}
void PlatformContainer::Colision(Hombre &h)
{
	for (unsigned int i = 0; i < container.size(); i++)
	{
		Interact::Colision(h, *(container[i]));
	}
}

int PlatformContainer::GetNum()
{

	return container.size();
}
Wall *PlatformContainer::operator[](unsigned int i)
{
	if (i > container.size()) // si me paso de indice, paso la ultima esfera
	{
		i = container.size() - 1;
	}

	return container[i];
}
