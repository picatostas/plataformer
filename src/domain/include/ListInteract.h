#pragma once
#include "ProjectileList.h"
#include "SphereList.h"
#include "PlatformContainer.h"
// Interactions between whole lists of objects.
class ListInteract
{
public:
	// Split or destroy every sphere hit by a projectile. Returns true if anything was hit.
	static bool Interact(SphereList &spheres, ProjectileList &projectiles);

	static void Interact(SphereList &spheres, PlatformContainer &platforms);
};
