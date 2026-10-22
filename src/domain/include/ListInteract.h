#pragma once
#include "ProjectileList.h"
#include "SphereList.h"
#include "PlatformContainer.h"
class ListInteract
{
public:
	static bool Interact(SphereList &spheres, ProjectileList &projectiles);

	static void Interact(SphereList &spheres, PlatformContainer &platforms);
};
