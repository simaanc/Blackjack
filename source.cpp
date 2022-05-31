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
			std::cout << "The rules of blackjack are fairly simple and your only opponent in the game is the dealer. Each player is dealt a two cards face up while the dealer only has one card face up. The goal is to have your two cards added total to be higher than the dealer’s two cards and under 21. If you go over 21 you “bust”, or lose, or if the dealers two cards added together are higher than yours you also lose. If your two card total is equal to the dealers then it is a “stand-off” or a tie. Cards values are usually face value, 2 is 2 and 10 is 10, while all face cards, jack/queen/king, are also 10. The only exception to this rule are Aces, they can take on the value of 1 or 11. To get your two cards total you simply add your two cards together. If you have any combination of an Ace or any card that is 10 points then you have what is called blackjack, 21 pts. Getting blackjack means you get paid more if you win. With all of that being said if you’re not satisfied with your two card total then you can take extra cards, called taking a hit, and for each hit you get you get one more card. The dealer does this as well but has a strict set of rules to follow on whether or not to take a hit. If a dealer’s hand is less than or equal to 16 or a “soft” 17, meaning they have an ace and a 6, they must take a hit. If it’s 17 or higher the dealer must stand.  So now that we know the dealer rules there are a few options for users.  As I stated earlier you can take hits to increase your card total. You may also split your cards and double down. Splitting can be done when your first two cards are of equal value and can only be split from the original hand, split hands cannot be split, the bet has to be equal or greater than the original bet for each hand. For each time you split you will receive and additional card for that hand and then you play like regular blackjack.  Users may also double down which consists of a user placing another bet of equal or lesser value when their first two cards total is equal to 9, 10, or 11 without aces. After doubling down you will only get one additional card. Some of you may have realized that if the dealer gets a blackjack or 21 you pretty much always lose, unless you yourself have blackjack." << std::endl;
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
	} while (input != 5);
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
	while (input < 1 or input > 5) {
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

