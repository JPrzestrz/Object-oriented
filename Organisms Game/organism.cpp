#include "organism.h"
#include "colors.h"
#include <iostream>
#include <Windows.h>
HANDLE static color = GetStdHandle(STD_OUTPUT_HANDLE);

Organism::Organism(OrganismType typeOrg, World* world, Point coord, int strength, int initiative, int bornRound)
{
    this->typeOrg=typeOrg;
    this->world=world;
    this->strength=strength;
    this->initiative=initiative;
    this->bornRound=bornRound;
    dead=false;
}

Organism::~Organism()
{
    delete[] dir;
}

Point Organism::GetPosition()
{
	return Point(position.GetX(), position.GetY());
}

Point Organism::RollFreePosition(Point position)
{
    int X=position.GetX();
    int Y=position.GetY();
    int maxX=world->GetSizeX();
    int maxY=world->GetSizeY();
    int possibleDir[4]={1,1,1,1};
    if(Y==0 || world->IsOccupiedBoard(Point(X,Y-1)) == true) possibleDir[0]=0;
    if(Y==maxY - 1 || world->IsOccupiedBoard(Point(X,Y+1)) == true) possibleDir[1]=0;
    if(X==0 || world->IsOccupiedBoard(Point(X-1,Y)) == true) possibleDir[2]=0;
    if(X==maxX - 1 || world->IsOccupiedBoard(Point(X+1,Y)) == true) possibleDir[3]=0;
    int numDir=0;
    int goodDir=0;
    for(int i=0;i<4;i++)
    {
        if(possibleDir[i]==1)
            numDir++;
    }
    if(numDir==0)
       return Point(X,Y);
    while(goodDir!=1)
    {
        int random=rand()%100;
        if(random <25 && possibleDir[0]==1)
        {
           return Point(X,Y-1);
           goodDir=1;
        }
        else if(random <50 && possibleDir[1]==1)
        {
           return Point(X,Y+1);
           goodDir=1;
        }
        else if(random <75 && possibleDir[2]==1)
        {
           return Point(X-1,Y);
           goodDir=1;
        }
        else if(random <100 && possibleDir[3]==1)
        {
           return Point(X+1,Y);
           goodDir=1;
        }
    }
}

Point Organism::RollPosition(Point position)
{
    int X=position.GetX();
    int Y=position.GetY();
    int maxX=world->GetSizeX();
    int maxY=world->GetSizeY();
    int possibleDir[4]={1,1,1,1};
    int numDir=0;
    // 0 -> up | 1 -> down | 2 -> left | 3-> right
    if(Y==0) possibleDir[0]=0;
    if(Y==maxY - 1) possibleDir[1]=0;
    if(X==0) possibleDir[2]=0;
    if(X==maxX - 1) possibleDir[3]=0;
    int goodDir=0;
    for(int i=0;i<4;i++)
    {
        if(possibleDir[i]==1)
            numDir++;
    }
    if(numDir==0)
       return Point(X,Y);
    while(goodDir!=1)
    {
        int random=rand()%100;
        if(random <25 && possibleDir[0]==1)
        {
           return Point(X,Y-1);
           goodDir=1;
        }
        else if(random <50 && possibleDir[1]==1)
        {
           return Point(X,Y+1);
           goodDir=1;
        }
        else if(random <75 && possibleDir[2]==1)
        {
           return Point(X-1,Y);
           goodDir=1;
        }
        else if(random <100 && possibleDir[3]==1)
        {
           return Point(X+1,Y);
           goodDir=1;
        }
    }
}

Organism::OrganismType Organism::RandomType()
{
    int number = rand() % ALL_TYPES;
    if(number==0) return OrganismType::GRASS;
    else if(number==1) return OrganismType::SOW;
    else if(number==2) return OrganismType::GUARANA;
    else if(number==3) return OrganismType::BELLADONNA;
    else if(number==4) return OrganismType::SOSNOWSKYS_HOGWED;
    else if(number==5) return OrganismType::SHEEP;
    else if(number==6) return OrganismType::WOLF;
    else if(number==7) return OrganismType::FOX;
    else if(number==8) return OrganismType::TURTLE;
    else if(number==9) return OrganismType::ANTELOPE;
}

Organism::OrganismType Organism::GetOrgType()
{
    return typeOrg;
}

void Organism::SetPosition(int x, int y)
{
    position=Point(x,y);
}

void Organism::SetDeath(bool death)
{
    this->dead=death;
}

void Organism::SetStrength(int power)
{
    this->strength = power;
}

void Organism::MakeMove(Point nextPos)
{
    int x = nextPos.GetX();
    int y = nextPos.GetY();
    world->GetBoard()[position.GetY()][position.GetX()] = nullptr;
    world->GetBoard()[y][x] = this;
    position.SetX(x);
    position.SetY(y);
    this->SetPosition(x,y);
}

bool Organism::SpecialAttackSkill(Organism * attacker, Organism * defender)
{
    return false;
}

bool Organism::GetDeath()
{
    return dead;
}

bool Organism::GetDidMultiply()
{
    return DidMultiply;
}

void Organism::SetDidMultiply(bool DidMult)
{
    this->DidMultiply=DidMult;
}

void Organism::SetBirth(int birth)
{
    this->bornRound=birth;
}

int Organism::GetStrength()
{
    return strength;
}

int Organism::GetInitiative()
{
    return initiative;
}

int Organism::GetBirth()
{
    return bornRound;
}

int Organism::GetColor()
{
    return colour;
}

char Organism::GetSymbol()
{
    return symbol;
}