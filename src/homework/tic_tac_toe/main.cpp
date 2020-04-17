#include "tic_tac_toe.h"
using std::cout;
using std::cin;
#include "tic_tac_toe_manager.h"
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"
int main() 
{
	int game_choice = 1;
	string first_p = "";
	int user_choice = 0;
	tic_tac_toe_manager gamemanager;
	TicTacToe3 game1;
	TicTacToe4 game2;
	vector<reference_wrapper<TicTacToe>> games{ game1, game2 };
	do
	{
		cout << "Enter 1 if you want to play a 3x3 tictactoe game or enter 2 to play a 4x4 default is 3x3";
		cin >> game_choice;
		if (game_choice == 1)
		{
			gamemanager.games.push_back(games.at(0));
			TicTacToe3 game1;
		}
		else if (game_choice == 2)
		{
			gamemanager.games.push_back(games.at(1));
			TicTacToe4 game2;
 		}
		reference_wrapper<TicTacToe> Last_instance = gamemanager.games.back();
		do
		{
			try
			{
				cout << "Choose X or O for first player: ";
				cin >> first_p;
				Last_instance.get().start_game(first_p);
			}
			catch (error b)
			{
				cout << b.get_message();
			}
		} while (first_p != "X" && first_p != "O");
		do
		{
			
			cin >> Last_instance.get();
			cout << Last_instance.get();
			
			
		} while (!(Last_instance.get().game_over() == true));
		
		gamemanager.save_game(Last_instance.get());
		cout << gamemanager;
		first_p = "";
		cout << "If you want to play another game enter anything if not enter 1";
		cin >> user_choice;
		if (user_choice = 1)
		{
			cout << gamemanager;
		}
		
	} while (user_choice != 1);
	return 0;
}