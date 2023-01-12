#include "Forest.h"
#include "Cell.h"

Forest::Forest() 
{
	SetupArray();
}

Forest::~Forest()
{
}

void Forest::SetupArray()
{
    
	for (int x = 0; x < 21; x++) 
	{
		for (int y = 0; y < 21; y++) 
		{
			if (x == 0 || y == 0 || x == 20|| y == 20) 
			{
				forestArray[x][y] = new Cell(0);
			}
			else
			{
				forestArray[x][y] = new Cell(1);
			}
		}
	}
}

void Forest::initializeFire()
{
	forestArray[10][10]-> setState(2);
	return;
}

void Forest::simulation()
{
	for (int x = 0; x < 21; x++)
	{
		for (int y = 0; y < 21; y++) 
		{
			forestArray[x][y]->display();

		}
		cout << "\n";
	}
	return;
}

void Forest::reSimulation()
{
	// Random number generator
	srand(time(0));
	int cellTemp[21][21];

	// Store cells which have atleast 1 neigbhour as burning tree
	for (int x = 0; x < 21; x++)
	{
		for (int y = 0; y < 21; y++) 
		{
			cellTemp[x][y] = 0;
			if (forestArray[x][y]->getState() == 1)
			{
				int temp = 0;
				if (x > 1) 
				{
					if (forestArray[x - 1][y]->getState() == 2)
					{
						temp = 1;
					}
				}
				if (x < 19)
				{
					if (forestArray[x + 1][y]->getState() == 2)
					{
						temp = 1;
					}
				}
				if (y > 1) 
				{
					if (forestArray[x][y - 1]->getState() == 2) 
					{
						temp = 1;
					}
				}
				if (y < 19) 
				{
					if (forestArray[x][y + 1]->getState() == 2)
					{
						temp = 1;
					}
				}
				cellTemp[x][y] = temp;
			}
		}
	}

	// Leaves the burning tree empty
	for (int x = 0; x < 21; x++)
	{
		for (int y = 0; y < 21; y++)
		{
			if (forestArray[x][y]->getState() == 2)
			{
				forestArray[x][y]->setState(0);
			}
		}
	}

	

	// Creates a random probability to burn trees
	for (int x = 0; x < 21; x++) {
		for (int y = 0; y < 21; y++) 
		{
			if (cellTemp[x][y] == 1) 
			{
				int t = rand();
				if (t % 1000 < 500) 
				{
					
					forestArray[x][y]->setState(2);
				}
			}
		}
	}

	
	return;
}