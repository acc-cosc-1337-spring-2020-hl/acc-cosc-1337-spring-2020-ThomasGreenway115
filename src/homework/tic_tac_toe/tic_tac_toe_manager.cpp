#include"tic_tac_toe_manager.h"


void tic_tac_toe_manager::save_game(unique_ptr<TicTacToe>& game)
{
	games.push_back(std::move(game));

	update_winner_count(game->get_winner());
	
}

void tic_tac_toe_manager::update_winner_count(string winner)
{
	if (winner == "X")
	{
		x_win++;
	}
	else if (winner == "O")
	{
		o_win++;
	}
	else
	{
		ties++;
	}
}

std::ostream & operator<<(std::ostream& out, const tic_tac_toe_manager& manager)
{
	out << "Times X has won: " << manager.x_win << "\n";
	out << "Times O has won: " << manager.o_win << "\n";
	out << "Times the outcome was a tie. " << manager.ties << "\n";
	return out;
}
