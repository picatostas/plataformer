#pragma once
#include "Pared.h"
class puertaNivel : public Pared
{
public:
	puertaNivel();
	puertaNivel(float x1, float y1, float x2, float y2, float z1);
	~puertaNivel(void);
	void Draw();
	friend class Interact;
};
