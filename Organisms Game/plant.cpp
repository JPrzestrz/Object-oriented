#include "plant.h"
#include "organismcreator.h"

Plant::Plant(OrganismType typeOrg, World *world, Point coord,int strength, int initiative, int bornRound)
:Organism(typeOrg,world,coord,strength,initiative,bornRound)
{
}

void Plant::Action()
{
    if(rand() % 100 > 85) Sowing();
}

void Plant::Collision(Organism *other) 
{
}

void Plant::Sowing()
{
    Point tempPoint = this->RollFreePosition(position);
    if(tempPoint == position) return;
    else {
        Organism* tempOrg = OrganismCreator::CreateNewOrganism(typeOrg,this->world,tempPoint);
        tempOrg->SetPosition(tempPoint.GetX(),tempPoint.GetY());
        world->AddOrganism(tempOrg);
        Commentator::AddComment("New plant " + tempOrg->OrganismTypeToString() + " is growing on pos: (" +
        to_string(tempPoint.GetX()) + "," + to_string(tempPoint.GetY()) +")");
    }
}

bool Plant::IsAnimal()
{
    return false;
}

Plant::~Plant() {}