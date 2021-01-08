#pragma once
#include "Wall.h"
class puertaNivel : public Wall
{
public:
	puertaNivel();
	~puertaNivel(void);
	void Draw();
	friend class Interact;
};
