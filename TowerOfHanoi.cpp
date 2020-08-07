/*
 * Tower of Hanoi game.
 * Developed as a portfolio projected by River Robinson.
 * Date: 7/23/2020 - 8/7/2020
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

 /// Prototype function for the startText() function.
void startText();

/// Prototype function for the howToPlay() function.
void howToPlay();

/// Prototype function for the newGame() function.
int newGame();

/// Prototype function for the displayColumns() function.
void displayColumns(std::stack<int> columnOne,
	std::stack<int> columnTwo,
	std::stack<int> columnThree);

/// Prototype function for the toLower() function.
std::string toLower(std::string str);

/// Prototype function for the playAgain() function.
bool playAgain();

/// Prototype function for the moveDisk() function.
void moveDisk(std::stack<int> & stkA, std::stack<int> & stkB);

/// Prototype function for the bool validateSelectedColumn() function.
bool validateSelectedColumn(std::string column);

/// Prototype function for the bool validMove() function.
bool validMove(std::stack<int> columnOne, std::stack<int> columnTwo);

/**
 * main function that provides the primary operations of the game.
 *
 * @return 0 to exit the program once the user is finished.
 */
int main() {
	// Call the startText() function and display the start menu.
	startText();

	// By default, this is false so that the game will run.
	// Once the game finishes and the user choses not to play
	// again, this will be set to true and the application with end.
	bool continuePlaying = true;

	// While continuePlaying is set to true, this will loop until the user chooses to be done.
	while (continuePlaying) {

		// Holds how many disks the user wants during their game.
		int disks = newGame();

		// Stack to hold all elements for column one.
		std::stack<int> columnOne;
		// Stack to hold all elements for column two.
		std::stack<int> columnTwo;
		// Stack to hold all elements for column three.
		std::stack<int> columnThree;

		// Push selected number of disks into columnOne in decending order.
		// Start from largest element i and progressively get smaller, stopping
		// at 1.
		for (int i = disks; i >= 1; --i) {
			// Push int i into columnOne.
			columnOne.push(i);
		}

		// This manages whether or not the current game is over
		bool isGameOver = false;

		// If isGameOver is equal to false, continue to loop because the game is
		// still being played by the user.
		while (!isGameOver) {

			// Print 25 new lines so that it appears as though the console has been cleared.
			std::cout << std::string(25, '\n');

			// Display the current status of the game.
			displayColumns(columnOne, columnTwo, columnThree);

			bool isValidMove = false;

			while (!isValidMove) {
				// Holds the first input from the user.
				std::string columnA = "";

				// Displays to the console.
				std::cout << "Which column do you want to move a disk from? : ";
				// Collects the users input.
				std::cin >> columnA;

				// While columnOne is invalid, stay in a loop until the user enters a correct value.
				while (!validateSelectedColumn(columnA)) {

					// Clear the input string.
					columnA.clear();
					// Display to the console.
					std::cout << "Input was invalid. Please try again : ";
					// Collect the user's new input.
					std::cin >> columnA;
				}

				// Holds the first input from the user.
				std::string columnB = "";

				// Displays to the console.
				std::cout << "Which column do you want to move a disk to? : ";
				// Collects the users input.
				std::cin >> columnB;

				// While columnTwo is invalid, stay in a loop until the user enters a correct value.
				while (!validateSelectedColumn(columnB)) {

					// Clear the input string.
					columnB.clear();
					// Display to the console.
					std::cout << "Input was invalid. Please try again : ";
					// Collect the user's new input.
					std::cin >> columnB;
				}

				
				// TODO : Find a better way to implement this somehow.

				// If the users two inputs are not the same, then proceed.
				if (columnA != columnB) {
					// If columnA is equal to a.
					if (toLower(columnA) == "a") {
						// If columnB equals b.
						if (toLower(columnB) == "b") {
							// Check if moving from columnOne to ColumnTwo is valid.
							if (validMove(columnOne, columnTwo)) {
								// Move the top disk from columnOne to columnTwo.
								moveDisk(columnOne, columnTwo);
								// Set isValidMove to true so the loop ends.
								isValidMove = true;
							} else {/* Nothing to do here. doNothing(); */ }
						}
						// Else columbB must be c.
						else {
							// Check if moving from columnOne to ColumnThree is valid.
							if (validMove(columnOne, columnThree)) {
								// Move the top disk from columnOne to columnThree.
								moveDisk(columnOne, columnThree);
								// Set isValidMove to true so the loop ends.
								isValidMove = true;
							} else {/* Nothing to do here. doNothing(); */ }
						}
					}
					// If columnA is equal to b.
					else if (toLower(columnA) == "b") {
						// If columnB is equal to a.
						if (toLower(columnB) == "a") {
							// Check if moving from columnTwo to ColumnOne is valid.
							if (validMove(columnTwo, columnOne)) {
								// Move the top disk from columnTwo to columnOne.
								moveDisk(columnTwo, columnOne);
								// Set isValidMove to true so the loop ends.
								isValidMove = true;
							} else {/* Nothing to do here. doNothing(); */ }
						}
						// Else columnB must be c.
						else {
							// Check if moving from columnTwo to ColumnThree is valid.
							if (validMove(columnTwo, columnThree)) {
								// Move the top disk from columnTwo to columnOne.
								moveDisk(columnTwo, columnThree);
								// Set isValidMove to true so the loop ends.
								isValidMove = true;
							} else {/* Nothing to do here. doNothing(); */ }
						}
					}
					// Else columnA must be c.
					else {
						// If columnB is equal to a.
						if (toLower(columnB) == "a") {
							// Check if moving from columnThree to ColumnOne is valid.
							if (validMove(columnThree, columnOne)) {
								// Move the top disk from columnThree to columnOne.
								moveDisk(columnThree, columnOne);
								// Set isValidMove to true so the loop ends.
								isValidMove = true;
							}
							else {/* Nothing to do here. doNothing(); */ }
						}
						// Else columnB must be a.
						else {
							// Check if moving from columnThree to ColumnTwo is valid.
							if (validMove(columnThree, columnTwo)) {
								// Move the top disk from columnThree to columnTwo.
								moveDisk(columnThree, columnTwo);
								// Set isValidMove to true so the loop ends.
								isValidMove = true;
							}
							else {/* Nothing to do here. doNothing(); */ }
						}
					}
				}
				// Else the user entered the same columns.
				else {
					// Tell the user they cannot pick the same column.
					std::cout << "You cannot pick the same columns!" << std::endl << std::endl;
				}

				// If isValidMove is still false, then the users move was invalid.
				if (!isValidMove) {
					// Tell the user the move was invalid.
					std::cout << "That move is not valid!" << std::endl;
				}else{ /* Nothing to do here. doNothing(); */ }
			}

			// The only way for the game to be complete is if columnOne is completely empty,
			// and for columnTwo or columnThree has all of the disks in it. Therefore, if 
			// columnTwo or columnThree is the same size as the number of disks in the game,
			// then the user has successfully completed the game.
			if (columnTwo.size() == disks || columnThree.size() == disks) {

				// Set isGameOver to true so the loop ends.
				isGameOver = true;

				// Display a congratulations message to the user.
				std::cout << std::endl << "Congratulations! You won!" << std::endl << std::endl;
			}
			else { /* There is nothing to do here. doNothing(); */ }
		}

		// Call the playAgain() function to see if they would like to play again, then set the
		// variable continuePlaying to whatever is returned. continuePlaying controls the parent
		// while loop.
		continuePlaying = playAgain();
	}

	// Return 0 to exit the program.
	return 0;
}

