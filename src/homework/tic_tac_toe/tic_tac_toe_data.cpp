#include "tic_tac_toe_data.h"

//cpp

void TicTacToeData::save_pegs(const std::vector<std::unique_ptr<TicTacToe>> & games)
{
	std::ofstream file_out(file_name, std::ios_base::trunc);
	
	
	
	for (auto &game : games)
	{
		for (auto peg : game->get_pegs())
		{
			file_out << peg ;
		}
		file_out << game->get_winner();
		file_out << "\n";
	}

	file_out.close();
}

std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games() const
{
	std::vector<std::unique_ptr<TicTacToe>> games;
	std::ifstream read_file(file_name);
	string line;
	string get_win;

	if (read_file.is_open())
	{
		vector<string> peg;
		while (std::getline(read_file, line)) {}
		{
			for (int i = 0; i < line.size(); i++) 
			{
				if (i == line.size() - 1) 
				{
					get_win = string(1, line[i]);
				}
				else 
				{
					string game(1, line[i]);
					peg.push_back(game);
				}
			}
			if (peg.size() < 10) 
			{
				std::unique_ptr <TicTacToe> game = std::make_unique<TicTacToe3>(peg, get_win);
				games.push_back(std::move(game));
			}
			else 
			{
				std::unique_ptr <TicTacToe> game = std::make_unique<TicTacToe4>(peg, get_win);
				games.push_back(std::move(game));
			}
		}
	}
	read_file.close();

	
	return games;
}
