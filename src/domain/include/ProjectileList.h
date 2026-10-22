#pragma once
#define MAX_PROJECTILES 3
#include "Projectile.h"
#include "Box.h"
#include "Interact.h"

class ProjectileList
{
private:
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

	void Collision(Wall wall);
	void Collision(Box &box);
	Projectile *operator[](int i);
	int GetNum();
};
