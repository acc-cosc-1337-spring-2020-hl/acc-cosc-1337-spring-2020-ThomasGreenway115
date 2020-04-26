//h
#include"tic_tac_toe.h"

#ifndef TIC_TAC_TOE_H_4
#define TIC_TAC_TOE_H_4

class TicTacToe4 : public TicTacToe
{
public:

	TicTacToe4() : TicTacToe(4) {}

	friend std::ostream& operator<<(std::ostream & out, TicTacToe4 &game);

	friend std::istream& operator>>(std::istream & in, TicTacToe4 &game);

private:

	bool check_column_win();

	bool check_row_win();

	bool check_diagonal_win();
};
#endif // !TIC_TAC_TOE_H_4