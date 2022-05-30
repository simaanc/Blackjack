//
// Created by Chris Simaan on 5/15/22.
//

#include <iostream>

#include "Hand.h"
#include "Deck.h"

class Dealer {

private:
	std::string dealerBlankHandString(Hand* hand);


public:

	void outputDealerBlankHand(Hand* hand);

    void stand(Hand* hand);

    void hit(Hand* hand, Deck* deck);

    bool hitCheck(Hand* hand);

    void clearHand(Hand* hand);
};

/*
     CS281 – Spring 2022
              Card Game Project
              Christopher Simaan & Duc Nguyen
              5/21/2022
              Dealer Logic
*/

