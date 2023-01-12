#include "Cell.h"
#include "Forest.h"


#include <conio.h>


using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


Cell::Cell()
{
	this->state = 0; 
}

Cell::Cell(int state)
{ 
	this->state = state; 
}

int Cell::getState() 
{ 
	return this->state; 
}

void Cell::setState(int state)
{
	this->state = state;
}

void Cell::display(void)
{
	if (this->state == 0)
	{
		std::cout << "   ";
	}
	else if (this->state == 1)
	{
		SetConsoleTextAttribute(h, 10);
		std::cout << "  &";
	}
	else
	{
		SetConsoleTextAttribute(h, 12);
		std::cout << "  X";
	}
	
}



