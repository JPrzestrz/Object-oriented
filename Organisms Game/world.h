#pragma once
#include <iostream>
#include <vector> 
#include "organism.h"
#include "point.h"

using namespace std;

class Organism;
class Human;

class World
{
protected:
    int SizeX, SizeY;
    int round;
    bool HumanAlive;
    Organism*** board;
    vector<Organism*> organisms;
    Human* human;
    void SortOrganisms();
public:
    World(int SIZEX, int SIZEY);
    World();
    World(World&& other);
    ~World();
    static World* LoadWorld();
    void SaveWorld();
    bool IsOccupiedBoard(Point place);
    void GenerateWorld(double percentage);
    void AddOrganism(Organism* organism);
    void DelOrganism(Organism* organism);
    void Draw();
    void InputSelect();
    void SetHumanAlive(bool HumanAlive);
    void MakeRound();
    int GetRound();
    int GetSizeX();
    int GetSizeY();
    bool GetHumanAlive();
    Point GetRandomPoint();
    Organism* WhatIsOnBoard(Point place);
    Organism* GetHuman();
    Organism*** GetBoard();


};