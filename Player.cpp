/*
     CS281 – Spring 2022
              Card Game Project
              Christopher Simaan & Duc Nguyen
              5/21/2022
              Player Logic
*/

#include "Player.h"

Player::Player() {
    money = 500;
    bet = 0;
}

void Player::setBet(int bet)
{
    this->bet = bet;
}

int Player::getBet()
{
    return bet;
}
