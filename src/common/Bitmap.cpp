#include "Bitmap.h"
#include "glut.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>

// BMP files store pixels as BGR(A). These come from GL 1.2 / EXT_bgra and are
// not always defined by the OpenGL 1.1 headers that ship with Windows.
#ifndef GL_BGR_EXT
#define GL_BGR_EXT 0x80E0
#endif
#ifndef GL_BGRA_EXT
#define GL_BGRA_EXT 0x80E1
#endif

Bitmap::Bitmap(char *texture_path) : bytes_pixel(0), texture(0)
{
	char buffer[3] = "\0";
	FILE *file;
	// Load the image file that will be used as a texture
	// Only 24 and 32 bit BMPs are supported (RGB and RGBA)
	file = fopen(texture_path, "rb");
	if (file == NULL)
	{
		std::cout << " file " << texture_path << " doesnt exist" << std::endl;
		return;
	}
	fread(buffer, sizeof(char), 2, file);
	if ((buffer[0] != 'B') || (buffer[1] != 'M'))
	{
		std::cout << " file " << texture_path << " gives error" << std::endl;
		fclose(file);
		return;
	}

	// The BMP header fields have fixed sizes, so read them with fixed-size types
	uint16_t bits_pixel = 0;
	int32_t width = 0, height = 0;
	uint32_t offset = 0;
	fseek(file, 0x1C, SEEK_SET);
	fread(&bits_pixel, sizeof(bits_pixel), 1, file);
	bytes_pixel = bits_pixel / 8;
	if ((bytes_pixel != 3) && (bytes_pixel != 4))
	{
		std::cout << " file " << texture_path << " wrong bytes per pixel " << std::endl;
		fclose(file);
		return;
	}
	fseek(file, 0x12, SEEK_SET);
	fread(&width, sizeof(width), 1, file);
	fread(&height, sizeof(height), 1, file);
	height = abs(height); // negative height means rows are stored top-down
	fseek(file, 0x0A, SEEK_SET);
	fread(&offset, sizeof(offset), 1, file);

	// Every BMP row is padded to a multiple of 4 bytes. OpenGL's default unpack
	// alignment is also 4, so the padded rows can be uploaded as they are, but
	// the buffer has to include the padding.
	size_t row_size = (width * bytes_pixel + 3) / 4 * 4;
	unsigned char *image = new unsigned char[row_size * height];
	fseek(file, offset, SEEK_SET);
	fread(image, sizeof(unsigned char), row_size * height, file);
	fclose(file);

	// Create the actual texture in OpenGL
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	if (bytes_pixel == 3)
	{
		std::cout << " file " << texture_path << " uses RGB" << std::endl;
		gluBuild2DMipmaps(GL_TEXTURE_2D, bytes_pixel, width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, image);
	}
	else
	{
		std::cout << " file " << texture_path << " uses RGBA" << std::endl;
		gluBuild2DMipmaps(GL_TEXTURE_2D, bytes_pixel, width, height, GL_BGRA_EXT, GL_UNSIGNED_BYTE, image);
	}
	// OpenGL keeps its own copy of the pixels
	delete[] image;
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

void Bitmap::ReleaseTexture()
{
	// Undo the state pushed by ApplyTexture
	if (bytes_pixel == 4)
	{
		glPopAttrib();
	}
}
