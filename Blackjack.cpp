#include <iostream>

#include "Blackjack.h"


Deck deck;

Hand playerHand1;
Hand playerHand2;
Hand dealerHand;
Dealer dealer;

Player player(50000);

void clearScreen();
void clearScreenAlt();
void pauseScreen();

void Blackjack::setup()
{
	//deck.generateCasinoDeck();
	//deck.shuffle();

	startGame();
}

void Blackjack::startGame() {
	if (deck.checkShouldReshuffle()) {
		deck.makeEmpty();
		deck.generateCasinoDeck();
		deck.shuffle();
	}

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
	deck.addCard(Card(ACE, HEART));
	deck.addCard(Card(KING, HEART));
	deck.addCard(Card(FIVE, HEART));
	deck.addCard(Card(ACE, HEART));

	playerHand1.drawCard(&deck);

	dealerHand.drawCard(&deck);

	playerHand1.drawCard(&deck);

	dealerHand.drawCard(&deck);

	//Blackjack Check
	if (playerHand1.isBlackJack()) {
		//If dealer also gets blackjack
		if (dealerHand.isBlackJack()) {
			clearScreenAlt();
			redrawRevealedHands();
			tie(&playerHand1);
		}
		//You win if they don't
		else {
			clearScreenAlt();
			redrawRevealedHands();
			playerWin(1.5, &playerHand1);
		}
	}
	else {
		redrawHands();
		handOnePrompts();
	}
}

void Blackjack::playerWin(float mult, Hand* hand)
{
	player.win(mult, hand->bet);
	
	newRound();

}


void Blackjack::dealerWin()
{

	newRound();
}

void Blackjack::tie(Hand *hand)
{
	playerWin(1, hand);

	newRound();
}

void Blackjack::handOnePrompts() {
	int input;
	//IF NOT DOUBLE OR SPLIT
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

	//IF NOT SPLIT BUT DOUBLE
	else if (!(player.checkSplit(&playerHand1)) && (player.checkDub(&playerHand1))) {
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
				break;


			}
			redrawHands();

		} while (input != 2);

	}
	//IF NOT DOUBLE BUT SPLIT
	else if (!(player.checkDub(&playerHand1)) && (player.checkSplit(&playerHand1))) {
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
				break;


			}
			redrawHands();

		} while (input != 2);
	}
	//IF BOTH SPLIT AND DOUBLE
	else if ((player.checkSplit(&playerHand1)) && (player.checkDub(&playerHand1))) {
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
				break;

			case 4:
				player.dub(&playerHand1);
				clearScreen();
				break;


			}
			redrawHands();

		} while (input != 2);
	}
}

void Blackjack::handTwoPrompts() {
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
				break;


			}
			redrawHands();

		} while (input != 2);
	}
}

void Blackjack::redrawHands() {
	clearScreen();

	std::cout << "Dealer Hand:\n";

	dealer.outputDealerBlankHand(&dealerHand);

	std::cout << "\n\n\n\n\n\n";

	std::cout << "Player Chips: " << player.getChips() << "\n";

	if (!dualHands()) {
		std::cout << "\nPlayer Hand:\n";
		std::cout << "Bet: " << playerHand1.bet << "\n";
		playerHand1.getCardsInHand();
	}
	else if (dualHands()) {
		std::cout << "\nPlayer Hand One:\n";
		std::cout << "Bet: " << playerHand1.bet << "\n";
		playerHand1.getCardsInHand();
		std::cout << "\n\n";
		std::cout << "Player Hand Two:\n";
		std::cout << "Bet: " << playerHand2.bet << "\n";
		playerHand2.getCardsInHand();
		std::cout << "\n\n";
	}
}

void Blackjack::redrawRevealedHands() {
	clearScreen();

	std::cout << "Dealer Hand:\n";

	dealerHand.getCardsInHand();

	std::cout << "\n\n\n\n\n\n";

	std::cout << "Player Chips: " << player.getChips() << "\n";

	if (!dualHands()) {
		std::cout << "\nPlayer Hand:\n";
		std::cout << "Bet: " << playerHand1.bet << "\n";
		playerHand1.getCardsInHand();
	}
	else if (dualHands()) {
		std::cout << "\nPlayer Hand One:\n";
		std::cout << "Bet: " << playerHand1.bet << "\n";
		playerHand1.getCardsInHand();
		std::cout << "\n\n";
		std::cout << "Player Hand Two:\n";
		std::cout << "Bet: " << playerHand2.bet << "\n";
		playerHand2.getCardsInHand();
		std::cout << "\n\n";
	}
}

int Blackjack::handTwoPlayerMenu() {
	int input;

	if (!(player.checkDub(&playerHand2))) {
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
	else if (player.checkDub(&playerHand2)) {
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

void Blackjack::newRound()
{
	std::string input;

	do
	{
		std::cout << "\Would you like to go another round? (Y/N)" << std::endl;
		std::cin >> input;
	} while (!std::cin.fail() && input[0] != 'y' && input[0] != 'n' && input[0] != 'Y' && input[0] != 'N');
	if (input[0] == 'y' || input[0] == 'Y') {
		
	}
	else {
		exit;
	}

}

int Blackjack::handOnePlayerMenu()
{
	int input;

	//IF NOT SPLIT OR DOUBLE
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

	//IF NOT SPLIT BUT DOUBLE
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

	//IF NOT DOUBLE BUT SPLIT
	else if (!(player.checkDub(&playerHand1)) && (player.checkDub(&playerHand1))) {
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

	//IF BOTH DOUBLE AND SPLIT
	else if ((player.checkSplit(&playerHand1)) && (player.checkDub(&playerHand1))) {
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
	//CATCH ALL JUST IN CASE
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

void Blackjack::endPlayerTurn()
{
	std::cout << "\nPLAYER TURN ENDED";
}

bool Blackjack::dualHands() {
	if (player.getNumberOfHands() == 1) {
		return true;
	}
	else {
		return false;
	}
}


void clearScreen() {
	system("CLS");
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}

void clearScreenAlt() {
	system("CLS");
}
void pauseScreen() {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "\n---Enter to Continue!---\n";
	std::cin.get();
}