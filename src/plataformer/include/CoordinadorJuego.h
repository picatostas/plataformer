#pragma once
#include "World.h"
#include <vector>
#include <string>

class CoordinadorJuego
{
protected:
	World world;
	enum States
	{
		INIT,
		GAME,
		GAMEOVER,
		VICTORY,
		PAUSE,
		CONTROLS,
		CONTROLS_IN_GAME,
		AUDIO_CONFIG,
		AUDIO_CONFIG_IN_GAME
	};
	States state;
	std::vector<std::string> audio_devices;

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
