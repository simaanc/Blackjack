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

bool Player::setBet(int bet, Hand *hand) {
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

    if (!((chips - hand->bet) < 0)) {
        if (hand->getHandSize() == 2 && hand->getOneScore() == 9 || hand->getOneScore() == 10 || hand->getOneScore() == 11) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

bool Player::checkSplit(Hand* hand) {
    if (!((chips - hand->bet) < 0)) {
        if (hand->getHandSize() > 1 && numOfHands == 0) {

            if (hand->getCardValue(0) == hand->getCardValue(1)) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    else {
        return false;
    }
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
