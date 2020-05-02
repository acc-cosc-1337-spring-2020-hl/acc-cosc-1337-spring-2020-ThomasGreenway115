//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
#include"tic_tac_toe.h"
#include"tic_tac_toe_data.h"
#include<memory>
using namespace std;

class tic_tac_toe_manager
{
public:
	tic_tac_toe_manager() = default;
	tic_tac_toe_manager(TicTacToeData& data);
	void save_game(unique_ptr<TicTacToe>& b);
	friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager);
private:
	vector<unique_ptr<TicTacToe>> games;
	int x_win = 0;
	int o_win = 0;
	int ties = 0;
	void update_winner_count(string winner);
	TicTacToeData destruct;

};
#endif // !TIC_TAC_TOE_MANAGER_H