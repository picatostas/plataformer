#include "Pared.h"
#include "glut.h"
#include "stdio.h"


Pared::Pared(void)
{
	color.White();
}


Pared::~Pared(void)
{
}

void Pared::SetColor(unsigned char r,unsigned char v, unsigned char a)
{
	color.r=r;
	color.g=v;
	color.b=a;

}

Pared::Pared(float x1, float y1, float x2, float y2,float z1)
{
	limit1.x=x1;
	limit1.y=y1;
	limit2.x=x2;
	limit2.y=y2;
	z=z1;
}

void Pared::SetPos(float x1, float y1, float x2, float y2,float z1)
{
	limit1.x=x1;
	limit1.y=y1;
	limit2.x=x2;
	limit2.y=y2;
	z=z1;
}

void Pared::Draw() 
{ 
	glDisable(GL_LIGHTING); 
	color.SetColor();
	glBegin(GL_POLYGON); 
		glVertex3d(limit1.x,limit1.y,z); 
		glVertex3d(limit2.x,limit2.y,z); 
		glVertex3d(limit2.x,limit2.y,-z); 
		glVertex3d(limit1.x,limit1.y,-z); 
	glEnd();
	glEnable(GL_LIGHTING); 
}

//Calculo de distancia de una pared a un punto, adicionalmente 
//se modifica el valor de un vector direccion opcional que contendrá 
//el vector unitario saliente que indica la direccion de la 
//recta más corta entre el punto y la pared. 
float Pared::Distancia(Vector2D punto, Vector2D *direccion)
{ 
	Vector2D u=(punto-limit1); 
	Vector2D v=(limit2-limit1).Unitario(); 
	float longitud=(limit1-limit2).modulo(); 
	Vector2D dir; 
	float valor=u*v; 
	float distancia=0; 
	
	if(valor<0) 
		dir=u; 
	else if(valor>longitud) 
		dir=(punto-limit2); 
	else 
		dir=u-v*valor; 
	distancia=dir.modulo(); 
	if(direccion!=0) //si nos dan un vector… 
		*direccion=dir.Unitario(); 
	return distancia; 
}