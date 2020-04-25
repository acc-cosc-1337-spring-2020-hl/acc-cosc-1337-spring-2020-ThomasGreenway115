//h
#include"tic_tac_toe.h"
#ifndef TIC_TAC_TOE_H_3
#define TIC_TAC_TOE_H_3


class TicTacToe3 : public TicTacToe
{
public:
	TicTacToe3(std::vector<string> p, string winner);
	
	TicTacToe3(): TicTacToe(3) {}

	friend std::ostream& operator<<(std::ostream & out, TicTacToe3 &game);

	friend std::istream& operator>>(std::istream & in, TicTacToe3 &game);

private:
	
	bool check_column_win();
	
	bool check_row_win();
	
	bool check_diagonal_win();
};
#endif // !TIC_TAC_TOE_H_3