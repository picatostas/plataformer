#pragma once
#include "glut.h"

class Bitmap
{
	unsigned int bytes_pixel;
	GLuint texture;

public:
	Bitmap(char *texture_path);
	void ApplyTexture();
	void ReleaseTexture();
};
