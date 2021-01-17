#include "CoordinadorJuego.h"
#include "OpenGL.h"
#include "glut.h"
#include "mmsystem.h"
#include "TextureContainer.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include <iostream>

CoordinadorJuego::CoordinadorJuego(void)
{
	SDL_Init(SDL_INIT_AUDIO);
	std::cout << "Current audio driver " << SDL_GetCurrentAudioDriver() << std::endl;
	int i, count = SDL_GetNumAudioDevices(0);
	for (i = 0; i < count; ++i)
	{
		audio_devices.push_back(SDL_GetAudioDeviceName(i, 0));
	}
	std::cout << "Audio devices found: " << audio_devices.size() << std::endl;
	for (unsigned int i = 0; i < audio_devices.size(); i++)
	{
		std::cout << "ID: " << i << " " << audio_devices[i] << std::endl;
	}
	state = INIT;
	if (audio_devices.size() > 0)
	{
		if (Mix_OpenAudioDevice(44100, AUDIO_S16, 2, 2046, audio_devices[0].c_str(), SDL_AUDIO_ALLOW_ANY_CHANGE))
		{
			std::cout << "Cannot open audio device" << Mix_GetError() << std::endl;
			system("pause");
			exit(1);
		}
	}
	else
	{
		std::cout << "ERROR: No audio devices found" << std::endl;
	}

	atexit(Mix_CloseAudio);
	Mix_AllocateChannels(50);
	world.shot = Mix_LoadWAV("sounds/pew.wav");
	world.jump = Mix_LoadWAV("sounds/jump.wav");
	world.hit_player = Mix_LoadWAV("sounds/hit_player.wav");
	world.hit_enemy = Mix_LoadWAV("sounds/hit_enemy.wav");
	world.get_bonus = Mix_LoadWAV("sounds/get_bonus.wav");
	world.player_died = Mix_LoadWAV("sounds/player_died.wav");
	Mix_Volume(-1, 200);
	mciSendString(TEXT("open \"./music/OPEN.mp3\" type mpegvideo alias open_sound"), NULL, 0, NULL);
	mciSendString(TEXT("open \"./music/JUEGO.mp3\" type mpegvideo alias game_sound"), NULL, 0, NULL);
	mciSendString(TEXT("open \"./music/WON.mp3\" type mpegvideo alias won_sound"), NULL, 0, NULL);
	mciSendString(TEXT("open \"./music/LOST.mp3\" type mpegvideo alias lost_sound"), NULL, 0, NULL);
	mciSendString(TEXT("Play open_sound"), NULL, 0, NULL);
}

CoordinadorJuego::~CoordinadorJuego(void)
{
}

void CoordinadorJuego::Draw()
{
	if (state == INIT)
	{
		OpenGL::Print("PLATAFORMER", 300, 100, 255, 255, 255);
		OpenGL::Print("Press -E- to start game", 320, 300, 5, 255, 255);
		OpenGL::Print("Press -O- to see the options", 320, 325, 130, 100, 255);
		OpenGL::Print("Press -S- to exit", 320, 350, 0, 100, 255);
	}
	else if (state == GAME)
	{
		world.Draw();
	}
	else if (state == GAMEOVER)
	{
		world.Draw();
		OpenGL::Print("YOU DIED         ", 300, 200, 255, 0, 0);
		OpenGL::Print("Press -C- to play again", 200, 250, 5, 255, 255);
		OpenGL::Print("Press -M- to go back to the main menu", 200, 275, 5, 255, 255);
		OpenGL::Print("Press -S- to exit", 270, 300, 0, 100, 255);
		glEnable(GL_LIGHTING);
	}
	else if (state == VICTORY)
	{
		world.Draw();
		OpenGL::Print("CONGRATS, ITS A VICTORY!", 250, 200, 218, 165, 32);
		OpenGL::Print("Press -C- to play again", 200, 250, 5, 255, 255);
		OpenGL::Print("Press -M- to go back to the main menu", 200, 275, 5, 255, 255);
		OpenGL::Print("Press -S- to exit", 270, 300, 5, 255, 255);
		glEnable(GL_LIGHTING);
	}
	else if (state == PAUSE)
	{
		world.Draw();
		OpenGL::Print("PAUSE", 370, 250, 255, 255, 0);
		OpenGL::Print("Press -C- to continue", 300, 300, 255, 255, 0);
		OpenGL::Print("Press -O- to see the options", 300, 325, 130, 100, 255);
		OpenGL::Print("Press -M- to go back to the main menu", 300, 350, 0, 100, 255);
		// glEnable(GL_LIGHTING);
	}
	else if (state == CONTROLS || state == CONTROLS_IN_GAME)
	{
		OpenGL::Print("CONTROLS", 250, 200, 218, 165, 32);
		OpenGL::Print("Move left-right keys -A- y -D-", 300, 250, 0, 100, 255);
		OpenGL::Print("Jump -W-", 300, 300, 0, 100, 255);
		OpenGL::Print("Shoot -Space-", 300, 350, 0, 100, 255);
		OpenGL::Print("Press -E- to go back to the main menu", 300, 380, 255, 0, 255);
		OpenGL::Print("Press -A- to go to Audio menu", 300, 400, 255, 0, 255);
		OpenGL::Print("Game goal, reach the level gate without being killed", 150, 430, 255, 255, 255);
	}
	else if (state == AUDIO_CONFIG || state == AUDIO_CONFIG_IN_GAME)
	{
		OpenGL::Print("AUDIO CONFIG", 250, 200, 218, 165, 32);
		OpenGL::Print("List of devices found", 300, 250, 0, 100, 255);
		int list_displacement = 250;
		for (unsigned int i = 0; i < audio_devices.size(); i++)
		{
			list_displacement += 25;
			OpenGL::Print(audio_devices[i], 300, list_displacement, 0, 100, 255);
		}

		OpenGL::Print("Press -E- to go back to the controls menu", 300, list_displacement + 30, 255, 0, 255);
	}
}

