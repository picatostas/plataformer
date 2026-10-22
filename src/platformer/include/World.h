#pragma once
#include "Bonus.h"
#include "Box.h"
#include "Projectile.h"
#include "Sphere.h"
#include "Player.h"
#include "Wall.h"
#include "SphereList.h"
#include "ProjectileList.h"
#include "PlatformContainer.h"
#include "PulsingSphere.h"
#include "LevelDoor.h"
#include "SDL2/SDL_mixer.h"

class World
{
private:
	int level;
	bool level_finished;

public:
	World();
	void Initialize();
	void Move();
	void Draw();
	virtual ~World();
	bool IsLevelFinished();
	int GetPlayerLives();
	float eye_x;
	float eye_y;
	float eye_z;
	SphereList spheres;
	ProjectileList projectiles;
	PlatformContainer platforms;
	Player player;
	Bonus bonus;
	Box box;
	LevelDoor door;
	Mix_Chunk *shot, *jump, *hit_player, *hit_enemy, *get_bonus, *player_died;

	void KeyDown(unsigned char key);
	void KeyUp(unsigned char key);
	void Key(unsigned char key);
	bool SetLevel();
};
