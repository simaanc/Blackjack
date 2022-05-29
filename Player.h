//
// Created by Chris Simaan on 5/15/22.
//

#pragma once

#include "Hand.h"

class Player {

private:
    static const int maxHands = 3;

    int numOfHands = 0;

    Hand playerHands[maxHands];

    int money;
    int bet;

    int handOneBet;
    int handTwoBet;
    int handThreeBet;
    int handFourBet;

public:
    Player();
    ~Player();

    void setBet(int bet, Hand *hand);

    int getBet(Hand *hand);

    void stand(Hand *hand);

    void hit(Hand *hand);

    bool checkDub(Hand *hand);

    bool checkSplit(Hand *hand);

    void dub(Hand *hand);

    void split(Hand *hand);

    //Returns specific hand from 2D array
    Hand returnHand(int handNumber);
};