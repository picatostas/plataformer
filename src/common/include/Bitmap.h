#pragma once
#include "glut.h"

class Bitmap
{
	bool status; // success=1 failure=0
	unsigned int width;
	unsigned int height;
	unsigned int bytes_pixel;
	unsigned char *image;
	GLuint texture;
	char *texture_path;

public:
	Bitmap(char *filename);
	Bitmap();
	bool GetStatus();
	void ApplyTexture();
	~Bitmap();
};
