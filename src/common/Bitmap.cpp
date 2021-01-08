#include "Bitmap.h"
#include "glut.h"
#include <stdio.h>

Bitmap::Bitmap(char *file_name)
{
	int bytes_pixel;
	long int width, height, offset;
	char buffer[3] = "\0";
	FILE *file;
	//Carga el file de imagen que se utilizara como textura
	//Solo soporta BMP de 24 y 32 bits (RGB y RGBA)
	file = fopen(file_name, "rb");
	if (file == NULL)
	{
		fclose(file);
		state = false;
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
			fclose(file);
			state = false;
			return;
		}
		fseek(file, 0x12, SEEK_SET);
		fread(&width, sizeof(long int), 1, file);
		fread(&height, sizeof(long int), 1, file);
		fseek(file, 0x0A, SEEK_SET);
		fread(&offset, sizeof(long int), 1, file);
		imagen = new unsigned char[width * height * bytes_pixel];
		fseek(file, offset, SEEK_SET);
		fread(imagen, sizeof(unsigned char), width * height * bytes_pixel, file);
		this->width = width;
		this->height = height;
		this->bytes_pixel = bytes_pixel;
		//Crea la textura, propiamente dicha, en openGL
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		if (bytes_pixel == 3)
			gluBuild2DMipmaps(GL_TEXTURE_2D, bytes_pixel, width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, imagen);
		else
			gluBuild2DMipmaps(GL_TEXTURE_2D, bytes_pixel, width, height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, imagen);

		state = true;
	}
	else
		state = false;
	fclose(file);
}

bool Bitmap::verEstado()
{
	return state;
}

void Bitmap::UseTexture()
{
	glEnable(GL_TEXTURE_2D);
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
	if (state)
		delete[] imagen;
}
