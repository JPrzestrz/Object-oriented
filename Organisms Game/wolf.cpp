#include "wolf.h"
#include "colors.h"

Wolf::Wolf(World* world, Point coord, int roundBorn)
	:Animal(OrganismType::WOLF, world, coord, WOLF_STRENGTH, WOLF_INTIATIVE, roundBorn)
{
	this->ChanceOfMoving = WOLF_CHANCEOFMOVE;
	this->colour = RED;
	this->MoveDistance=WOLF_MOVE_DISTANCE;
	this->symbol = WOLF_SYMBOL;
}

string Wolf::OrganismTypeToString()
{
	return "Wolf";
}

Wolf::~Wolf(){}