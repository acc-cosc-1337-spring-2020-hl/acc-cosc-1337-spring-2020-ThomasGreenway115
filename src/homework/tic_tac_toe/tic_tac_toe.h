//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;

class error
{
public:
	error(string msg) : message{ msg } {};
	
	string get_message() { return message; };


private:
	string message;

};
class TicTacToe
{
public:
	TicTacToe(std::vector<string> p, string win) : pegs{ p }, winner{ win } {};
	explicit TicTacToe(int size) : pegs{size*size, " " } {}

	const vector<string> get_pegs();

	void start_game(string first_player);
	
	void mark_board(int position);

	string get_player()const { return player; };

	bool game_over();

	string get_winner() { return winner; };

	friend std::ostream& operator<<(std::ostream& out, TicTacToe& c);
	friend std::istream& operator>>(std::istream& in, TicTacToe& c);
	
protected:
	vector<string> pegs;
	
	virtual bool check_column_win();

	virtual bool check_row_win();

	virtual bool check_diagonal_win();

private:
	void set_next_player();

	string player;

	bool check_board_full();

	void clear_board();

	void set_winner();

	string winner = "";
};
#endif //!TIC_TAC_TOE_H