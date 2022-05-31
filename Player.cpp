/*
	 CS281 – Spring 2022
			  Card Game Project
			  Christopher Simaan & Duc Nguyen
			  5/21/2022
			  Player Logic
*/

#include "Player.h"
#include<iostream>
#include "Deck.h"
#include "Hand.h"

Player::Player(int startingchips, std::string oName)
{
	chips = startingchips;
	name = oName;
}

/*Player::Player(const Player& player)
{
	chips = player.chips;
	name = player.name;
}
*/

bool Player::setBet(int bet, Hand* hand) {
	if (bet > chips) {
		return false;
	}
	else {
		hand->bet = bet;
		chips = chips - bet;
	}
}

void Player::setChips(int inputChips)
{
	chips = inputChips;
}

int Player::getNumberOfHands()
{
	return numOfHands;
}

int Player::getChips()
{
	return chips;
}

std::string Player::getName()
{
	return name;
}

int Player::getBet(Hand* hand) {
	return bet;
}

void Player::stand(Hand* hand) {

}

bool Player::hit(Hand* hand, Deck* deck) {
	if (hand->canDraw()) {
		hand->drawCard(deck);
		return true;
	}
	else {
		return false;
	}
}

bool Player::checkDub(Hand* hand) {

	if (hand->getHandSize() == 2) {
		if (!((chips - hand->bet) < 0)) {
			if (hand->getOneScore() == 9 || hand->getOneScore() == 10 || hand->getOneScore() == 11) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

bool Player::checkSplit(Hand* hand) {
	if (!((chips - hand->bet) < 0)) {
		if (numOfHands < 1) {
			if (hand->getHandSize() > 1) {

				if (hand->getCardValue(0) == hand->getCardValue(1)) {
					return true;
				}
				else {
					return false;
				}
			} return false;
		}
		return false;
	}
	return false;
}

void Player::dub(Hand* hand) {
	int originalbet = hand->bet;
	hand->bet = originalbet * 2;
	chips = chips - originalbet;
}

void Player::split(Hand* hand1, Hand* hand2) {
	numOfHands++;

	hand2->addCard(hand1->getCardForSplit());
	hand1->removeCard();

	hand2->bet = hand1->bet;


	chips = chips - hand1->bet;

}

void Player::clearHands(Hand* hand1, Hand* hand2)
{
	hand1->clear();
	hand2->clear();

	numOfHands = 0;
}

void Player::win(float mult, float payout)
{
	chips = chips + (mult * payout);
}

Player Player::createAcc()
{
	std::string name;
	std::string line;

	// ask for the username
	std::cout << "Please enter your username: ";
	std::cin >> name;
	Player newPlayer(50000, name);
	std::cout << "Your username is: " << newPlayer.getName() << "\nYou currently have: " << newPlayer.getChips() << "\n";

	return newPlayer;
}

