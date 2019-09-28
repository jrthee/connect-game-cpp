///////////////////////////////////////////////
// Julia Thee
// Connect Game: Board class member functions and member data implementations
///////////////////////////////////////////////

#include "Board.h"	// include definition of class Board	
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::to_string;

// constructor initializes the private data members representing the board height and width using user input values
Board::Board(int boardHeight, int boardWidth)
	: height(boardHeight), width(boardWidth)
{
	// empty body; all initialization done by this point
}	// end Board constructor 

// method returns the height of the board as an integer
int Board::getHeight() const {
	return height;
}

// method sets the height of the board to the specified height value
void Board::setHeight(int newHeight) {
	height = newHeight;
}

// method returns the width of the board as an integer
int Board::getWidth() const {
	return width;
}

// method sets the width of the board to the specified width value
void Board::setWidth(int newWidth) {
	width = newWidth;
}

// method clears the board by setting all elements of the 2D board vector to an empty space;
// method resizes the vector to the board's height and width
void Board::clearBoard(void) {
	slots.resize(getHeight(), vector<string>(getWidth(), " "));
}

// method puts the specified checker in the topmost available position in the specified column
void Board::add_checker(string checker, int column) {
	vector<vector<string>> slots = getSlots();	// set local variable to 2D board vector of board's column values 
	if (column >= 0 && column < getWidth()) {	// make sure that the input column is a valid column on the board
		int row = 0;  // start with topmost row 
		// iterate through the rows of the board until the last (bottom-most) empty space in the given column is found
		while ((row < (getHeight() - 1)) && (slots.at(row + 1).at(column) == " ")) {
			row++;	// increment row each time an empty space in the given column is found
		}
		setSlots(row, column, checker);	// update bottom-most empty space in given column to the specified checker
	}
}

// method returns a boolean value indicating if the specified column can have a checker added to it (is the column full?)
bool Board::can_add_to(int column) {
	vector<vector<string>> slots = getSlots();	// set local variable to 2D board vector of board's column values 
	if (column >= 0 && column < getWidth()) {	// make sure that the input column is a valid column on the board
		if (slots.at(0).at(column) == " ") {	// check if topmost position in column is an empty space
			return true;	// if topmost position in column is an empty space, then this column can be added to
		}
		else {
			return false;  // if topmost position in column is not an empty space, then this column is full and cannot be added to
		}
	}
	return false;	// invalid column was given as input
}

// method returns a boolean value indicating if the board is full of checkers (if so, all columns are full of checkers)
bool Board::is_full(void) {
	for (int column = 0; column < getWidth(); column++) {	// iterate over every column in the board
		if (can_add_to(column) == true) {	// check if the column can have a checker added to it (by calling can_add_to method)
			return false;	// return false if column is not full
		}
	}
	return true;	// if this point is reached, every column is full of checkers, so return true indicating that the board is full
}

// method removes the topmost checker from the specified column
void Board::remove_checker(int column) {
	vector<vector<string>> slots = getSlots();	// set local variable to 2D board vector of board's column values 
	int row = 0;  // start with topmost row 
	if (column >= 0 && column < getWidth()) {	// make sure that the input column is a valid column on the board
		// iterate through the rows of the board until the topmost checker in the given column is found
		while ((row < (getHeight() - 1)) && (slots.at(row).at(column) == " ")) {
			row++;	// increment row each time an empty space in the given column is found
		}
		setSlots(row, column, " ");	// update topmost checker in given column to an empty space
	}
}

// method updates the board slot at the given row and column index to the input checker value
void Board::setSlots(int row, int column, string checker) {
	slots.at(row).at(column) = checker;
}

// method returns a 2D vector representation of the board's column values
vector<vector<string>> Board::getSlots() const {
	return slots;
}

// method returns a reference to the board's 2D vector representation
vector<vector<string>> Board::getSlotsUsingRef() const {
	vector<vector<string>> const& slotsRef = slots;	// set local variable as reference to private data member slots
	return slotsRef;
}

// method prints the board as a 2D vector representation of the board's column values using a reference to the vector
void Board::print() const {
	string board = "";	// initialize board representation as empty string 
	vector<vector<string>> const& slotsRef = getSlotsUsingRef();	// get reference to board's 2D vector representation

	for (vector<string> row : slotsRef) {	// iterate over each row in vector (using vector reference)
		board += "|";	// add wall to board's string representation
		for (string column : row) {	// iterate over each column in current row of vector
			board += column;	// add value at column to board's string representation
			board += "|";	// add wall to board's string representation
		}
		board += "\n";
	}
	board += (string(getWidth() * 2, '-') + "-");	// add bottom wall (--------) to the board's string representation
	board += "\n";
	for (int col = 0; col < getWidth(); col++) {	// iterate over each column in board
		board += " " + to_string(col + 1);	// add column number under each printed column in board's string representation
	}
	cout << board;	// print board's string representation
}