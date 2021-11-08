#pragma once
#include "plant.h"

#define GRASS_SYMBOL 'G'
#define GRASS_STRENGTH 0
#define GRASS_INITIATIVE 0

class Grass : public Plant
{
public:
    Grass(World *world, Point coord, int roundBorn);
    string OrganismTypeToString() override;
};