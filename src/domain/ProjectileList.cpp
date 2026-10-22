#include "ProjectileList.h"
#include <iostream>
using namespace std;

ProjectileList::ProjectileList(void)
{
	count = 0;
	for (int i = 0; i < MAX_PROJECTILES; i++)
		items[i] = 0;
}

ProjectileList::~ProjectileList(void)
{
}

bool ProjectileList::Add(Projectile *proj)
{
	if (count < MAX_PROJECTILES)
		items[count++] = proj;
	else
		return false;
	return true;
}
void ProjectileList::Draw()
{
	for (int i = 0; i < count; i++)
		items[i]->Draw();
}
void ProjectileList::Move(float t)
{
	for (int i = 0; i < count; i++)
		items[i]->Move(t);
}
void ProjectileList::DestroyContents()
{
	// Reset the list too, otherwise it keeps pointing at deleted projectiles
	for (int i = 0; i < count; i++)
	{
		delete items[i];
		items[i] = 0;
	}
	count = 0;
}
void ProjectileList::Collision(Wall wall)
{
	// Backwards, because Remove() shifts the following items down
	for (int i = count - 1; i >= 0; i--)
	{
		if (Interact::Collision(*(items[i]), wall))
			Remove(i);
	}
}
void ProjectileList::Collision(Box &box)
{
	ProjectileList::Collision(box.roof);
	ProjectileList::Collision(box.floor);
	ProjectileList::Collision(box.left_side);
	ProjectileList::Collision(box.right_side);
}
int ProjectileList::GetNum()
{
	return count;
}

void ProjectileList::Remove(int index)
{
	if ((index < 0) || (index >= count))
		return;
	delete items[index];
#ifdef DEBUG
	cout << "projectile removed" << endl;
#endif
	count--;
	for (int i = index; i < count; i++)
		items[i] = items[i + 1];
}
Projectile *ProjectileList::operator[](int i)
{
	if (i >= count) // index out of range: return the last projectile
		i = count - 1;

	if (i < 0)     // negative index: return the first projectile
		i = 0; // in the list

	return items[i];
}
