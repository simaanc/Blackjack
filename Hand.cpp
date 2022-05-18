//
// Created by Chris Simaan on 5/15/22.
//

#include <iostream>
#include "Hand.h"

Hand::Hand() {

}

Hand::Hand(Card *card1, Card *card2) {

}


Hand::~Hand() {

}

bool Hand::drawCard(Deck deck) {
    if (canDraw()) {
        //std::cout << deck.getCard();
        //hand[0] = deck.getCard();
        return true;
    } else
    return false;
}



int Hand::getCardCount() {
    return 0;
}

int Hand::getElevenScore() {
    return 0;
}

int Hand::getOneScore() {
    return 0;
}

void Hand::clear() {

}

bool Hand::isBust() {
    return false;
}

bool Hand::isCharlie() {
    return false;
}

bool Hand::canDraw() {
    return false;
}

bool Hand::isBlackJack() {
    return false;
}

std::string Hand::getCardsInHand() {
    return std::string();
}

