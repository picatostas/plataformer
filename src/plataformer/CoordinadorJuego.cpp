#include "CoordinadorJuego.h"
#include <Windows.h>
#include "OpenGL.h"
#include "glut.h"
CoordinadorJuego::CoordinadorJuego(void)
{
	estado = INICIO;
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
		OpenGL::Print((char *)"Presione -E- para comenzar a jugar", 320, 300, 5, 255, 255);
		OpenGL::Print((char *)"Presione -O- para ver las opciones", 320, 325, 130, 100, 255);
		OpenGL::Print((char *)"Presione -S- para salir", 320, 350, 0, 100, 255);
	}
	else if (estado == JUEGO)
	{
		world.Draw();
	}
	else if (estado == GAMEOVER)
	{
		world.Draw();
		OpenGL::Print((char *)"HAS PERDIDO         ", 300, 200, 255, 0, 0);
		OpenGL::Print((char *)"TE QUEDASTE SIN VIDAS", 300, 225, 255, 0, 255);
		OpenGL::Print((char *)"Presione -C- para volver a jugar", 200, 250, 5, 255, 255);
		OpenGL::Print((char *)"Presione -M- para volver al menu principal", 200, 275, 5, 255, 255);
		OpenGL::Print((char *)"Presione -S- para salir, gallina", 270, 300, 0, 100, 255);
		glEnable(GL_LIGHTING);
	}
	else if (estado == FIN)
	{
		world.Draw();
		OpenGL::Print((char *)"ENHORABUENA, HAS GANADO!", 250, 200, 218, 165, 32);
		OpenGL::Print((char *)"Presione -C- para volver a jugar", 200, 250, 5, 255, 255);
		OpenGL::Print((char *)"Presione -M- para volver al menu principal", 200, 275, 5, 255, 255);
		OpenGL::Print((char *)"Presione -S- para salir", 270, 300, 5, 255, 255);
		glEnable(GL_LIGHTING);
	}
	else if (estado == PAUSA)
	{
		world.Draw();
		OpenGL::Print((char *)"PAUSA", 370, 250, 255, 255, 0);
		OpenGL::Print((char *)"Presione -C- para continuar", 300, 300, 255, 255, 0);
		OpenGL::Print((char *)"Presione -O- para ver las opciones", 300, 325, 130, 100, 255);
		OpenGL::Print((char *)"Presione -S- para volver al menu principal", 300, 350, 0, 100, 255);
		glEnable(GL_LIGHTING);
	}
	else if (estado == CONTROLES)
	{
		OpenGL::Print((char *)"CONTROLES", 250, 200, 218, 165, 32);
		OpenGL::Print((char *)"Movimiento lateral  keys -A- y -D-", 300, 250, 0, 100, 255);
		OpenGL::Print((char *)"Salto -W-", 300, 300, 0, 100, 255);
		OpenGL::Print((char *)"Disparo -Espacio-", 300, 350, 0, 100, 255);
		OpenGL::Print((char *)"Presione -E- para volver al Menu", 300, 380, 255, 0, 255);
		OpenGL::Print((char *)"Objetivo, Alcanza la puerta rosa sin que las esferas te maten", 150, 420, 255, 255, 255);
	}
	else if (estado == CONTROLES_IN_GAME)
	{
		OpenGL::Print((char *)"CONTROLES", 250, 200, 218, 165, 32);
		OpenGL::Print((char *)"Movimiento lateral  keys -A- y -D-", 300, 250, 0, 100, 255);
		OpenGL::Print((char *)"Salto -W-", 300, 300, 0, 100, 255);
		OpenGL::Print((char *)"Disparo -Espacio-", 300, 350, 0, 100, 255);
		OpenGL::Print((char *)"Presione -E- para volver al menu de pausa", 300, 380, 255, 0, 255);
		OpenGL::Print((char *)"Objetivo, Alcanza la puerta rosa sin que las esferas te maten", 150, 420, 255, 255, 255);
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
