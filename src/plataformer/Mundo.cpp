#include "glut.h"
#include <math.h>
#include "Mundo.h"
#include "ListaInteract.h"
#include <iostream>
#include "EsferaPulsante.h"
#include "stdbool.h"

using namespace std;

Mundo::Mundo()
{
	nivelterminado = false;
}
Mundo::~Mundo()
{
	esferas.DestruirContenido();
	disparos.DestruirContenido();
	plataformas.DestruirContenido();
}
void Mundo::Rotared()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}

void Mundo::Draw()
{
	gluLookAt(x_ojo, y_ojo, z_ojo, // pos del ojo
		  0.0, y_ojo, 0.0,     // hacia que punto mira  (0,0,0)
		  0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)

	hombre.Draw();
	bonus.Draw();
	caja.Draw();
	esferas.Draw();
	plataformas.Draw();
	disparos.Draw();
	puerta.Draw();

	glDisable(GL_LIGHTING);
	// Back screen
	glBegin(GL_POLYGON);
	glColor3ub(0, 165, 255); // azul cielo
	glVertex3d(-10.0f, 0, -10);
	glVertex3d(-10.0f, 15.0f, -10);
	glVertex3d(10.0f, 15.0f, -10);
	glVertex3d(10.0f, 0, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Mundo::Move()
{
	hombre.Move(0.025f);
	esferas.Mueve(0.025f);
	disparos.Move(0.025f);
	bonus.Move(0.025f);
	Interact::Rebote(hombre, caja);
	esferas.Rebote(caja);
	ListaInteract::Interact(esferas, plataformas);
	ListaInteract::Interact(esferas, disparos);
	esferas.Rebote();
	disparos.Colision(caja);
	plataformas.Colision(hombre);
	Interact::Colision(hombre, bonus);

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
		esferas.Eliminar(aux);
	}

	bonus.SetVel();

	if (Interact::Colision(hombre, puerta))
	{
		nivelterminado = true;
	}
	else
		nivelterminado = false;
	cout << "Vidas hombre"
	     << "\t" << hombre.GetVidas() << endl;
	cout << "Estado nivel"
	     << "\t" << nivelterminado << endl;
} // fin mundo draw

void Mundo::Inicializa()
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

void Mundo::TeclaDown(unsigned char key)
{
	switch (key)
	{
	case 'w':
		if (hombre.GetSalto() == true)
			hombre.SetVel(hombre.GetVel().x, 8.0f);
		break;
	case 'a':
		hombre.SetVel(-10.0f, hombre.GetVel().y);
		break;
	case 'd':
		hombre.SetVel(10.0f, hombre.GetVel().y);
		break;
	}
}

void Mundo::TeclaUp(unsigned char key)
{
	switch (key)
	{
	case 'w':
		hombre.SetVel(hombre.GetVel().x, 0.0f);
		break;
	case 'a':
		hombre.SetVel(0.0f, hombre.GetVel().y);
		break;
	case 'd':
		hombre.SetVel(0.0f, hombre.GetVel().y);
		break;
	}
}

void Mundo::TeclaEspecial(unsigned char key)
{
	switch (key)
	{
		// TODO: Implement
	}
}

void Mundo::Tecla(unsigned char key)
{
	switch (key)
	{
	case '1':
		esferas.Agregar(new Esfera(0.5f, -5.0f, 10, 4));
		break;
	case '2':
		esferas.Agregar(new Esfera(1.0f, 5.0f, 10, 4));
		break;
	case '3':
		esferas.Agregar(new Esfera(1.5f, -5.0f, 5, 4));
		break;
	case '4':
		esferas.Agregar(new Esfera(2.0f, 5.0f, 5, 4));
		break;

	case ' ':
	{

		Disparo *d = new Disparo();
		Vector2D pos = hombre.GetPos();
		if (hombre.GetVel().x >= 0)
			d->SetVel(10, 0);
		else
			d->SetVel(-10, 0);
		d->SetPos(pos.x, pos.y + 1);
		d->color.Steel();
		disparos.Agregar(d);

		break;
	}
	case 'o':
	{
		esferas.DestruirContenido();

		break;
	}
	case 't':
	{
		hombre.SetVidas(50);

		break;
	}
	case 'm':
	{
		nivelterminado = true;

		break;
	}
	}
}
int Mundo::GetNumEsferas()
{

	return esferas.GetNum();
}

bool Mundo::Impacto()
{
	return impacto;
}
bool Mundo::SetLevel()

{
	nivel++;
	hombre.SetPos(-8, 0);
	esferas.DestruirContenido();
	disparos.DestruirContenido();
	plataformas.DestruirContenido();
	float platform_depth = 1.0f;

	if (nivel == 1)
	{
		puerta.SetPos(8, 12, 9, 14, 5, true);
		Wall *p1 = new Wall(-7.0f, 4.0f, -3.0f, 4.0f, platform_depth, false);
		p1->color.Brown();
		plataformas.Agregar(p1);
		Wall *p2 = new Wall(-2.0f, 5.0f, 2.0f, 5.0f, platform_depth, false);
		p2->color.Brown();
		plataformas.Agregar(p2);
		Wall *p3 = new Wall(4.0f, 7.0f, 8.0f, 7.0f, platform_depth, false);
		p3->color.Brown();
		plataformas.Agregar(p3);
		Wall *p5 = new Wall(-7.0f, 8.0f, -3.0f, 8.0f, platform_depth, false);
		p5->color.Brown();
		plataformas.Agregar(p5);
		Wall *p6 = new Wall(8.0, 12, 10, 12, platform_depth, false);
		p6->color.Brown();
		plataformas.Agregar(p6);

		Wall *p7 = new Wall(-5.0, 11, -2.0, 11, platform_depth, false);
		p7->color.Brown();
		plataformas.Agregar(p7);

		Wall *p8 = new Wall(0.0, 10, 3, 10, platform_depth, false);
		p8->color.Brown();
		plataformas.Agregar(p8);

		Wall *p9 = new Wall(-2.0, 2, 1, 2, platform_depth, false);
		p9->color.Brown();
		plataformas.Agregar(p9);

		Wall *p10 = new Wall(1.0, 12, 3, 12, platform_depth, false);
		p10->color.Brown();
		plataformas.Agregar(p10);

		Wall *p11 = new Wall(-10, 13, -8, 13, platform_depth, false);
		p11->color.Brown();
		plataformas.Agregar(p11);
		bonus.SetPos(-9, 13);

		for (int i = 0; i < 5; i++)
		{
			Esfera *aux = new Esfera(0.5f, -5.0f + i, 10 + i, 4);
			aux->SetColor(i * 40, 0, 255 - i * 40);
			esferas.Agregar(aux);
		}
	}

	if (nivel == 2)
	{
		puerta.SetPos(8, 12, 9, 14, 5, false);
		Wall *p6 = new Wall(8.0, 12, 10, 12, platform_depth, false);
		p6->color.Brown();
		plataformas.Agregar(p6);

		Wall *p1 = new Wall(-8.0f, 2.0f, -6.0f, 2.0f, platform_depth, false);
		p1->color.Brown();
		plataformas.Agregar(p1);
		Wall *p2 = new Wall(-6.0f, 4.0f, -4.0f, 4.0f, platform_depth, false);
		p2->color.Brown();
		plataformas.Agregar(p2);
		Wall *p3 = new Wall(-1.0f, 4.0f, 1.0f, 4.0f, platform_depth, false);
		p3->color.Brown();
		plataformas.Agregar(p3);
		Wall *p5 = new Wall(4.0f, 4.0f, 6.0f, 4.0f, platform_depth, false);
		p5->color.Brown();
		plataformas.Agregar(p5);
		Wall *p61 = new Wall(8.0, 6, 10, 6, platform_depth, false);
		p61->color.Brown();
		plataformas.Agregar(p61);

		Wall *p7 = new Wall(5.0, 7, 6.0, 7, platform_depth, false);
		p7->color.Brown();
		plataformas.Agregar(p7);

		Wall *p8 = new Wall(2.0, 8, 4, 8, platform_depth, false);
		p8->color.Brown();
		plataformas.Agregar(p8);

		Wall *p9 = new Wall(-1.0, 9, 0, 9, platform_depth, false);
		p9->color.Brown();
		plataformas.Agregar(p9);

		Wall *p10 = new Wall(-4.0, 10, -2, 10, platform_depth, false);
		p10->color.Brown();
		plataformas.Agregar(p10);

		Wall *p11 = new Wall(1, 11, 3, 11, platform_depth, false);
		p11->color.Brown();
		plataformas.Agregar(p11);
		Wall *p12 = new Wall(5, 12, 6, 12, platform_depth, false);
		p12->color.Brown();
		plataformas.Agregar(p12);

		EsferaPulsante *e3 = new EsferaPulsante(5, 5);
		e3->SetPos(3, 2);
		e3->SetVel(5, 3);
		esferas.Agregar(e3);

		EsferaPulsante *e2 = new EsferaPulsante(5, 5);
		e2->SetPos(-6, 6);
		e2->SetVel(5, 3);
		esferas.Agregar(e2);

		for (int i = 0; i < 2; i++)
		{
			Esfera *aux = new Esfera(0.5f, -5.0f + i, 10 + i, 4);
			aux->SetColor(i * 40, 0, 255 - i * 40);
			esferas.Agregar(aux);
		}
		bonus.SetPos(-7, 8);
	}
	if (nivel == 3)
	{
		puerta.SetPos(8, 12, 9, 14, 5, true);
		Wall *p6 = new Wall(8.0, 12, 10, 12, platform_depth, false);
		p6->color.Brown();
		plataformas.Agregar(p6);

		Wall *p1 = new Wall(1.0f, 3.0f, 3.0f, 3.0f, platform_depth, false);
		p1->color.Brown();
		plataformas.Agregar(p1);
		Wall *p2 = new Wall(4.0f, 4.0f, 6.0f, 4.0f, platform_depth, false);
		p2->color.Brown();
		plataformas.Agregar(p2);
		Wall *p3 = new Wall(6.0f, 6.0f, 8.0f, 6.0f, platform_depth, false);
		p3->color.Brown();
		plataformas.Agregar(p3);
		Wall *p5 = new Wall(-1.0f, 6.0f, 1.0f, 6.0f, platform_depth, false);
		p5->color.Brown();
		plataformas.Agregar(p5);
		Wall *p61 = new Wall(-4.0, 9, -2, 9, platform_depth, false);
		p61->color.Brown();
		plataformas.Agregar(p61);

		Wall *p7 = new Wall(-8.0, 2, -6.0, 2, platform_depth, false);
		p7->color.Brown();
		plataformas.Agregar(p7);

		Wall *p8 = new Wall(-9.0, 5, 4 - 7, 5, platform_depth, false);
		p8->color.Brown();
		plataformas.Agregar(p8);

		Wall *p9 = new Wall(-8.0, 7, -6, 7, platform_depth, false);
		p9->color.Brown();
		plataformas.Agregar(p9);

		Wall *p10 = new Wall(2.0, 8, 4, 8, platform_depth, false);
		p10->color.Brown();
		plataformas.Agregar(p10);

		Wall *p11 = new Wall(5, 9, 6, 9, platform_depth, false);
		;
		p11->color.Brown();
		plataformas.Agregar(p11);
		Wall *p12 = new Wall(0, 12, 1, 12, platform_depth, false);
		p12->color.Brown();
		plataformas.Agregar(p12);
		Wall *p13 = new Wall(3, 10, 4, 10, platform_depth, false);
		p13->color.Brown();
		plataformas.Agregar(p13);
		bonus.SetPos(-2, 12);
		for (int i = 0; i < 3; i++)
		{
			Esfera *aux = new Esfera(1.1, -9 + 2 * i, 13, i, 5);
			aux->SetColor(i * 40, 0, 255 - i * 40);
			esferas.Agregar(aux);
		}
		Esfera *e1 = new EsferaPulsante(5, 5);
		e1->SetPos(-3, 4);
		e1->SetVel(1, 1);
		esferas.Agregar(e1);
	}
	if (nivel <= 3)
		return true;
	else
	{
		return false;
	}
}
bool Mundo::estadoNivel()
{
	return nivelterminado;
}
int Mundo::GetVidasHombre()
{
	return hombre.GetVidas();
}
