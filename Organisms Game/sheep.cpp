#include "sheep.h"
#include "colors.h"

Sheep::Sheep(World* world, Point coord, int roundBorn)
	:Animal(OrganismType::SHEEP, world, coord, SHEEP_STRENGTH, SHEEP_INTIATIVE, roundBorn)
{
	this->ChanceOfMoving = SHEEP_CHANCEOFMOVE;
	this->colour = LYELLOW;
	this->MoveDistance=SHEEP_MOVE_DISTANCE;
	this->symbol = SHEEP_SYMBOL;
}

string Sheep::OrganismTypeToString()
{
	return "Sheep";
}

Sheep::~Sheep(){}