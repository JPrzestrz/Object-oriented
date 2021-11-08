#include "organismcreator.h"

Organism* OrganismCreator::CreateNewOrganism(Organism::OrganismType typeOrg, World* world, Point coord)
{
    switch(typeOrg){
        case Organism::OrganismType::HUMAN: return new Human(world,coord,world->GetRound());
        // plants
        case Organism::OrganismType::GRASS: return new Grass(world,coord,world->GetRound());
        case Organism::OrganismType::SOW: return new Sow(world,coord,world->GetRound());
        case Organism::OrganismType::GUARANA: return new Guarana(world,coord,world->GetRound());
        case Organism::OrganismType::BELLADONNA: return new Belladonna(world,coord,world->GetRound());
        case Organism::OrganismType::SOSNOWSKYS_HOGWED: return new Hogwed(world,coord,world->GetRound());
        // animals
        case Organism::OrganismType::SHEEP: return new Sheep(world, coord,world->GetRound());
        case Organism::OrganismType::WOLF: return new Wolf(world, coord,world->GetRound());
        case Organism::OrganismType::FOX: return new Fox(world, coord,world->GetRound());
        case Organism::OrganismType::TURTLE: return new Turtle(world, coord,world->GetRound());
        case Organism::OrganismType::ANTELOPE: return new Antelope(world, coord,world->GetRound());

        default: return nullptr;
    }
}