#include "ExeCom.h"
#include "Decoder.h"




void Decoder(int reg[], int& accum) {
	int stpCmd = -99999;
	int counter = 0;
	int opCode = 0;
	int memLoc = 0;

	while (reg[counter] != stpCmd) {

		if (reg[counter] == stpCmd)
			break;

		if (reg[counter] < -9999 || reg[counter] > 9999) {
			cout << "INVALID WORD -- CONTINUING TO NEXT MEMORY LOCATION" << endl;
			continue;
		}

		if (reg[counter] <= 0)
			continue;
		 

		opCode = reg[counter] / 100;
		memLoc = reg[counter] % 100;

		if (opCode == 43) {
			cout << "Encountered Halt Command, Terminating" << endl;
			break;
		}

		opCall(reg, accum, opCode, memLoc);

		opCode = 0;
		memLoc = 0;
		counter++;
	}
	return;
}


void opCall(int reg[], int& accum, int opCode, int memLoc) {
	int const read = 10;
	int const write = 11;
	int const load = 20;
	int const store = 21;
	int const add = 30;
	int const sub = 31;
	int const div = 32;
	int const multi = 33;
	int const branch = 40;
	int const branchNeg = 41;
	int const branchZero = 42;
	//int memDump = MEMDUMP;
	//int br = BREAK;
	//int cont = CONTINUE;
	ExeCom command;

	switch (opCode) {
		case read: 
			command.Read(reg, memLoc);
			break;
		case write: 
			command.Write(reg, memLoc);
			break;
		case load: 
			command.Load(reg, accum, memLoc);
			break;
		case store: 
			command.Store(reg, accum, memLoc);
			break;
		case add: 
			command.Add(reg, accum, memLoc);
			break;
		case sub: 
			command.Subtract(reg, accum, memLoc);
			break;
		case div: 
			command.Divide(reg, accum, memLoc);
			break;
		case multi: 
			command.Multiply(reg, accum, memLoc);
			break;
		//case branch: command.Branch(memLoc);break;
		//case branchNeg: command.BranchNeg(memLoc);break;
		//case branchZero: command.BranchZero(memLoc);break;
		//case memDump: command.MemDump(memLoc);break;
		//case br: command.Br(memLoc);break;
		//case cont: command.Cont(memLoc);break;
		default: 
			return;
			break;
	}
	return;
}