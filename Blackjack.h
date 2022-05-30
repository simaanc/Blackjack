#pragma once
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


};

