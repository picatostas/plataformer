#include "CoordinadorJuego.h"
#include "dominio\OpenGL.h"
#include "glut.h"
#include <Windows.h>
CoordinadorJuego::CoordinadorJuego(void)
{
	estado=INICIO;
	PlaySound(TEXT("OPEN.mp3"),NULL, SND_FILENAME |SND_ASYNC |SND_LOOP );
	//mundo.Inicializa();
}


CoordinadorJuego::~CoordinadorJuego(void)
{
}
void CoordinadorJuego::Draw()
{
	if (estado==INICIO)
	{
		OpenGL::Print("PLATAFORMER",300,100,255,255,255);
		OpenGL::Print("Presione -E- para comenzar a jugar",320,300,5,255,255);
		OpenGL::Print("Presione -O- para ver las opciones",320,325,130,100,255);
		OpenGL::Print("Presione -S- para salir",320,350,0,100,255);
		//PlaySound(TEXT("OPEN.mp3"),NULL, SND_FILENAME |SND_ASYNC |SND_ASYNC);

	}
	else if (estado==JUEGO)
	{
		//PlaySound(TEXT("JUEGO.mp3"),NULL, SND_FILENAME |SND_ASYNC |SND_ASYNC );
		mundo.Draw();
	}
	else if (estado==GAMEOVER)
	{
		mundo.Draw();
		OpenGL::Print("   HAS PERDIDO         ",300,200,255,0,0);
		OpenGL::Print("TE QUEDASTE SIN VIDAS",300,250,255,0,255);
		OpenGL::Print("Presione -C- para volver a jugar, si tienes agallas",200,300,5,255,255);
		OpenGL::Print("Presione -S- para salir, gallina",270,350,0,100,255);

		glEnable(GL_LIGHTING);
	}
	else if (estado==FIN)
	{
		mundo.Draw();

		OpenGL::Print("ENHORABUENA, HAS GANADO!",250,200,218,165,32);
		OpenGL::Print("Pulsa -C- para continuar",300,250,255,255,255);
		OpenGL::Print("Presione -S- para salir",300,300,0,100,255);
		glEnable(GL_LIGHTING);
	}
	else if (estado==PAUSA)
	{
		mundo.Draw();
		OpenGL::Print("PAUSA",370,250,255,255,0);
		OpenGL::Print("Presione -C- para continuar",300,300,255,255,0);
		glEnable(GL_LIGHTING);
	}
	else if (estado==CONTROLES)
	{
		OpenGL::Print("CONROLES",250,200,218,165,32);
		OpenGL::Print("Movimiento lateral  teclas -A- y -D-",300,250,0,100,255);
		OpenGL::Print("Salto -W-",300,300,0,100,255);
		OpenGL::Print("Disparo -Espacio-",300,350,0,100,255);
		OpenGL::Print("Presione -E- para volver al Men�",300,380,255,0,255);
		OpenGL::Print("Objetivo, Alcanza la puerta rosa sin que las esferas te maten",150,420,255,255,255);
	}
}
void CoordinadorJuego::TeclaEspecial(unsigned char key)
{
	if (estado==JUEGO)
	{
		mundo.TeclaEspecial(key);
	}

}
void CoordinadorJuego::TeclaUp(unsigned char key)
{
	if (estado==JUEGO)
	{
		mundo.TeclaUp(key);
	}

}
void CoordinadorJuego::TeclaDown(unsigned char key)
{
	if (estado==JUEGO)
	{
		mundo.TeclaDown(key);
	}

}
void CoordinadorJuego::Tecla(unsigned char key)
{
	if(estado==INICIO)
	{
		if (key =='e')
		{
			PlaySound(TEXT("JUEGO.mp3"),NULL, SND_FILENAME |SND_ASYNC |SND_LOOP );
			mundo.Inicializa();
			estado=JUEGO;
		}
		if ( key== 's')
			exit(0);
		if ( key== 'o')
			estado=CONTROLES;
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
		if ( key== 'p')
			estado=PAUSA;


	}

	else if (estado==GAMEOVER)
	{
		if (key == 'c')
		{
			PlaySound(TEXT("OPEN.mp3"),NULL, SND_FILENAME |SND_ASYNC |SND_LOOP );
			mundo.Inicializa();
			estado=INICIO;
		}
		if (key == 's')
			exit(0);

	}
	else if (estado==FIN)
	{
		if(key == 'c')
			PlaySound(TEXT("OPEN.mp3"),NULL, SND_FILENAME |SND_ASYNC |SND_LOOP );
			estado=INICIO;
		if(key== 's')
			exit(0);
	}
	else if (estado ==PAUSA)
	{
		if(key== 'c')
			estado=JUEGO;
	}
	else if ( estado == CONTROLES)
	{
		if ( key == 'e')
			estado=INICIO;
	}

}
void CoordinadorJuego::Move()
{
	if(estado==JUEGO)
	{
		//PlaySound(TEXT("JUEGO.mp3"),NULL, SND_FILENAME |SND_ASYNC |SND_ASYNC);
		mundo.Move();
		//if(mundo.GetNumEsferas()==0)
		if (mundo.estadoNivel())
		{
			if(!mundo.SetLevel())
			{
				PlaySound(TEXT("WON.mp3"),NULL, SND_FILENAME |SND_ASYNC |SND_LOOP );
				estado=FIN;
			}
		}
		//if(mundo.Impacto())
		if(mundo.GetVidasHombre()==0)
		{
			PlaySound(TEXT("LOST.mp3"),NULL, SND_FILENAME |SND_ASYNC |SND_LOOP );
			estado=GAMEOVER;
		}

	}


	if(estado==PAUSA)
	{

	}
}
