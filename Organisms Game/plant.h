#pragma once
#include "organism.h"

class Plant : public Organism
{
protected:
    Plant(OrganismType typeOrg, World *world, Point coord, int strength, int initiative, int roundBorn);
    virtual void Sowing();
public:
    virtual ~Plant();
    virtual void Action() override;
    bool IsAnimal() override;
    void Collision(Organism *other) override;
};