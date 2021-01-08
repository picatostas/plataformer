#pragma once
#include "glut.h"

class Bitmap
{
	bool estado;
	unsigned int width;
	unsigned int height;
	unsigned int bytes_pixel;
	unsigned char *imagen;
	GLuint texture;

public:
	Bitmap(char *nombre_archivo);
	bool verEstado();
	void useTexture();
	~Bitmap();
};
