#ifndef NAVI
#define NAVI

//This is my Navigation base class
class Navi
{
public:
	Navi(); //Our constructor
	virtual int ChangeUnitSize(int unit); //This method a virtual method since we'll have a child class handle this.
	virtual void GetPosition(int& x, int& y); //We also have this as a virtual method for another childe class to handle
};

#endif