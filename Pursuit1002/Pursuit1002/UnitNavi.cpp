//Include C++ defined header files
#include <iostream>
#include <string>


//Include UnitNavi header file
#include "UnitNavi.h"

using namespace std; //Use the standard C++ library

UnitNavi::UnitNavi(void) : Navi(){};

int UnitNavi::ChangeUnitSize(int unit) {
	int * ptr_unit = &unit; //Create a pointer for our unit

	int oldUnit, newUnit; //Create 2 variables, our old unit, and our new unit

	cout << "\nChange unit size: " << *ptr_unit << " >> "; /*Gather input*/cin >> newUnit;



	//If our input is not an integer, we give our unit our default value of 1

	if (cin.fail()) {

		cerr << "!!!INVALID INPUT!!!" << endl; //Invalid input!!!

		newUnit = 1; //Set to the default value

	}



	cin.clear(); cin.ignore(INT_MAX, '\n'); //Clear cin's stream buffer, and ignore any other stuff.

	oldUnit = *ptr_unit; //We assign our current unit to the oldUnit variable before updating our unit value

	*ptr_unit = newUnit; //Update our unit through our pointer

	cout << "\nYou set unit size from " << oldUnit << " >> " << newUnit; //Print out our changes

	return *ptr_unit; //Return our pointer
}