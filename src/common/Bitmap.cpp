#include "Bitmap.h"
#include "glut.h"
#include <stdio.h>
#include <iostream>

Bitmap::Bitmap()
{
}
Bitmap::Bitmap(char *filename)
{
	texture_path = filename;
	int bytes_pixel;
	long int width, height, offset;
	char buffer[3] = "\0";
	FILE *file;
	// Load the image file that will be used as a texture
	// Only 24 and 32 bit BMPs are supported (RGB and RGBA)
	file = fopen(texture_path, "rb");
	if (file == NULL)
	{
		std::cout << " file " << texture_path << " doesnt exist" << std::endl;
		fclose(file);
		status = false;
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
			status = false;
			return;
		}
		fseek(file, 0x12, SEEK_SET);
		fread(&width, sizeof(long int), 1, file);
		fread(&height, sizeof(long int), 1, file);
		fseek(file, 0x0A, SEEK_SET);
		fread(&offset, sizeof(long int), 1, file);
		image = new unsigned char[width * height * bytes_pixel];
		fseek(file, offset, SEEK_SET);
		fread(image, sizeof(unsigned char), width * height * bytes_pixel, file);
		this->width = width;
		this->height = height;
		this->bytes_pixel = bytes_pixel;
		// Create the actual texture in OpenGL
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		if (bytes_pixel == 3)
		{
			std::cout << " file " << texture_path << " uses RGB" << std::endl;
			gluBuild2DMipmaps(GL_TEXTURE_2D, bytes_pixel, width, height, GL_RGB, GL_UNSIGNED_BYTE, image);
		}
		else
		{
			std::cout << " file " << texture_path << " uses RGBA" << std::endl;
			gluBuild2DMipmaps(GL_TEXTURE_2D, bytes_pixel, width, height, GL_RGBA, GL_UNSIGNED_BYTE, image);
		}

		status = true;
	}
	else
	{
		std::cout << " file " << texture_path << " gives error" << std::endl;
		status = false;
	}
	fclose(file);
}

bool Bitmap::GetStatus()
{
	return status;
}

void Bitmap::ApplyTexture()
{
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
	if (status)
		delete[] image;
}
