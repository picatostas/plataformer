#ifndef __TEXTURECONTAINER_H__
#define __TEXTURECONTAINER_H__

#include <unordered_map>
#include "Bitmap.h"
#include "stdbool.h"
#include <string>

class TextureContainer
{
private:
	bool initialized;
	TextureContainer() { initialized = false; }
	TextureContainer(TextureContainer const &) = delete;
	void operator=(TextureContainer const &) = delete;
	std::unordered_map<std::string, Bitmap *> container;
	static TextureContainer *s_instance;

public:
	void LoadCommonTextures();
	Bitmap *GetTexture(std::string texture);
	bool GetStatus();
	static TextureContainer &GetInstance()
	{
		if (!s_instance)
		{
			s_instance = new TextureContainer();
		}
		return *s_instance;
	}
};

#endif // __TEXTURECONTAINER_H__
