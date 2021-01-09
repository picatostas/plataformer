#pragma once
#include "glut.h"

class Bitmap
{
	bool estado; //exito=1 fallo=0
	unsigned int ancho;
	unsigned int alto;
	unsigned int bytes_pixel;
	unsigned char *imagen;
	GLuint texture;

public:
	Bitmap(char *nombre_archivo);
	bool verEstado();
	void usarTextura();
	~Bitmap();
};
