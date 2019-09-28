///////////////////////////////////////////////
// Julia Thee
// Connect Game: Connect abstract-base-class implementation
///////////////////////////////////////////////

#include "Connect.h"	// include definition of class Connect
#include "Connect3.h"	// include definition of class Connect3
#include "Connect4.h"	// include definition of class Connect4
#include "Connect5.h"	// include definition of class Connect5
#include "Player.h"		// include definition of class Player
#include "RealPlayer.h"	// include definition of class RealPlayer
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// initialize static private data member gameOver in global namespace scope
int Connect::gameOver = 0;

// default constructor for Connect abstract-base-class
Connect::Connect()
{
	// no body needed; static private data member gameOver already initialized
}

// method returns the game status (game over or not over) as an integer
int Connect::getGameOver() const {
	return gameOver;
}

// method sets the game status (game over or not over) as an integer
void Connect::setGameOver(int newGameOver) {
	gameOver = newGameOver;
}

// method that initiates the game play by accepting a board and two players as input; method repeatedly calls method to process the next move
void Connect::play_game(Board board, Player* player1, Player* player2) {
	Board latestBoard = board;	// initialize local variable to represent the latest version of the board and the checkers on it
	while (getGameOver() == 0) {	 // check if the game is still ongoing (if gameOver != 0, then there has been a win or tie)
		latestBoard = process_move(latestBoard, player1);	// process the next move using the latest board and given player 1
		if (getGameOver() == 0) {
			latestBoard = process_move(latestBoard, player2); // process the next move using the latest board and given player 2
		}
	}
}

// method processes next move (adding the next checker and checking for a win or tie); accepts a board and player as input
Board Connect::process_move(Board board, Player* player) {
	cout << endl;
	player->print();	// print out the player's string representation, provided in their respective classes
	cout << "'s turn" << endl;
	int column = -1;	// initialize local variable column to -1
	if (player->getIntelligenceLevel() <= 0) {	// check if player is either real or random (CPU) player (intelligent CPU player has intelligence > 0)
		int column = player->next_move(board);	// process player's next move by getting column that player would like to place their checker in
		board.add_checker(player->getChecker(), column);	// add player's checker to specified column
	}
	else {	// if 'else' branch taken, then player has intelligence > 0, so is a CPU player (of CPUPlayer class)
		int column = player->next_move_CPU(board);	// process player's next move by getting column that player would like to place their checker in
		board.add_checker(player->getChecker(), column);  // add player's checker to specified column
	}
	cout << "\n";
	board.print();	// display the updated board after player's checker has been added to board
	if (is_win_for(board, player->getChecker()) == true) {	// check if the player has won the game, based on the board and their checker
		cout << "\n\nCongratulations! Player " << player->getChecker() << " won the game!" << endl;
		setGameOver(1);	// since player won the game, then the game is over, so set gameOver static private data member to 1
		return board;
	}
	else if (board.is_full() == true) {	// check if the board is full of checkers, so no more checkers can be added
		cout << "\n\nIt's a tie!" << endl;  // if board is full, then the game is tied
		setGameOver(1);	// since the game is tied, then the game is over, so set gameOver static private data member to 1
		return board;
	}
	else {
		return board;
	}
}

// method that returns either true or false indicating if the specified checker has won the game on the given board
bool Connect::is_win_for(Board board, string checker) {
	if ((is_horizontal_win(board, checker) == true) ||	// check if the checker won the game horizontally
		(is_vertical_win(board, checker) == true) ||	// check if the checker won the game vertically
		(is_up_diagonal_win(board, checker) == true) ||	// check if the checker won the game diagonally up
		(is_down_diagonal_win(board, checker) == true))	// check if the checker won the game diagonally down
	{
		return true;	// if any of the above cases are true, then the player with the specified checker won the game
	}
	else {
		return false;	// if none of the above cases are true, then the player with the specified checker did not win the game
	}
}