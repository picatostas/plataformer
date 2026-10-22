#include "PlatformContainer.h"
#include <iostream>
#include "World.h"

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
void PlatformContainer::Remove(unsigned int index)
{
	if (index >= container.size())
		return;
	delete container[index];
	container.erase(container.begin() + index);
	cout << "platform removed" << endl;
}
void PlatformContainer::Remove(Platform *plat)
{
	for (unsigned int i = 0; i < container.size(); i++)
		if (container[i] == plat)
		{
			cout << "platform to remove" << endl;
			Remove(i);
			return;
		}
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
	if (i > container.size()) // index out of range: return the last platform
	{
		i = container.size() - 1;
	}

	return container[i];
}
