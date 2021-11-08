#pragma once
#include "animal.h"

#define WOLF_SYMBOL 'W'
#define WOLF_MOVE_DISTANCE 1
#define WOLF_CHANCEOFMOVE 1
#define WOLF_STRENGTH 9
#define WOLF_INTIATIVE 5

class Wolf : public Animal
{
public:
	Wolf(World* world, Point coord, int bornRound);
	string OrganismTypeToString() override;
	~Wolf();
};