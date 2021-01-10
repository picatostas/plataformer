#include "TextureContainer.h"

TextureContainer *TextureContainer::s_instance = nullptr;

void TextureContainer::LoadCommonTextures()
{
	container.emplace("old_door", new Bitmap((char *)"textures/old_door.bmp"));
	container.emplace("dungeon_wall", new Bitmap((char *)"textures/dungeon_wall.bmp"));
	container.emplace("dungeon_aisle", new Bitmap((char *)"textures/dungeon_aisle.bmp"));
	container.emplace("wooden_floor", new Bitmap((char *)"textures/wooden_floor.bmp"));
	container.emplace("wooden_box", new Bitmap((char *)"textures/wooden_box.bmp"));
	initialized = true;
}

Bitmap *TextureContainer::GetTexture(std::string texture)
{
	return container[texture];
}
bool TextureContainer::GetStatus()
{
	return initialized;
}
