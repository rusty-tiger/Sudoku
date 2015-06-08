/*
 * Sudoku.cpp
 *
 *  Created on: 8 Jun 2015
 *      Author: adam-jr
 */
#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku():
		m_Sudoku()
{

}

Sudoku::~Sudoku()
{

}

void Sudoku::_Init()
{
	for (int R = 0; R<c_ChartSize;R++)
	{
		for (int C = 0; C<c_ChartSize;C++)
		{
			m_Sudoku[R][C].set();
		}
	}

	int Sudoku[] =
		   {5, 3, 0, 0, 7, 0, 0, 0, 0,
			6, 0, 0, 1, 9, 5, 0, 0, 0,
			0, 9, 8, 0, 0, 0, 0, 6, 0,
			8, 0, 0, 0, 6, 0, 0, 0, 3,
			4, 0, 0, 8, 0, 3, 0, 0, 1,
			7, 0, 0, 0, 2, 0, 0, 0, 6,
			0, 6, 0, 0, 0, 0, 2, 8, 0,
			0, 0, 0, 4, 1, 9, 0, 0, 5,
			0, 0, 0, 0, 8, 0, 0, 7, 9};

	for (int R = 0; R<c_ChartSize;R++)
	{
		for (int C = 0; C<c_ChartSize;C++)
		{
			if(Sudoku[(R*c_ChartSize)+C] != 0)
			{
				m_Sudoku[R][C].reset();
				m_Sudoku[R][C].set(Sudoku[(R*c_ChartSize)+C]-1);

			}
		}
	}


}

void Sudoku::_PrintGrid()
{
	for (int R = 0; R<c_ChartSize;R++)
	{
		cout << "++---+---+---++---+---+---++---+---+---++" << endl;
		if (R == 0||R == 3||R == 6)
		{
			cout << "++---+---+---++---+---+---++---+---+---++" << endl;
		}
		for (int C = 0; C<c_ChartSize;C++)
		{
			if (C == 0||C == 3||C == 6)
			{
				cout << "|";
			}
			if (_GetDecimal(m_Sudoku[R][C]) != 0)
			{
				cout << "| "<< _GetDecimal(m_Sudoku[R][C]) << " ";
			}
			else
			{
				cout << "|   ";
			}
		}
		cout << "||" << endl;
	}
	cout << "++---+---+---++---+---+---++---+---+---++" << endl;
	cout << "++---+---+---++---+---+---++---+---+---++" << endl;
}

int Sudoku::_GetDecimal(std::bitset<c_ChartSize> InputValue)
{
	int ReturnValue = 0;
	if (InputValue.count() == 1)
	{
		for (int I = 0; I<c_ChartSize;I++)
		{
			if (InputValue.test(I))
			{
				ReturnValue = I+1;
				break;
			}
		}
	}

	return ReturnValue;
}

void Sudoku::_Solve()
{
	int i = 0;
	bool NoChange = false;
	while(1)
	{
		NoChange = false;
		for (int R = 0; R<c_ChartSize;R++)
		{
			for (int C = 0; C<c_ChartSize;C++)
			{
				if (m_Sudoku[R][C].count() == 1)
				{
					for (int TempC = 0; TempC<c_ChartSize;TempC++)
					{
						if (TempC!=C)
						{
							if (m_Sudoku[R][TempC].test(_GetDecimal(m_Sudoku[R][C])-1))
							{
								m_Sudoku[R][TempC].reset(_GetDecimal(m_Sudoku[R][C])-1);
								NoChange = true;
							}
						}
					}
					for (int TempR = 0; TempR<c_ChartSize;TempR++)
					{
						if (TempR!=R)
						{
							if (m_Sudoku[TempR][C].test(_GetDecimal(m_Sudoku[R][C])-1))
							{
								m_Sudoku[TempR][C].reset(_GetDecimal(m_Sudoku[R][C])-1);
								NoChange = true;
							}
						}
					}



				}
			}
		}
		for (int GR = 0; GR < 9; GR += 3)
		{
			for (int GC = 0; GC < 9; GC += 3)
			{
				for(int R = 0; R < 3; R++)
				{
					for(int C = 0; C < 3; C++)
					{

					}
				}
			}
		}
		if (!NoChange)
		{
			break;
		}
		else
		{
			i++;

		}
	}
}



