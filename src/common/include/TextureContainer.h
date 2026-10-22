#ifndef __TEXTURECONTAINER_H__
#define __TEXTURECONTAINER_H__

#include <unordered_map>
#include "Bitmap.h"
#include "stdbool.h"
#include <string>

// Singleton that owns every texture, looked up by name (e.g. "wooden_box").
// Walls only store the texture name, so they can be created before the
// OpenGL context exists; the textures themselves are loaded later by
// LoadCommonTextures(), when the first game starts.
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
	// Returns nullptr if no texture has that name
	Bitmap *GetTexture(std::string texture);
	// True once LoadCommonTextures() has run
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
