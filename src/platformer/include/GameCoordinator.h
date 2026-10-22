#pragma once
#include "World.h"
#include <vector>
#include <string>
#include "SDL2/SDL_mixer.h"

class GameCoordinator
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
	Mix_Music *main_menu_music, *game_music, *defeat_music, *victory_music;

public:
	GameCoordinator(void);
	virtual ~GameCoordinator(void);
	void Key(unsigned char key);
	void KeyDown(unsigned char key);
	void KeyUp(unsigned char key);
	void Move();
	void Draw();
};
