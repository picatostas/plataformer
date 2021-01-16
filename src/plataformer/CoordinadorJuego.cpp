#include "CoordinadorJuego.h"
#include "OpenGL.h"
#include "glut.h"
#include "mmsystem.h"
#include "TextureContainer.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

CoordinadorJuego::CoordinadorJuego(void)
{
	estado = INICIO;
	if (Mix_OpenAudio(44100, AUDIO_S16, 2, 4096))
	{
		std::cout << "No se puede inicializar SDL_mixer" << Mix_GetError() << std::endl;
		system("pause");
		exit(1);
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
	if (estado == INICIO)
	{
		OpenGL::Print((char *)"PLATAFORMER", 300, 100, 255, 255, 255);
		OpenGL::Print((char *)"Press -E- to start game", 320, 300, 5, 255, 255);
		OpenGL::Print((char *)"Press -O- to see the options", 320, 325, 130, 100, 255);
		OpenGL::Print((char *)"Press -S- to exit", 320, 350, 0, 100, 255);
	}
	else if (estado == JUEGO)
	{
		world.Draw();
	}
	else if (estado == GAMEOVER)
	{
		world.Draw();
		OpenGL::Print((char *)"YOU DIED         ", 300, 200, 255, 0, 0);
		OpenGL::Print((char *)"Press -C- to play again", 200, 250, 5, 255, 255);
		OpenGL::Print((char *)"Press -M- to go back to the main menu", 200, 275, 5, 255, 255);
		OpenGL::Print((char *)"Press -S- to exit", 270, 300, 0, 100, 255);
		glEnable(GL_LIGHTING);
	}
	else if (estado == FIN)
	{
		world.Draw();
		OpenGL::Print((char *)"CONGRATS, ITS A VICTORY!", 250, 200, 218, 165, 32);
		OpenGL::Print((char *)"Press -C- to play again", 200, 250, 5, 255, 255);
		OpenGL::Print((char *)"Press -M- to go back to the main menu", 200, 275, 5, 255, 255);
		OpenGL::Print((char *)"Press -S- to exit", 270, 300, 5, 255, 255);
		glEnable(GL_LIGHTING);
	}
	else if (estado == PAUSA)
	{
		world.Draw();
		OpenGL::Print((char *)"PAUSE", 370, 250, 255, 255, 0);
		OpenGL::Print((char *)"Press -C- to continue", 300, 300, 255, 255, 0);
		OpenGL::Print((char *)"Press -O- to see the options", 300, 325, 130, 100, 255);
		OpenGL::Print((char *)"Press -M- to go back to the main menu", 300, 350, 0, 100, 255);
		// glEnable(GL_LIGHTING);
	}
	else if (estado == CONTROLES)
	{
		OpenGL::Print((char *)"CONTROLS", 250, 200, 218, 165, 32);
		OpenGL::Print((char *)"Move left-right keys -A- y -D-", 300, 250, 0, 100, 255);
		OpenGL::Print((char *)"Jump -W-", 300, 300, 0, 100, 255);
		OpenGL::Print((char *)"Shoot -Space-", 300, 350, 0, 100, 255);
		OpenGL::Print((char *)"Press -E- to go back to the main menu", 300, 380, 255, 0, 255);
		OpenGL::Print((char *)"Game goal, reach the level gate without being killed", 150, 420, 255, 255, 255);
	}
	else if (estado == CONTROLES_IN_GAME)
	{
		OpenGL::Print((char *)"CONTROLS", 250, 200, 218, 165, 32);
		OpenGL::Print((char *)"Move left-right keys -A- y -D-", 300, 250, 0, 100, 255);
		OpenGL::Print((char *)"Jump -W-", 300, 300, 0, 100, 255);
		OpenGL::Print((char *)"Shoot -Space-", 300, 350, 0, 100, 255);
		OpenGL::Print((char *)"Press -E- to go back to the pause menu", 300, 380, 255, 0, 255);
		OpenGL::Print((char *)"Game goal, reach the level gate without being killed", 150, 420, 255, 255, 255);
	}
}

void CoordinadorJuego::KeyEspecial(unsigned char key)
{
	if (estado == JUEGO)
	{
		world.KeyEspecial(key);
	}
}

void CoordinadorJuego::KeyUp(unsigned char key)
{
	if (estado == JUEGO)
	{
		world.KeyUp(key);
	}
}

void CoordinadorJuego::KeyDown(unsigned char key)
{
	if (estado == JUEGO)
	{
		world.KeyDown(key);
	}
}

void CoordinadorJuego::Key(unsigned char key)
{
	if (estado == INICIO)
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
			estado = JUEGO;
		}

		if (key == 's')
		{
			exit(0);
		}

		if (key == 'o')
		{
			estado = CONTROLES;
		}
	}
	else if (estado == JUEGO)
	{
		world.Key(key);
		if (key == 'p')
		{
			mciSendString(TEXT("pause game_sound"), NULL, 0, NULL);
			estado = PAUSA;
		}
	}

	else if (estado == GAMEOVER)
	{
		if (key == 'c')
		{
			mciSendString(TEXT("stop lost_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play game_sound"), NULL, 0, NULL);
			world.Inicializa();
			estado = JUEGO;
		}
		if (key == 'm')
		{
			mciSendString(TEXT("stop lost_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play open_sound"), NULL, 0, NULL);
			estado = INICIO;
		}

		if (key == 's')
		{
			exit(0);
		}
	}
	else if (estado == FIN)
	{
		if (key == 'c')
		{
			mciSendString(TEXT("stop won_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play game_sound"), NULL, 0, NULL);
			world.Inicializa();
			estado = JUEGO;
		}
		if (key == 'm')
		{
			mciSendString(TEXT("stop won_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play open_sound"), NULL, 0, NULL);
			estado = INICIO;
		}

		if (key == 's')
		{
			exit(0);
		}
	}
	else if (estado == PAUSA)
	{
		if (key == 'c')
		{
			mciSendString(TEXT("resume game_sound"), NULL, 0, NULL);
			estado = JUEGO;
		}
		if (key == 's')
		{
			mciSendString(TEXT("stop game_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play open_sound"), NULL, 0, NULL);
			estado = INICIO;
		}
		if (key == 'o')
		{
			estado = CONTROLES_IN_GAME;
		}
	}
	else if (estado == CONTROLES)
	{
		if (key == 'e')
		{
			estado = INICIO;
		}
	}
	else if (estado == CONTROLES_IN_GAME)
	{
		if (key == 'e')
		{
			estado = PAUSA;
		}
	}
}

void CoordinadorJuego::Move()
{
	if (estado == JUEGO)
	{
		world.Move();
		if (world.estadoNivel())
		{
			if (!world.SetLevel())
			{
				mciSendString(TEXT("stop game_sound"), NULL, 0, NULL);
				mciSendString(TEXT("play won_sound"), NULL, 0, NULL);
				estado = FIN;
			}
		}

		if (world.GetVidasHombre() == 0)
		{
			mciSendString(TEXT("stop game_sound"), NULL, 0, NULL);
			mciSendString(TEXT("play lost_sound"), NULL, 0, NULL);
			estado = GAMEOVER;
		}
	}

	if (estado == PAUSA)
	{
	}
}
