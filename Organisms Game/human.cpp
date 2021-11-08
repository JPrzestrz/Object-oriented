#include "colors.h"
#include "human.h"
#include "commentator.h"
#include <iostream>
#define TIME_SKILL 5

Human::Human(World *world, Point coord, int bornRound) 
:Animal(OrganismType::HUMAN,world,coord,HUMAN_STRENGTH,HUMAN_INITIATIVE,bornRound)
{
    this->symbol=HUMAN_SYMBOL;
    this->MoveDistance=HUMAN_MOVE_DISTANCE;
    this->colour=YELLOW;
    this->ChanceOfMoving=HUMAN_CHANCEOFMOVE;
    moveDirection=Direction::SAME;
    ability = new Ability();
}

Human::Ability::Ability()
{
    cooldown=0;
    CanActivate=true;
}

Organism::Direction Human::GetMoveDirection()
{
    return moveDirection;
}

string Human::OrganismTypeToString()
{
    return "Human";
}

void Human::Action()
{
    if(ability->GetCooldown()==SKILL_COOLDOWN)
    {
        Commentator::AddComment("Purification activated!");
        Commentator::Comment();
        Purification();
    }
    if(ability->GetCooldown()!=0)
    {
       ability->SetCooldown(ability->GetCooldown()-1);
       if(ability->GetCooldown()==0)
          ability->SetCanActivate(true);
    }
    for(int i=0;i<MoveDistance;i++)
    {
        Point nextPosition = PlanMove();
        if(world->IsOccupiedBoard(nextPosition)==true && world->WhatIsOnBoard(nextPosition)!=this)
        {
            Collision(world->WhatIsOnBoard(nextPosition));
            break;
        }
        else if(world->WhatIsOnBoard(nextPosition)!=this) MakeMove(nextPosition);

    }
    moveDirection = Direction::SAME;
}

void Human::SetMoveDirection(Direction moveDirection)
{
    this->moveDirection=moveDirection;
}

void Human::Purification()
{
    int x = position.GetX();
    int y = position.GetY();
    int maxX=world->GetSizeX();
    int maxY=world->GetSizeY();
    int possibleDir[4]={1,1,1,1};
    int numDir=0;
    // 0 -> up | 1 -> down | 2 -> left | 3-> right
    if(y==0) possibleDir[0]=0;
    if(y==maxY - 1) possibleDir[1]=0;
    if(x==0) possibleDir[2]=0;
    if(x==maxX - 1) possibleDir[3]=0;
    Organism * tempOrg = nullptr;
    for(int i=0;i<4;i++)
    {
        if(i==0 && possibleDir[i]==1)
        {
            tempOrg = world->WhatIsOnBoard(Point(x,y-1));
        }
        else if(i==1 && possibleDir[i]==1)
        {
            tempOrg = world->WhatIsOnBoard(Point(x,y+1));
        }
        else if(i==2 && possibleDir[i]==1)
        {
            tempOrg = world->WhatIsOnBoard(Point(x-1,y));
        }
        else if(i==3 && possibleDir[i]==1)
        {
            tempOrg = world->WhatIsOnBoard(Point(x+1,y));
        }

        if(tempOrg != nullptr)
        {
            world->DelOrganism(tempOrg);
            Commentator::AddComment("Human's purification is killing "+tempOrg->OrganismTypeToString());
        }
    }
}

bool Human::Ability::GetCanActivate()
{
    return CanActivate;
}

int Human::Ability::GetCooldown()
{
    return cooldown;
}

void Human::Ability::SetCanActivate(bool CanActivate)
{
    this->CanActivate = CanActivate;
}

void Human::Ability::SetCooldown(int cooldown)
{
    this->cooldown = cooldown;
}

Human::Ability* Human::GetAbility()
{
    return ability;
}

void Human::Ability::Activate()
{
    if(cooldown==0)
    {
        CanActivate = false;
        cooldown = SKILL_COOLDOWN;
    }
    else if(cooldown > 0)
    {
        cout<<"You have to wait "<<cooldown<<" rounds to activate purification\n";
    }
}

Point Human::PlanMove()
{
    int x = position.GetX();
    int y = position.GetY();
    int maxX=world->GetSizeX();
    int maxY=world->GetSizeY();
    if(x == 0 && moveDirection == Direction::LEFT) return Point(x,y);
    else if(x == maxX - 1 && moveDirection == Direction::RIGHT) return Point(x,y);
    else if(y == maxY - 1 && moveDirection == Direction::DOWN) return Point(x,y);
    else if(y == 0 && moveDirection == Direction::UP) return Point(x,y);
    else if(moveDirection==Direction::UP) return Point(x,y-1);
    else if(moveDirection==Direction::DOWN) return Point(x,y+1);
    else if(moveDirection==Direction::LEFT) return Point(x-1,y);
    else if(moveDirection==Direction::RIGHT) return Point(x+1,y);
    else return Point(x,y);
}

Human::~Human() {}
