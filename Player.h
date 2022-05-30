//
// Created by Chris Simaan on 5/15/22.
//

#pragma once

#include "Hand.h"

class Player {
private:
    static const int maxHands = 3;

    int numOfHands = 0;

    int chips;
    int bet;

    int handOneBet;
    int handTwoBet;
    int handThreeBet;
    int handFourBet;

public:
    Player(int startingchips);

    void setBet(int bet, Hand *hand);

    int getBet(Hand *hand);

    void stand(Hand *hand);

    bool hit(Hand *hand, Deck *deck);

    bool checkDub(Hand *hand);

    bool checkSplit(Hand *hand);

    void dub(Hand *hand);

    void split(Hand *hand1, Hand *hand2);
};