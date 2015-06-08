//============================================================================
// Name        : Tests.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Sudoku.h"

int main() {

	Sudoku Sudoko1;
	Sudoko1._Init();
	Sudoko1._Solve();

	Sudoko1._PrintGrid();
	return 0;
}
