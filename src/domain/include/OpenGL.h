#pragma once
#include <string>

class OpenGL
{
public:
	// Draw text in window pixels, measured from the top-left corner
	static void Print(std::string msg, int x, int y, unsigned char r = 255, unsigned char g = 255, unsigned char b = 255);
};
