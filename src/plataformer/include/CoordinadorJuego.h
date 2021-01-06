#pragma once
#include "Mundo.h"

class CoordinadorJuego
{
protected:
	Mundo mundo;
	enum Estado
	{
		INICIO,
		JUEGO,
		GAMEOVER,
		FIN,
		PAUSA,
		CONTROLES,
		CONTROLES_IN_GAME
	};
	Estado estado;

public:
	CoordinadorJuego(void);
	virtual ~CoordinadorJuego(void);
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void TeclaDown(unsigned char key);
	void TeclaUp(unsigned char key);
	void Move();
	void Draw();
	friend class Interact;
};
