#pragma once
#include "Platform.h"
#include "Interact.h"
#include <vector>
using namespace std;

class PlatformContainer
{
public:
	PlatformContainer(void);
	virtual ~PlatformContainer(void);
	bool Add(Platform *plat);
	void DestroyContents();
	void Remove(unsigned int index);
	void Remove(Platform *plat);
	void Draw();
	void Collision(Player &plyr);
	void Collision(Sphere *sph);
	int GetNum();
	Platform *operator[](unsigned int i);

private:
	vector<Platform *> container;
};
