#include "SphereList.h"
#include <iostream>
using namespace std;

SphereList::SphereList(void)
{
	/*items.size()=0;
	for (int i=0;i<MAX_SPHERES;i++)
		items[i]=0;*/
}

SphereList::~SphereList(void)
{
}

bool SphereList::Add(Sphere *sph)
{
	items.push_back(sph);
	return true;
}
void SphereList::Draw()
{
	for (unsigned int i = 0; i < items.size(); i++)
		items[i]->Draw();
}
void SphereList::Move(float t)
{
	for (unsigned int i = 0; i < items.size(); i++)
		items[i]->Move(t);
}
void SphereList::Bounce(Box &box)
{
	for (unsigned int i = 0; i < items.size(); i++)
		Interact::Bounce(*(items[i]), box);
}
void SphereList::Bounce(Wall wall)
{
	for (unsigned int i = 0; i < items.size(); i++)
		Interact::Bounce(*(items[i]), wall);
}
void SphereList::Bounce()
{

	for (unsigned int i = 0; i < items.size(); i++)
		for (unsigned int j = i + 1; j < items.size(); j++)
			Interact::Bounce(*(items[i]), *(items[j]));
}

void SphereList::DestroyContents()
{
	for (unsigned int i = 0; i < items.size(); i++)
		delete items[i];
	items.clear();
}
int SphereList::GetNum()
{
	return items.size();
}
void SphereList::Remove(unsigned int index)
{
	if (index >= items.size())
		return;
	delete items[index];
	items.erase(items.begin() + index);
	cout << "sphere removed" << endl;
	/*items.size()--;
	for(int i=index;i<items.size();i++)
	items[i]=items[i+1];*/
}
void SphereList::Remove(Sphere *sph)
{
	for (unsigned int i = 0; i < items.size(); i++)
		if (items[i] == sph)
		{
			cout << "sphere to remove" << endl;
			Remove(i);
			return;
		}
}
Sphere *SphereList::Collision(Player &plyr)
{
	for (unsigned int i = 0; i < items.size(); i++)
	{
		if (Interact::Collision(*(items[i]), plyr))
			return items[i];
	}
	return 0;
}
Sphere *SphereList::operator[](unsigned int i)
{
	if (i >= items.size()) // index out of range: return the last sphere
	{
		i = items.size() - 1;
	}

	// if (i < 0)     // negative index: return the first sphere
	// 	i = 0; // in the list

	return items[i];
}
