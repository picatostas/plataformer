#include "glut.h"
#include <math.h>
#include "World.h"
#include "ListaInteract.h"
#include <iostream>
#include "EsferaPulsante.h"
#include "stdbool.h"

using namespace std;

World::World()
{
	puerta.LoadTexture("old_door");
	nivelterminado = false;
}
World::~World()
{
	esferas.DestruirContenido();
	disparos.DestruirContenido();
	platforms.DestruirContenido();
}
void World::Rotared()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void World::Draw()
{
	gluLookAt(x_ojo, y_ojo, z_ojo, // pos del ojo
		  0.0, y_ojo, 0.0,     // hacia que punto mira  (0,0,0)
		  0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)

	hombre.Draw();
	bonus.Draw();
	box.Draw();
	esferas.Draw();
	platforms.Draw();
	disparos.Draw();
	puerta.Draw();
}

void World::Move()
{
	hombre.Move(0.025f);
	esferas.Mueve(0.025f);
	disparos.Move(0.025f);
	// bonus.Move(0.025f);
	Interact::Rebote(hombre, box);
	esferas.Rebote(box);
	ListaInteract::Interact(esferas, platforms);
	ListaInteract::Interact(esferas, disparos);
	esferas.Rebote();
	disparos.Colision(box);
	platforms.Colision(hombre);
	if (Interact::Colision(hombre, bonus))
	{
		Mix_PlayChannel(-1, get_bonus, 0);
	}

	if (hombre.GetVel().y == 0)
		hombre.SetSalto(true);
	else
		hombre.SetSalto(false);
	cout << "estado del salto"
	     << "\t" << hombre.GetSalto() << endl;
	Esfera *aux = esferas.Colision(hombre);
	if (aux != 0)
	{

		hombre.SetVidas(hombre.GetVidas() - 1);
		Mix_PlayChannel(-1, hit_player, 0);
		esferas.Eliminar(aux);
	}
	if (hombre.GetVidas() == 0)
	{
		Mix_PlayChannel(-1, player_died, 0);
	}
	// bonus.SetVel();

	if (Interact::Colision(hombre, puerta))
	{
		cout << " Colision with puerta nivel" << endl;
		nivelterminado = true;
	}
	else
		nivelterminado = false;
	cout << "Vidas hombre"
	     << "\t" << hombre.GetVidas() << endl;
	cout << "Estado nivel"
	     << "\t" << nivelterminado << endl;
} // fin world draw

void World::Inicializa()
{
	hombre.SetVidas(3);
	hombre.SetVel(0, 0);
	impacto = false;
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	nivel = 0;
	SetLevel();
}

void World::KeyDown(unsigned char key)
{
	switch (key)
	{
	case 'w':
	case 'W':
		if (hombre.GetSalto() == true)
			hombre.SetVel(hombre.GetVel().x, 8.0f);
		break;
	case 'a':
	case 'A':
		hombre.SetVel(-10.0f, hombre.GetVel().y);
		hombre.SetRot(-1);
		break;
	case 'd':
	case 'D':
		hombre.SetVel(10.0f, hombre.GetVel().y);
		hombre.SetRot(1);
		break;
	}
}

void World::KeyUp(unsigned char key)
{
	switch (key)
	{
	case 'w':
	case 'W':
		hombre.SetVel(hombre.GetVel().x, 0.0f);
		Mix_PlayChannel(-1, jump, 0);
		break;
	case 'a':
	case 'A':
		hombre.SetVel(0.0f, hombre.GetVel().y);
		hombre.SetRot(0);
		break;
	case 'd':
	case 'D':
		hombre.SetVel(0.0f, hombre.GetVel().y);
		hombre.SetRot(0);
		break;
	}
}

void World::KeyEspecial(unsigned char key)
{
	switch (key)
	{
		// TODO: Implement
	}
}

void World::Key(unsigned char key)
{
	switch (key)
	{
	case '1':
		esferas.Add(new Esfera(0.5f, -5.0f, 10, 4));
		break;
	case '2':
		esferas.Add(new Esfera(1.0f, 5.0f, 10, 4));
		break;
	case '3':
		esferas.Add(new Esfera(1.5f, -5.0f, 5, 4));
		break;
	case '4':
		esferas.Add(new Esfera(2.0f, 5.0f, 5, 4));
		break;

	case ' ':
	{

		Disparo *d = new Disparo();
		Vector2D pos = hombre.GetPos();
		if (hombre.GetVel().x >= 0)
		{
			d->SetVel(20, 0);
		}
		else
		{
			d->SetVel(-20, 0);
		}
		d->SetPos(pos.x, pos.y + 1);
		d->color.Steel();
		disparos.Add(d);
		Mix_PlayChannel(-1, shot, 0);

		break;
	}
	case 'o':
        case 'O':
	{
		esferas.DestruirContenido();

		break;
	}
	case 't':
	case 'T':
	{
		hombre.SetVidas(50);

		break;
	}
	case 'm':
	case 'M':
	{
		nivelterminado = true;
		cout << " Colision with puerta nivel" << endl;

		break;
	}
	}
}
int World::GetNumEsferas()
{

	return esferas.GetNum();
}

bool World::Impacto()
{
	return impacto;
}
bool World::SetLevel()

