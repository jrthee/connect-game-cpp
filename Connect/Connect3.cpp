///////////////////////////////////////////////
// Julia Thee
// CIS554-70618 Object Oriented Programming in C++
// Final Project
// Connect Game: Class Connect3 implementation
// Date: 09/17/2019
///////////////////////////////////////////////

#include "Connect3.h"	// include definition of class Connect3
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// method that checks for a horizontal win for the specified checker on the given board (3 checkers in a row horizontally)
bool Connect3::is_horizontal_win(Board board, string checker) const {
	vector<vector<string>> slots = board.getSlots();	// get the current 2D vector of the board's columns and their values
	for (int row = 0; row < board.getHeight(); row++) {	// iterate over all rows in the board
		for (int column = 0; column < board.getWidth() - 2; column++) {	// iterate over all columns in the board
			// if statement below checks if the current checker, and the two checkers immediately to the right, are all equal to the specified checker
			if ((slots.at(row).at(column) == checker) &&
				(slots.at(row).at(column + 1) == checker) &&
				(slots.at(row).at(column + 2) == checker))
			{
				return true;	// the player with the specified checker won horizontally 
			}
		}
	}
	return false;	// the player with the specified checker lost horizontally 
}

// method that checks for a vertical win for the specified checker on the given board (3 checkers in a row vertically)
bool Connect3::is_vertical_win(Board board, string checker) const {
	vector<vector<string>> slots = board.getSlots();	// get the current 2D vector of the board's columns and their values
	for (int row = 0; row < board.getHeight() - 2; row++) {	// iterate over all rows in the board
		for (int column = 0; column < board.getWidth(); column++) {	// iterate over all columns in the board
			// if statement below checks if the current checker, and the two checkers immediately below, are all equal to the specified checker
			if ((slots.at(row).at(column) == checker) &&
				(slots.at(row + 1).at(column) == checker) &&
				(slots.at(row + 2).at(column) == checker))
			{
				return true;	// the player with the specified checker won vertically 
			}
		}
	}
	return false;	// the player with the specified checker lost vertically 
}

// method that checks for a diagonally up win for the specified checker on the given board (3 checkers in a row diagonally up)
bool Connect3::is_up_diagonal_win(Board board, string checker) const {
	vector<vector<string>> slots = board.getSlots();	// get the current 2D vector of the board's columns and their values
	for (int row = 2; row < board.getHeight(); row++) {	// iterate over all rows in the board
		for (int column = 0; column < board.getWidth() - 2; column++) {	// iterate over all columns in the board
			// if statement below checks if the current checker, and the two checkers immediately diagonally up, are all equal to the specified checker
			if ((slots.at(row).at(column) == checker) &&
				(slots.at(row - 1).at(column + 1) == checker) &&
				(slots.at(row - 2).at(column + 2) == checker))
			{
				return true;	// the player with the specified checker won diagonally up 
			}
		}
	}
	return false;	// the player with the specified checker lost diagonally up 
}

// method that checks for a diagonally down win for the specified checker on the given board (3 checkers in a row diagonally down)
bool Connect3::is_down_diagonal_win(Board board, string checker) const {
	vector<vector<string>> slots = board.getSlots();	// get the current 2D vector of the board's columns and their values
	for (int row = 0; row < board.getHeight() - 2; row++) {	// iterate over all rows in the board
		for (int column = 0; column < board.getWidth() - 2; column++) {	// iterate over all columns in the board
			// if statement below checks if the current checker, and the two checkers immediately diagonally down, are all equal to the specified checker
			if ((slots.at(row).at(column) == checker) &&
				(slots.at(row + 1).at(column + 1) == checker) &&
				(slots.at(row + 2).at(column + 2) == checker))
			{
				return true;	// the player with the specified checker won diagonally down 
			}
		}
	}
	return false;	// the player with the specified checker lost diagonally down 
}