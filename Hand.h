//
// Created by Chris Simaan on 5/15/22.
//

#pragma once

#include <string>
#include "Deck.h"

class Hand {
private:

    static const int maxSize = 5;

    int handSize = 0;

    Card hand[maxSize];


public:
    bool isPlayer;

    int bet = 0;

    Hand();

    //Initialize Deck with 2 Cards
    Hand(Card *card1, Card *card2);

    ~Hand();

    //draw card to hand
    bool drawCard(Deck*);

    void addCard(Card card);
    
    void removeCard();

    //Get number of cards in hand
    int getCardCount();

    //Get score if Ace is counted as an 11
    int getElevenScore();

    //Get score if Ace is counted as a 1
    int getOneScore();

    //Return hand size
    int getHandSize();

    int getCardValue(int card);

    Card getCardFromPosition(int pos);

    //Clear the hand
    void clear();
    //Checks for Ace
    bool checkAce();

    //Checks if Player/Dealer Hand > 21 if Ace = 1
    bool isBustOne();

    //Checks if Player/Dealer Hand > 21 if Ace = 11
    bool isBustEleven();

    //Checks if Bust in General
    bool isBust();

    //Auto win if player gets 5 cards in their hand without bust
    bool isCharlie();

    //Checks if Player can keep drawing
    bool canDraw();

    //Checks if hand is blackjack
    bool isBlackJack();

    //Displays getHandGraphic(); with formatting
    void getCardsInHand();

    //Returns hand as a string with formatted card graphic
    std::string getHandGraphic();

    Card getCardForSplit();

};