/**
 * Basic function that outputs a series of texts, introducting what the game is
 * and why this project exists. This function is only launched at the start of the
 * program to welcome users to the game.
 */
void startText() {
	// Output the following text to the console for the user to read.
	std::cout << "Welcome to Tower of Hanoi in the console." << std::endl;
	std::cout << "This project was written by River Robinson entirely in C++." << std::endl << std::endl;
	std::cout << "Tower of Hanoi is a mathematical game that consists of three posts" << std::endl;
	std::cout << "and a stack of disks of different sizes. The goal of the game is to" << std::endl;
	std::cout << "move the entire stack of disks from one post to another. This project" << std::endl;
	std::cout << "has adapted the game to use columns instead of posts and numbers" << std::endl;
	std::cout << "instead of disks." << std::endl << std::endl;

	// Call the howToPlay() function so that the rules and instructions are displayed.
	howToPlay();
}

/**
 * Displays the rules of the game and how to play through an output of text to the console.
 * This function is called whenever the player needs to view the rules while the game is
 * in play.
 */
void howToPlay() {
	// Output the following text to the console for the user to read.
	std::cout << "There are three rules to play." << std::endl;
	std::cout << "1.) Only one disk can be moved in a single turn." << std::endl;
	std::cout << "2.) Each turn, a single disk can be placed onto another disk" << std::endl;
	std::cout << "    or into an empty column." << std::endl;
	std::cout << "3.) A larger disk cannot be placed onto a smaller disk." << std::endl << std::endl;
	std::cout << "To play, enter the letter of which column you would" << std::endl;
	std::cout << "like to move the disk from and hit enter, a second line" << std::endl;
	std::cout << "will appear for you to enter the letter of the column" << std::endl;
	std::cout << "that you would like to enter the disk into." << std::endl << std::endl;
	std::system("pause");
	std::cout << std::endl << std::endl << std::endl;
}

