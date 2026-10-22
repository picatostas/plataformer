#pragma once
#include "Wall.h"
#include "GL/gl.h"
// Exit of the level: the player finishes the level by reaching it.
class LevelDoor : public Wall
{
public:
	LevelDoor();
	~LevelDoor(void);
	friend class Interact;
};
