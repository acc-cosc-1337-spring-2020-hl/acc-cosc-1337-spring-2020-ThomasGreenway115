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


	while (std::get_line(read_file, line))
	{
		vector<string> peg;
		for (auto ch : line)
		{
			
			string(1, ch);
			
		}
	}
	
	return games;
}
