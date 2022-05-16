//
// Created by Chris Simaan on 5/15/22.
//

#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H

#include <string>

class Hand {
public:
    Hand();

    ~Hand();

    //Add card to hand
    bool addCard();

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

    //Returns hand as a string
    std::string getCardsInHand();
};


#endif //BLACKJACK_HAND_H
