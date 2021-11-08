#include "belladonna.h"
#include "colors.h"
#include "commentator.h"

Belladonna::Belladonna(World *world, Point coord, int bornRound)
:Plant(OrganismType::BELLADONNA,world,coord,BELLADONNA_STRENGTH,BELLADONNA_INITIATIVE,bornRound)
{
    this->colour=GREEN;
    this->symbol=BELLADONNA_SYMBOL;
}

bool Belladonna::SpecialAttackSkill(Organism * attacker, Organism * defender)
{
    Commentator::AddComment(attacker->OrganismTypeToString()+" ate " + this->OrganismTypeToString());
    if(attacker->IsAnimal()==true)
    {
        world->DelOrganism(attacker);
        Commentator::AddComment(attacker->OrganismTypeToString()+" died from eating belladonna");
    }
    return true;
}

string Belladonna::OrganismTypeToString()
{
	return "Belladonna";
}