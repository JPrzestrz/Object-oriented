#pragma once
#include "animal.h"

#define ANTELOPE_SYMBOL 'A'
#define ANTELOPE_MOVE_DISTANCE 2
#define ANTELOPE_CHANCEOFMOVE 1
#define ANTELOPE_STRENGTH 4
#define ANTELOPE_INTIATIVE 4

class Antelope : public Animal
{
public:
	Antelope(World* world, Point coord, int bornRound);
	string OrganismTypeToString() override;
	bool SpecialAttackSkill(Organism * attacker, Organism * defender) override;
	~Antelope();
};