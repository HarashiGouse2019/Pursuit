#pragma once
#include <iostream>

#include <string>

#include <cmath>

#include <time.h>

#include <conio.h>

#include <cstdlib>

#include <windows.h>

#include <algorithm>

using namespace std;

//We'll make a class that'll handle the entire simulation
class Sim {
public:
	Sim(); //Our constructor
	void Start(); //And a start method
};

//We'll also include a Sector class...
class Sector {
public:
	Sector();
	unsigned int sectorSize = 10; //The Default Sector Size

	const unsigned int height = sectorSize; //The height of the sector

	const unsigned int width = sectorSize; //The width of the sector
};

//And an enemy class for the simulation
class Enemy {
public:
	Enemy();

	Sector sector; //Create a instance of our Sector class

	int coord_x = rand() % sector.sectorSize; //Give the enemy a random x coordinate based from the sectorSize

	int coord_y = rand() % sector.sectorSize; //Give the enemy a random y coordinate based from the sectorSizes
};