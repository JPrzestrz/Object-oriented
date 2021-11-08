#pragma once
#include "animal.h"

#define FOX_SYMBOL 'F'
#define FOX_MOVE_DISTANCE 1
#define FOX_CHANCEOFMOVE 1
#define FOX_STRENGTH 3
#define FOX_INTIATIVE 7

class Fox : public Animal
{
public:
	Fox(World* world, Point coord, int bornRound);
	string OrganismTypeToString() override;
	~Fox();
protected:
	Point RollPosition(Point place) override;
};