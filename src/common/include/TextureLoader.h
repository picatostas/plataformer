#ifndef __TEXTURELOADER_H__
#define __TEXTURELOADER_H__

#pragma once
#include "GL/gl.h"

#define STB_IMAGE_IMPLEMENTATION

class TextureLoader
{

public:
	TextureLoader();
	~TextureLoader();
	static GLuint LoadTexture(char *filename);
};

#endif // __TEXTURELOADER_H__
