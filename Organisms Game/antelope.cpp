#include "antelope.h"
#include "colors.h"
#include "commentator.h"

Antelope::Antelope(World* world, Point coord, int roundBorn)
	:Animal(OrganismType::ANTELOPE, world, coord, ANTELOPE_STRENGTH, ANTELOPE_INTIATIVE, roundBorn)
{
	this->ChanceOfMoving = ANTELOPE_CHANCEOFMOVE;
	this->MoveDistance=ANTELOPE_MOVE_DISTANCE;
	this->colour = PURPLE;
	this->symbol = ANTELOPE_SYMBOL;
}

bool Antelope::SpecialAttackSkill(Organism * attacker, Organism * defender)
{
	if(rand()%100 < 50)
	{
		if(this==attacker)
		{
			Commentator::AddComment(OrganismTypeToString()+" run away from " + defender->OrganismTypeToString());
			MakeMove(RollFreePosition(defender->GetPosition()));
		}
		else if(this == defender)
		{
			Commentator::AddComment(OrganismTypeToString()+" run away from " + attacker->OrganismTypeToString());
			Point tempPos = this->position;
			MakeMove(RollFreePosition(this->position));
			if(position == tempPos) {
				world->DelOrganism(this);
				Commentator::AddComment(attacker->OrganismTypeToString()+" killed "+ OrganismTypeToString());
			}
			attacker->MakeMove(tempPos);
		}
		return true;
	}
	else 
	{
		return false;
	}
}

string Antelope::OrganismTypeToString()
{
	return "Antelope";
}

Antelope::~Antelope() {}