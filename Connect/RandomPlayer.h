#pragma once

///////////////////////////////////////////////
// Julia Thee
// CIS554-70618 Object Oriented Programming in C++
// Final Project
// Connect Game: Class RandomPlayer interface
// Date: 09/17/2019
///////////////////////////////////////////////

#ifndef __RANDOM_PLAYER_H__
#define __RANDOM_PLAYER_H__

#include "Player.h"	// include definition of class Player

// Declarations of RandomPlayer class member functions and member data;
// Member functions override virtual functions in abstract-base-class Player
class RandomPlayer : public Player
{
public:
	RandomPlayer(string checker, int intelligenceLevel);	// constructor function that initializes the player's checker and intelligence level
	virtual string getChecker(void) const;	// method that returns the player's checker as a string
	void setChecker(string checker);	// method that sets the player's checker to the given string value
	int getIntelligenceLevel(void) const;	// method that returns the player's intelligence level as an integer
	void setIntelligenceLevel(int intelligenceLevel);	// method that sets the player's intelligence level to the given integer value
	string getOpponentChecker(void) const;	// method that returns the player's opponent's checker as a string

	virtual void print(void) const;	// method that prints the player's string representation
	virtual int next_move(Board) const;	// method that processes the next move of the player, given a Board object as input
	virtual int next_move_CPU(Board) { return 0; };	// method that processes the next move of the CPU player, given a Board object as input

private:
	string checker = "";	// private data member representing the player's checker
	int intelligenceLevel = 0;	// private data member representing the player's intelligence level
};

#endif