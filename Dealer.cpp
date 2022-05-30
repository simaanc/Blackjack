#include "Dealer.h"

std::string Dealer::dealerBlankHandString(Hand* hand)
{
    std::string convertRanks[13] = { "A", "2", "3", "4", "5", "6", "7",
                                "8", "9", "10", "J", "Q", "K" };
    std::string convertSuits[4] = { "♣", "♦", "♥", "♠" };

    //Top
    std::string top = "┌─────────┐ ";

    //Side
    std::string side = "│         │ ";

    //Buttom
    std::string bottom = "└─────────┘ ";


    std::string sidetop1;
    std::string suit1;
    std::string sidebottom1;

    std::string sidetop2;
    std::string suit2;
    std::string sidebottom2;

    std::string color1;
    std::string color2 = "\033[0m";;

    std::string newline = "\n";

    Card card1 = hand->getCardFromPosition(0);

    if (card1.getSuits() == 1 or card1.getSuits() == 2) {
        color1 = "\033[0;31m";
    }
    else {
        color1 = "\033[0m";
    }

    if (card1.getRank() == 9) {
        sidetop1 = "│ " + color1 + convertRanks[card1.getRank()] + "\033[0m      │ ";
        suit1 = "│    " + color1 + convertSuits[card1.getSuits()] + "\033[0m    │ ";
        sidebottom1 = "│      " + color1 + convertRanks[card1.getRank()] + "\033[0m │ ";

    }
    else {
        sidetop1 = "│ " + color1 + convertRanks[card1.getRank()] + "\033[0m       │ ";
        suit1 = "│    " + color1 + convertSuits[card1.getSuits()] + "\033[0m    │ ";
        sidebottom1 = "│       " + color1 + convertRanks[card1.getRank()] + "\033[0m │ ";

    }

    sidetop2 = "│ " + color2 + "?" + "\033[0m       │ ";
    suit2 = "│    " + color2 + "?" + "\033[0m    │ ";
    sidebottom2 = "│       " + color2 + "?" + "\033[0m │ ";


    return
        top + top + newline +
        sidetop1 + sidetop2 + newline +
        side + side + newline +
        suit1 + suit2 + newline +
        side + side + newline +
        sidebottom1 + sidebottom2 + newline +
        bottom + bottom + newline;
}

void Dealer::outputDealerBlankHand(Hand* hand)
{
    std::cout << dealerBlankHandString(hand);
}

void Dealer::stand(Hand* hand)
{

}

void Dealer::hit(Hand* hand, Deck* deck)
{
    hand->drawCard(deck);
}

bool Dealer::hitCheck(Hand* hand)
{
    //Check if can draw in general
    if (hand->canDraw()) {
        //Check if hand is >= 17
        if (hand->getElevenScore() >= 17) {
            return false;
        }
        //If it's not dealer will hit
        else {
            return true;
        }
    } 
    return false;
}

void Dealer::clearHand(Hand* hand)
{
    hand->clear();
}
