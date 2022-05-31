/*
	 CS281 – Spring 2022
			  Card Game Project
			  Christopher Simaan & Duc Nguyen
			  5/21/2022
			  Black Jack Game
*/

#include <iostream>

#include "Blackjack.h"

int baseMenu();
int testMenuPrompt();

void testMenu();

void clearScreen();
void pauseScreen();

int main() {
	Blackjack blackjack;

	int input;

	do {
		input = baseMenu();
		switch (input) {
		case 1:
			blackjack.setup();

			break;
		case 2:
			
			pauseScreen();
			break;
		case 3:
			testMenu();

			pauseScreen();
			break;
		case 4:
			blackjack.save();
			
			pauseScreen();
			break;
		case 5:

			pauseScreen();
			break;

			clearScreen();
		}
	} while (input != 4);
}

int baseMenu() {
	int input;
	std::cout << "Please Maximize Console For Best Experience.\n" << std::endl;
	std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
		<< "1. Start Game" << std::endl
		<< "2. Rules" << std::endl
		<< "3. Test Menu" << std::endl
		<< "4. Save to leader board" << std::endl
		<< "5. Exit Program" << std::endl
		<< std::endl;
	std::cout << "Enter Choice: ";
	std::cin >> input;
	while (input < 1 or input > 4) {
		std::cout << "Enter a valid Choice from the menu: ";
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		std::cin >> input;
	}
	return input;
}

int testMenuPrompt() {
	int input;
	std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
		<< "1. Generate Deck" << std::endl
		<< "2. Generate Casino Deck" << std::endl
		<< "3. Shuffle Deck" << std::endl
		<< "4. Print Deck" << std::endl
		<< "5. Get Card" << std::endl
		<< "6. Empty Deck" << std::endl
		<< "7. Draw Card Into Test Hand" << std::endl
		<< "8. Display Hand" << std::endl
		<< "9. Get One Score" << std::endl
		<< "10. Get Eleven Score" << std::endl
		<< "11. Clear Hand" << std::endl
		<< "12. Test Double" << std::endl
		<< "13. Test Split" << std::endl
		<< "14. Add Specific Card To Hand" << std::endl
		<< "15. Exit Menu" << std::endl
		<< std::endl;
	std::cout << "Enter Choice: ";
	std::cin >> input;
	while (input < 1 or input > 15) {
		std::cout << "Enter a valid Choice from the menu: ";
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		std::cin >> input;
	}
	return input;
}

void testMenu() {
	Deck testdeck;
	Hand testhand1;
	Hand testhand2;
	Player testplayer(50000, "test");

	int input;
	do {
		input = testMenuPrompt();
		switch (input) {
		case 1:
			testdeck.generateDeck();
			std::cout << "Generated Deck";

			pauseScreen();
			break;
		case 2:
			testdeck.generateCasinoDeck();
			std::cout << "Generated Deck";

			pauseScreen();
			break;
		case 3:
			testdeck.shuffle();
			std::cout << "Shuffle Deck!";
			pauseScreen();
			break;
		case 4:
			testdeck.printDeck();

			pauseScreen();
			break;
		case 5:
			std::cout << testdeck.getCard().cardGraphic();

			pauseScreen();
			break;
		case 6:
			testdeck.makeEmpty();
			std::cout << "Clear all cards in the deck!";
			pauseScreen();
			break;
		case 7:
			testhand1.drawCard(&testdeck);

			pauseScreen();
			break;
		case 8:
			testhand1.getCardsInHand();

			pauseScreen();
			break;
		case 9:
			std::cout << "TestHand1 One Score: " << testhand1.getOneScore();

			pauseScreen();
			break;
		case 10:
			std::cout << "TestHand1 Eleven Score: " << testhand1.getElevenScore();

			pauseScreen();
			break;
		case 11:
			testhand1.clear();
			testhand2.clear();

			pauseScreen();
			break;
		case 12:
			if (testplayer.checkDub(&testhand1)) {
				testplayer.dub(&testhand1);
			}
			else {
				std::cout << "Can't Double\n";
			}
			pauseScreen();
			break;
		case 13:
			if (testplayer.checkSplit(&testhand1)) {
				testplayer.split(&testhand1, &testhand2);
			}
			else {
				std::cout << "Can't Split\n";
			}
			pauseScreen();
			break;
		case 14:

			pauseScreen();
			break;
		}
		clearScreen();
	} while (input != 15);
}

