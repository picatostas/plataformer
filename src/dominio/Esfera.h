#pragma once
#include "comun/Vector2D.h"
#include "Paleta_color.h"
#include "ObjetoMovil.h"
class Esfera : public ObjetoMovil
{

protected:
	float rad;

public:
	Paleta_color color;
	Esfera(float r, float x = 0.0f, float y = 0.0f,
	       float vx = 0.0f, float vy = 0.0f);
	Esfera(void);
	virtual ~Esfera(void);
	virtual Esfera *Dividir();
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetRad(float r);

	void Draw(void);
	//void Move(float t);

	float Getrad();

	//colision entres esferas
	float Distancia(Vector2D punto, Vector2D *direccion = 0);

	friend class Interact;
};
