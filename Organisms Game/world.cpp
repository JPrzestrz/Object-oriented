#include "world.h"
#include "colors.h"
#include "organismcreator.h"
#include "keys.h"
#include <algorithm>
#include <Windows.h>
#include <tuple>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <math.h>
HANDLE static color = GetStdHandle(STD_OUTPUT_HANDLE);

#define BORDER 1

World::World(int SizeX, int SizeY)
{
    this->SizeX=SizeX;
    this->SizeY=SizeY;
    cout<<"Created world of size: "<<SizeX<<"x"<<SizeY<<endl;
    round=1;
    board= new Organism **[SizeY];
    HumanAlive=true;
    for(int i=0;i<SizeY;i++)
        board[i]=new Organism * [SizeY];
    for(int i=0;i<SizeY;i++)
    {
        for(int j=0;j<SizeX;j++)
            board[i][j]=nullptr;
    }
}

World::World(World&& other)
{
    this->SizeX=other.SizeX;
    this->SizeY=other.SizeY;
    this->round=other.round;
    this->board=other.board;
    this->HumanAlive=other.HumanAlive;
    this->organisms=other.organisms;
    this->human=other.human;
}

World::~World() {
	for (int i = 0; i < SizeY; i++) {
		delete[] board[i];
	}
	delete board;
}

void World::SaveWorld()
{
    ofstream fout;
    string fileName;
    string tempType;
    cout<<"\nGive name of file that you want to save file to (without extension)\n";
    cin>>fileName;
    fileName+=".txt";
    fout.open(fileName, ofstream::app);
    if(!fout.is_open()) cout<<"Error in saving!\n";
    else
    {
        fout<<SizeX;
        fout<<" ";
        fout<<SizeY;
        fout<<" ";
        fout<<round;
        fout<<" ";
        fout<<HumanAlive<<"\n";
        
        for(int i=0;i<organisms.size();i++)
        {
            fout<<(int)organisms[i]->GetOrgType()<<" ";
            fout<<organisms[i]->GetPosition().GetX()<<" ";
            fout<<organisms[i]->GetPosition().GetY()<<" ";
            fout<<organisms[i]->GetStrength()<<" ";
            fout<<organisms[i]->GetBirth()<<" ";
            fout<<organisms[i]->GetDeath()<<" ";
            if(organisms[i]->GetOrgType()== Organism::OrganismType::HUMAN)
            {
                fout<<human->GetAbility()->GetCooldown()<<" ";
                fout<<human->GetAbility()->GetCanActivate()<<" ";
            }
            fout<<"\n";
        }
        cout<<"World has been saved!\n";
    }
}

World* World::LoadWorld()
{
    ifstream in_file;
    string fileName;
    cout<<"Give name of file you want to load (without extension)\n";
    cin>>fileName;
    fileName+=".txt";
    in_file.open(fileName);
    if(!in_file.is_open()) cout<<"Error in loading!\n";
    else
    {
        int tempType;
        int tempNum;
        int x;
        int y;
        in_file>>x;
        in_file>>y;
        World* tempWorld = new World(x,y);
        in_file>>tempWorld->round;
        int temp;
        in_file>>temp;
        tempWorld->HumanAlive = (bool)temp;
        tempWorld->human=nullptr;
        Organism * tempOrg = nullptr;
        while(!in_file.eof())
        {
            int x;
            int y;
            in_file>>tempType;
            in_file>>x;
            in_file>>y;
            tempOrg=OrganismCreator::CreateNewOrganism((Organism::OrganismType)tempType,tempWorld,Point(x,y));
            tempOrg->SetPosition(x,y);
            in_file>>tempNum;
            tempOrg->SetStrength(tempNum);
            in_file>>tempNum;
            tempOrg->SetBirth(tempNum);
            in_file>>tempNum;
            tempOrg->SetDeath((bool)tempNum);
            if(tempType==(int)Organism::OrganismType::HUMAN)
            {
                tempWorld->human = (Human*)tempOrg;
                in_file>>tempNum;
                tempWorld->human->GetAbility()->SetCooldown(tempNum);
                in_file>>tempNum;
                tempWorld->human->GetAbility()->SetCanActivate(tempNum);
            }
            tempWorld->AddOrganism(tempOrg);
        }
        return tempWorld;
    }
}

bool World::IsOccupiedBoard(Point place)
{
    if(board[place.GetY()][place.GetX()]==nullptr) return false;
    else return true;
}

bool World::GetHumanAlive()
{
    return HumanAlive;
}

void World::GenerateWorld(double percentage)
{
    int orgCount=floor(SizeY*SizeY*percentage);
    Point where = GetRandomPoint();
    Organism* tempOrg = OrganismCreator::CreateNewOrganism(Organism::OrganismType::HUMAN,this,where);
    tempOrg->SetPosition(where.GetX(),where.GetY());
    // test output
    //cout<<"Added Human on pos ("<<where.GetX()<<","<<where.GetY()<<")\n";
    //cout<<"Check: ("<<tempOrg->GetPosition().GetX()<<","<<tempOrg->GetPosition().GetY()<<")\n";
    AddOrganism(tempOrg);
    human=(Human*)tempOrg;
    for(int i=0;i<orgCount-1;i++)
    {
        Point where = GetRandomPoint();
        Organism* tempOrg = OrganismCreator::CreateNewOrganism(Organism::RandomType(),this,where);
        tempOrg->SetPosition(where.GetX(),where.GetY());
        // test output
        //cout<<"Added organism on pos ("<<where.GetX()<<","<<where.GetY()<<")\n";
        //cout<<"Check: ("<<tempOrg->GetPosition().GetX()<<","<<tempOrg->GetPosition().GetY()<<")\n";
        AddOrganism(tempOrg);
    }
}

