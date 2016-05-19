#pragma once

//This is the Decoder code
//This will take in the Memory Register (reg[]) and the Accumulator (accum)
void Decoder(int reg[], int& accum);

//This is the opCall function
//This accepts an Operation ID (opCode) and a Memory Location(memLoc)
//It will look at the opCode, and if it is a valid Operation ID
//it will call the needed function
//If the opCode is not a valid Operation ID it will return to the Decoder
void opCall(int[], int&, int, int);