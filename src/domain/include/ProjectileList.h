#pragma once
#define MAX_PROJECTILES 3
#include "Projectile.h"
#include "Box.h"
#include "Interact.h"

// The projectiles in flight. At most MAX_PROJECTILES at a time; the list
// owns them and deletes them when they are removed.
class ProjectileList
{
private:
	Projectile *items[MAX_PROJECTILES];
	int count;

public:
	ProjectileList(void);
	virtual ~ProjectileList(void);

	// Returns false (and does not take ownership) if the list is full
	bool Add(Projectile *proj);
	void DestroyContents();
	void Move(float t);
	void Draw();

	void Remove(int index);

	// Remove the projectiles that hit the wall / the room's walls
	void Collision(Wall wall);
	void Collision(Box &box);
	Projectile *operator[](int i);
	int GetNum();
};
