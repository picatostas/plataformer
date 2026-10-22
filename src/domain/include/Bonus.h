#pragma once
#include "Vector2D.h"

class Bonus
{
public:
	Bonus(void);
	virtual ~Bonus(void);

private:
	float rot;
	Vector2D pos;

public:
	void SetPos(int mx, int my);

	void Draw(void);

	friend class Interact;
};
