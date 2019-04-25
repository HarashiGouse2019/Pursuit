#ifndef POSI_NAVI
#define POSI_NAVI

//Including our Navi header file
#include "Navi.h"

//This child of Navigation base class return a position
class PosiNavi : public Navi {
public:
	PosiNavi(); //Our contructor
	void GetPosition(int& x, int& y); //Our GetPosition function which is derived from Navi
};

#endif