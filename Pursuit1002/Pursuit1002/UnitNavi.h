#ifndef UNIT_NAVI
#define UNIT_NAVI

//Including our Navi header file
#include "Navi.h"

//This child of base Navigation class allow how far we're able to step/move
class UnitNavi : public Navi {
public:
	UnitNavi(); //Our contructor
	int ChangeUnitSize(int unit); //And our method.
};

#endif