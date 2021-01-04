#pragma once
#include "comun/Vector2D.h"
#include "Paleta_color.h"
#include "ObjetoMovil.h"
class Disparo : public ObjetoMovil
{
public:
	Disparo(void);
	virtual~Disparo(void);

protected:
	float rad;	
	Vector2D posinicial;
	int estelas;
	

public:
	void estela(float p);
	Paleta_color color;
	void SetPos(int mx,int my);
	virtual void Draw(void);
	float GetRad();
	friend class Interact;
};

