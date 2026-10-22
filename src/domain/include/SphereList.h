#pragma once

#include "Sphere.h"
#include "Interact.h"
#include <vector>
using namespace std;
class SphereList
{
public:
	SphereList(void);
	~SphereList(void);
	void Draw();
	void Move(float t);
	void Bounce();
	void Bounce(Box &box);
	bool Add(Sphere *sph);
	void DestroyContents();
	void Remove(unsigned int index);
	void Remove(Sphere *sph);
	int GetNum();
	Sphere *Collision(Player &plyr);
	Sphere *operator[](unsigned int i);

private:
	vector<Sphere *> items;
};
