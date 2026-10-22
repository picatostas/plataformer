#include "ListInteract.h"
#include "SphereList.h"
#include "ProjectileList.h"
#include "PlatformContainer.h"

ListInteract::ListInteract(void)
{
}

ListInteract::~ListInteract(void)
{
}
bool ListInteract::Interact(SphereList &spheres, ProjectileList &projectiles)
{
	bool any_hit = false;
	for (int i = spheres.GetNum() - 1; i >= 0; i--)
		for (int j = 0; j < projectiles.GetNum(); j++)
		{
			if (Interact::Collision(*spheres[i], *projectiles[j]))
			{
				Sphere *half = spheres[i]->Split();
				if (half == 0) // no split
				{
					spheres.Remove(spheres[i]);
				}
				else
				{
					spheres.Add(half);
				}
				projectiles.Remove(j);
				any_hit = true;
				// Sphere i was split or removed; stop checking it against more projectiles
				break;
			}
		}
	return any_hit;
}
void ListInteract::Interact(SphereList &spheres, PlatformContainer &platforms)
{
	for (int i = 0; i < spheres.GetNum(); i++)
		for (int j = 0; j < platforms.GetNum(); j++)
			Interact::Bounce(*spheres[i], *platforms[j]);
}
