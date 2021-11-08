#include "animal.h"
#include "organismcreator.h"
#include <Windows.h>
#include <iostream>

Animal::~Animal()
{
}

Animal::Animal(OrganismType typeOrg, World *world, Point coord,int strength, int initiative, int bornRound)
:Organism(typeOrg,world,coord,strength,initiative,bornRound)
{
    dir = new bool[4]{true,true,true,true};
    DidMultiply = false;
}

void Animal::Collision(Organism* otherOrg)
{
    if(typeOrg == otherOrg->GetOrgType())
    {
        if(rand()%100 > 75)
        {
           Multiplication(otherOrg);
        }
    }
    else 
    {
        // special ability when it's attacked
        if(otherOrg->SpecialAttackSkill(this,otherOrg)) return;
        if(SpecialAttackSkill(this,otherOrg)) return;

        if(strength >= otherOrg->GetStrength()) {
            world->DelOrganism(otherOrg);
            MakeMove(otherOrg->GetPosition());
            Commentator::AddComment(OrganismTypeToString()+ " killed "+ otherOrg->OrganismTypeToString());
        }
        else 
        {
            world->DelOrganism(this);
            Commentator::AddComment(otherOrg->OrganismTypeToString()+ " killed "+ OrganismTypeToString());
        }
    }
}

void Animal::Action()
{
    for(int i=0;i<MoveDistance;i++)
    {
        Point nextPos = PlanMove();
        if(world->IsOccupiedBoard(nextPos)==true && world->WhatIsOnBoard(nextPos) != this)
        {
            Collision(world->WhatIsOnBoard(nextPos));
            break;
        }
        else if (world->WhatIsOnBoard(nextPos) != this) MakeMove(nextPos);
    }
}

void Animal::Multiplication(Organism * other)
{
    if(this->DidMultiply == true || other->GetDidMultiply() == true) return;
    Point tempPoint = this->RollFreePosition(position);
    if (tempPoint == position) {
        Point temp2Point = other->RollFreePosition(other->GetPosition());
        if(temp2Point == other->GetPosition()) return;
        else {
            Organism* tempOrg = OrganismCreator::CreateNewOrganism(typeOrg,this->world,temp2Point);
            tempOrg->SetPosition(temp2Point.GetX(),temp2Point.GetY());
            world->AddOrganism(tempOrg);
            DidMultiply = true;
            other->SetDidMultiply(true);
            Commentator::AddComment("New animal "+OrganismTypeToString()+" was born on pos: ("+to_string(temp2Point.GetX())+","+to_string(temp2Point.GetY())+")");
        }
    }
    else{
        Organism* tempOrg = OrganismCreator::CreateNewOrganism(typeOrg,this->world,tempPoint);
        tempOrg->SetPosition(tempPoint.GetX(),tempPoint.GetY());
        world->AddOrganism(tempOrg);
        DidMultiply = true;
        other->SetDidMultiply(true);
        Commentator::AddComment("New animal "+OrganismTypeToString()+" was born on pos: ("+to_string(tempPoint.GetX())+","+to_string(tempPoint.GetY())+")");
    }
}

bool Animal::IsAnimal()
{
    return true;
}

double Animal::GetChanceOfMoving()
{
    return ChanceOfMoving;
}

int Animal::GetMoveDistance()
{
    return MoveDistance;
}

void Animal::SetChanceOfMoving(double chanceOfMoving)
{
    this->ChanceOfMoving = chanceOfMoving;
}

void Animal::SetMoveDistance(int distance)
{
    this->MoveDistance = distance;
}

Point Animal::PlanMove()
{
    if(rand()%100>=(int)(ChanceOfMoving*100))return position;
    else return RollPosition(position);
}