{
	nivel++;
	// nivel = 0;
	hombre.SetPos(-8, 0);
	esferas.DestruirContenido();
	disparos.DestruirContenido();
	platforms.DestruirContenido();
	// Test_level
	if (nivel == 0)
	{
		puerta.SetPos(-2.0f, 1.25f, 2.0f, 8.0f, 0.0f, true);

		Platform *level_platforms[] = {
		    new Platform(-3.0f, 1.0f, 6.0f)};

		for (unsigned int i = 0; i < sizeof(level_platforms) / sizeof(level_platforms[0]); i++)
		{
			platforms.Add(level_platforms[i]);
		}
		bonus.SetPos(-20, 13);
	}

	if (nivel == 1)
	{
		puerta.SetPos(8.25, 11, 9.75, 13.25, 0, true);

		Platform *level_platforms[] = {
		    new Platform(8.0f, 11.0f, 3.0f),
		    new Platform(-7.0f, 3.0f, 4.0f),
		    new Platform(4.0f, 6.0f, 4.0f),
		    new Platform(-7.0f, 7.0f, 4.0f),
		    new Platform(-5.0f, 10.0f, 2.0f),
		    new Platform(0.0f, 9.0f, 3.0f),
		    new Platform(-2.0f, 1.0f, 3.0f),
		    new Platform(1.0f, 11.0f, 2.0f),
		    new Platform(-10.0f, 12.0f, 2.0f),
		    new Platform(-2.0f, 4.0f, 4.0f)};

		for (unsigned int i = 0; i < sizeof(level_platforms) / sizeof(level_platforms[0]); i++)
		{
			platforms.Add(level_platforms[i]);
		}
		bonus.SetPos(-9, 13);

		for (int i = 0; i < 5; i++)
		{
			Esfera *aux = new Esfera(0.5f, -5.0f + i, 10 + i, 4);
			aux->SetColor(i * 40, 0, 255 - i * 40);
			esferas.Add(aux);
		}
	}

	if (nivel == 2)
	{
		puerta.SetPos(8.25, 11, 9.75, 13.25, 0, true);
		Platform *level_platforms[] = {
		    new Platform(8.0f, 11.0f, 2.0f),
		    new Platform(-6.0f, 1.0f, 2.0f),
		    new Platform(-6.0f, 3.0f, 2.0f),
		    new Platform(-1.0f, 3.0f, 2.0f),
		    new Platform(4.0f, 3.0f, 2.0f),
		    new Platform(8.0f, 5.0f, 2.0f),
		    new Platform(5.0f, 6.0f, 2.0f),
		    new Platform(2.0f, 7.0f, 2.0f),
		    new Platform(-1.0f, 8.0f, 2.0f),
		    new Platform(-4.0f, 9.0f, 2.0f),
		    new Platform(1.0f, 10.0f, 2.0f),
		    new Platform(5.0f, 11.0f, 2.0f)};

		for (unsigned int i = 0; i < sizeof(level_platforms) / sizeof(level_platforms[0]); i++)
		{
			platforms.Add(level_platforms[i]);
		}

		EsferaPulsante *e3 = new EsferaPulsante(5, 5);
		e3->SetPos(3, 2);
		e3->SetVel(5, 3);
		esferas.Add(e3);

		EsferaPulsante *e2 = new EsferaPulsante(5, 5);
		e2->SetPos(-6, 6);
		e2->SetVel(5, 3);
		esferas.Add(e2);

		for (int i = 0; i < 2; i++)
		{
			Esfera *aux = new Esfera(0.5f, -5.0f + i, 10 + i, 4);
			aux->SetColor(i * 40, 0, 255 - i * 40);
			esferas.Add(aux);
		}
		bonus.SetPos(-7, 8);
	}
	if (nivel == 3)
	{
		puerta.SetPos(8.25, 11, 9.75, 13.25, 0, true);
		Platform *level_platforms[] = {
		    new Platform(8.0f, 11.0f, 2.0f),
		    new Platform(1.0f, 2.0f, 2.0f),
		    new Platform(4.0f, 3.0f, 2.0f),
		    new Platform(6.0f, 5.0f, 2.0f),
		    new Platform(-1.0f, 5.0f, 2.0f),
		    new Platform(-4.0f, 8.0f, 2.0f),
		    new Platform(-8.0f, 1.0f, 2.0f),
		    new Platform(-9.0f, 4.0f, 2.0f),
		    new Platform(-8.0f, 8.0f, 2.0f),
		    new Platform(2.0f, 7.0f, 2.0f),
		    new Platform(5.0f, 8.0f, 2.0f),
		    new Platform(0.0f, 11.0f, 2.0f),
		    new Platform(3.0f, 9.0f, 2.0f)};

		for (unsigned int i = 0; i < sizeof(level_platforms) / sizeof(level_platforms[0]); i++)
		{
			platforms.Add(level_platforms[i]);
		}

		bonus.SetPos(-2, 12);
		for (int i = 0; i < 3; i++)
		{
			Esfera *aux = new Esfera(1.1, -9 + 2 * i, 13, i, 5);
			aux->SetColor(i * 40, 0, 255 - i * 40);
			esferas.Add(aux);
		}
		Esfera *e1 = new EsferaPulsante(5, 5);
		e1->SetPos(-3, 4);
		e1->SetVel(1, 1);
		esferas.Add(e1);
	}
	if (nivel <= 3)
		return true;
	else
	{
		return false;
	}
}
bool World::estadoNivel()
{
	return nivelterminado;
}
int World::GetVidasHombre()
{
	return hombre.GetVidas();
}