/**
 * This function is called so that whenever a new game is started, the user
 * can select how many disks they would like to have during their game.
 *
 * @return an int value containing how many disks the user wants to use.
 */
int newGame() {

	// Holds the total amount of disks the user wants to use. 
	int disks = -1;

	// While 
	while (disks < 3 || disks > 9) {

		// Ask the user how many disks they would like in their game.
		std::cout << "How many rings would you like?" << std::endl;
		std::cout << "Enter a number between 3 and 9 : ";

		// Collect an input from the user.
		std::cin >> disks;

		// If our input happened but the data was not a valid integer.
		if (std::cin.fail()) {
			// Clear our cin error.
			std::cin.clear();
			// Ignore the first 1000 characters within our cin statement.
			std::cin.ignore(1000, '\n');
			// Let the user know that they should try again using a number.
			std::cout << "Woops! Thats not a number. Lets try that again." << std::endl << std::endl;
		}
		// If the user entered a value that is less than 3 or greater than 10.
		else if (disks < 3 || disks > 9) {
			// Let the user know the number they entered is invalid.
			std::cout << "Woops! It looks like that number is invalid. lets try that again!" << std::endl << std::endl;
		}
		else {
			// Nothing goes within this else statement, therefore, doNothing();
		}
	}

	// Return how many disks the user wants.
	return disks;
}

/**
 * This function takes three stack objects and outputs them to the console
 * in a graphical manner that allows the user to visualize their game.
 *
 * @stack object for column one.
 *
 * @stack object for column two.
 *
 * @stack object for column three.
 */
void displayColumns(std::stack<int> columnOne,
					std::stack<int> columnTwo,
					std::stack<int> columnThree) {

	// Holds the value of which 'row' is currently being read.
	// This is set to whichever column is the largest.
	int currentRow = 0;

	// If columnOne is larger than columnTwo and columnThree.
	if ((columnOne.size() >= columnTwo.size()) && (columnOne.size() >= columnThree.size())) {
		// Set currentRow to be equal to the size of columnOne.
		currentRow = columnOne.size();
	}
	// Else if, columnTwo is larger than columnOne and columnThree.	
	else if ((columnTwo.size() >= columnOne.size()) && (columnTwo.size() >= columnThree.size())) {
		// Set currentRow to be equal to the size of columnTwo.
		currentRow = columnTwo.size();
	}
	// Else, by process of elimination, columnThree must be the largest.
	else {
		// Set currentRow to be equal to the soze of columnThree.
		currentRow = columnThree.size();
	}

	// Formatting for the console.
	std::cout << "-------------------" << std::endl;

	// While our current row is not equal to zero, then continue
	// to loop. Everything within this loop is printed on the same
	// line, the loop is to format each line individually.
	while (currentRow != 0) {

		// Formatting for the console.
		std::cout << "|  ";

		// If columnOne is equal in size to the currentRow, output the 
		// top of the column then delete the top element.
		if (columnOne.size() == currentRow) {
			// Display the top element to the console.
			std::cout << columnOne.top();
			// Pop off the top element.
			columnOne.pop();
		}
		else {
			// Add a single space to help keep the columns the same size.
			std::cout << " ";
		}

		// Formatting for the console.
		std::cout << "  |  ";

		// If columnTwo is equal in size to the currentRow, output the 
		// top of the column then delete the top element.
		if (columnTwo.size() == currentRow) {
			// Display the top element to the console.
			std::cout << columnTwo.top();
			// Pop off the top element.
			columnTwo.pop();
		}
		else {
			// Add a single space to help keep the columns the same size.
			std::cout << " ";
		}

		// Formatting for the console.
		std::cout << "  |  ";

		// If columnThree is equal in size to the currentRow, output the 
		// top of the column then delete the top element.
		if (columnThree.size() == currentRow) {
			// Display the top element to the console.
			std::cout << columnThree.top();
			// Pop off the top element.
			columnThree.pop();
		}
		else {
			// Add a single space to help keep the columns the same size.
			std::cout << " ";
		}

		// Formatting for the console.
		std::cout << "  |";

		// Create a new line.
		std::cout << std::endl;

		// Subtract one from currentRow.
		--currentRow;
	}

	// Formatting for the console.
	std::cout << "-------------------" << std::endl;
	std::cout << "   A     B     C   " << std::endl;

	// Nothing left to do, so this function is over. return 0;
}

