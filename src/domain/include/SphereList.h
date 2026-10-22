#pragma once

#include "Sphere.h"
#include "Interact.h"
#include <vector>
using namespace std;
// All the spheres in the level. The list owns them and deletes them when
// they are removed.
class SphereList
{
public:
	SphereList(void);
	~SphereList(void);
	void Draw();
	void Move(float t);
	// Bounce every pair of spheres off each other
	void Bounce();
	void Bounce(Box &box);
	bool Add(Sphere *sph);
	void DestroyContents();
	void Remove(unsigned int index);
	void Remove(Sphere *sph);
	int GetNum();
	// First sphere touching the player, or 0
	Sphere *Collision(Player &plyr);
	Sphere *operator[](unsigned int i);

private:
	vector<Sphere *> items;
};
