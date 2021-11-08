#pragma once
#include "plant.h"

#define GUARANA_SYMBOL '&'
#define GUARANA_STRENGTH 0
#define GUARANA_INITIATIVE 0
#define ADD_STRENGTH 3

class Guarana : public Plant
{
public:
    Guarana(World *world, Point coord, int roundBorn);
    string OrganismTypeToString() override;
    bool SpecialAttackSkill(Organism * attacker, Organism * defender) override;
};