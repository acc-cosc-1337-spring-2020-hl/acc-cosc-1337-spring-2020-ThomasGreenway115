#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include"tic_tac_toe.h"
#include<iostream>
#include<functional>

using std::cout; using std::cin; using std::string;

int main()
{
	
	string cont;
	TicTacToeData destruct;
	unique_ptr<tic_tac_toe_manager> gamemanager = make_unique<tic_tac_toe_manager>(destruct);
	do
	{
		unique_ptr<TicTacToe> game1;
		int game_type;
		cout << "\nTictactoe 3 or 4? Enter 4 for 4x4 or 3 for 3x3";
		cin >> game_type;
		
		if (game_type == 4)
		{
			game1 = make_unique<TicTacToe4>();
		}
		else
		{
			game1 = make_unique<TicTacToe3>();
		}

		string player = "Y";

		while (!(player == "O" || player == "X"))
		{
			try
			{
				cout << "Enter player: ";
				cin >> player;

				game1->start_game(player);
			}
			catch (error e)
			{
				cout << e.get_message();
			}
		}

		int choice = 1;

		do
		{
			try
			{
				cin >> *game1;
				cout << *game1;
			}
			catch (error e)
			{
				cout << e.get_message();
			}

		} while (!game1->game_over());

		cout << "\nWinner: " << game1->get_winner() << "\n";
		gamemanager->save_game(game1);
		cout << *gamemanager;


		cout << "Enter Y to play again: ";
		cin >> cont;

	} while (cont == "Y");

	

	return 0;
}