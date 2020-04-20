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
	if (position < 1 || position > 16)
	{
		throw error("Position must be 1 to 16.");
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
		set_winner();
		return true;
	}
	else if (check_diagonal_win() == true)
	{
		set_winner();
		return true;
	}
	else if (check_row_win() == true)
	{
		set_winner();
		return true;
	}
	else if(check_board_full())
	{
		winner = "C";
		return true;
	}

	return false;
}

bool TicTacToe::check_column_win()
{
	return false;
}

bool TicTacToe::check_row_win()
{
	return false;
}

bool TicTacToe::check_diagonal_win()
{
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





//This causes test cases that check for wins to fail which is frustrating bc you said to make these false but didn't explain if you wanted us to connect the tictactoe3 functions to the game_over function.
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
	if (c.pegs.size() == 9)
	{
		for (std::size_t i = 0; i < 9; i += 3)
		{
			out << c.pegs[i] << "|" << c.pegs[i + 1] << "|" << c.pegs[i + 2] << "\n";
		}
	}
	else if (c.pegs.size() == 16)
	{
		for (int i = 0; i < 16; i += 4)
		{
			out << c.pegs[i] << "|" << c.pegs[i + 1] << "|" << c.pegs[i + 2] << "|" << c.pegs[i + 3] << "\n";
		}
	}
	out << "\n";
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
