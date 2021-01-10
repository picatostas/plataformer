#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ColorPalette.h"
#include "ModelLoader.h"
class Hombre : public ObjetoMovil
{
private:
	float altura, anchura;
	int vidas;
	bool salto;
	int rot;
	ModelLoader model;

public:
	ColorPalette color;
	void Draw();
	void SetG(float g);
	Hombre(void);
	virtual ~Hombre(void);
	friend class Interact;
	float GetAltura();
	int GetVidas();
	void SetVidas(int vid);
	bool GetSalto();
	void SetSalto(bool sal);
	void SetRot(int rot);
};
