#pragma once
#include "glut.h"

class Bitmap
{
	bool status; // success=1 failure=0
	unsigned int bytes_pixel;
	GLuint texture;
	char *texture_path;

public:
	Bitmap(char *filename);
	Bitmap();
	bool GetStatus();
	void ApplyTexture();
	void ReleaseTexture();
	~Bitmap();
};
