#include "hogwed.h"
#include "colors.h"
#include "commentator.h"

Hogwed::Hogwed(World *world, Point coord, int bornRound)
:Plant(OrganismType::SOSNOWSKYS_HOGWED,world,coord,HOGWED_STRENGTH,HOGWED_INITIATIVE,bornRound)
{
    this->colour=GREEN;
    this->symbol=HOGWED_SYMBOL;
}

void Hogwed::Action()
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
            Commentator::AddComment(OrganismTypeToString()+ " killed "+tempOrg->OrganismTypeToString());
        }
    }
    if(rand()%100 < 10) Sowing();
}

bool Hogwed::SpecialAttackSkill(Organism * attacker, Organism * defender)
{
    world->DelOrganism(this);
    Commentator::AddComment(attacker->OrganismTypeToString()+" ate " + this->OrganismTypeToString());
    world->DelOrganism(attacker);
    Commentator::AddComment(this->OrganismTypeToString()+ " killed " + attacker->OrganismTypeToString());
    return true;
}

string Hogwed::OrganismTypeToString()
{
	return "Sosnowsky's Hogweed";
}