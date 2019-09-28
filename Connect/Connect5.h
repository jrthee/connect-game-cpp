#pragma once

///////////////////////////////////////////////
// Julia Thee
// CIS554-70618 Object Oriented Programming in C++
// Final Project
// Connect Game: Class Connect5 interface
// Date: 09/17/2019
///////////////////////////////////////////////

#ifndef __CONNECT5_H__
#define __CONNECT5_H__

#include "Connect.h"  // include definition of class Connect

// Declarations of Connect5 class member functions and member data;
// Member functions override virtual functions in abstract-base-class Connect
class Connect5 : public Connect
{
public:
	virtual bool is_horizontal_win(Board, string checker) const;	// method that checks for a horizontal win for the specified checker on the given board
	virtual bool is_vertical_win(Board, string checker) const;	// method that checks for a vertical win for the specified checker on the given board
	virtual bool is_up_diagonal_win(Board, string checker) const;  // method that checks for an up diagonal win for the specified checker on the given board
	virtual bool is_down_diagonal_win(Board, string checker) const;  // method that checks for a down diagonal win for the specified checker on the given board
};

#endif