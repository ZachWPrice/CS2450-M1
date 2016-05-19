#include <cassert>   // Provides assert
#include <cstdlib>   // Provides NULL, std::size_t
#include <iostream>  // Provides std::cout
#include <iomanip>   // Provides std::setw
#include <algorithm> // Provides std::max
#include <string>	 // Provides string
#include <fstream>   // Provides ifstream
#include "ExeCom.h"
using namespace std;

ExeCom::ExeCom()
{
}

void ExeCom::Load(int array[], int &accumulator, int location)
{
	accumulator = array[location-1];
}

void ExeCom::Store(int array[], int accumulator, int location)
{
	array[location - 1] = accumulator;
}

void ExeCom::Divide(int array[], int &accumulator, int location)
{
	int dividend = array[location - 1];
	int divisor = accumulator;

	if (divisor != NULL)
	{
		accumulator = dividend / divisor;
	}
	else if (dividend == NULL)
	{
		accumulator = 0;
	}
	else
	{
		cout << "Memory location contains zero or no value." << endl;
		cout << "Division can't be executed." << endl;
		cout << "Accumulator stays unchanged." << endl;
	}
}


/*
//This version include the remainder, which isn't currently needed, above is the same thing, with that removed
void ExeCom::Divide(int array[], int &accumulator, int location, int &remainder)
{
	int dividend = array[location - 1];
	int divisor = accumulator;

	if (divisor != NULL)
	{
		accumulator = dividend / divisor;
		remainder = dividend %  divisor;
	}
	else if (dividend == NULL)
	{
		accumulator = 0;
		remainder = 0;
	}
	else
	{
		cout << "Memory location contains zero or no value." << endl;
		cout << "Division can't be executed." << endl;
		cout << "Accumulator stays unchanged." << endl;
	}
}*/

void ExeCom::Multiply(int array[], int &accumulator, int location)
{
	accumulator = array[location - 1] * accumulator;
}

void ExeCom::Subtract(int reg[], int& accum, int memLoc) {
	//Still need to find out what he would like done with overflow 
	//For now, maxing out and putting it in accum
	if (accum - reg[memLoc -1] > 9999) {
		accum = 9999;
	}
	else if (accum - reg[memLoc -1] < -9999) {
		accum = -9999;
	}
	else {
		accum = accum - reg[memLoc -1];
	}
	return;
}

void ExeCom::Add(int reg[], int& accum, int memLoc) {
	//Still need to find out what he would like done with overflow 
	//For now, maxing out and putting it in accum

	if (accum + reg[memLoc - 1] > 9999) {
		accum = 9999;
	}
	else if (accum + reg[memLoc - 1] < -9999) {
		accum = -9999;
	}
	else {
		accum = accum + reg[memLoc - 1];
	}
	return;
}

//This still needs more Error checking
void ExeCom::Read(int reg[], int memLoc) {
	int temp = 0;
	bool loop = true;
	while (loop) {
		cout << "Please enter a value: ";
		cin >> temp;
		if (temp < -9999 || temp > 9999) {
			cout << "That is not a valid input, please input an integer between -9999 and 9999";
		}
		else {
			loop = false;
		}
	}
	reg[memLoc - 1] = temp;
	return;
}

void ExeCom::Write(int reg[], int memLoc) {
	cout << "The value in register " << memLoc << " is " << reg[memLoc - 1] << endl;
	return;
}

ExeCom::~ExeCom()
{
}