void World::AddOrganism(Organism * organism)
{
    organisms.push_back(organism);
    board[organism->GetPosition().GetY()][organism->GetPosition().GetX()]=organism;
}

void World::DelOrganism(Organism * organism)
{
    GetBoard()[organism->GetPosition().GetY()][organism->GetPosition().GetX()] = nullptr;
    organism->SetDeath(true);
    if(organism->GetOrgType()==Organism::OrganismType::HUMAN)
    {
        HumanAlive=false;
        human=nullptr;
    }
}

void World::Draw()
{
    system("cls");
    SetConsoleTextAttribute(color, YELLOW);
    cout<<"s184850 Jakub Przestrzelski\n";
    SetConsoleTextAttribute(color, LBLUE);
    cout<<"Round "<<round<<" !\n";
    for(int i=0;i<SizeX+1;i++)
    {
        SetConsoleTextAttribute(color, GRAY);
        cout<<"##";
    }
    cout<<endl;
    for(int i=0;i<SizeY;i++)
    {
        SetConsoleTextAttribute(color, GRAY);
        cout<<"#";
        SetConsoleTextAttribute(color, WHITE);
        for(int j=0;j<SizeX;j++)
        {
            if(board[i][j]==nullptr)
                cout<<". ";
            else
            {
                SetConsoleTextAttribute(color, board[i][j]->GetColor());
                cout<<board[i][j]->GetSymbol()<<" ";
                SetConsoleTextAttribute(color, WHITE);
            }

        }
        SetConsoleTextAttribute(color, GRAY);
        cout<<"#\n";
        SetConsoleTextAttribute(color, WHITE);
    }
    for(int i=0;i<SizeX+1;i++)
    {
        SetConsoleTextAttribute(color, GRAY);
        cout<<"##";
    }
    SetConsoleTextAttribute(color, WHITE);
    cout<<"\nesc - exit game\narrows - human moving\nr - activate human's ability\ns - save world\n";
    for(int i=0;i<SizeX+1;i++)
    {
        SetConsoleTextAttribute(color, GRAY);
        cout<<"##";
    }
    SetConsoleTextAttribute(color, WHITE);
    cout<<endl;
    Commentator::Comment();
}

void World::MakeRound()
{
    Commentator::ClearComment();
    SortOrganisms();
    InputSelect();
    if( HumanAlive == false) return;
    round++;
    Draw();
    for(size_t i = 0; i< organisms.size();i++)
    {
        if(organisms[i]->GetDeath()==true) { continue; }
        else if ( organisms[i]->GetBirth()!=round)
        {
            organisms[i]->Action();
            Draw();
        }
    }

    for(size_t i =0;i<organisms.size();i++)
    {
        if(organisms[i]->GetDeath() == true)
        {
            delete organisms[i];
            organisms.erase(organisms.begin()+i);
        }
    }
    for(size_t i = 0;i<organisms.size();i++)
    {
        organisms[i]->SetDidMultiply(false);
    }
}

void World::SortOrganisms()
{
    sort(organisms.begin(), organisms.end(),
		[](Organism* temp1, Organism* temp2) {
			int tini1 = temp1->GetInitiative();
			int tini2 = temp2->GetInitiative();
			int born1 = temp1->GetBirth();
			int born2 = temp2->GetBirth();
			return tie(tini2, born1) < tie(tini1, born2);
		});
}

void World::SetHumanAlive(bool HumanAlive)
{
    this->HumanAlive = false;
}

void World::InputSelect()
{
    cout<<"\nchoose action...";
    int input;
    while(true){
    input=_getch();
    if(input==ARROWS){

        if(HumanAlive)
        {
            input=_getch();
            if (input == K_UP) {
                human->SetMoveDirection(Organism::Direction::UP);
                break;
			}
            else if (input == K_DOWN) {
                human->SetMoveDirection(Organism::Direction::DOWN);
                break;
            }
            else if (input == K_RIGHT) {
                human->SetMoveDirection(Organism::Direction::RIGHT);
                break;
            }
            else if (input == K_LEFT) {
                human->SetMoveDirection(Organism::Direction::LEFT);
                break;
            }
        }
        else{
            cout<<"Human is dead\n";
            _getch();
        }
    }
    else if (input==END)
    {
        SetHumanAlive(false);
        break;
    }
    else if (input==K_ABILITY)
    {
        Human::Ability* tempAbility = human->GetAbility();
        if(tempAbility->GetCanActivate()==true)
        {
            tempAbility->Activate();
            human->SetMoveDirection(Organism::Direction::SAME);
            human->Action();
            Draw();
        }
    }
    else if(input == K_SAVE)
    {
        cout<<"go save!:";
        SaveWorld();
    }
    }
}

int World::GetRound()
{
    return round;
}

int World::GetSizeX()
{
    return SizeX;
}

int World::GetSizeY()
{
    return SizeY;
}

Organism* World::WhatIsOnBoard(Point place)
{
    return board[place.GetY()][place.GetX()];
}

Organism* World::GetHuman()
{
    return human;
}

Organism*** World::GetBoard()
{
    return board;
}

Point World::GetRandomPoint()
{
    for (int i = 0; i < SizeY; i++) 
    {
		for (int j = 0; j < SizeX; j++) 
        {
			if (board[i][j] == nullptr) 
            {
				while (true)
                 {
					int x = rand() % SizeX;
					int y = rand() % SizeY;
					if (board[y][x] == nullptr) return Point(x, y);
				}
			}
		}
	}
    return Point(-1,-1);
}