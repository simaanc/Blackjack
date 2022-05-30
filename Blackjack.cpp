#include <iostream>

#include "Blackjack.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"


void clearScreen();
void pauseScreen();

void redrawHands();

void handOnePrompts();

void handTwoPrompts();

int handOnePlayerMenu();

int handTwoPlayerMenu();

void endPlayerTurn();

bool dualHands();

Deck deck;

Hand playerHand1;
Hand playerHand2;
Hand dealerHand;
Dealer dealer;

Player player(50000);

void Blackjack::setup()
{
	//deck.generateCasinoDeck();
	//deck.shuffle();

	startGame();
}

void Blackjack::startGame() {
	int bet;

	std::string yesorno;

	int error;

	clearScreen();

	std::cout << "You currently have: " << player.getChips();

	do {
		if (player.getChips() == 0) {
			do
			{
				std::cout << "\nSorry you can't bet anymore. Would you like to reset chips? (Y/N)" << std::endl;
				std::cin >> yesorno;
			} while (!std::cin.fail() && yesorno[0] != 'y' && yesorno[0] != 'n' && yesorno[0] != 'Y' && yesorno[0] != 'N');
			if (yesorno[0] == 'y' || yesorno[0] == 'Y') {
				player.setChips(50000);
				std::cout << "\nYou currently have: " << player.getChips();
			}
			else {
				exit;
			}
		}

		error = 0;

		std::cout << "\nHow much would you like to bet? ";
		std::cin >> bet;

		if (std::cin.fail()) {
			std::cout << "Please enter a valid number" << std::endl;
			error = 1;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}

		if (bet > player.getChips()) {
			std::cout << "You don't have enough for this amount" << std::endl;
			error = 1;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	} while (error == 1);

	player.setBet(bet, &playerHand1);

	dealing();
}

void Blackjack::dealing() {
	int input;

	clearScreen();

	deck.addCard(Card(SIX, HEART));
	deck.addCard(Card(SEVEN, HEART));
	deck.addCard(Card(EIGHT, HEART));
	deck.addCard(Card(NINE, HEART));
	deck.addCard(Card(FIVE, HEART));
	deck.addCard(Card(FIVE, HEART));
	deck.addCard(Card(FIVE, HEART));
	deck.addCard(Card(FIVE, HEART));
	deck.addCard(Card(FIVE, HEART));

	playerHand1.drawCard(&deck);

	dealerHand.drawCard(&deck);

	playerHand1.drawCard(&deck);

	dealerHand.drawCard(&deck);

	redrawHands();

	handOnePrompts();

}

void handOnePrompts() {
	int input;

	if (!(player.checkSplit(&playerHand1)) && !(player.checkDub(&playerHand1))) {
		do {
			if (!dualHands()) {
				std::cout << "";
			}
			else if (dualHands()) {
				std::cout << "Hand 1:\n";
			}

			input = handOnePlayerMenu();
			switch (input) {
			case 1:
				playerHand1.drawCard(&deck);

				break;
			case 2:
				if (!dualHands()) {
					endPlayerTurn();
				}
				else if (dualHands()) {
					redrawHands();
					handTwoPrompts();
				}
				break;
			}
			redrawHands();
		} while (input != 2);
	}
	if (!(player.checkSplit(&playerHand1)) && (player.checkDub(&playerHand1))) {
		do {
			if (!dualHands()) {
				std::cout << "";
			}
			else if (dualHands()) {
				std::cout << "Hand 1:\n";
			}
			input = handOnePlayerMenu();
			switch (input) {
			case 1:
				playerHand1.drawCard(&deck);


				break;
			case 2:
				if (!dualHands()) {
					endPlayerTurn();
				}
				else if (dualHands()) {
					redrawHands();

					handTwoPrompts();
				}
				break;

			case 3:
				player.dub(&playerHand1);
				clearScreen();

			}
			redrawHands();

		} while (input != 2);

	}
	if (!(player.checkDub(&playerHand1)) && (player.checkDub(&playerHand1)) && (!dualHands())) {
		do {
			if (!dualHands()) {
				std::cout << "";
			}
			else if (dualHands()) {
				std::cout << "Hand 1:\n";
			}
			input = handOnePlayerMenu();
			switch (input) {
			case 1:
				playerHand1.drawCard(&deck);


				break;
			case 2:
				if (!dualHands()) {
					endPlayerTurn();
				}
				else if (dualHands()) {
					redrawHands();
					
					handTwoPrompts();
				}				
				break;

			case 3:
				player.split(&playerHand1, &playerHand2);
				clearScreen();


			}
			redrawHands();

		} while (input != 2);
	}

	if (!(player.checkDub(&playerHand1)) && (player.checkDub(&playerHand1)) && (dualHands())) {
		do {
			if (!dualHands()) {
				std::cout << "";
			}
			else if (dualHands()) {
				std::cout << "Hand 1:\n";
			}
			input = handOnePlayerMenu();
			switch (input) {
			case 1:
				playerHand1.drawCard(&deck);


				break;
			case 2:
				if (!dualHands()) {
					endPlayerTurn();
				}
				else if (dualHands()) {

					redrawHands();

					handTwoPrompts();
				}				
				break;

			}
			redrawHands();

		} while (input != 2);
	}

	if (player.checkSplit(&playerHand1) && player.checkDub(&playerHand1) && (!dualHands())) {
		do {
			if (!dualHands()) {
				std::cout << "";
			}
			else if (dualHands()) {
				std::cout << "Hand 1:\n";
			}
			input = handOnePlayerMenu();
			switch (input) {
			case 1:
				playerHand1.drawCard(&deck);

				break;
			case 2:

				if (!dualHands()) {
					endPlayerTurn();
				}
				else if (dualHands()) {

					redrawHands();

					handTwoPrompts();
				}				
				break;

			case 3:
				player.split(&playerHand1, &playerHand2);
				clearScreen();

			case 4:
				player.dub(&playerHand1);

			}
			redrawHands();

		} while (input != 2);
	}

	if (player.checkSplit(&playerHand1) && player.checkDub(&playerHand1) && (dualHands())) {
		do {
			if (!dualHands()) {
				std::cout << "";
			}
			else if (dualHands()) {
				std::cout << "Hand 1:\n";
			}
			input = handOnePlayerMenu();
			switch (input) {
			case 1:
				playerHand1.drawCard(&deck);

				break;
			case 2:

				if (!dualHands()) {
					endPlayerTurn();
				}
				else if (dualHands()) {
					redrawHands();

					handTwoPrompts();
				}				
				break;

			case 3:
				player.dub(&playerHand1);

			}
			redrawHands();

		} while (input != 2);
	}
}

void handTwoPrompts() {
	int input;

	if (!(player.checkDub(&playerHand2))) {
		do {
			std::cout << "Hand 2:\n";
			input = handTwoPlayerMenu();
			switch (input) {
			case 1:
				playerHand2.drawCard(&deck);

				break;
			case 2:

				break;
			}
			redrawHands();
		} while (input != 2);
	}
	else if (player.checkDub(&playerHand2)) {
		do {
			std::cout << "Hand 2:\n";

			input = handTwoPlayerMenu();
			switch (input) {
			case 1:
				playerHand2.drawCard(&deck);

				break;
			case 2:

				break;

			case 3:
				player.dub(&playerHand2);
				clearScreen();

			}
			redrawHands();

		} while (input != 2);
	}
}

void redrawHands() {
	clearScreen();

	std::cout << "Dealer Hand:\n";

	dealer.outputDealerBlankHand(&dealerHand);

	std::cout << "\n\n\n\n\n\n";

	if (!dualHands()) {
		std::cout << "Player Hand:\n";
		playerHand1.getCardsInHand();
	}
	else if (dualHands()) {
		std::cout << "Player Hand One:\n";
		playerHand1.getCardsInHand();
		std::cout << "\n\n";
		std::cout << "Player Hand Two:\n";
		playerHand2.getCardsInHand();
		std::cout << "\n\n";
	}
}

void clearScreen() {
	system("CLS");
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}
void pauseScreen() {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "\n---Enter to Continue!---\n";
	std::cin.get();
}

int handTwoPlayerMenu() {
	int input;

	if (!(player.checkDub(&playerHand1))) {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> input;
		while (input < 1 or input > 2) {
			std::cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::cin >> input;
		}
		return input;

	}
	else if (player.checkDub(&playerHand1)) {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< "3. Double"
			<< std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> input;
		while (input < 1 or input > 3) {
			std::cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::cin >> input;
		}
		return input;

	}
	else {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> input;
		while (input < 1 or input > 2) {
			std::cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::cin >> input;
		}
		return input;
	}
}

int handOnePlayerMenu()
{
	int input;

	if (!(player.checkSplit(&playerHand1)) && !(player.checkDub(&playerHand1))) {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> input;
		while (input < 1 or input > 2) {
			std::cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::cin >> input;
		}
		return input;

	}
	else if (!(player.checkSplit(&playerHand1)) && (player.checkDub(&playerHand1))) {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< "3. Double"
			<< std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> input;
		while (input < 1 or input > 3) {
			std::cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::cin >> input;
		}
		return input;

	}
	else if (!(player.checkDub(&playerHand1)) && (player.checkDub(&playerHand1)) && (!dualHands())) {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< "3. Split"
			<< std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> input;
		while (input < 1 or input > 3) {
			std::cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::cin >> input;
		}
		return input;

	}

	else if (!(player.checkDub(&playerHand1)) && (player.checkDub(&playerHand1)) && (dualHands())) {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< "3. Double"
			<< std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> input;
		while (input < 1 or input > 3) {
			std::cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::cin >> input;
		}
		return input;

	}

	else if (player.checkSplit(&playerHand1) && player.checkDub(&playerHand1) && (!dualHands())) {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< "3. Split" << std::endl
			<< "4. Double"
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

	else if (player.checkSplit(&playerHand1) && player.checkDub(&playerHand1) && (dualHands())) {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< "3. Double"
			<< std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> input;
		while (input < 1 or input > 3) {
			std::cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::cin >> input;
		}
		return input;
	}
	else {
		std::cout << "Enter the number for the operation you wish to perform from the menu." << std::endl
			<< "1. Hit" << std::endl
			<< "2. Stand" << std::endl
			<< std::endl;
		std::cout << "Enter Choice: ";
		std::cin >> input;
		while (input < 1 or input > 2) {
			std::cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			std::cin >> input;
		}
		return input;
	}
}

void endPlayerTurn()
{
	std::cout << "PLAYER TURN ENDED";
}

bool dualHands() {
	if (player.getNumberOfHands() == 1) {
		return true;
	}
	else {
		return false;
	}
}
