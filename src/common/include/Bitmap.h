#pragma once
#include "glut.h"

// An OpenGL texture loaded from a 24-bit (RGB) or 32-bit (RGBA) BMP file.
// Needs an OpenGL context, so it can only be created after the window exists.
class Bitmap
{
	unsigned int bytes_pixel;
	GLuint texture;

public:
	Bitmap(char *texture_path);
	// Bind the texture for the next draw calls; call ReleaseTexture() after drawing
	void ApplyTexture();
	void ReleaseTexture();
};
