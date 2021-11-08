#include "fox.h"
#include "colors.h"

Fox::Fox(World* world, Point coord, int roundBorn)
	:Animal(OrganismType::FOX, world, coord, FOX_STRENGTH, FOX_INTIATIVE, roundBorn)
{
	this->ChanceOfMoving = FOX_CHANCEOFMOVE;
	this->MoveDistance=FOX_MOVE_DISTANCE;
	this->colour = PURPLE;
	this->symbol = FOX_SYMBOL;
}

Point Fox::RollPosition(Point place)
{
	int x = position.GetX();
	int y = position.GetY();
	int sizeX = world->GetSizeX();
	int sizeY = world->GetSizeY();
	// 0 -> up | 1 -> down | 2 -> left | 3-> right
	int possibleDir[4]={1,1,1,1};
    int numDir=0;
	int goodDir=0;
	Organism * tempOrg;
	if(x==0) possibleDir[2]=0;
	else 
	{
		tempOrg=world->GetBoard()[x-1][y];
		if(tempOrg!=nullptr && tempOrg->GetStrength() > this->strength)
		{
			possibleDir[2]=0;
		}
	}
	if(x==sizeX-1) possibleDir[3]=0;
	else 
	{
		tempOrg=world->GetBoard()[x+1][y];
		if(tempOrg!=nullptr && tempOrg->GetStrength() > this->strength)
		{
			possibleDir[3]=0;
		}
	}
	if(y==0) possibleDir[0]=0;
	else 
	{
		tempOrg=world->GetBoard()[x][y-1];
		if(tempOrg!=nullptr && tempOrg->GetStrength() > this->strength)
		{
			possibleDir[0]=0;
		}
	}
	if(y==sizeY-1) possibleDir[1]=0;
	else 
	{
		tempOrg=world->GetBoard()[x][y+1];
		if(tempOrg!=nullptr && tempOrg->GetStrength() > this->strength)
		{
			possibleDir[1]=0;
		}
	}

	for(int i=0;i<4;i++)
	{
		numDir++;
	}

	if(numDir==0) return Point(x,y);
	while(goodDir!=1)
    {
        int random=rand()%100;
        if(random <25 && possibleDir[0]==1)
        {
           return Point(x,y-1);
           goodDir=1;
        }
        else if(random <50 && possibleDir[1]==1)
        {
           return Point(x,y+1);
           goodDir=1;
        }
        else if(random <75 && possibleDir[2]==1)
        {
           return Point(x-1,y);
           goodDir=1;
        }
        else if(random <100 && possibleDir[3]==1)
        {
           return Point(x+1,y);
           goodDir=1;
        }
    }
}

string Fox::OrganismTypeToString()
{
	return "Fox";
}

Fox::~Fox(){}