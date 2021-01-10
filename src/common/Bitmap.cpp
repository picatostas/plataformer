#include "Bitmap.h"
#include "glut.h"
#include <stdio.h>
#include <iostream>

Bitmap::Bitmap()
{
}
Bitmap::Bitmap(char *nombre_archivo)
{
	texture_path = nombre_archivo;
	int bytes_pixel;
	long int ancho, alto, offset;
	char buffer[3] = "\0";
	FILE *file;
	//Carga el file de imagen que se utilizara como textura
	//Solo soporta BMP de 24 y 32 bits (RGB y RGBA)
	file = fopen(texture_path, "rb");
	if (file == NULL)
	{
		std::cout << " file " << texture_path << " doesnt exist" << std::endl;
		fclose(file);
		estado = false;
		return;
	}
	fread(buffer, sizeof(char), 2, file);
	if ((buffer[0] == 'B') && (buffer[1] == 'M'))
	{
		fseek(file, 0x1C, SEEK_SET);
		fread(&bytes_pixel, sizeof(int), 1, file);
		bytes_pixel /= 8;
		if ((bytes_pixel != 3) && (bytes_pixel != 4))
		{
			std::cout << " file " << texture_path << " wrong bytes per pixel " << std::endl;
			fclose(file);
			estado = false;
			return;
		}
		fseek(file, 0x12, SEEK_SET);
		fread(&ancho, sizeof(long int), 1, file);
		fread(&alto, sizeof(long int), 1, file);
		fseek(file, 0x0A, SEEK_SET);
		fread(&offset, sizeof(long int), 1, file);
		imagen = new unsigned char[ancho * alto * bytes_pixel];
		fseek(file, offset, SEEK_SET);
		fread(imagen, sizeof(unsigned char), ancho * alto * bytes_pixel, file);
		this->ancho = ancho;
		this->alto = alto;
		this->bytes_pixel = bytes_pixel;
		//Crea la textura, propiamente dicha, en openGL
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		if (bytes_pixel == 3)
		{
			std::cout << " file " << texture_path << " uses RGB" << std::endl;
			gluBuild2DMipmaps(GL_TEXTURE_2D, bytes_pixel, ancho, alto, GL_RGB, GL_UNSIGNED_BYTE, imagen);
		}
		else
		{
			std::cout << " file " << texture_path << " uses RGBA" << std::endl;
			gluBuild2DMipmaps(GL_TEXTURE_2D, bytes_pixel, ancho, alto, GL_RGBA, GL_UNSIGNED_BYTE, imagen);
		}

		estado = true;
	}
	else
	{
		std::cout << " file " << texture_path << " gives error" << std::endl;
		estado = false;
	}
	fclose(file);
}

bool Bitmap::verEstado()
{
	return estado;
}

void Bitmap::ApplyTexture()
{
	std::cout << " Using texture" << texture_path << std::endl;

	glBindTexture(GL_TEXTURE_2D, texture);
	if (bytes_pixel == 4)
	{
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
}

Bitmap::~Bitmap()
{
	if (estado)
		delete[] imagen;
}
