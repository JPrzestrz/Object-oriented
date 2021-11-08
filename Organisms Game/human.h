#pragma once
#include "animal.h"

#define HUMAN_SYMBOL 'H'
#define HUMAN_MOVE_DISTANCE 1
#define HUMAN_CHANCEOFMOVE 1
#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4
#define SKILL_COOLDOWN 5

class Human: public Animal
{
public:
    Human(World *world, Point coord, int roundBorn);
    ~Human();
    void Action() override;
    string OrganismTypeToString() override;
    Direction GetMoveDirection();
    void SetMoveDirection(Direction moveDirection);

    class Ability
    {
    public:
        Ability();
        void Activate();
        void Disactivate();

        bool GetCanActivate();
        void SetCanActivate(bool CanActivate);
        int GetCooldown();
        void SetCooldown(int cooldown);
    protected:
        bool CanActivate;
        int cooldown;
    };

    Ability* GetAbility();
protected:
    Direction moveDirection;
    Ability* ability;
    Point PlanMove() override;
    void Purification();
};