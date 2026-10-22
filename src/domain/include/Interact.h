#pragma once
#include "Bonus.h"
#include "Box.h"
#include "Projectile.h"
#include "Sphere.h"
#include "Player.h"
#include "LevelDoor.h"
#include "Platform.h"
#include "Vector2D.h"

class Interact
{
public:
	Interact(void);
	virtual ~Interact(void);

	static void Bounce(Player &plyr, Box box);
	static bool Bounce(Sphere &sph, Wall wall);
	static bool Bounce(Sphere &sph, Platform plat);
	static void Bounce(Sphere &sph, Box box);
	static void Bounce(Sphere &sph1, Sphere &sph2);
	static void Bounce(Sphere &sph, Player &plyr);
	static void Collision(Player &plyr, Wall wall);
	static bool Collision(Sphere sph, Player plyr);
	static bool Collision(Projectile proj, Wall wall);
	static bool Collision(Projectile proj, Box box);
	static bool Collision(Sphere sph, Projectile proj);
	static bool Collision(Player &plyr, LevelDoor door);
	static bool Collision(Player &plyr, Bonus &bon);
	static void Collision(Player &plyr, Platform &plat);
};
