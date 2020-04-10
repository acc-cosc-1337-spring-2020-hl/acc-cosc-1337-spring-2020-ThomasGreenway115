#include "tic_tac_toe.h"
using std::cout;
using std::cin;
#include "tic_tac_toe_manager.h"
int main() 
{
	string first_p = "";
	int user_choice = 0;
	TicTacToe game;
	tic_tac_toe_manager gamemanager;
	do
	{
		do
		{
			try
			{
				cout << "Choose X or O for first player: ";
				cin >> first_p;
				game.start_game(first_p);
			}
			catch (error b)
			{
				cout << b.get_message();
			}
		} while (first_p != "X" && first_p != "O");
		do
		{
			
			cin >> game;
			cout << game;
			
			
		} while (!(game.game_over() == true));
		
		gamemanager.save_game(game);
		cout << gamemanager;
		first_p = "";
		cout << "If you want to play another game enter anything if not enter 1";
		cin >> user_choice;
		
	} while (user_choice != 1);
	if (user_choice = 1)
	{
		cout << gamemanager;
	}

	return 0;
}