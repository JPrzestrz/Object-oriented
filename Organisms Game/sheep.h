#pragma once
#include "animal.h"

#define SHEEP_SYMBOL 'S'
#define SHEEP_MOVE_DISTANCE 1
#define SHEEP_CHANCEOFMOVE 1
#define SHEEP_STRENGTH 4
#define SHEEP_INTIATIVE 4

class Sheep : public Animal
{
public:
	Sheep(World* world, Point coord, int bornRound);
	string OrganismTypeToString() override;
	~Sheep();
};