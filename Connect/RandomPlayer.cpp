///////////////////////////////////////////////
// Julia Thee
// CIS554-70618 Object Oriented Programming in C++
// Final Project
// Connect Game: Class RandomPlayer implementation
// Date: 09/17/2019
///////////////////////////////////////////////

#include "RandomPlayer.h"	// include definition of class RandomPlayer
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

RandomPlayer::RandomPlayer(string playerChecker, int intelLevel)
	: checker(playerChecker), intelligenceLevel(intelLevel)
{
	// empty body
}	// end RandomPlayer constructor 

// method that returns the player's checker as a string
string RandomPlayer::getChecker() const {
	return checker;
}

// method that sets the player's checker to the given string value
void RandomPlayer::setChecker(string playerChecker) {
	checker = playerChecker;
}

// method that returns the player's intelligence level as an integer
int RandomPlayer::getIntelligenceLevel() const {
	return intelligenceLevel;
}

// method that sets the player's intelligence level to the given integer value
void RandomPlayer::setIntelligenceLevel(int newIntelligenceLevel) {
	intelligenceLevel = newIntelligenceLevel;
}

// method that returns the player's opponent's checker as a string
string RandomPlayer::getOpponentChecker(void) const {
	if (checker == "X") {
		return "O";
	}
	else {
		return "X";
	}
}

// method that prints the player's string representation
void RandomPlayer::print(void) const {
	cout << "\nCPU Player " << checker << " (difficulty level " << intelligenceLevel + 1 << ")";
}

// method that processes the next move of the player, given a Board object as input
int RandomPlayer::next_move(Board board) const {
	int boardColumns = board.getWidth();	// initialize local variable to value of the board's width
	std::vector<int> notFullVector(boardColumns, -1);	// declare vector of length equal to boards width; initialize vector values to -1
	int notFullColumns = 0;		// variable representing number of columns that are not full
	for (int column = 0; column < board.getWidth(); column++) {	 // iterate over all columns of board
		if (board.can_add_to(column) == true) {	 // check if the current column has a free space to add the next checker
			notFullVector[notFullColumns] = column;	 // column is not full, so add column index to vector 
			notFullColumns++;	// increment number of columns that are not full
		}
	}
	int randomColumn = rand() % notFullColumns;	 // choose one of the not-full columns at random
	return notFullVector[randomColumn];  // return randomly chosen column index as column to put player's checker 

}