#pragma once

#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"

class Blackjack
{
private:
	
	//if winner = 1, player wins
	//if winner = 2, dealer wins
	int winner = 0;

public:
	void setup();

	void startGame();

	void dealing();

	void playerWin(float mult, Hand* hand);

	void dealerWin();

	void tie(Hand* hand);

	void redrawHands();

	void redrawRevealedHands();

	void handOnePrompts();

	void handTwoPrompts();

	int handOnePlayerMenu();

	int handTwoPlayerMenu();

	void newRound();

	void endPlayerTurn();

	bool dualHands();
};

