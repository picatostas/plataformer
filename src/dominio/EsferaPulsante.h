#pragma once
#include "Esfera.h"
class EsferaPulsante : public Esfera
{
private:
	float rad_min,rad_max,pulso;
public:
	EsferaPulsante(float px,float py);
	void Move(float t);
	Esfera * Dividir();
	EsferaPulsante();
	~EsferaPulsante(void);
	void SetPulso(float t);

};

