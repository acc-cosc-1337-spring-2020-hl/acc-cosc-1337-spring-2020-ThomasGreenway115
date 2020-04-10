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
	void start_game(string first_player);
	
	void mark_board(int position);

	string get_player()const { return player; };

	bool game_over();

	string get_winner() { return winner; };

	friend std::ostream& operator<<(std::ostream& out, TicTacToe& c);
	friend std::istream& operator>>(std::istream& in, TicTacToe& c);
private:
	void set_next_player();

	string player;

	bool check_board_full();

	vector<string> pegs{ 9, " " };

	void clear_board();

	bool check_column_win();

	bool check_row_win();

	bool check_diagonal_win();

	void set_winner();

	string winner = "";
};
#endif //!TIC_TAC_TOE_H