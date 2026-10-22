#pragma once
#define MAX_PROJECTILES 3
#include "Projectile.h"
#include "Box.h"
#include "Interact.h"
#include "SphereList.h"
#include <vector>
using namespace std;

class ProjectileList
{
private:
	//vector <Projectile*> items;
	Projectile *items[MAX_PROJECTILES];
	int count;

public:
	ProjectileList(void);
	virtual ~ProjectileList(void);

	bool Add(Projectile *proj);
	void DestroyContents();
	void Move(float t);
	void Draw();

	void Remove(int index);
	void Remove(Projectile *proj);

	void Collision(Wall wall);
	void Collision(Box &box);
	void Collision(Sphere *sph);
	Projectile *operator[](int i);
	int GetNum();
	friend class ListInteract;
};
