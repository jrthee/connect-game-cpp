#pragma once

///////////////////////////////////////////////
// Julia Thee
// CIS554-70618 Object Oriented Programming in C++
// Final Project
// Connect Game: Class CPUPlayer interface
// Date: 09/17/2019
///////////////////////////////////////////////

#ifndef __CPU_PLAYER_H__
#define __CPU_PLAYER_H__

#include "Player.h"	// include definition of class Player

// Declarations of CPUPlayer class member functions and member data;
// Member functions override virtual functions in abstract-base-class Player
class CPUPlayer : public Player
{
public:
	CPUPlayer(string checker, int intelligenceLevel);	// constructor function that initializes the player's checker and intelligence level
	virtual string getChecker(void) const;	// method that returns the player's checker as a string
	void setChecker(string checker);	// method that sets the player's checker to the given string value
	int getIntelligenceLevel(void) const;	// method that returns the player's intelligence level as an integer
	void setIntelligenceLevel(int intelligenceLevel);	// method that sets the player's intelligence level to the given integer value
	int getCurrentIntelligenceLevel(void) const;	// method that returns the player's intelligence level used recursively in the scores_for method
	void setCurrentIntelligenceLevel(int intelligenceLevel);	// method that sets the player's intelligence level used recursively in the scores_for method
	string getOpponentChecker(void) const;	// method that returns the player's opponent's checker as a string
	string getNextOpponentChecker(void) const;	// method that returns the checker of the next (recursive) opponent's checker in the scores_for method
	void setNextOpponentChecker(string);	// method that sets the checker of the next (recursive) opponent's checker in the scores_for method
	string getNextChecker(void) const;	// method that returns the checker of the next (recursive) player's checker in the scores_for method
	void setNextChecker(string);	// method that sets the checker of the next (recursive) player's checker in the scores_for method
	virtual void print(void) const;	// method that prints the player's string representation
	virtual int next_move(Board) const { return 0; };	// method that processes the next move of the player, given a Board object as input
	virtual int next_move_CPU(Board);	// method that processes the next move of the CPU player, given a Board object as input
	vector<int> scores_for(Board, string checker, int intelligenceLevel, vector<int>);	// method that returns the column scores for the player
	int max_score_column(vector<int>);	// method that takes a vector of column scores, and returns the column with the maximum score (unless a win or loss was found)

private:
	string checker = "";	// private data member representing the player's checker
	int intelligenceLevel = 0;	// private data member representing the player's intelligence level
	int currentIntelligenceLevel = 0;	// private data member representing the player's current intelligence level (needed for recursion)
	string nextOpponentChecker = "X";	// private data member representing the opponent's checker in the next recursive iteration
	string nextChecker = "O";	// private data member representing the player's checker in the next recursive iteration
	static int firstIteration;	// static private data member indicating if this is the first iteration in the process to find the scores for the board
	static int firstLossColumn;	// static private data member representing which column resulted in the first loss detected (unless a win was found first)
	static int winFound;	// static private data member representing which column resulted in the first win detected (unless a loss was found first)
	vector<int> CPUVector;	// private data member representing the vector holding the CPU's final scores for the board
	vector<int> OppVector;	// private data member representing the vector holding the opponent's scores for the board that resulted from recursion
	vector<int> nextVector; // private data member representing the vector that will be used in the next recursive iteration
	vector<int> scoresVector;	// private data member representing the vector that is used in the current recursive iteration
};

#endif