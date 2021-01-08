#pragma once
#include "Wall.h"
class puertaNivel : public Wall
{
public:
	puertaNivel();
	puertaNivel(float x1, float y1, float x2, float y2, float z1);
	~puertaNivel(void);
	void Draw();
	friend class Interact;
};
