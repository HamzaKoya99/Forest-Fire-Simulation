
#ifndef CellH
#define CellH

#include <string>
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Cell
{
	
private:
	int state;
public:
	
	Cell();
	Cell(int state);
	int getState();
	void setState(int state);
	void display(void);

};




#endif // !Cell_H

