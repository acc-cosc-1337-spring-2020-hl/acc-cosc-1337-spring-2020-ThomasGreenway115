#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"
#include"tic_tac_toe_manager.h"
#include<memory>
//Do you want me to include test cases for 4x4? You removed them when you corrected my hw 9 test cases so Im going to keep them removed.

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test set first player to X")
{

	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

	game->start_game("X");

	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test set first player to O")
{

	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

	game->start_game("O");

	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test start game with X game flow")
{

	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

	game->start_game("X");
	REQUIRE(game->get_player() == "X");

	game->mark_board(4);
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column", "[X wins second column]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();

	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//X         
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//X 
	//X wins 
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by second column", "[X wins second column]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();

	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//X         
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(8);//X 
	//X wins 
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by third column", "[X wins third column]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();

	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//X         
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(6);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//X 
	//X wins 
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by first row", "[X wins first row]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();

	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//X         
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//X 
	//X wins 
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by second row", "[X wins second row]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();

	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//X         
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(6);//X 
	//X wins 
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win by third row", "[X wins third row]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();

	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//X         
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(8);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//X 
	//X wins 
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win diagonal 1", "[X wins with 1 5 9]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();

	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//X         
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//X 
	//X wins 
	REQUIRE(board->game_over() == true);
}

TEST_CASE("Test win diagonal 2", "[X wins with 3 5 7]")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();

	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//X         
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//X 
	//X wins 
	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "X");
}

TEST_CASE("Test tie")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();

	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);//X         
	REQUIRE(board->game_over() == false);
	board->mark_board(2);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(4);//X          
	REQUIRE(board->game_over() == false);
	board->mark_board(7);//O          
	REQUIRE(board->game_over() == false);
	board->mark_board(5);//X 
	REQUIRE(board->game_over() == false);
	board->mark_board(6);//O 
	REQUIRE(board->game_over() == false);
	board->mark_board(3);//X 
	REQUIRE(board->game_over() == false);
	board->mark_board(9);//O 
	REQUIRE(board->game_over() == false);
	board->mark_board(8);//X 
	//no winner
	REQUIRE(board->game_over() == true);
	REQUIRE(board->get_winner() == "C");
}


TEST_CASE("Win by first column4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(5);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(13);//X
	//X wins
	REQUIRE(game4->game_over() == true);
	REQUIRE(game4->get_winner() == "X");
}

TEST_CASE("Win by second column4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(14);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by third column4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(11);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(15);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}
TEST_CASE("Win by fourth column4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(8);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(12);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(15);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by first row4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by second row4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(5);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(8);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by third row4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(11);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(12);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}
TEST_CASE("Win by fourth row4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(13);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(14);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(15);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by diagonally top left4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(11);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Win by diagonally bottom left4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(13);//X
	//X wins
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("For no Winner4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE(game4->game_over() == false);
	game4->mark_board(1);//X        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(2);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(3);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(4);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(6);//X
	REQUIRE(game4->game_over() == false);
	game4->mark_board(5);//O        
	REQUIRE(game4->game_over() == false);
	game4->mark_board(8);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(7);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(10);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(9);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(12);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(11);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(13);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(14);//O          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(15);//X          
	REQUIRE(game4->game_over() == false);
	game4->mark_board(16);//O          
	REQUIRE(game4->game_over() == true);
}

TEST_CASE("Mark position4") {
	std::unique_ptr<TicTacToe> game4 = std::make_unique<TicTacToe4>();
	game4->start_game("X");
	REQUIRE_THROWS_AS(game4->mark_board(0), error);
	REQUIRE_THROWS_AS(game4->mark_board(17), error);
	game4->mark_board(5);

}


