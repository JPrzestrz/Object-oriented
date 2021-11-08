#include "grass.h"
#include "colors.h"

Grass::Grass(World *world, Point coord, int bornRound)
:Plant(OrganismType::GRASS,world,coord,GRASS_STRENGTH,GRASS_INITIATIVE,bornRound)
{
    this->colour=GREEN;
    this->symbol=GRASS_SYMBOL;
}

string Grass::OrganismTypeToString()
{
	return "Grass";
}