//
// Created by duc on 5/6/2022.
//

#include "deckOfCards.h"

Card::Card() {
    rank = ACE;
    suit = CLUB;
}


Card::Card(Ranks rank, Suits suit){
    this -> rank = rank;
    this -> suit = suit;
}

std::string Card::toString()const {
   std::string convertRanks[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                                   "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
   std::string convertSuits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
   std::string printString = convertRanks[rank] + " of " + convertSuits[suit];
   return printString;
}



