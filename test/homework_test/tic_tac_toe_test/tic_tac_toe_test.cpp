#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
TEST_CASE("Test can't call mark board before start game")
{
	TicTacToe3 game;
	REQUIRE_THROWS_AS(game.mark_board(1), error);
}
TEST_CASE("Test start game accepts only X or O")
{
	TicTacToe3 game;
	REQUIRE_THROWS_AS(game.start_game("R"), error);
}
TEST_CASE("Test set first player to X")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}
TEST_CASE("Test set first player to O")
{
	TicTacToe3 game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}
TEST_CASE("Test Start game with X game flow")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
	game.mark_board(4);
	REQUIRE(game.get_player() == "O");

}
TEST_CASE("Test start game with O game flow")
{
	TicTacToe3 game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
	game.mark_board(2);
	REQUIRE(game.get_player() == "X");
}
TEST_CASE("Test the game_over function when 9 slots are selected")
{
	TicTacToe3 game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(3);
	game.mark_board(4);
	game.mark_board(6);
	game.mark_board(5);
	game.mark_board(7);
	game.mark_board(8);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test Mark Position only accepts values 1 through 16")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE_THROWS_AS(game.mark_board(0), error);
	REQUIRE_THROWS_AS(game.mark_board(17), error);
	game.mark_board(5);
}
TEST_CASE("Test win by first column")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(1);      
	REQUIRE(game.game_over() == false);
	game.mark_board(2);       
	REQUIRE(game.game_over() == false);
	game.mark_board(4);        
	REQUIRE(game.game_over() == false);
	game.mark_board(5);        
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test win by second column")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(1);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(8);//X
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test win by third column")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(1);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(6);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(9);//X
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test win by first row")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(1);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(4);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//X
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test win by second row")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(4);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(7);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(6);//X
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test win by third row")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(7);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(8);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(9);//X
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test win by first diagonal")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(1);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(7);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(9);//X
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test win diagonal from top left")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(1);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(7);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(9);//X
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test win diagonal from bottom left")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(7);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//X
	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test for no winner")
{
	TicTacToe3 game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(1);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//0
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(4);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(6);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(7);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(8);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(9);//O
	REQUIRE(game.get_winner() == "C");
	REQUIRE(game.game_over() == true);

}
TEST_CASE("Check 1 to 16 diagional win") {
	TicTacToe4 game;
	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(11);
	REQUIRE(game.game_over() == false);
	game.mark_board(14);
	REQUIRE(game.game_over() == false);
	game.mark_board(16);


	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Check 4 to 13 diagional win") {
	TicTacToe4 game;
	game.start_game("X");
	game.mark_board(4);//X
	REQUIRE(game.game_over() == false);
	game.mark_board(2);//O
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == false);
	game.mark_board(10);
	REQUIRE(game.game_over() == false);
	game.mark_board(16);
	REQUIRE(game.game_over() == false);
	game.mark_board(13);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Check first column win - 4x4") {
	TicTacToe4 game;

	game.start_game("X");
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(10);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(13);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}
TEST_CASE("Check second column win -4x4") {
	TicTacToe4 game;

	game.start_game("X");
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(10);
	REQUIRE(game.game_over() == false);
	game.mark_board(12);
	REQUIRE(game.game_over() == false);
	game.mark_board(14);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Check third column win 4x4") {
	TicTacToe4 game;

	game.start_game("O");
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(11);
	REQUIRE(game.game_over() == false);
	game.mark_board(12);
	REQUIRE(game.game_over() == false);
	game.mark_board(15);

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}
TEST_CASE("Check 4th column win 4x4") {
	TicTacToe4 game;

	game.start_game("O");
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(12);
	REQUIRE(game.game_over() == false);
	game.mark_board(11);
	REQUIRE(game.game_over() == false);
	game.mark_board(16);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Check first row win 4x4") {
	TicTacToe4 game;

	game.start_game("O");
	game.mark_board(1); 
	REQUIRE(game.game_over() == false);
	game.mark_board(5); 
	REQUIRE(game.game_over() == false);
	game.mark_board(2); 
	REQUIRE(game.game_over() == false);
	game.mark_board(9); 
	REQUIRE(game.game_over() == false);
	game.mark_board(3); 
	REQUIRE(game.game_over() == false);
	game.mark_board(8); 
	REQUIRE(game.game_over() == false);
	game.mark_board(4); 
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Check second row win 4x4") {
	TicTacToe4 game;

	game.start_game("X");
	game.mark_board(5); 
	REQUIRE(game.game_over() == false);
	game.mark_board(1); 
	REQUIRE(game.game_over() == false);
	game.mark_board(6); 
	REQUIRE(game.game_over() == false);
	game.mark_board(16); 
	REQUIRE(game.game_over() == false);
	game.mark_board(7); 
	REQUIRE(game.game_over() == false);
	game.mark_board(15); 
	REQUIRE(game.game_over() == false);
	game.mark_board(8); 

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Check third row win 4x4") {
	TicTacToe4 game;

	game.start_game("O");
	game.mark_board(9); 
	REQUIRE(game.game_over() == false);
	game.mark_board(5); 
	REQUIRE(game.game_over() == false);
	game.mark_board(10); 
	REQUIRE(game.game_over() == false);
	game.mark_board(3); 
	REQUIRE(game.game_over() == false);
	game.mark_board(11); 
	REQUIRE(game.game_over() == false);
	game.mark_board(15);
	REQUIRE(game.game_over() == false);
	game.mark_board(12); 

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Check 4th row win 4x4") {
	TicTacToe4 game;

	game.start_game("O");
	game.mark_board(13); 
	REQUIRE(game.game_over() == false);
	game.mark_board(5); 
	REQUIRE(game.game_over() == false);
	game.mark_board(14); 
	REQUIRE(game.game_over() == false);
	game.mark_board(3); 
	REQUIRE(game.game_over() == false);
	game.mark_board(15); 
	REQUIRE(game.game_over() == false);
	game.mark_board(1); 
	REQUIRE(game.game_over() == false);
	game.mark_board(16); 
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}