/**
 * Takes a string and converts it to lowercase. std::lower accepts a single char
 * this accepts an entire string.
 *
 * @std::string to be converted to all lowercase.
 *
 * @return a string that has been converted to all lowercase.
 */
std::string toLower(std::string str) {

	// Transform each character of str by using std::lower, starting at the beginning,
	// and ending at the end of the string.
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);

	// Return the string after being transformed.
	return str;
}

/**
 * Asks the user if they would like to play again, then takes
 * an input of y, Y, n, or N and returns true of false based
 * on their input.
 *
 * @return true or false based on the users input.
 */
bool playAgain() {

	// Create an endless loop here, we will return from within the loop.
	while (true) {

		// Holds the input from the user, in regards to if they want to play again or not.
		std::string input = "";

		// Ask the user if they want to play again.
		std::cout << "Would you like to play again? y/n : ";
		// Collect the input from the user.
		std::cin >> input;

		// If the user inserted something other than 'y', 'Y', 'n', 'N', then tell
		// the user that their input is invalid.
		if (toLower(input) != "y" && toLower(input) != "n") {
			// Output that the input is invalid.
			std::cout << "'" << input << "'" << " is not a valid input." << std::endl;
		}
		// Else if, the user entered 'n' or 'N'.
		else if (toLower(input) == "n") {
			// Return false because the user does not want to play again.
			return false;
		}
		else {
			// else, the user entered 'y' or 'Y', therefore turn true because they want to play again.
			return true;
		}
	}
}

/**
 * Take the top element of one stack and place it within a second stack.
 *
 * @std::stack that the disk should be removed from.
 *
 * @std::stack that the disk should be placed into.
 */
void moveDisk(std::stack<int> & stkA, std::stack<int> & stkB) {

	// Take the top element of stkA and place it on top of stkB.
	stkB.emplace(stkA.top());

	// Remove the top element of stkA.
	stkA.pop();
}

/**
 * Takes an input string and determines whether it is equal to
 * A, B, or C.
 *
 * @string to be verified.
 *
 * @return true or false in regards to if it is valid.
 */
bool validateSelectedColumn(std::string column) {

	// Convert the input to lowercase 
	column = toLower(column);

	// If the input is not equal to a, b, or c then return false.
	if (column != "a" && column != "b" && column != "c") {
		return false;
	}
	// Since we returned false on anything that wasn't a, b, or c
	// then the input must be valid, so return true.
	else {
		return true;
	}
}

/**
 * Check the validity of the move.
 *
 * @std::string that contains the column the disk is being moved from.
 *
 * @std::string that contains the column the disk is being moved to.
 *
 * @return true or false depending on whether or not the move is valid.
 */
bool validMove(std::stack<int> columnOne, std::stack<int> columnTwo) {
	
	// Check to make sure columnOne is not empty.
	if (!columnOne.empty()) {
		// Check to see if columnTwo is empty.
		if (!columnTwo.empty()) {
			// Check to see if the disk being placed is smaller than
			// the disk it is being placed onto.
			if (columnOne.top() <= columnTwo.top()) {
				return true;
			}
			// Else the disk being moved is larger than the one
			// it is being placed onto.
			else {
				return false;
			}
		}
		// Else, column two is empty and the disk can be moved.
		else {
			return true;
		}
	}
	// Else columnOne is empty, meaning there is no disk to move.
	else {
		return false;
	}
}