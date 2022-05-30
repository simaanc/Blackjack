//
// Created by Chris Simaan on 5/15/22.
//

#pragma once

#include "Hand.h"

class Player {
private:
    int numOfHands = 0;

    int chips;
    int bet;

    //How much payout will be multiplied by
    int multiplier;
    //Amount that will be given to player if they win
    int payout;

public:
    Player(int startingchips);

    bool setBet(int bet, Hand *hand);

    void setChips(int inputChips);

    int getNumberOfHands();

    int getChips();

    int getBet(Hand *hand);

    void stand(Hand *hand);

    bool hit(Hand *hand, Deck *deck);

    bool checkDub(Hand *hand);

    bool checkSplit(Hand *hand);

    void dub(Hand *hand);

    void split(Hand *hand1, Hand *hand2);

    void clearHands(Hand* hand1, Hand* hand2);
};