#pragma once

///////////////////////////////////////////////
// Julia Thee
// Connect Game: Class Connect3 interface
///////////////////////////////////////////////

#ifndef __CONNECT3_H__
#define __CONNECT3_H__

#include "Connect.h"  // include definition of class Connect

// Declarations of Connect3 class member functions and member data;
// Member functions override virtual functions in abstract-base-class Connect
class Connect3 : public Connect
{
public:
	virtual bool is_horizontal_win(Board, string checker) const;	// method that checks for a horizontal win for the specified checker on the given board
	virtual bool is_vertical_win(Board, string checker) const;	// method that checks for a vertical win for the specified checker on the given board
	virtual bool is_up_diagonal_win(Board, string checker) const;  // method that checks for an up diagonal win for the specified checker on the given board
	virtual bool is_down_diagonal_win(Board, string checker) const;  // method that checks for a down diagonal win for the specified checker on the given board
};

#endif