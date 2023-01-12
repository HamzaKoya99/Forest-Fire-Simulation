#pragma once
#ifndef ForestH
#define ForestH

#include "Cell.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <windows.h>


using namespace std;

class Forest
{
private:
	Cell* forestArray[21][21];
   

public: 
	Forest();
	~Forest();
	void SetupArray();
	void initializeFire();
	void simulation();
	void reSimulation();
};

#endif // !ForestH
