#include <cassert>   // Provides assert
#include <cstdlib>   // Provides NULL, std::size_t
#include <iostream>  // Provides std::cout
#include <iomanip>   // Provides std::setw
#include <algorithm> // Provides std::max
#include <string>	 // Provides string
#include <fstream>   // Provides ifstream
using namespace std;


#pragma once
class ExeCom
{
public:
	ExeCom();
	~ExeCom();

	// Load function
	// Purpose: gets a word from the specified location and puts it in the accumulator
	// Parameters: array data as int, accumulator as int by ref, location as int
	// Returns: none
	void Load(int[], int&, int);

	// Store function
	// Purpose: places the word in the accumulator in a specific location
	// Parameters: array data as int by ref, accumulator as int, location as int
	// Returns: none
	void Store(int[], int, int);

	// Divide function
	// Purpose: takes the word from the specified location in memory and divides it from the word in the accumulator, storing the result in the accumulator
	// Parameters: array data as int, accumulator as int by ref, location, remainder as int by ref
	// Returns: none
	void Divide(int[], int&, int);

	// Multiply function
	// Purpose: takes the word from the specified location in memory and multiplies it to the word in the accumulator, storing the result in the accumulator
	// Parameters: array data as int, accumulator as int by ref, location
	// Returns: none
	void Multiply(int[], int&, int);

	//Subtract Function
	//Purpose: Takes the word from specified memory location, subtracts it from the Accumulator
	//Parameters: MemoryRegister as an int array, Accumulator as a int ref, memory Location as an int
	//Returns: none
	void Subtract(int[], int&, int);

	//Add Function
	//Purpose: Add a specified memory word to the Accumulator
	//Parameters: Memory Register as an int array, Accumlator as an int reference, memory location as an int
	//Returns: none
	void Add(int[], int&, int);

	//Read Function
	//Purpose: Prompt the user to input a value that will then be stored in a Memory Location
	//Parameters: Memory Register as an int array, memory location as an int
	//Returns: None
	void Read(int[], int);

	//Write Function
	//Purpose: Print to the screen the memLoc and the value in memLoc
	//Parameters: Memory Register as an int array, memory location as an int
	//Returns: None
	void Write(int[], int);
	
};

