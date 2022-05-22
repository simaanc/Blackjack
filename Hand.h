//
// Created by Chris Simaan on 5/15/22.
//

#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H

#include <string>
#include "Deck.h"

class Hand {
private:

    static const int maxSize = 5;

    int handSize = 0;

    Card hand[maxSize];

public:
    bool isPlayer;

    Hand();

    //Initialize Deck with 2 Cards
    Hand(Card *card1, Card *card2);

    ~Hand();

    //draw card to hand
    bool drawCard(Deck*);
    
    //Get number of cards in hand
    int getCardCount();

    //Get score if Ace is counted as an 11
    int getElevenScore();

    //Get score if Ace is counted as a 1
    int getOneScore();

    //Clear the hand
    void clear();

    //Checks if Player/Dealer Hand > 21
    bool isBust();

    //Auto win if player gets 5 cards in their hand without bust
    bool isCharlie();

    //Checks if Player can keep drawing
    bool canDraw();

    //Checks if hand is blackjack
    bool isBlackJack();

    //Returns hand as a string with formatted card graphic
    void getCardsInHand();

    std::string getHandGraphic();
};


#endif //BLACKJACK_HAND_H
