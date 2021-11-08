#pragma once
#include "plant.h"

#define BELLADONNA_SYMBOL 'b'
#define BELLADONNA_STRENGTH 99
#define BELLADONNA_INITIATIVE 0

class Belladonna : public Plant
{
public:
    Belladonna(World *world, Point coord, int roundBorn);
    string OrganismTypeToString() override;
    bool SpecialAttackSkill(Organism * attacker, Organism * defender) override;
};