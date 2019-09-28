///////////////////////////////////////////////
// Julia Thee
// Connect Game: program test
///////////////////////////////////////////////

#include "Board.h"		// include definition of class Board
#include "Connect.h"	// include definition of class Connect
#include "Connect3.h"	// include definition of class Connect3
#include "Connect4.h"	// include definition of class Connect4
#include "Connect5.h"	// include definition of class Connect5
#include "Player.h"		// include definition of class Player
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;
using std::streamsize;

// Program demonstrating Connect game 
int main()
{
	// declare and initialize local variables
	string playGame = "yes";	// variable representing whether or not the game should be played
	double connectGameTemp = 0.0;	// variable representing the version of Connect chosen by the user to play
	string opponentType = "";	// variable representing the type of opponent chosen (Real player or CPU player)
	double difficultyLevelTemp = -1.0;  // variable representing the difficulty level chosen by the user

	cout << "WELCOME TO CONNECT!\n" << endl;
	cout << "Which Connect game would you like to play?\n" << endl;	// ask user which version of Connect they'd like to play, then display the versions
	cout << "Connect 3" << endl;
	cout << "Connect 4" << endl;
	cout << "Connect 5" << endl;
	cout << "\nType 3, 4 or 5: ";	// prompt user to input which Connect version they'd like to play
	cin >> connectGameTemp;	// save user input

	// while loop checks if valid input has been given, and makes sure that Connect game chosen is between 3 and 5
	while (cin.fail() || connectGameTemp < 3 || connectGameTemp > 5) {
		if (cin.fail()) {	// execute if user enters invalid input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid Connect game (3, 4 or 5): ";  // prompt user to input valid Connect game version
		cin >> connectGameTemp;  // save user input
	}
	int connectGame = connectGameTemp;	// convert connectGame variable from double to integer
	cout << "\nLet's play Connect " << connectGame << "!\n" << endl;

	vector<Player*> playerVector(2);	// declare vector of pointer variables of type Player
	RealPlayer player1(-1);		// declare and initialize RealPlayer object (constructor is overloaded function; checker "X" set as default)
	playerVector[0] = &player1;	// point base class Player pointer to derived class RealPlayer object memory location

	RealPlayer playerReal("O", -1);	// declare and initialize RealPlayer object (constructor is overloaded function)
	RealPlayer& playerRealRef(playerReal);	// declare and initialize reference to RealPlayer object (to demonstrate accessing class member by reference)

	RandomPlayer playerRandom("", 0);	// declare and initialize RandomPlayer object 
	CPUPlayer playerCPU("", 0);	// declare and initialize CPUPlayer object 

	cout << "Would you like to challenge another player or the CPU?\nType \"Player\" or \"CPU\": ";	// ask user which type of opponent they'd like to face
	// discard characters in input (all characters until new line '\n' is reached); this is done so "getline()" function will be executed 
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, opponentType);	// save user input
	// while loop makes sure that a valid opponent type was chosen
	while (opponentType != "Player" && opponentType != "player" && opponentType != "CPU" && opponentType != "cpu") {
		cout << "Please type either \"Player\" or \"CPU\": ";	// prompt user to input valid opponent type
		getline(cin, opponentType);	// save user input
	}

	if (opponentType == "CPU" || opponentType == "cpu") {	// branch taken if user chose CPU as their opponent type
		cout << "\nYou've challenged the CPU! How smart would you like the CPU to be?" << endl; // ask user what difficulty level they'd like to play
		cout << "***Note: The smarter the CPU, the longer it takes to think!\n" << endl;	// the higher the level, the longer it will take the CPU to make their next move
		cout << "1: Very Easy" << endl;  // random guessing CPU (class type RandomPlayer)
		cout << "2: Easy" << endl;	// difficulty levels 2-5 are class type CPUPlayer (player determines which move to make based on looking ahead at potential outcomes)
		cout << "3: Medium" << endl;
		cout << "4: Hard" << endl;
		cout << "5: Very Hard" << endl;

		cout << "\nPlease enter your choice of difficulty level (between 1 and 5): ";	// prompt user to input difficulty level
		cin >> difficultyLevelTemp;	 // save user input
		// while loop checks that input is valid, and that the difficulty level chosen is between 1 and 5
		while (cin.fail() || difficultyLevelTemp < 1 || difficultyLevelTemp > 5) {
			if (cin.fail()) {	// execute if user enters invalid input
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Please enter a valid difficulty level (between 1 and 5): ";	// prompt user to input valid difficulty level
			cin >> difficultyLevelTemp;	// save user input
		}
		int difficultyLevel = difficultyLevelTemp;	// convert difficulty level from double to integer
		difficultyLevel = difficultyLevel - 1;	// subtract 1 from difficultylevel so that correct values are used later in code

		if (difficultyLevel == 0) {	 // indicates that a RandomPlayer should be used as the opponent
			playerVector[1] = &playerRandom;	// point base class Player pointer to derived class RandomPlayer object memory location 
			playerRandom.setChecker("O");	// set checker of RandomPlayer object to be "O"
			playerRandom.setIntelligenceLevel(difficultyLevel);  // set intelligence (difficulty level) of RandomPlayer object to be 0
		}
		else {  // indicates that a CPUPlayer should be used as the opponent
			playerVector[1] = &playerCPU;	// point base class Player pointer to derived class CPUPlayer object memory location 
			playerCPU.setChecker("O");	// set checker of CPUPlayer object to be "O"
			playerCPU.setIntelligenceLevel(difficultyLevel);  // set intelligence (difficulty level) of CPUPlayer object to be equal to the difficulty level chosen
		}
		cout << "\nGreat choice.\n\nYou will be checker " << playerVector[0]->getChecker() << ". ";
		cout << "The CPU will be checker " << playerVector[1]->getChecker() << ".\n\n" << endl;
	}
	else {	// branch taken if user chose another (real) player as their opponent type
		cout << "\nYou've challenged another player!\n" << endl;
		playerVector[1] = &playerReal;	// point base class Player pointer to derived class RealPlayer object memory location 
		playerReal.setChecker("O");	 // set checker of RealPlayer object to be "O"
		playerRealRef.setIntelligenceLevel(-1);	 // use reference to RealPlayer object to set intelligence of RealPlayer object to be equal to -1
		cout << "You will be checker " << playerVector[0]->getChecker() << ". ";
		cout << "Your opponent will be checker " << playerVector[1]->getChecker() << ".\n\n" << endl;
	}

	// create board with size based on Connect game version chosen
	Board board(0, 0);	// declare and initialize board with height and width equal to 0
	int height = (connectGame * 2) - 2;	 // compute the height of the board, based on the Connect game version chosen
	board.setHeight(height);  // set the height of the Board object to the height value computed
	board.setWidth(height + 1); // set the width of the Board object to 1 greater than the height value computed

	board.clearBoard();	 // call the clearBoard() method on the Board object to resize and initialize the board with empty space values
	board.print();	// display the string representation of the Board object

	// declare three Connect games: one of these games will be played (based on the user's input)
	Connect3 connect3;
	Connect4 connect4;
	Connect5 connect5;

	if (connectGame == 3) {	 // take branch if user chose to play Connect3
		Connect* connectPtr = &connect3;  // point base class Connect pointer to derived class Connect3 object memory location 
		connectPtr->play_game(board, playerVector[0], playerVector[1]);	// use base class Connect pointer to initiate the playing of the game
	}
	else if (connectGame == 4) {  // take branch if user chose to play Connect4
		Connect* connectPtr = &connect4;  // point base class Connect pointer to derived class Connect4 object memory location 
		connectPtr->play_game(board, playerVector[0], playerVector[1]); // use base class Connect pointer to initiate the playing of the game
	}
	else {  // take branch if user chose to play Connect5
		Connect* connectPtr = &connect5;  // point base class Connect pointer to derived class Connect5 object memory location 
		connectPtr->play_game(board, playerVector[0], playerVector[1]); // use base class Connect pointer to initiate the playing of the game
	}

	return 0;
}