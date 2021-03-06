#include "CoordinadorJuego.h"
#include "OpenGL.h"
#include "glut.h"
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
		std::cout << "Opening audio device " << audio_devices[0].c_str() << " by default" << std::endl;
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
	main_menu_music = Mix_LoadMUS("music/main_menu.mp3");
	defeat_music = Mix_LoadMUS("music/defeat.mp3");
	victory_music = Mix_LoadMUS("music/victory.mp3");
	game_music = Mix_LoadMUS("music/game.mp3");
	Mix_VolumeChunk(world.get_bonus, 50);
	Mix_VolumeMusic(100);
	Mix_Volume(-1, 100);
	Mix_PlayMusic(main_menu_music, -1);
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
		OpenGL::Print("Move left-right keys -A- & -D-", 300, 250, 0, 100, 255);
		OpenGL::Print("Jump -W-", 300, 300, 0, 100, 255);
		OpenGL::Print("Shoot -Space-", 300, 350, 0, 100, 255);
		OpenGL::Print("Press -E- to go back", 300, 380, 255, 0, 255);
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
		if (key == 'e' || key == 'E')
		{
			TextureContainer &container = TextureContainer::GetInstance();
			if (!container.GetStatus())
			{
				container.LoadCommonTextures();
			}
			Mix_PlayMusic(game_music, -1);
			world.Inicializa();
			state = GAME;
		}

		if (key == 's' || key == 'S')
		{
			exit(0);
		}

		if (key == 'o' || key == 'O')
		{
			state = CONTROLS;
		}
	}
	else if (state == GAME)
	{
		world.Key(key);
		if (key == 'p' || key == 'P')
		{
			Mix_PauseMusic();
			state = PAUSE;
		}
	}

	else if (state == GAMEOVER)
	{
		if (key == 'c' || key == 'C')
		{
			Mix_PlayMusic(game_music, -1);
			world.Inicializa();
			state = GAME;
		}
		if (key == 'm' || key == 'M')
		{
			Mix_PlayMusic(main_menu_music, -1);
			state = INIT;
		}

		if (key == 's' || key == 'S')
		{
			exit(0);
		}
	}
	else if (state == VICTORY)
	{
		if (key == 'c' || key == 'C')
		{
			Mix_PlayMusic(game_music, -1);
			world.Inicializa();
			state = GAME;
		}
		if (key == 'm' || key == 'M')
		{
			Mix_PlayMusic(main_menu_music, -1);
			state = INIT;
		}

		if (key == 's' || key == 'S')
		{
			exit(0);
		}
	}
	else if (state == PAUSE)
	{
		if (key == 'c' || key == 'C')
		{
			Mix_ResumeMusic();
			state = GAME;
		}
		if (key == 'm' || key == 'M')
		{
			Mix_ResumeMusic();
			Mix_PlayMusic(main_menu_music, -1);
			state = INIT;
		}
		if (key == 'o' || key == 'O')
		{
			state = CONTROLS_IN_GAME;
		}
	}
	else if (state == CONTROLS)
	{
		if (key == 'e' || key == 'E')
		{
			state = INIT;
		}
		if (key == 'a' || key == 'A')
		{
			state = AUDIO_CONFIG;
		}
	}
	else if (state == CONTROLS_IN_GAME)
	{
		if (key == 'e' || key == 'E')
		{
			state = PAUSE;
		}
		if (key == 'a' || key == 'A')
		{
			state = AUDIO_CONFIG_IN_GAME;
		}
	}
	else if (state == AUDIO_CONFIG)
	{
		if (key == 'e' || key == 'E')
		{
			state = CONTROLS;
		}
	}
	else if (state == AUDIO_CONFIG_IN_GAME)
	{
		if (key == 'e' || key == 'E')
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
				Mix_PlayMusic(victory_music, -1);
				state = VICTORY;
			}
		}

		if (world.GetVidasHombre() == 0)
		{
			Mix_PlayMusic(defeat_music, -1);
			state = GAMEOVER;
		}
	}

	if (state == PAUSE)
	{
	}
}
