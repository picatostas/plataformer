#pragma once
#include "Wall.h"
class LevelDoor : public Wall
{
public:
	LevelDoor();
	~LevelDoor(void);
	void Draw();
	friend class Interact;
};
