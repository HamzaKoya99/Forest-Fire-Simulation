#include "Cell.h"
#include "Forest.h"

#include<iostream>
#include<time.h>
#include <string>
#include <windows.h>

using namespace std;

int main() 
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int temp;
	bool redraw = true;
	std::string input;

	Forest* forest = new Forest();
	forest->simulation();
	forest->initializeFire();

	SetConsoleTextAttribute(h, 15);
	cout << "Fire Starts at center of the cell\n";
	forest->simulation();

	 
	while (redraw)
	{
		SetConsoleTextAttribute(h, 15);
		std::cout << "Press Enter to continue | Press any other key and press Enter to Exit" << std::endl;
		
		std::getline(std::cin, input);

		if (input != "") redraw = false;
		
		else 
		{
			forest->simulation();
			forest->reSimulation();
		}
	}
	return 0;
}