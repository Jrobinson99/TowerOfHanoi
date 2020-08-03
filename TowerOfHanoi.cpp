/*
 * Tower of Hanoi game.
 * Developed as a portfolio projected by River Robinson.
 * Date: 7/23/2020
 */

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
	bool gameOver = false;

	// While gameOver is equal to false, then keep the game running.
	while (!gameOver) {
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

		displayColumns(columnOne, columnTwo, columnThree);

	}

	// The game is over and the player does not want to play again, therefore,
	// go ahead and exit the program.
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
	while (disks < 3 || disks > 10) {

		// Ask the user how many disks they would like in their game.
		std::cout << "How many rings would you like?" << std::endl;
		std::cout << "Enter a number between 3 and 10 : ";

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
		else if (disks < 3 || disks > 10) {
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

	// Holds the value of the largest column.
	int largestColumn = 0;


	if ((columnOne.size() >= columnTwo.size()) && (columnOne.size() >= columnThree.size()))
		largestColumn = columnOne.size();
	else if ((columnTwo.size() >= columnOne.size()) && (columnTwo.size() >= columnThree.size()))
		largestColumn = columnTwo.size();
	else
		largestColumn = columnThree.size();

	std::cout << largestColumn << std::endl;
}