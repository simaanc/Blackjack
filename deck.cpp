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
            std::cout << "Add "<< oCard.toString() << " into the deck!!\n";
        }
    }
    std::cout << " Successfully generate deck with " << size << " cards\n";}

void Deck::printDeck(){
    if (isEmpty())   std::cout << "Empty Deck!!!\n";
    else{
        for (int count = 0; count < size; count++)
            std::cout << list[count].toString() << "\n";
    }
}

void Deck::makeEmpty() {
    size = 0;
}

bool Deck::isEmpty(){
    if (size == 0)   return true;
    else  return false;
}

void Deck::shuffle() {

    if (isEmpty())   std::cout << "Empty Deck!!!\n";

    else {
        int numCards = 0;
        srand(time(NULL));
        Card temp[MaxSize];

        for (int i = 0; i < 52; i++) {
            int r = i + (rand() % (52 - i));
            list[i] = temp[i];
            list[i] = list[r];
            list[r] = temp[i];
        }
    }
}

Card Deck::getNextCard() {
    pos++;
    return list[pos];
}

void Deck::resetDeck() {
    pos = -1;
}









