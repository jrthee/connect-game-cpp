///////////////////////////////////////////////
// Julia Thee
// Connect Game: Class CPUPlayer implementation
///////////////////////////////////////////////

#include "CPUPlayer.h"	// include definition of class CPUPlayer
#include "Connect.h"	// include definition of class Connect
#include "Connect3.h"	// include definition of class Connect3
#include "Connect4.h"	// include definition of class Connect4
#include "Connect5.h"	// include definition of class Connect5
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::max_element;

// initialize static private data members in global namespace scope
int CPUPlayer::firstIteration = 1;
int CPUPlayer::firstLossColumn = -1;
int CPUPlayer::winFound = -1;

// constructor function that initializes the player's checker and intelligence level
CPUPlayer::CPUPlayer(string playerChecker, int intelLevel)
	: checker(playerChecker), intelligenceLevel(intelLevel)
{
	// empty body
}	// end CPUPlayer constructor 

// method that returns the player's checker as a string
string CPUPlayer::getChecker() const {
	return checker;
}

// method that sets the player's checker to the given string value
void CPUPlayer::setChecker(string playerChecker) {
	checker = playerChecker;
}

// method that returns the player's intelligence level as an integer
int CPUPlayer::getIntelligenceLevel() const {
	return intelligenceLevel;
}

// method that sets the player's intelligence level to the given integer value
void CPUPlayer::setIntelligenceLevel(int newIntelligenceLevel) {
	intelligenceLevel = newIntelligenceLevel;
}

// method that returns the player's intelligence level used recursively in the scores_for method
int CPUPlayer::getCurrentIntelligenceLevel() const {
	return currentIntelligenceLevel;
}

// method that sets the player's intelligence level used recursively in the scores_for method
void CPUPlayer::setCurrentIntelligenceLevel(int newIntelligenceLevel) {
	currentIntelligenceLevel = newIntelligenceLevel;
}

// method that returns the checker of the next (recursive) opponent's checker in the scores_for method
string CPUPlayer::getNextOpponentChecker(void) const {
	return nextOpponentChecker;
}

// method that sets the checker of the next (recursive) opponent's checker in the scores_for method
void CPUPlayer::setNextOpponentChecker(string nextOppChecker) {
	nextOpponentChecker = nextOppChecker;
}

// method that returns the checker of the next (recursive) player's checker in the scores_for method
string CPUPlayer::getNextChecker(void) const {
	return nextChecker;
}

// method that sets the checker of the next (recursive) player's checker in the scores_for method
void CPUPlayer::setNextChecker(string nxtChecker) {
	nextChecker = nxtChecker;
}


// method that returns the player's opponent's checker as a string
string CPUPlayer::getOpponentChecker(void) const {
	if (getChecker() == "X") {
		return "O";
	}
	else {
		return "X";
	}
}

// method that prints the player's string representation
void CPUPlayer::print(void) const {
	cout << "\nCPU Player " << checker << " (difficulty level " << intelligenceLevel + 1 << ")";
}

// method that takes a vector of column scores, and returns the column with the maximum score (unless a win or loss was found)
int CPUPlayer::max_score_column(vector<int> scoresVector) {
	int maxScoreValue;	// declare the variable to hold the maximum score
	maxScoreValue = *max_element(scoresVector.begin(), scoresVector.end());	 // get maximum score value in input vector
	int maxScore = int(maxScoreValue);	// make sure that maximum score is of type 'int'

	vector<int> maxValueVector(scoresVector.size(), -1);	// declare vector with size equal to that of the input vector; initialize vector values to -1
	int maxColumns = 0;	 // initialize variable to hold the number of columns in the input vector that have a score equal to the maximum score
	for (unsigned int i = 0; i < scoresVector.size(); i++) {	// iterate over entire input vector
		if (scoresVector[i] == maxScore) {	// take if branch if vector value is equal to the maximum score
			maxValueVector[maxColumns] = i;	// save column index in vector holding the max-value columns
			maxColumns++;	// increment number of columns that have maximum score
		}
	}
	int randomColumn = rand() % maxColumns;	// choose column index with maximum score at random
	if (firstLossColumn != -1) {	// if branch taken if a loss was found (before a win was found)
		int tempColumn = firstLossColumn;	// save column that caused first loss in temporary variable
		firstLossColumn = -1;	// reset firstLossColumn variable to -1
		return tempColumn;	// return column
	}
	else if (winFound != -1) {	// else if branch taken if a win was found (before a loss was found)
		int tempColumn = winFound;	// save column that caused first win in temporary variable
		winFound = -1;	// reset winFound variable to -1
		return tempColumn;	// return column
	}
	else {
		return maxValueVector[randomColumn];	// if win or loss was not found, return random column in vector holding max-score columns
	}
}

