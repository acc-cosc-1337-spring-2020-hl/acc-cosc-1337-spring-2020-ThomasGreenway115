#include "tic_tac_toe_4.h"
#include<iostream>
using std::cout;
/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/

bool TicTacToe4::check_colunm_win()
{
	if (pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[8] == pegs[12] && pegs[0] != " ")
	{
		return true;
	}
	else if (pegs[1] == pegs[5] && pegs[5] == pegs[9] && pegs[9] == pegs[13] && pegs[1] != " ")
	{
		return true;
	}
	else if (pegs[2] == pegs[6] && pegs[6] == pegs[10] && pegs[10] == pegs[14] && pegs[2] != " ")
	{
		return true;
	}
	else if (pegs[3] == pegs[7] && pegs[7] == pegs[11] && pegs[11] == pegs[15] && pegs[3] != " ")
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/

bool TicTacToe4::check_row_win()
{
	if (pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[2] == pegs[3] && pegs[0] != " ")
	{
		return true;
	}
	else if (pegs[4] == pegs[5] && pegs[5] == pegs[6] && pegs[6] == pegs[7] && pegs[4] != " ")
	{
		return true;
	}
	else if (pegs[8] == pegs[9] && pegs[9] == pegs[10] && pegs[10] == pegs[11] && pegs[8] != " ")
	{
		return true;
	}
	else if (pegs[12] == pegs[13] && pegs[13] == pegs[14] && pegs[14] == pegs[15] && pegs[12] != " ")
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/

bool TicTacToe4::check_diagonal_win()
{
	if (pegs[0] == pegs[5] && pegs[5] == pegs[10] && pegs[10] == pegs[15] && pegs[0] != " ")
	{
		return true;
	}
	else if (pegs[3] == pegs[6] && pegs[6] == pegs[9] && pegs[9] == pegs[12] && pegs[3] != " ")
	{
		return true;
	}
	else
	{
		return false;
	}
}
std::ostream & operator<<(std::ostream & out, TicTacToe4 & game)
{
	out << "\n";
	for (int i = 0; i < game.pegs.size(); i += 4) {
		out << game.pegs[i] << " | " << game.pegs[i + 1] << " | " << game.pegs[i + 2] << " | " << game.pegs[i + 3] << "\n";
	}
	return out;
}

std::istream & operator>>(std::istream & in, TicTacToe4 & game)
{
	int board_selection;

	cout << "Choose a Position between 1 and 16 \n";
	in >> board_selection;
	game.mark_board(board_selection);
	return in;
}
