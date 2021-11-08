#pragma once
#include "plant.h"

#define SOW_SYMBOL 't'
#define SOW_STRENGTH 0
#define SOW_INITIATIVE 0

class Sow : public Plant
{
public:
    Sow(World *world, Point coord, int roundBorn);
    void Action() override;
    string OrganismTypeToString() override;
};