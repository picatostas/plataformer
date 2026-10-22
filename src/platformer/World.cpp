#include "glut.h"
#include <math.h>
#include "World.h"
#include "ListInteract.h"
#include <iostream>
#include "PulsingSphere.h"
#include "stdbool.h"

using namespace std;

World::World()
{
	door.LoadTexture("old_door");
	level_finished = false;
}
World::~World()
{
	spheres.DestroyContents();
	projectiles.DestroyContents();
	platforms.DestroyContents();
}
void World::RotateCamera()
{
	float dist = sqrt(eye_x * eye_x + eye_z * eye_z);
	float ang = atan2(eye_z, eye_x);
	ang += 0.05f;
	eye_x = dist * cos(ang);
	eye_z = dist * sin(ang);
}

void World::Draw()
{
	gluLookAt(eye_x, eye_y, eye_z, // eye position
		  0.0, eye_y, 0.0,     // point the eye looks at
		  0.0, 1.0, 0.0);      // up direction (Y axis)

	player.Draw();
	bonus.Draw();
	box.Draw();
	spheres.Draw();
	platforms.Draw();
	projectiles.Draw();
	door.Draw();
}

void World::Move()
{
	player.Move(0.025f);
	spheres.Move(0.025f);
	projectiles.Move(0.025f);
	// bonus.Move(0.025f);
	Interact::Bounce(player, box);
	spheres.Bounce(box);
	ListInteract::Interact(spheres, platforms);
	ListInteract::Interact(spheres, projectiles);
	spheres.Bounce();
	projectiles.Collision(box);
	platforms.Collision(player);
	if (Interact::Collision(player, bonus))
	{
		Mix_PlayChannel(-1, get_bonus, 0);
	}

	if (player.GetVel().y == 0)
		player.SetCanJump(true);
	else
		player.SetCanJump(false);
	cout << "jump state"
	     << "\t" << player.GetCanJump() << endl;
	Sphere *hit = spheres.Collision(player);
	if (hit != 0)
	{

		player.SetLives(player.GetLives() - 1);
		Mix_PlayChannel(-1, hit_player, 0);
		spheres.Remove(hit);
	}
	if (player.GetLives() == 0)
	{
		Mix_PlayChannel(-1, player_died, 0);
	}
	// bonus.SetVel();

	if (Interact::Collision(player, door))
	{
		cout << " Collision with level door" << endl;
		level_finished = true;
	}
	else
		level_finished = false;
	cout << "Player lives"
	     << "\t" << player.GetLives() << endl;
	cout << "Level state"
	     << "\t" << level_finished << endl;
} // end World::Move

void World::Initialize()
{
	player.SetLives(3);
	player.SetVel(0, 0);
	impact = false;
	eye_x = 0;
	eye_y = 7.5;
	eye_z = 30;
	level = 0;
	SetLevel();
}

void World::KeyDown(unsigned char key)
{
	switch (key)
	{
	case 'w':
	case 'W':
		if (player.GetCanJump() == true)
			player.SetVel(player.GetVel().x, 8.0f);
		break;
	case 'a':
	case 'A':
		player.SetVel(-10.0f, player.GetVel().y);
		player.SetRot(-1);
		break;
	case 'd':
	case 'D':
		player.SetVel(10.0f, player.GetVel().y);
		player.SetRot(1);
		break;
	}
}

void World::KeyUp(unsigned char key)
{
	switch (key)
	{
	case 'w':
	case 'W':
		player.SetVel(player.GetVel().x, 0.0f);
		Mix_PlayChannel(-1, jump, 0);
		break;
	case 'a':
	case 'A':
		player.SetVel(0.0f, player.GetVel().y);
		player.SetRot(0);
		break;
	case 'd':
	case 'D':
		player.SetVel(0.0f, player.GetVel().y);
		player.SetRot(0);
		break;
	}
}

void World::SpecialKey(unsigned char key)
{
	switch (key)
	{
		// TODO: Implement
	}
}

void World::Key(unsigned char key)
{
	switch (key)
	{
	case '1':
		spheres.Add(new Sphere(0.5f, -5.0f, 10, 4));
		break;
	case '2':
		spheres.Add(new Sphere(1.0f, 5.0f, 10, 4));
		break;
	case '3':
		spheres.Add(new Sphere(1.5f, -5.0f, 5, 4));
		break;
	case '4':
		spheres.Add(new Sphere(2.0f, 5.0f, 5, 4));
		break;

	case ' ':
	{

		Projectile *proj = new Projectile();
		Vector2D pos = player.GetPos();
		if (player.GetVel().x >= 0)
		{
			proj->SetVel(20, 0);
		}
		else
		{
			proj->SetVel(-20, 0);
		}
		proj->SetPos(pos.x, pos.y + 1);
		proj->color.Steel();
		projectiles.Add(proj);
		Mix_PlayChannel(-1, shot, 0);

		break;
	}
	case 'o':
        case 'O':
	{
		spheres.DestroyContents();

		break;
	}
	case 't':
	case 'T':
	{
		player.SetLives(50);

		break;
	}
	case 'm':
	case 'M':
	{
		level_finished = true;
		cout << " Collision with level door" << endl;

		break;
	}
	}
}
int World::GetNumSpheres()
{

	return spheres.GetNum();
}

bool World::HasImpact()
{
	return impact;
}
bool World::SetLevel()

