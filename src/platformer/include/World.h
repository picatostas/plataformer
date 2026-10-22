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

// One running game: the room, the current level's objects and the player.
// Levels are numbered from 1; SetLevel() loads the next one.
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
	// Camera position
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
	// Sound effects, loaded by GameCoordinator
	Mix_Chunk *shot, *jump, *hit_player, *hit_enemy, *get_bonus, *player_died;

	// Held keys: movement and jump
	void KeyDown(unsigned char key);
	void KeyUp(unsigned char key);
	// Single presses: shooting and debug keys
	void Key(unsigned char key);
	// Load the next level. Returns false when there are no more levels.
	bool SetLevel();
};
