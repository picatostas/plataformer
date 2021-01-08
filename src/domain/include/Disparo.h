#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ColorPalette.h"
class Disparo : public ObjetoMovil
{
public:
	Disparo(void);
	virtual ~Disparo(void);

protected:
	float rad;
	Vector2D posinicial;

public:
	ColorPalette color;
	void SetPos(int mx, int my);

	virtual void Draw(void);

	float GetRad();

	friend class Interact;
};
