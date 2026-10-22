#pragma once
#include "Platform.h"
#include "Interact.h"
#include <vector>

// The platforms of the current level. The container owns them.
class PlatformContainer
{
public:
	PlatformContainer(void);
	virtual ~PlatformContainer(void);
	bool Add(Platform *plat);
	void DestroyContents();
	void Draw();
	void Collision(Player &plyr);
	int GetNum();
	Platform *operator[](unsigned int i);

private:
	std::vector<Platform *> container;
};
