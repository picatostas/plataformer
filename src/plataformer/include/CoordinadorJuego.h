#pragma once
#include "World.h"

class CoordinadorJuego
{
protected:
	World world;
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
	void KeyEspecial(unsigned char key);
	void Key(unsigned char key);
	void KeyDown(unsigned char key);
	void KeyUp(unsigned char key);
	void Move();
	void Draw();
	friend class Interact;
};
