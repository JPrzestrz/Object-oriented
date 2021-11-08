#pragma once
#include "organism.h"

class Animal: public Organism
{
public:
    virtual ~Animal();
    virtual void Action() override;
    virtual void Collision(Organism *other) override;
    
    bool IsAnimal() override;

    int GetMoveDistance();
    void SetMoveDistance(int MoveDistance);
    void SetChanceOfMoving(double chanceOfMoving);
    double GetChanceOfMoving();

protected:
    double ChanceOfMoving;
    int MoveDistance;
    virtual Point PlanMove();
    virtual void Multiplication(Organism * other);
    Animal(OrganismType typeOrg, World *world, Point coord,int strength, int initiative, int bornRound);
};