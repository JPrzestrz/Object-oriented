#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include "world.h"
#include "keys.h"

using namespace std;

#define SIZE 15

int main()
{
	srand(time(NULL));
	World* world;
	string ChooseWorld;
	while (true) {
		cout << "Choose L if you want to load game or N if you want to generate new world:\n";
		cin >> ChooseWorld;
		if (ChooseWorld == "N" || ChooseWorld == "n")
		{
			while(true){
			int sizex, sizey;
			cout << "Give size of world:\nx: ";
			cin >> sizex;
			cout << "y: ";
			cin >> sizey;
			if (sizex > 0 && sizey > 0)
			{
				world = new World(sizex, sizey);
				break;
			}
			}
            double percentage;
            cout << "Choose % of population 0-100:\n";
			cin>>percentage;
			percentage/=100;
            world->GenerateWorld(percentage);
			break;
		}
        else if(ChooseWorld == "L" || ChooseWorld == "l")
        {
            world = World::LoadWorld();
            break;
        }
	}
	cout << "START\npress any key...\n";
	_getch();
	world->Draw();
	while (world->GetHumanAlive() == true) {
		world->MakeRound();
	}
}