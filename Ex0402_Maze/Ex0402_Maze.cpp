#include <iostream>

#include "../shared/Stack.h"

using namespace std;

constexpr int kNumRows = 10;
constexpr int kNumCols = 9;

char maze[kNumRows][kNumCols] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', 'S', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '0', '1', '0', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1'},
	{'1', '1', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', 'G', '1'}, // <- 'G' Finish
	{'1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

void PrintMaze()
{
	for (int j = 0; j < kNumRows; j++)
	{
		for (int i = 0; i < kNumCols; i++)
			cout << maze[j][i] << " ";
		cout << endl;
	}
}

struct Pos
{
	int row;
	int col;

	friend ostream& operator<<(ostream& os, const Pos& pos)
	{
		cout << "(" << pos.row << ", " << pos.col << ")" << flush;
		return os;
	}
};

//void RecurMaze(Pos p)
//{
//	const char mark = maze[p.row][p.col];
//
//	if (mark == 'G')
//	{
//		cout << "Found!" << endl;
//		return;
//	}
//
//
//	if (mark != '1' && mark != 'X')
//	{
//		maze[p.row][p.col] = 'X';
//		RecurMaze({ p.row + 1, p.col });
//		RecurMaze({ p.row - 1, p.col });
//		RecurMaze({ p.row, p.col + 1});
//		RecurMaze({ p.row, p.col - 1});
//	}
//	
//
//}


int RecurMaze(Pos p)
{
	const char mark = maze[p.row][p.col];
	
	if (mark == 'G')
	{
		cout << "Found!" << endl;
		return 1;
	}
	if (mark != '1' && mark != 'X')
	{
		maze[p.row][p.col] = 'X';
		if (RecurMaze({ p.row + 1, p.col })) return 1;
		if (RecurMaze({ p.row - 1, p.col })) return 1;
		if (RecurMaze({ p.row, p.col - 1 })) return 1;
		if (RecurMaze({ p.row, p.col + 1})) return 1;
		
	}
	
	return 0;
}

void StackMaze()
{
	Stack<Pos> s;

	Pos start = { 1, 1 };


	s.Push(start); 


	while (!s.IsEmpty())
	{
		Pos p = s.Top();
		s.Pop();

		cout << p << " ";

		const char mark = maze[p.row][p.col];

		if (mark == 'G')
		{
			cout << "Found!" << endl;
			break;
		}

		if (mark != '1' && mark != 'X')
		{
			maze[p.row][p.col] = 'X';
			s.Push({ p.row + 1, p.col });
			s.Push({ p.row - 1, p.col });
			s.Push({ p.row, p.col + 1 });
			s.Push({ p.row, p.col - 1 });
		}
		
	}
}

int main()
{
	PrintMaze();

	RecurMaze({ 1, 1 });

	StackMaze();

	PrintMaze();

	return 0;
}

