#include "PlatformContainer.h"

PlatformContainer::PlatformContainer(void)
{
}
PlatformContainer::~PlatformContainer(void)
{
}

bool PlatformContainer::Add(Platform *plat)
{
	container.push_back(plat);
	return true;
}
void PlatformContainer::Draw()
{
	for (unsigned int i = 0; i < container.size(); i++)
		container[i]->Draw();
}
void PlatformContainer::DestroyContents()
{
	for (unsigned int i = 0; i < container.size(); i++)
		delete container[i];
	container.clear();
}
void PlatformContainer::Collision(Player &plyr)
{
	for (unsigned int i = 0; i < container.size(); i++)
	{
		Interact::Collision(plyr, *(container[i]));
	}
}

int PlatformContainer::GetNum()
{
	return container.size();
}
Platform *PlatformContainer::operator[](unsigned int i)
{
	if (i >= container.size()) // index out of range: return the last platform
	{
		i = container.size() - 1;
	}

	return container[i];
}
