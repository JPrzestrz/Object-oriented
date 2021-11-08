#include "sowthistle.h"
#include "colors.h"

Sow::Sow(World *world, Point coord, int bornRound)
:Plant(OrganismType::GRASS,world,coord,SOW_STRENGTH,SOW_INITIATIVE,bornRound)
{
    this->colour=GREEN;
    this->symbol=SOW_SYMBOL;
}

void Sow::Action()
{
    for(int i=0;i<3;i++)
    {
        if(rand()%100>75) Sowing();
    }
}

string Sow::OrganismTypeToString()
{
	return "Sow Thistle";
}