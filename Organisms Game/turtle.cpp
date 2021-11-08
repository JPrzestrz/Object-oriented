#include "turtle.h"
#include "colors.h"
#include "commentator.h"

Turtle::Turtle(World* world, Point coord, int roundBorn)
	:Animal(OrganismType::TURTLE, world, coord, TURTLE_STRENGTH, TURTLE_INTIATIVE, roundBorn)
{
	this->ChanceOfMoving = TURTLE_CHANCEOFMOVE;
	this->colour = PURPLE;
	this->MoveDistance=TURTLE_MOVE_DISTANCE;
	this->symbol = TURTLE_SYMBOL;
}

bool Turtle::SpecialAttackSkill(Organism * attacker, Organism * defender)
{
	if(this == defender)
	{
		if(attacker->GetStrength() < 5 && attacker->IsAnimal() == true)
		{
			Commentator::AddComment(OrganismTypeToString()+ " reflected attack of " + attacker->OrganismTypeToString());
			return true;
		}
		else return false;
	}
	else if(this == attacker)
	{
		if(attacker->GetStrength()>= defender->GetStrength()) return false;
		else
		{
			if(defender->GetStrength() < 5 && defender->IsAnimal() == true)
			{
				Commentator::AddComment(OrganismTypeToString()+ " reflected attack of " + defender->OrganismTypeToString());
				return true;
			}
			else return false;
		}
	}
}

string Turtle::OrganismTypeToString()
{
	return "Turtle";
}

Turtle::~Turtle() {}