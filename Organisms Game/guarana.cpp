#include "guarana.h"
#include "colors.h"
#include "commentator.h"

Guarana::Guarana(World *world, Point coord, int bornRound)
:Plant(OrganismType::GUARANA,world,coord,GUARANA_STRENGTH,GUARANA_INITIATIVE,bornRound)
{
    this->colour=GREEN;
    this->symbol=GUARANA_SYMBOL;
}

string Guarana::OrganismTypeToString()
{
	return "Guarana";
}

bool Guarana::SpecialAttackSkill(Organism * attacker, Organism * defender)
{
    Point tempPos = this->position;
    world->DelOrganism(this);
    attacker->MakeMove(tempPos);
    Commentator::AddComment(attacker->OrganismTypeToString()+" ate " + this->OrganismTypeToString()+ " and increased his strength by " + to_string(ADD_STRENGTH));
    attacker->SetStrength(attacker->GetStrength()+ADD_STRENGTH);
    return true;
}