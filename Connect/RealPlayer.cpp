///////////////////////////////////////////////
// Julia Thee
// Connect Game: Class RealPlayer implementation
///////////////////////////////////////////////

#include "RealPlayer.h"	// include definition of class RealPlayer
#include "Board.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

// overloaded constructor function that initializes the player's checker and intelligence level
RealPlayer::RealPlayer(string playerChecker, int intelLevel)
{
	// initialize player's checker and intelligence level using 'this' pointer
	this->checker = playerChecker;
	this->intelligenceLevel = intelLevel;
}	// end RealPlayer constructor 

// overloaded constructor function that initializes the player's intelligence level; default value of "X" used in checker initialization
RealPlayer::RealPlayer(int intelLevel)
	: checker("X"), intelligenceLevel(intelLevel)
{
	// empty body
}	// end RealPlayer constructor 

// method that returns the player's checker as a string
string RealPlayer::getChecker() const {
	return checker;
}

// method that sets the player's checker to the given string value
void RealPlayer::setChecker(string playerChecker) {
	checker = playerChecker;
}

// method that returns the player's intelligence level as an integer
int RealPlayer::getIntelligenceLevel() const {
	return intelligenceLevel;
}

// method that sets the player's intelligence level to the given integer value
void RealPlayer::setIntelligenceLevel(int newIntelligenceLevel) {
	intelligenceLevel = newIntelligenceLevel;
}

// method that returns the player's opponent's checker as a string
string RealPlayer::getOpponentChecker(void) const {
	if (getChecker() == "X") {
		return "O";
	}
	else {
		return "X";
	}
}

// method that prints the player's string representation
void RealPlayer::print(void) const {
	cout << "\nPlayer " << checker;
}

// method that processes the next move of the player, given a Board object as input
int RealPlayer::next_move(Board board) const {
	double tempColumn = -1.0;	// initialize column variable to as double, so that if user enters double value, the value will be rounded down to nearest integer
	cout << "Enter a column: ";	// prompt user to input which column they'd like to place their checker in
	cin >> tempColumn;	// save user input
	// while loop checks that input was valid, and that column chosen was within the range of the board's columns
	while (cin.fail() || tempColumn < 1 || tempColumn > board.getWidth()) {
		if (cin.fail()) {	// execute if user enters invalid input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid column (between 1 and " << board.getWidth() << "): ";	// prompt user to input valid column
		cin >> tempColumn;	// save user input
	}
	int column = tempColumn;	// convert user input from double to int, so that column returned from function is valid
	column = column - 1;	// subtract 1 from column to reflect numbering system of printed board 
	while (true) {	// execute until user enters a valid column that is not full
		if (board.can_add_to(column) == true) {
			return column;	// if column chosen is not full, then return column
		}
		else {
			cout << "\nTry again!" << endl;	 // let the user know that they have to choose another column (since the column they chose was full)
			cout << "Enter a column: ";	 //  prompt user to input column
			cin >> tempColumn;	// save user input
			// while loop checks that input was valid, and that column chosen was within the range of the board's columns
			while (cin.fail() || tempColumn < 1 || tempColumn > board.getWidth()) {
				if (cin.fail()) {	// execute if user enters invalid input
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "Please enter a valid column (between 1 and " << board.getWidth() << "): ";	// prompt user to input valid column
				cin >> tempColumn;	// save user input
			}
			column = tempColumn;  // convert user input from double to int, so that column returned from function is valid	
			column = column - 1;  // subtract 1 from column to reflect numbering system of printed board 
		}
	}
}