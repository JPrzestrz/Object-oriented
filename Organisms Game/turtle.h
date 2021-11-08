#pragma once
#include "animal.h"

#define TURTLE_SYMBOL 'F'
#define TURTLE_MOVE_DISTANCE 1
#define TURTLE_CHANCEOFMOVE 0.25
#define TURTLE_STRENGTH 2
#define TURTLE_INTIATIVE 1

class Turtle : public Animal
{
public:
	Turtle(World* world, Point coord, int bornRound);
	string OrganismTypeToString() override;
	bool SpecialAttackSkill(Organism * attacker, Organism * defender) override;
	~Turtle();
};