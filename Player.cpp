/*
     CS281 – Spring 2022
              Card Game Project
              Christopher Simaan & Duc Nguyen
              5/21/2022
              Player Logic
*/

#include "Player.h"

Player::Player() {
    money = 50000;
    bet = 0;
}

void Player::setBet(int bet, Hand *hand)
{
    hand->bet = bet;
}

int Player::getBet(Hand* hand)
{
    return bet;
}

void Player::stand(Hand* hand)
{

}

void Player::hit(Hand *hand)
{
    
}

bool Player::checkDub(Hand* hand)
{
    if (hand->getOneScore() == 9 || hand->getOneScore() == 10 || hand->getOneScore() == 11) {
        return true;
    }
    else {
        return false;
    }
}

bool Player::checkSplit(Hand* hand)
{
    if (hand->getCardValue(1) == hand->getCardValue(2)) {
        return true;
    }
    else {
        return false;
    }
}

void Player::dub(Hand* hand) {

}

void Player::split(Hand* hand) {

}

Hand Player::returnHand(int handNumber)
{
    return playerHands[handNumber];
}
