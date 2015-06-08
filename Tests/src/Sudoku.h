/*
 * Sudoku.h
 *
 *  Created on: 8 Jun 2015
 *      Author: adam-jr
 */

#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <iostream>
#include <bitset>

#define c_ChartSize 9
typedef std::bitset<c_ChartSize> SuDoKu[c_ChartSize][c_ChartSize];

class Sudoku
{
public:
	Sudoku();
	~Sudoku();
	void _PrintGrid();
	int _GetDecimal(std::bitset<c_ChartSize>);
	void _Init();
	void _Solve();
private:
	SuDoKu m_Sudoku;

};



#endif /* SUDOKU_H_ */
