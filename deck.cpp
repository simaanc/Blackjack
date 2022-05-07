//
// Created by duc on 5/6/2022.
//
#include "deckOfCards.h"
#include <iostream>

Deck::Deck() {
    size = 0;
}

void Deck::addCard(Card oCard)
{
    list[size] = oCard;
    size ++;
}
void Deck::generateDeck() {
    makeEmpty();

    for (Ranks i = ACE; i <= KING; i = Ranks(i+1)){
        for (Suits j = CLUB; j <= SPADE; j = Suits(j+1)){
            Card oCard(i,j);
            addCard(oCard);
            std::cout << "Add "<< oCard.toString() << " into the deck!!!" << std::endl;
        }
    }
    std::cout << " Successfully generate deck with " << size << " cards" << std::endl;}

void Deck::printDeck(){
    if (size == 0)   std::cout << "Empty Deck!!!" << std::endl;
    else{
        for (int count = 0; count < size; count++)
            std::cout << list[count].toString() << std::endl;
    }
}

void Deck::makeEmpty() {
    size = 0;
}






