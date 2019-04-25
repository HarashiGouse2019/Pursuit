/****************************************************************************************************************************************************************
*														WELCOME TO THE GAME OF PURSUIT!!!!																		*
*																																								*
*										This is the first program where I've actually used pointers in my code.													*
*										I honestly didn't know what I should write a program of at first, until													*
*										this idea happened.																										*
*																																								*
*										Putting together my current knowledge of C++, I created a simple console												*
*										where you are given a coordinate, and you go to it based on sound.														*
*																																								*
*										It actually get's harder when you get closer, for you can barely hear													*
*										anything. With that, you have to take smaller steps.																	*
*																																								*
*										You can play this game for as long as you like until you are satisfied.													*
****************************************************************************************************************************************************************/


//Using C++ defined header files
#include <iostream>

#include <string>

#include <cmath>

#include <time.h>

#include <conio.h>

#include <cstdlib>

#include <windows.h>

#include <algorithm>

//include user header files
#include "ConsolePrint.h"
#include "PosiNavi.h"
#include "UnitNavi.h"
#include "Sim.h"


using namespace std; //using the standard library

//Our Main Function

int main(int argc, char** argv[]) {

	ConsolePrint print;
	
	srand(time(NULL)); //Create our random seed;

	print.DisplayText("Welcome Comrade!!!");

	string name;
	name = print.AskForName(); //We'll use a function to get input from the user.

	print.DisplayText("Well, it's good to have you here" + name); //Tell us that it is nice to meet us!!!

	print.GiveTutorial(); //Print out our tutorial

	print.DisplayText("There's an enemy somewhere on the sector, " + name);

	print.DisplayText("Pursuit him!!!");

	Sim * simulation = new Sim(); //We create a new object called simulation

	simulation->Start(); //We access and run the Start method;

	return 0; //Return code 0, which signifies the program ran successfully.
}