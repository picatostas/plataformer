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
#include "SpecialProjectile.h"
#include "LevelDoor.h"
#include "SDL2/SDL_mixer.h"

class World
{
private:
	bool impact;
	int level;
	bool level_finished;

public:
	bool can_jump;
	World();
	void Initialize();
	void RotateCamera();
	void Move();
	void Draw();
	virtual ~World();
	int GetNumSpheres();
	bool IsLevelFinished();
	int GetPlayerLives();
	bool HasImpact();
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
	SpecialProjectile special_projectile;
	Mix_Chunk *shot, *jump, *hit_player, *hit_enemy, *get_bonus, *player_died;

	void SpecialKey(unsigned char key);
	void KeyDown(unsigned char key);
	void KeyUp(unsigned char key);
	void Key(unsigned char key);
	bool SetLevel();
};
