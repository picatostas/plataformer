#include "TextureLoader.h"
#include "stb_image.h"
#include "stdlib.h"
#include <iostream>
#include "GL/gl.h"
#include "freeglut.h"

TextureLoader::~TextureLoader()
{
}

GLuint TextureLoader::LoadTexture(char *filename)
{

	GLuint texture;
	int width, height, nrChannels;
	unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	if (nrChannels == 3)
	{

		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	stbi_image_free(data);
	return texture;
}
