#pragma once

///////////////////////////////////////////////
// Julia Thee
// CIS554-70618 Object Oriented Programming in C++
// Final Project
// Connect Game: Class Player interface
// Date: 09/17/2019
///////////////////////////////////////////////

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Board.h"	// include definition of class Board
#include <string>
using std::string;

// Player abstract-base-class definition
class Player
{
public:
	virtual string getChecker(void) const = 0;	// abstract method that returns the player's checker as a string 
	virtual int getIntelligenceLevel(void) const = 0;	// abstract method that returns the player's intelligence level as a string
	virtual void print(void) const = 0;	 // abstract method that prints the player's string representation
	virtual int next_move(Board) const = 0;  // abstract method that processes the next move of the player (real or random (CPU) player), given a Board object as input
	virtual int next_move_CPU(Board) = 0;  // abstract method that processes the next move of the player (CPU player), given a Board object as input
};

#endif