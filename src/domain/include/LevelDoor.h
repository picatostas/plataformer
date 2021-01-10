#pragma once
#include "Wall.h"
#include "GL/gl.h"
class LevelDoor : public Wall
{
public:
	LevelDoor();
	~LevelDoor(void);
	friend class Interact;
};
