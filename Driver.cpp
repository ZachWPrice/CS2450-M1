#include <cassert>   // Provides assert
#include <cstdlib>   // Provides NULL, std::size_t
#include <iostream>  // Provides std::cout
#include <iomanip>   // Provides std::setw
#include <algorithm> // Provides std::max
#include <string>	 // Provides string
#include <fstream>   // Provides ifstream
#include "ExeCom.h"
#include "Decoder.h"
using namespace std;

const int MEMORY = 100;

int main()
{
	int accumulator = 0;
	int testArray[MEMORY];
	
	for (int i = 0; i < MEMORY; i++) // initialize array of zeros
	{
		testArray[i] = 0;
	}

	testArray[0] = 1050; //Read to 50
	testArray[1] = 2050; //Load from 50
	testArray[2] = 1051; //Read to 51
	testArray[3] = 3051; //Add 51 to accum
	testArray[4] = 2152; //store to 52
	testArray[5] = 1150; //Write 50
	testArray[6] = 1151; //Write 51
	testArray[7] = 1152; //Write 52
	testArray[8] = 4300; //Halt

	Decoder(testArray, accumulator);

	system("pause");
	return 0;
}