void CoordinadorJuego::KeyEspecial(unsigned char key)
{
	if (state == GAME)
	{
		world.KeyEspecial(key);
	}
}

void CoordinadorJuego::KeyUp(unsigned char key)
{
	if (state == GAME)
	{
		world.KeyUp(key);
	}
}

void CoordinadorJuego::KeyDown(unsigned char key)
{
	if (state == GAME)
	{
		world.KeyDown(key);
	}
}

void CoordinadorJuego::Key(unsigned char key)
{
	if (state == INIT)
	{
		if (key == 'e')
		{
			TextureContainer &container = TextureContainer::GetInstance();
			if (!container.GetStatus())
			{
				container.LoadCommonTextures();
			}
			mciSendString(TEXT("stop open_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play game_sound"), NULL, 0, NULL);
			world.Inicializa();
			state = GAME;
		}

		if (key == 's')
		{
			exit(0);
		}

		if (key == 'o')
		{
			state = CONTROLS;
		}
	}
	else if (state == GAME)
	{
		world.Key(key);
		if (key == 'p')
		{
			mciSendString(TEXT("pause game_sound"), NULL, 0, NULL);
			state = PAUSE;
		}
	}

	else if (state == GAMEOVER)
	{
		if (key == 'c')
		{
			mciSendString(TEXT("stop lost_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play game_sound"), NULL, 0, NULL);
			world.Inicializa();
			state = GAME;
		}
		if (key == 'm')
		{
			mciSendString(TEXT("stop lost_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play open_sound"), NULL, 0, NULL);
			state = INIT;
		}

		if (key == 's')
		{
			exit(0);
		}
	}
	else if (state == VICTORY)
	{
		if (key == 'c')
		{
			mciSendString(TEXT("stop won_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play game_sound"), NULL, 0, NULL);
			world.Inicializa();
			state = GAME;
		}
		if (key == 'm')
		{
			mciSendString(TEXT("stop won_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play open_sound"), NULL, 0, NULL);
			state = INIT;
		}

		if (key == 's')
		{
			exit(0);
		}
	}
	else if (state == PAUSE)
	{
		if (key == 'c')
		{
			mciSendString(TEXT("resume game_sound"), NULL, 0, NULL);
			state = GAME;
		}
		if (key == 's')
		{
			mciSendString(TEXT("stop game_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play open_sound"), NULL, 0, NULL);
			state = INIT;
		}
		if (key == 'o')
		{
			state = CONTROLS_IN_GAME;
		}
	}
	else if (state == CONTROLS)
	{
		if (key == 'e')
		{
			state = INIT;
		}
		if (key == 'a')
		{
			state = AUDIO_CONFIG;
		}
	}
	else if (state == CONTROLS_IN_GAME)
	{
		if (key == 'e')
		{
			state = PAUSE;
		}
		if (key == 'a')
		{
			state = AUDIO_CONFIG_IN_GAME;
		}
	}
	else if (state == AUDIO_CONFIG)
	{
		if (key == 'e')
		{
			state = CONTROLS;
		}
	}
	else if (state == AUDIO_CONFIG_IN_GAME)
	{
		if (key == 'e')
		{
			state = CONTROLS_IN_GAME;
		}
	}
}

void CoordinadorJuego::Move()
{
	if (state == GAME)
	{
		world.Move();
		if (world.estadoNivel())
		{
			if (!world.SetLevel())
			{
				mciSendString(TEXT("stop game_sound"), NULL, 0, NULL);
				mciSendString(TEXT("play won_sound"), NULL, 0, NULL);
				state = VICTORY;
			}
		}

		if (world.GetVidasHombre() == 0)
		{
			mciSendString(TEXT("stop game_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play lost_sound"), NULL, 0, NULL);
			state = GAMEOVER;
		}
	}

	if (state == PAUSE)
	{
	}
}
