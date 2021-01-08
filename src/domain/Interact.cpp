#include "Interact.h"
#include "stdio.h"
#include <stdlib.h>
#include "glut.h"
#include "Hombre.h"
#include "Caja.h"
#include <math.h>
//#include "Mundo.h"
#include "CoordinadorJuego.h"
#include <iostream>
using namespace std;

#define PI 3.14159

Interact::Interact(void)
{
}

Interact::~Interact(void)
{
}

void Interact::Rebote(Hombre &h, Caja c)
{
	float xmax = c.suelo.limit2.x - h.anchura / 2;
	float xmin = c.suelo.limit1.x + h.anchura / 2;
	float ymin = c.suelo.limit1.y;
	float ymax = c.techo.limit2.y - 1 - h.anchura;
	if (h.pos.x > xmax)
		h.pos.x = xmax;
	if (h.pos.x < xmin)
		h.pos.x = xmin;
	if (h.pos.y > ymax)
		h.pos.y = ymax;
	if (h.pos.y <= ymin)
	{
		h.pos.y = ymin;
		h.vel.y = 0;
	}
}

bool Interact::Rebote(Esfera &e, Wall p)
{
	Vector2D dir;
	float dif = p.Distancia(e.pos, &dir) - e.rad;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.vel;
		e.vel = v_inicial - (dir * (v_inicial * dir)) * 2.0f;
		e.pos = e.pos - dir * dif;
		return true;
	}
	return false;
}
//colision entres esferas
void Interact::Rebote(Esfera &e1, Esfera &e2)
{

	float dist, sup1, sup2, v1_n, v2_n, v1_t, v2_t, v1_modfin, v2_modfin;
	Vector2D dir, dirt, v1, v2, v1_final, v2_final;

	dist = e2.Distancia(e1.pos, &dir);

	if (dist <= e1.rad + e2.rad)
	{
		v1 = e1.vel;
		v2 = e2.vel;
		sup1 = 4 * PI * e1.rad * e1.rad;
		sup2 = 4 * PI * e2.rad * e2.rad;

		dirt.x = -dir.y;
		dirt.y = dir.x;
		//descompos vectorial de las veles
		//segun normal al movimiento y tangente
		v1_n = dir * v1;
		v1_t = dirt * v1;
		v2_n = dir * v2;
		v2_t = dirt * v2;

		v1_modfin = (v1_n * (sup1 - sup2) + 2 * sup2 * v2_n) / (sup1 + sup2);
		v2_modfin = (v2_n * (sup2 - sup1) + 2 * sup1 * v1_n) / (sup1 + sup2);

		v1_final = dir * v1_modfin + dirt * v1_t;
		v2_final = dir * v2_modfin + dirt * v2_t;
		e1.vel = v1_final;
		e2.vel = v2_final;
	}
}
void Interact::Rebote(Esfera &e, Caja c)
{
	bool flag_suelo, flag_techo, flag_pared_izq, flag_pared_der;
	flag_suelo = Rebote(e, c.suelo);
	flag_techo = Rebote(e, c.techo);
	flag_pared_izq = Rebote(e, c.pared_izq);
	flag_pared_der = Rebote(e, c.pared_der);

	if (flag_suelo == true)
	{
		float xmax = c.suelo.limit2.x;
		float xmin = c.suelo.limit1.x;
		if (e.pos.x > xmax)
			e.pos.x = xmax;
		if (e.pos.x < xmin)
			e.pos.x = xmin;
	}

	if (flag_techo == true)
	{
		float xmax = c.techo.limit2.x;
		float xmin = c.techo.limit1.x;
		if (e.pos.x > xmax)
			e.pos.x = xmax;
		if (e.pos.x < xmin)
			e.pos.x = xmin;
	}

	if (flag_pared_izq == true)
	{
		float ymax = c.pared_izq.limit2.y;
		float ymin = c.pared_izq.limit1.y;
		if (e.pos.y > ymax)
			e.pos.y = ymax;
		if (e.pos.y < ymin)
			e.pos.y = ymin;
	}

	if (flag_pared_der == true)
	{
		float ymax = c.pared_der.limit2.y;
		float ymin = c.pared_der.limit1.y;
		if (e.pos.y > ymax)
			e.pos.y = ymax;
		if (e.pos.y < ymin)
			e.pos.y = ymin;
	}
}
void Interact::Rebote(Esfera &e, Hombre &h)
{
	float dist, sup1, sup2, v1_n, v2_n, v1_t, v2_t, v1_modfin, v2_modfin;
	Vector2D dir, dirt, v1, v2, v1_final, v2_final;

	dist = e.Distancia(h.pos, &dir);

	if (dist <= h.altura + e.rad)
	{
		v1 = e.vel;
		v2 = h.vel;
		sup1 = 4 * PI * e.rad * e.rad;
		sup2 = 4 * PI * h.altura * h.altura;

		dirt.x = -dir.y;
		dirt.y = dir.x;
		//descompos vectorial de las veles
		//segun normal al movimiento y tangente
		v1_n = dir * v1;
		v1_t = dirt * v1;
		v2_n = dir * v2;
		v2_t = dirt * v2;

		v1_modfin = (v1_n * (sup1 - sup2) + 2 * sup2 * v2_n) / (sup1 + sup2);
		v2_modfin = (v2_n * (sup2 - sup1) + 2 * sup1 * v1_n) / (sup1 + sup2);

		v1_final = dir * v1_modfin + dirt * v1_t;
		v2_final = dir * v2_modfin + dirt * v2_t;
		e.vel = v1_final;
		h.vel = v2_final;
	}
}
bool Interact::Colision(Esfera e, Hombre h)
{
	Vector2D pos = h.GetPos();
	pos.y += h.GetAltura(); // posicion del centro

	float distancia = (e.pos - pos).modulo();
	if (distancia < e.rad)
	{
		return true;
	}
	return false;
}

