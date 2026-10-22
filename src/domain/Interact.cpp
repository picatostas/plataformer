#include "Interact.h"
#include <iostream>
using namespace std;

#define PI 3.14159

void Interact::Bounce(Player &plyr, Box &box)
{
	float xmax = box.floor.limit2.x - plyr.width / 2;
	float xmin = box.floor.limit1.x + plyr.width / 2;
	float ymin = box.floor.limit1.y;
	float ymax = box.roof.limit2.y - 1 - plyr.width;
	if (plyr.pos.x > xmax)
		plyr.pos.x = xmax;
	if (plyr.pos.x < xmin)
		plyr.pos.x = xmin;
	if (plyr.pos.y > ymax)
		plyr.pos.y = ymax;
	if (plyr.pos.y <= ymin)
	{
		plyr.pos.y = ymin;
		plyr.vel.y = 0;
	}
}

// Reflect the sphere's velocity off the wall (v' = v - 2(v.n)n) and push
// it back out by the amount it overlaps the wall.
bool Interact::Bounce(Sphere &sph, Wall wall)
{
	Vector2D dir;
	float diff = wall.Distance(sph.pos, &dir) - sph.rad;
	if (diff <= 0.0f)
	{
		Vector2D initial_vel = sph.vel;
		sph.vel = initial_vel - (dir * (initial_vel * dir)) * 2.0f;
		sph.pos = sph.pos - dir * diff;
		return true;
	}
	return false;
}
bool Interact::Bounce(Sphere &sph, Platform &plat)
{
	return Bounce(sph, plat.roof) || Bounce(sph, plat.floor);
}
// Elastic collision between two spheres, using their surface area as the
// mass. Only the velocity along the line between the centres changes; the
// tangential part is kept.
void Interact::Bounce(Sphere &sph1, Sphere &sph2)
{

	float dist, area1, area2, v1_n, v2_n, v1_t, v2_t, v1_n_final, v2_n_final;
	Vector2D dir, tdir, v1, v2, v1_final, v2_final;

	dist = sph2.Distance(sph1.pos, &dir);

	if (dist <= sph1.rad + sph2.rad)
	{
		v1 = sph1.vel;
		v2 = sph2.vel;
		area1 = 4 * PI * sph1.rad * sph1.rad;
		area2 = 4 * PI * sph2.rad * sph2.rad;

		tdir.x = -dir.y;
		tdir.y = dir.x;
		// decompose the velocities into components
		// normal and tangent to the collision
		v1_n = dir * v1;
		v1_t = tdir * v1;
		v2_n = dir * v2;
		v2_t = tdir * v2;

		v1_n_final = (v1_n * (area1 - area2) + 2 * area2 * v2_n) / (area1 + area2);
		v2_n_final = (v2_n * (area2 - area1) + 2 * area1 * v1_n) / (area1 + area2);

		v1_final = dir * v1_n_final + tdir * v1_t;
		v2_final = dir * v2_n_final + tdir * v2_t;
		sph1.vel = v1_final;
		sph2.vel = v2_final;
	}
}
// Bounce off the room's walls, then clamp the sphere so it cannot escape
// past the end of a wall it just hit.
void Interact::Bounce(Sphere &sph, Box &box)
{
	bool floor_hit, roof_hit, left_wall_hit, right_wall_hit;
	floor_hit = Bounce(sph, box.floor);
	roof_hit = Bounce(sph, box.roof);
	left_wall_hit = Bounce(sph, box.left_side);
	right_wall_hit = Bounce(sph, box.right_side);

	if (floor_hit == true)
	{
		float xmax = box.floor.limit2.x;
		float xmin = box.floor.limit1.x;
		if (sph.pos.x > xmax)
			sph.pos.x = xmax;
		if (sph.pos.x < xmin)
			sph.pos.x = xmin;
	}

	if (roof_hit == true)
	{
		float xmax = box.roof.limit2.x;
		float xmin = box.roof.limit1.x;
		if (sph.pos.x > xmax)
			sph.pos.x = xmax;
		if (sph.pos.x < xmin)
			sph.pos.x = xmin;
	}

	if (left_wall_hit == true)
	{
		float ymax = box.left_side.limit2.y;
		float ymin = box.left_side.limit1.y;
		if (sph.pos.y > ymax)
			sph.pos.y = ymax;
		if (sph.pos.y < ymin)
			sph.pos.y = ymin;
	}

	if (right_wall_hit == true)
	{
		float ymax = box.right_side.limit2.y;
		float ymin = box.right_side.limit1.y;
		if (sph.pos.y > ymax)
			sph.pos.y = ymax;
		if (sph.pos.y < ymin)
			sph.pos.y = ymin;
	}
}
// A sphere hits the player when it touches the top of the player's head
bool Interact::Collision(Sphere &sph, Player &plyr)
{
	Vector2D pos = plyr.GetPos();
	pos.y += plyr.GetHeight(); // top of the player's head

	float distance = (sph.pos - pos).magnitude();
	if (distance < sph.rad)
	{
		return true;
	}
	return false;
}

bool Interact::Collision(Projectile &proj, Wall &wall)
{
	return wall.Distance(proj.pos) <= proj.rad;
}
bool Interact::Collision(Sphere sph, Projectile proj)
{
	Vector2D diff = sph.pos - proj.pos;
	float dist = diff.magnitude();
	if (dist < sph.rad)
		return true;
	return false;
}
bool Interact::Collision(Player &plyr, LevelDoor door)
{
	if (plyr.pos.x > door.limit1.x && plyr.pos.x < door.limit2.x && plyr.pos.y >= door.limit1.y)
	{
#ifdef DEBUG
		cout << "Player hit door" << endl;
#endif
		return true;
	}
	return false;
}
bool Interact::Collision(Player &plyr, Bonus &bon)
{
	if (((plyr.pos.x > bon.pos.x - 1) && (plyr.pos.x < bon.pos.x + 1)) && ((plyr.pos.y < bon.pos.y + 1) && (plyr.pos.y > bon.pos.y - 1)))
	{
		plyr.SetLives(3);
		bon.SetPos(20, 20);
		return true;
	}
	return false;
}

void Interact::Collision(Player &plyr, Platform &plat)
{
	float xmin = plat.x - plyr.width / 2;
	float xmax = (plat.x + plat.width) + plyr.width / 2;
	float y = plat.y + plat.height;

	// Over the platform, with the feet less than 0.5 below its top: snap onto it
	if (plyr.pos.x > xmin && plyr.pos.x < xmax && plyr.pos.y < y && plyr.pos.y > y - 0.5f)
	{
		plyr.pos.y = y;
		plyr.SetVel(plyr.GetVel().x, 0);
	}
}
