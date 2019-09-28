#pragma once

///////////////////////////////////////////////
// Julia Thee
// Connect Game: Connect abstract-base-class definition
///////////////////////////////////////////////

#ifndef __CONNECT_H__
#define __CONNECT_H__

#include "Board.h"	// include definition of class Board
#include "RealPlayer.h"	// include definition of class RealPlayer
#include "RandomPlayer.h"	// include definition of class RandomPlayer
#include "CPUPlayer.h"	// include definition of class CPUPlayer
#include <iostream>
#include <string>
#include <array>
#include <vector>
using std::string;
using std::array;
using std::vector;

// Connect abstract-base-class definition
class Connect
{
public:
	Connect(); // default constructor
	int getGameOver(void) const; // method returns the game status (game over or not over) as an integer
	void setGameOver(int gameOver); // method sets the game status (game over or not over) as an integer
	void play_game(Board, Player* player1, Player* player2); // method that initiates the game play by accepting a board and two players as input
	Board process_move(Board, Player* player); // method that processes next move (adding the next checker and checking for a win or tie); accepts a board and player as input
	bool is_win_for(Board, string checker);	// method that returns either true or false indicating if the specified checker has won the game on the given board
	virtual bool is_horizontal_win(Board, string checker) const = 0;	// abstract method that checks for a horizontal win for the specified checker on the given board
	virtual bool is_vertical_win(Board, string checker) const = 0;	// abstract method that checks for a vertical win for the specified checker on the given board
	virtual bool is_up_diagonal_win(Board, string checker) const = 0;  // abstract method that checks for an up diagonal win for the specified checker on the given board
	virtual bool is_down_diagonal_win(Board, string checker) const = 0;  // abstract method that checks for a down diagonal win for the specified checker on the given board

private:
	static int gameOver;	// static private data member representing whether or not the game is still ongoing (there has not been a win or tie yet)
};

#endif