void Interact::Colision(Hombre &h, Wall p)
{
	float xmin = p.limit1.x - h.anchura / 2;
	float xmax = p.limit2.x + h.altura / 2;
	float y = p.limit1.y;

	if (h.pos.x > xmin && h.pos.x < xmax && h.pos.y < y && h.pos.y > y - 0.5f)
	{
		h.pos.y = y;
		h.SetVel(h.GetVel().x, 0);
		//h.salto=true;
	}
	//h.salto=false;
	//cout<<"estado del salto"<<"\t"<<h.salto<<endl;
}
bool Interact::Colision(Disparo d, Wall p)
{

	Vector2D dir;
	float dif = p.Distancia(d.pos, &dir) - d.rad;
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = d.vel;
		d.vel = v_inicial - dir * 2.0 * (v_inicial * dir);
		d.pos = d.pos - dir * dif;
		return true;
	}
	return false;
}
bool Interact::Colision(Esfera e, Disparo d)
{
	Vector2D aux = e.pos - d.pos;
	float dist = aux.modulo();
	//Wall aux; // creamos una pared auxiliar
	//Vector2D p1=d.pos;
	//Vector2D p2=d.posinicial;
	//aux.SetPos(p1.x,p1.y,p2.x,p2.y,0); // que coincida con el disparo
	// para calcular su distancia
	if (dist < e.rad)
		return true;
	return false;
}
bool Interact::Colision(Hombre &h, puertaNivel p)
{
	if (h.pos.x > p.limit1.x && h.pos.x < p.limit2.x && h.pos.y >= p.limit1.y)
		return true;
	return false;
}
void Interact::Colision(Hombre &h, Bonus &b)
{
	if (((h.pos.x > b.pos.x - 1) && (h.pos.x < b.pos.x + 1)) && ((h.pos.y < b.pos.y + 1) && (h.pos.y > b.pos.y - 1)))
	{
		h.SetVidas(3);
		b.SetPos(20, 20);
	}
}

void Interact::Colision(Hombre &h, Platform &p)
{
	float xmin = p.x - h.anchura / 2;
	float xmax = (p.x + p.width) + h.altura / 2;
	float y = p.y + p.height;

	if (h.pos.x > xmin && h.pos.x < xmax && h.pos.y < y && h.pos.y > y - 0.5f)
	{
		h.pos.y = y;
		h.SetVel(h.GetVel().x, 0);
	}
}
