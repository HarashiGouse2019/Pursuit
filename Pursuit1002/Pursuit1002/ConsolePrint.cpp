//Include our user defined header file, as well as header files defined from C++
#include "ConsolePrint.h"
#include <iostream>
#include <string>

using namespace std; //Using the standard C++ library

//Create some preprocessors
#define BREAK cout << "-----------------------------------------------------------------------------------------------------------" << endl;

//Declaring our constructor
ConsolePrint::ConsolePrint(void) {};

//Displays Text on the Console
string ConsolePrint::DisplayText(string text) {

	string * ptrText = &text; //Create a pointer for our text

	cout << *ptrText << endl; //Print our parameter to the console

	return *ptrText; //Return our pointer

}

//Give us what this program is and how to use it
void ConsolePrint::GiveTutorial() {

	BREAK; //Create a line

	cout << "What you see here is a military simulation where you pursuit the enemy!" << endl;

	cout << "You have no idea where he is located, but given the right tools, I'm positive that you'll get the job done!" << endl;

	BREAK; //Create a line

	cout << "Move will arrow keys" << endl;

	cout << "Print your current position with <Space>" << endl;

	cout << "If you feel like it'll take long, you can change the amount of steps with <Return>... \nThe default is always 1 unit" << endl;

	BREAK; //Create a line


	cout << "The enemy himself will escape each time you find him, and the sector widens, making this a bit harder." << endl;

	cout << "Rely on the sounds given to you, however if you ever get closer to the enemy, the sound's frequency will lower, \nalso adding in the difficulty." << endl;

	cout << "Good luck!!!" << endl;

	BREAK; //Create a line
}

//A function that will ask for our names
string ConsolePrint::AskForName() {
	cout << "Give use your name private: "; cin >> name;
	return name;
}