{
	level++;
	// level = 0;
	player.SetPos(-8, 0);
	spheres.DestroyContents();
	projectiles.DestroyContents();
	platforms.DestroyContents();
	// Test_level
	if (level == 0)
	{
		door.SetPos(-2.0f, 1.25f, 2.0f, 8.0f, 0.0f, true);

		Platform *level_platforms[] = {
		    new Platform(-3.0f, 1.0f, 6.0f)};

		for (unsigned int i = 0; i < sizeof(level_platforms) / sizeof(level_platforms[0]); i++)
		{
			platforms.Add(level_platforms[i]);
		}
		bonus.SetPos(-20, 13);
	}

	if (level == 1)
	{
		door.SetPos(8.25, 11, 9.75, 13.25, 0, true);

		Platform *level_platforms[] = {
		    new Platform(8.0f, 11.0f, 3.0f),
		    new Platform(-7.0f, 3.0f, 4.0f),
		    new Platform(4.0f, 6.0f, 4.0f),
		    new Platform(-7.0f, 7.0f, 4.0f),
		    new Platform(-5.0f, 10.0f, 2.0f),
		    new Platform(0.0f, 9.0f, 3.0f),
		    new Platform(-2.0f, 1.0f, 3.0f),
		    new Platform(1.0f, 11.0f, 2.0f),
		    new Platform(-10.0f, 12.0f, 2.0f),
		    new Platform(-2.0f, 4.0f, 4.0f)};

		for (unsigned int i = 0; i < sizeof(level_platforms) / sizeof(level_platforms[0]); i++)
		{
			platforms.Add(level_platforms[i]);
		}
		bonus.SetPos(-9, 13);

		for (int i = 0; i < 5; i++)
		{
			Sphere *sph = new Sphere(0.5f, -5.0f + i, 10 + i, 4);
			sph->SetColor(i * 40, 0, 255 - i * 40);
			spheres.Add(sph);
		}
	}

	if (level == 2)
	{
		door.SetPos(8.25, 11, 9.75, 13.25, 0, true);
		Platform *level_platforms[] = {
		    new Platform(8.0f, 11.0f, 2.0f),
		    new Platform(-6.0f, 1.0f, 2.0f),
		    new Platform(-6.0f, 3.0f, 2.0f),
		    new Platform(-1.0f, 3.0f, 2.0f),
		    new Platform(4.0f, 3.0f, 2.0f),
		    new Platform(8.0f, 5.0f, 2.0f),
		    new Platform(5.0f, 6.0f, 2.0f),
		    new Platform(2.0f, 7.0f, 2.0f),
		    new Platform(-1.0f, 8.0f, 2.0f),
		    new Platform(-4.0f, 9.0f, 2.0f),
		    new Platform(1.0f, 10.0f, 2.0f),
		    new Platform(5.0f, 11.0f, 2.0f)};

		for (unsigned int i = 0; i < sizeof(level_platforms) / sizeof(level_platforms[0]); i++)
		{
			platforms.Add(level_platforms[i]);
		}

		PulsingSphere *sph3 = new PulsingSphere(5, 5);
		sph3->SetPos(3, 2);
		sph3->SetVel(5, 3);
		spheres.Add(sph3);

		PulsingSphere *sph2 = new PulsingSphere(5, 5);
		sph2->SetPos(-6, 6);
		sph2->SetVel(5, 3);
		spheres.Add(sph2);

		for (int i = 0; i < 2; i++)
		{
			Sphere *sph = new Sphere(0.5f, -5.0f + i, 10 + i, 4);
			sph->SetColor(i * 40, 0, 255 - i * 40);
			spheres.Add(sph);
		}
		bonus.SetPos(-7, 8);
	}
	if (level == 3)
	{
		door.SetPos(8.25, 11, 9.75, 13.25, 0, true);
		Platform *level_platforms[] = {
		    new Platform(8.0f, 11.0f, 2.0f),
		    new Platform(1.0f, 2.0f, 2.0f),
		    new Platform(4.0f, 3.0f, 2.0f),
		    new Platform(6.0f, 5.0f, 2.0f),
		    new Platform(-1.0f, 5.0f, 2.0f),
		    new Platform(-4.0f, 8.0f, 2.0f),
		    new Platform(-8.0f, 1.0f, 2.0f),
		    new Platform(-9.0f, 4.0f, 2.0f),
		    new Platform(-8.0f, 8.0f, 2.0f),
		    new Platform(2.0f, 7.0f, 2.0f),
		    new Platform(5.0f, 8.0f, 2.0f),
		    new Platform(0.0f, 11.0f, 2.0f),
		    new Platform(3.0f, 9.0f, 2.0f)};

		for (unsigned int i = 0; i < sizeof(level_platforms) / sizeof(level_platforms[0]); i++)
		{
			platforms.Add(level_platforms[i]);
		}

		bonus.SetPos(-2, 12);
		for (int i = 0; i < 3; i++)
		{
			Sphere *sph = new Sphere(1.1, -9 + 2 * i, 13, i, 5);
			sph->SetColor(i * 40, 0, 255 - i * 40);
			spheres.Add(sph);
		}
		Sphere *sph1 = new PulsingSphere(5, 5);
		sph1->SetPos(-3, 4);
		sph1->SetVel(1, 1);
		spheres.Add(sph1);
	}
	if (level <= 3)
		return true;
	else
	{
		return false;
	}
}
bool World::IsLevelFinished()
{
	return level_finished;
}
int World::GetPlayerLives()
{
	return player.GetLives();
}
