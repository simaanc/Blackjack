/*
     CS281 – Spring 2022
              Card Game Project
              Christopher Simaan & Duc Nguyen
              5/21/2022
              Player Logic
*/

#include "Player.h"
#include "Deck.h"
#include "Hand.h"

Player::Player(int startingchips)
{
    chips = startingchips;
}

void Player::setBet(int bet, Hand *hand) {
    hand->bet = bet;
}

int Player::getBet(Hand* hand) {
    return bet;
}

void Player::stand(Hand* hand) {

}

bool Player::hit(Hand *hand, Deck *deck) {
    if (hand->canDraw()) {
        hand->drawCard(deck);
        return true;
    } else {
        return false;
    }
}

bool Player::checkDub(Hand* hand) {
    if (hand->getHandSize() == 2 && hand->getOneScore() == 9 || hand->getOneScore() == 10 || hand->getOneScore() == 11) {
        if (bet * 2 <= chips) {
            return true;
        }
        return false;
    } else {
        return false;
    }
}

bool Player::checkSplit(Hand* hand) {
    if (hand->getHandSize() > 1) {

        if (hand->getCardValue(0) == hand->getCardValue(1)) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void Player::dub(Hand* hand) {

}

void Player::split(Hand* hand1, Hand* hand2) {
    numOfHands++;

    hand2->addCard(hand1->getCardForSplit());
    hand1->removeCard();

    int hand1bet = hand1->bet;

    hand2->bet = hand1bet;

}
