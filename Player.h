//
// Created by Chris Simaan on 5/15/22.
//

#pragma once

#include "Hand.h"

class Player {
private:
    int numOfHands = 0;
    std::string name;
    int chips;
    int bet;

public:

    Player(int startingchips, std::string name);

    bool setBet(int bet, Hand *hand);

    void setChips(int inputChips);

    int getNumberOfHands();

    int getChips();

    std::string getName();

    int getBet(Hand *hand);

    void stand(Hand *hand);

    bool hit(Hand *hand, Deck *deck);

    bool checkDub(Hand *hand);

    bool checkSplit(Hand *hand);

    void dub(Hand *hand);

    void split(Hand *hand1, Hand *hand2);

    void clearHands(Hand* hand1, Hand* hand2);

    void win(float mult, float payout);

    Player createAcc();

   


};