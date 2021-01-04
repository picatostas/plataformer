#include "Vector2D.h"
#include "math.h"


Vector2D::Vector2D(float xv,float yv)
{
	x=xv;
	y=yv;
}


Vector2D::~Vector2D(void)
{
}


Vector2D Vector2D::operator+(Vector2D op) 
{ 
	Vector2D resultado; 
	resultado.x=x+op.x; 
	resultado.y=y+op.y; 
	return resultado; 
}

Vector2D Vector2D::operator+(float real) 
{ 
	Vector2D resultado; 
	resultado.x=x+real; 
	resultado.y=y; 
	return resultado;
}

float Vector2D::modulo()
{
	return (float)sqrt(x*x+y*y);
}

float Vector2D::argumento()
{
	return (float)atan2(y,x);
}

Vector2D Vector2D::Unitario()
{
	Vector2D retorno(x,y);
	float mod=modulo();
	if(mod>0.00001)
	{
		retorno.x/=mod;
		retorno.y/=mod; 
	} 
	return retorno; 
}

Vector2D Vector2D::operator - (Vector2D &v) 
{ 
	Vector2D res; 
	res.x=x-v.x; 
	res.y=y-v.y; 
	return res; 
} 

Vector2D Vector2D::operator + (Vector2D &v) 
{ 
	Vector2D res; 
	res.x=x+v.x; 
	res.y=y+v.y; 
	return res; 
}

float Vector2D::operator * (Vector2D &v)
{
	float res;
	res=(x*v.x)+(y*v.y);
	return res;
}

Vector2D Vector2D::operator * (float e)
{
	Vector2D res;
	res.x=(x*e);
	res.y=(y*e);
	return res;

}