// method that returns the column scores for the player, with the scores representing which column the player should choose to place their next checker (place checker in max-score column)
vector<int> CPUPlayer::scores_for(Board board, string checker, int intelligenceLevel, vector <int> scoresVector) {
	// declare three Connect games: one of the games will be used (depending on game user is playing) to access Connect member functions
	Connect3 newGame3;
	Connect4 newGame4;
	Connect5 newGame5;

	Connect* connectNewGamePtr = NULL;	// declare Connect pointer variable; initialize it to null
	if (board.getHeight() == 4) {	// branch taken if Connect3 is being played
		connectNewGamePtr = &newGame3;	// point Connect pointer variable to new Connect3 game memory location
	}
	else if (board.getHeight() == 6) {	// branch taken if Connect4 is being played
		connectNewGamePtr = &newGame4;	// point Connect pointer variable to new Connect4 game memory location
	}
	else {	// branch taken if Connect5 is being played
		connectNewGamePtr = &newGame5;	// point Connect pointer variable to new Connect5 game memory location
	}

	// check if this is the first iteration of the method to initialize private data members only once (since this method may be called recursively)
	if (firstIteration == 1) {
		CPUVector.resize(board.getWidth(), 50);	// resize vector holding CPU's final scores to the width of the board; initialize values to 50
		OppVector.resize(board.getWidth(), 50); // resize vector holding opponent's scores to the width of the board; initialize values to 50
		nextVector.resize(board.getWidth(), 50); // resize vector holding next (recursive) vector's scores to the width of the board; initialize values to 50
		scoresVector.resize(board.getWidth(), 50);	// resize vector holding current vector's scores to the width of the board; initialize values to 50
		setCurrentIntelligenceLevel(getIntelligenceLevel());	// set variable currentIntelligenceLevel to the player's intelligence level
		firstIteration++;	// increment static data member so that this if-branch is not taken again during potential recursive calls
	}

	// iterate over entire length of the board to get column scores
	for (int column = 0; column < board.getWidth(); column++)
	{
		if (board.can_add_to(column) == false) {	// branch taken if the current column is full
			scoresVector[column] = -1;
		}
		else if ((connectNewGamePtr->is_win_for(board, checker)) == true) {	// branch taken if the current player has won
			scoresVector[column] = 100;
		}
		else if ((connectNewGamePtr->is_win_for(board, getNextOpponentChecker())) == true) {  // branch taken if the opponent player has won
			scoresVector[column] = 0;
		}
		else if (intelligenceLevel <= 0) {	// branch taken if intelligence level has reached 0 (ends recursive calling)
			scoresVector[column] = 50;
		}

		else {
			board.add_checker(checker, column);  // add checker to column to test what the result will be 
			if (checker == "O") {	// branch taken if current player is CPU Player playing main Connect game
				setNextChecker("X");	// set the checker to be used in next recursive call to "X" (opposite CPU's checker)
				nextOpponentChecker = "O";	// set the opponent's checker to be used in next recursive call to "O" (CPU's checker)
				OppVector = scores_for(board, getNextChecker(), intelligenceLevel - 1, nextVector);	// recursively call method with updated parameters
			}
			else {	// branch taken if current player is the opponent to CPU Player playing main Connect game
				setNextChecker("O");  // set the checker to be used in next recursive call to "O" (CPU's checker)
				nextOpponentChecker = "X";	// set the opponent's checker to be used in next recursive call to "X" (opposite CPU's checker)
				OppVector = scores_for(board, getNextChecker(), intelligenceLevel - 1, nextVector);	// recursively call method with updated parameters
			}

			int maxScoreValue;	// declare the variable to hold the maximum score
			maxScoreValue = *max_element(OppVector.begin(), OppVector.end());	// get maximum score value in input vector
			int maxScore = int(maxScoreValue);  // make sure that maximum score is of type 'int'

			if (maxScore == 0) {	// take branch if maximum value in vector is 0 (loss was found for opponent)
				if (firstLossColumn == -1 && checker == "X" && winFound == -1) {
					firstLossColumn = column;	// set static private data member equal to the column index that caused the loss
				}
				scoresVector[column] = 100;
			}
			else if (maxScore == 100) {	 // take branch if maximum value in vector is 100 (win was found for opponent)
				if (firstLossColumn == -1 && checker == "O" && winFound == -1) {
					winFound = column;	// set static private data member equal to the column index that caused the win
				}
				scoresVector[column] = 0;
			}
			else if (maxScore == 50) {	// take branch if maximum value in vector is 50 (no win or loss found for opponent)
				scoresVector[column] = 50;
			}
			board.remove_checker(column);  // remove the checker from the board (as it was only used to see what would result if checker was placed)
		}
	}
	return scoresVector;	// return the vector holding the scores for each column
}

// method that processes the next move of the player, given a Board object as input
int CPUPlayer::next_move_CPU(Board board) {
	vector<int> scores = scores_for(board, getChecker(), getIntelligenceLevel(), CPUVector);  // get scores for each column; pass board, CPU checker, intelligence and vector as input
	firstIteration = 1;	// reset static private data member back to 1 (as it may have been changed by method just called) 
	return max_score_column(scores);	// get column to put next checker in, decided by method called
}