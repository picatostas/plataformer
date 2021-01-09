#include "Wall.h"
#include "glut.h"

Wall::Wall(void)
{
}

Wall::~Wall(void)
{
}

Wall::Wall(float x1, float y1, float x2, float y2, float z1, bool is_front, ColorPalette color)
{
	limit1.x = x1;
	limit1.y = y1;
	limit2.x = x2;
	limit2.y = y2;
	z = z1;
	this->is_front = is_front;
	this->color = color;
}

void Wall::SetPos(float x1, float y1, float x2, float y2, float z1, bool is_front)
{
	limit1.x = x1;
	limit1.y = y1;
	limit2.x = x2;
	limit2.y = y2;
	z = z1;
	this->is_front = is_front;
}

void Wall::Draw()
{
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);

	// To draw a front planel
	if (is_front)
	{
		glVertex3d(limit1.x, limit1.y, z);
		glVertex3d(limit2.x, limit1.y, z);
		glVertex3d(limit2.x, limit2.y, z);
		glVertex3d(limit1.x, limit2.y, z);
	}
	// To draw a normal plane to the front panel
	else
	{
		glVertex3d(limit1.x, limit1.y, z);
		glVertex3d(limit2.x, limit2.y, z);
		glVertex3d(limit2.x, limit2.y, -z);
		glVertex3d(limit1.x, limit1.y, -z);
	}

	glEnd();
	glEnable(GL_LIGHTING);
}

//Calculo de distancia de una pared a un punto, adicionalmente
//se modifica el valor de un vector direccion opcional que contendra
//el vector unitario saliente que indica la direccion de la
//recta mas corta entre el punto y la pared.
float Wall::Distancia(Vector2D punto, Vector2D *direccion)
{
	Vector2D u = (punto - limit1);
	Vector2D v = (limit2 - limit1).Unitario();
	float longitud = (limit1 - limit2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0.0f;

	if (valor < 0.0f)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limit2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector
		*direccion = dir.Unitario();
	return distancia;
}
