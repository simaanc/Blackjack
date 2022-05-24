//
// Created by Chris Simaan on 5/15/22.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H


class Player {

private:
    int money;
    int bet;
public:
    Player();
    ~Player();

    void setBet(int bet);

    int getBet();

    void stand();

    void hit();

    void dub();

    void split();

};


#endif //BLACKJACK_PLAYER_H
