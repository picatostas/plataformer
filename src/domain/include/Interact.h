#pragma once
#include "Bonus.h"
#include "Box.h"
#include "Projectile.h"
#include "Sphere.h"
#include "Player.h"
#include "LevelDoor.h"
#include "Platform.h"
#include "Vector2D.h"

// Collision detection and response between pairs of game objects.
// Bounce() changes the objects' motion; Collision() reports whether
// two objects touch (and handles the effect where noted).
class Interact
{
public:
	// Keep the player inside the room
	static void Bounce(Player &plyr, Box &box);
	static bool Bounce(Sphere &sph, Wall wall);
	static bool Bounce(Sphere &sph, Platform &plat);
	static void Bounce(Sphere &sph, Box &box);
	static void Bounce(Sphere &sph1, Sphere &sph2);
	static bool Collision(Sphere &sph, Player &plyr);
	static bool Collision(Projectile &proj, Wall &wall);
	static bool Collision(Sphere sph, Projectile proj);
	static bool Collision(Player &plyr, LevelDoor door);
	// Also refills the player's lives and moves the bonus off-screen
	static bool Collision(Player &plyr, Bonus &bon);
	// Land the player on the platform when falling onto it
	static void Collision(Player &plyr, Platform &plat);
};
