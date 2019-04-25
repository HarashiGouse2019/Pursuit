//Include our C++ define header files

#include <iostream>

#include <string>

#include <cmath>

#include <time.h>

#include <conio.h>

#include <cstdlib>

#include <windows.h>

#include <algorithm>

//Along with our user defined headers that we've created

#include "Sim.h"

#include "Navi.h"

#include "UnitNavi.h"

#include "PosiNavi.h"

#include "ConsolePrint.h"

using namespace std; //Using the standard C++ library

// Creates a line

#define BREAK cout << "-----------------------------------------------------------------------------------------------------------" << endl;

#define KEY_UP 0x48 //ASCII CODE (72) FOR THE UP KEY

#define KEY_DOWN 0x50 //ASCII CODE (80) FOR THE DOWN KEY

#define KEY_LEFT 0x4B //ASCII CODE (75) FOR THE LEFT KEY

#define KEY_RIGHT 0x4D //ASCII CODE (77) FOR THE RIGHT KEY

#define SPACE 0x20 //ASCII CODE (32) FOR THE SPACE BAR

#define RETURN 0x0D //ASCII CODE (13) FOR THE ENTER/RETURN KEY

#define ALT_UNIT Beep(0x03E8, 0x32); Beep(0x03E8, 0x32); //BEEPS TWO TIMES WITH A FREQUENCY OF 1000 AND A DURATION OF 50 MILLISECONDS

#define SHOW_POS Beep(0x1F4, 0x32); Beep(0x1F4, 0x32); //BEEPS TWOS TIME WITH A FREQUENCY OF 500 AND A DURATION OF 50 MILLISECONDS

#define MATCH Beep(0x7D0, 0xC8); //BEEPS ONE TIME WITH A FREQUENCY OF 2000 AND A DURATION OF 200 MILLISECONDS

//Create our Sim constructor
Sim::Sim(void) {};

void Sim::Start() {

	int unitSize = 1; //Initialize unitSize, and give it a value of 1;

	ConsolePrint print; //We create our ConsolePrint object for our simulation

	Navi * unitNavigation = new UnitNavi(); //We'll also creat new child objects that derive from the Navi class
	Navi * positionTracker = new PosiNavi();

	Sector sector; //Create our sector.

	Enemy enemy; //Create an instance of our Enemy class

	//Our person spawns at the center of our sector

	int coord_x = sector.height / 2;

	int coord_y = sector.width / 2;


	//Then we create pointers to our coordinate!

	int * ptrx = &coord_x;

	int * ptry = &coord_y;

	bool MATCH_X = false; //Set a boolean to check if our x coordinates match

	bool MATCH_Y = false; //Set a boolean to check if our y coordinates match

	bool gameOn = true;

	do {

		//The Actual Movement Begins

		int c = 0; //Initialize c to toggle from 0 to 1 when we send input

		while (1)

		{

			c = 0;

			//We set if the input value is true through a switch...case statement

			switch ((c = _getch())) {

			case KEY_UP:

				MATCH_Y = false; //Y coordinates don't match

				system("CLS"); //Clear the console

				cout << "--- CURRENTLY IN PURSUIT---" << endl; //Print out CURRENTLY IN PURSUIT

				*ptry += unitSize; //MoveUp

				Beep(((max(*ptry, enemy.coord_y) - min(*ptry, enemy.coord_y)) % 0x7FFF), 0x64); //Send a sound to let us know that we are getting closer

				break;



			case KEY_DOWN:

				MATCH_Y = false; //Y coordinates don't match

				system("CLS"); //Clear the console

				cout << "--- CURRENTLY IN PURSUIT---" << endl; //Print out CURRENTLY IN PURSUIT

				*ptry -= unitSize; //MoveDown

				Beep(((max(*ptry, enemy.coord_y) - min(*ptry, enemy.coord_y)) % 0x7FFF), 0x64); //Send a sound to let us know that we are getting closer

				break;



			case KEY_LEFT:

				MATCH_X = false; //X coordinates don't match

				system("CLS"); //Clear the console

				cout << "--- CURRENTLY IN PURSUIT---" << endl; //Print out CURRENTLY IN PURSUIT

				*ptrx -= unitSize; //MoveLeft

				Beep(((max(*ptrx, enemy.coord_x) - min(*ptrx, enemy.coord_x)) % 0x7FFF), 0x64); //Send a sound to let us know that we are getting closer

				break;



			case KEY_RIGHT:

				MATCH_X = false; //X coordinates don't match

				system("CLS"); //Clear the console

				cout << "--- CURRENTLY IN PURSUIT---" << endl; //Print out CURRENTLY IN PURSUIT

				*ptrx += unitSize; //MoveRight

				Beep(((max(*ptrx, enemy.coord_x) - min(*ptrx, enemy.coord_x)) % 0x7FFF), 0x64); //Send a sound to let us know that we are getting closer

				break;



			case SPACE:

				system("CLS"); //Clear the console

				SHOW_POS; //Beep 2 times to get our current position

				cout << "\nCurrent Position: "; //Print out

				positionTracker->GetPosition(*ptrx, *ptry);      //our current position

				break;



			case RETURN:

				system("CLS"); //Clear Console

				ALT_UNIT; //Beep 2 time to allow us to change our unit

				unitSize = unitNavigation->ChangeUnitSize(unitSize); //Gather input

				break;



			default:

				cout << endl << "\b" << endl;  //Backspace

				break;



			}



			//If the x coordinates match

			if (MATCH_X == false) {

				if (*ptrx == enemy.coord_x) {

					MATCH; //Make a noise

					MATCH_X = true; //Set MATCH_X to TRUE

				}

				else {

					MATCH_X = false; //Set MATCH_X to FALSE

				}

			}

			//If the y coordinates match

			if (MATCH_Y == false) {

				if (*ptry == enemy.coord_y) {

					MATCH; //Make a noise

					MATCH_Y = true; //SET MATCH_Y to TRUE

				}

				else {

					MATCH_Y = false; //SET MATCH_Y to FALSE

				}

			}



			//If both x and y coordinates are matching

			if (*ptrx == enemy.coord_x && *ptry == enemy.coord_y) {

				if (sector.sectorSize == 10000) {

					system("CLS"); //Clear our console.

					cout << "---!!!PURSUIT COMPLETE!!!---" << endl; //Print out that we have completed our pursuit!!!

					print.DisplayText("You've done it comrade!!!"); //Tell us that we have done well

					print.DisplayText("Great Work!!!"); //Great work

					gameOn = false; //set our bool to false, breaking our of the while loop

					system("pause"); //Pause the application
				}

				else {

					MATCH; MATCH_X = false; MATCH_Y = false; //Make a noise and set both MATCH_X, and MATCH_Y to FALSE

					sector.sectorSize *= 10; //Sector is times 10 every time we find the enemy

					print.DisplayText("You found out that the enemy located at coordinates: "); /*Grab the enemy's coordinate. This will only be displayed once*/ positionTracker->GetPosition(enemy.coord_x, enemy.coord_y);

					enemy.coord_x = rand() % sector.sectorSize; //Regenerate a new location on the x coordinate

					enemy.coord_y = rand() % sector.sectorSize; //Regenerate a new location on the y coordinate

					print.DisplayText("He spots you, and runs away!!!"); //A message to use

					print.DisplayText("Continue the pursuit!!!"); //Continue the pursuit

				}

			}

		}

	} while (gameOn);
	return quick_exit(EXIT_SUCCESS);
}

//Our contructors, which didn't need to be used.
Sector::Sector(void) {

}

Enemy::Enemy(void) {

}