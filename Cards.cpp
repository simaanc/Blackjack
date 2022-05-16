//
// Created by duc on 5/6/2022.
//

#include "Deck.h"

Card::Card() {
    rank = ACE;
    suit = CLUB;
}

Card::Card(Ranks rank, Suits suit) {
    this->rank = rank;
    this->suit = suit;
}

std::string Card::toString() const {

    std::string convertRanks[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                                    "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    std::string convertSuits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};


    std::string printString = convertRanks[rank] + " of " + convertSuits[suit];
    return printString;
}

std::string Card::cardGraphic() {


    std::string convertRanks[13] = {"A", "2", "3", "4", "5", "6", "7",
                                    "8", "9", "10", "J", "Q", "K"};
    std::string convertSuits[4] = {"\u2663", "\u2666", "\u2665", "\u2660"};

std::string color;

if (suit == 1 or suit == 2) {
    color = "\033[0;31m";
} else {
    color = "\033[0m";
}

    if (rank == 9) {
        std::string graphic =
                //Top
                "┌─────────┐\n"
                "│ " + color + convertRanks[rank] + "\033[0m      │\n" +
                //Side
                "│         │\n" +
                //Suit
                "│    " + color + convertSuits[suit] + "\033[0m    │\n" +
                //Side
                "│         │\n" +
                //Check if Double Width + Rank
                "│      " + color + convertRanks[rank] + "\033[0m │\n" +
                //Buttom
                "└─────────┘\n";
        return graphic;
    } else {
        std::string graphic =
                //Top
                "┌─────────┐\n"
                //Check if Double Width + Rank
                "│ "  + color + convertRanks[rank] + "\033[0m       │\n" +
                //Side
                "│         │\n" +
                //Suit
                "│    "  + color + convertSuits[suit] + "\033[0m    │\n" +
                //Side
                "│         │\n" +
                //Check if Double Width + Rank
                "│       "  + color + convertRanks[rank] + "\033[0m │\n" +
                //Buttom
                "└─────────┘\n";
        return graphic;
    }

}





