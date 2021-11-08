#pragma once
#include "allclasses.h"

class OrganismCreator
{
public:
	static Organism* CreateNewOrganism(Organism::OrganismType typeOrg, World *world, Point coord);
};