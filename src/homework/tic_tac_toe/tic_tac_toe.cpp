//cpp
#include "tic_tac_toe.h"
using std::cout;

void TicTacToe::start_game(string first_player)
{
	if (first_player == "X" || first_player == "O")
	{
		player = first_player;
	}
	else if (first_player != "X" && first_player != "O")
	{
		throw error("Player must be X or O.\n");
	}
	else
	{
		clear_board();
		player = first_player;
	}
	
}

void TicTacToe::mark_board(int position)
{
	if (position < 1 || position > 9)
	{
		throw error("Position must be 1 to 9.");
	}
	else if (player == "")
	{
		throw error("Must start game first.");
	}
	else
	{
		pegs[position - 1] = player;
		if (game_over() == false)
		{
			set_next_player();
		}
	}
	
	
}

bool TicTacToe::game_over()
{
	if (check_column_win() == true)
	{
		return true;
	}
	else if (check_diagonal_win() == true)
	{
		return true;
	}
	else if (check_row_win() == true)
	{
		return true;
	}
	else if(check_row_win() == false && check_diagonal_win() == false && check_column_win() == false)
	{
		winner = "C";
	}
	else if (check_board_full() == true)
	{
		return true;
	}
	return false;
}

void TicTacToe::set_next_player()
{
	if (player == "X")
	{
		player = "O";
	}
	else
	{
		player = "X";
	}
}

bool TicTacToe::check_board_full()
{
	for (auto peg : pegs)
	{
		if (peg == " ")
		{
			return false;
		}
	}
	return true;
}

void TicTacToe::clear_board()
{
	for (auto &peg : pegs)
	{
		peg = " ";
	}
}

bool TicTacToe::check_column_win()
{
	if (pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X")
	{
		return true;
	}
	else if (pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X")
	{
		return true;
	}
	else if (pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X")
	{
		return true;
	}
	if (pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O")
	{
		return true;
	}
	else if (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O")
	{
		return true;
	}
	else if (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TicTacToe::check_row_win()
{
	if (pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X")
	{
		return true;
	}
	else if (pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X")
	{
		return true;
	}
	else if (pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X")
	{
		return true;
	}
	if (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O")
	{
		return true;
	}
	else if (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O")
	{
		return true;
	}
	else if (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TicTacToe::check_diagonal_win()
{
	if (pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X")
	{
		return true;
	}
	else if (pegs[6] == "X" && pegs[4] == "X" && pegs[2] == "X")
	{
		return true;
	}
	
	if (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O")
	{
		return true;
	}
	else if (pegs[6] == "O" && pegs[4] == "O" && pegs[2] == "O")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TicTacToe::set_winner()
{
	if (player == "X")
	{
		winner = "O";
	}
	else if (player == "O")
	{
		winner = "X";
	}
}
std::ostream & operator<<(std::ostream & out, TicTacToe& c)
{
	out << "\n";

	for (std::size_t i = 0; i < 9; i += 3) 
	{
		out << c.pegs[i] << "|" << c.pegs[i + 1] << "|" << c.pegs[i + 2] << "\n";
	}
	return out;
}

std::istream & operator>>(std::istream & in, TicTacToe & c)
{
	cout << "Enter a position between 1 and 9: ";
	int position;
	in >> position;
	c.mark_board(position);
	return in;
}
