#pragma once
#include <string>
#include "world.h"
#include "point.h"

using namespace std;
#define ALL_TYPES 10

class World;
class Point;

class Organism
{
public:
    enum class OrganismType
    { 
        HUMAN,
        //plants
        GRASS,
        SOW,
        GUARANA,
        BELLADONNA,
        SOSNOWSKYS_HOGWED,
        // animals
        WOLF,
        SHEEP,
        FOX,
        TURTLE,
        ANTELOPE
    };
    enum class Direction
    {
        UP,
        DOWN,
        RIGHT,
        LEFT,
        SAME
    };

    virtual ~Organism();
    virtual void Action() = 0;
    virtual void Collision(Organism *other) = 0;
    virtual bool IsAnimal() = 0;
    virtual bool SpecialAttackSkill(Organism * attacker, Organism * defender);
    virtual string OrganismTypeToString() = 0;
    static OrganismType RandomType();
    Point GetPosition();
    string OrganismToString();
    OrganismType GetOrgType();
    virtual Point RollFreePosition(Point coord);
    virtual Point RollPosition(Point coord);

    void SetPosition(int x, int y);
    void SetDeath(bool dead);
    void MakeMove(Point nextPos);
    void SetDidMultiply(bool DidMult);
    void SetStrength(int power);
    void SetBirth(int birth);
    bool GetDeath();
    bool GetDidMultiply();
    char GetSymbol();
    int GetStrength();
    int GetColor();
    int GetInitiative(); 
    int GetBirth();
protected:
    int strength;
    int initiative;
    int bornRound;
    int colour;
    bool dead;
    bool DidMultiply;
    bool*  dir;
    char symbol;
    Point position;
    World* world;
    OrganismType typeOrg;
    Organism(OrganismType typeOrg, World* world, Point coord,int strength, int initiative, int bornRound);
};