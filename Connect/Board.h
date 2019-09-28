#pragma once

///////////////////////////////////////////////
// Julia Thee
// CIS554-70618 Object Oriented Programming in C++
// Final Project
// Connect Game: Board class member functions and member data declarations
// Date: 09/17/2019
///////////////////////////////////////////////

#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <string>
#include <array>
#include <vector>
using std::string;
using std::array;
using std::vector;

// Declarations of Board class member functions and member data
class Board
{
public:
	explicit Board(int height, int width);	// constructor initializes the board height and width
	int getHeight(void) const;	// method returns the board height as an integer
	void setHeight(int newHeight);  // method sets the board height as the input value
	int getWidth(void) const;	// method returns the board width as an integer
	void setWidth(int newWidth);  // method sets the board width as the input value

	void clearBoard(void);	// method clears the board so that no checkers are on the board 
	void add_checker(string checker, int column);	// method adds specified checked to specified column
	bool can_add_to(int column);	// method returns a boolean value indicating if a checker can be placed in the specified column
	bool is_full(void);		// method returns a boolean value indicating if the board is full of checkers
	void remove_checker(int column);	// method removes the topmost checker in the specified column

	void setSlots(int row, int column, string checker);	// method updates the board slot at the given row/column index to the input checker value
	vector<vector<string>> getSlots() const;	// method returns a 2D vector representation of the board's column values
	vector<vector<string>> getSlotsUsingRef() const;  // method returns a reference to the board's 2D vector representation

	void print(void) const;	// method prints the board as a 2D vector representation of the board's column values using a reference to the vector

private:
	int height = 0;	// private data member representing the board height
	int width = 0;	// private data member representing the board width 
	vector < vector < string> > slots;	// private data member representing the 2D board and the checkers within it
};	// end class Board

#endif