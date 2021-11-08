#pragma once
#include "plant.h"

#define HOGWED_SYMBOL 'h'
#define HOGWED_STRENGTH 10
#define HOGWED_INITIATIVE 0

class Hogwed : public Plant
{
public:
    Hogwed(World *world, Point coord, int roundBorn);
    void Action() override;
    bool SpecialAttackSkill(Organism * attacker, Organism * defender) override;
    string OrganismTypeToString() override;
};