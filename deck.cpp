//
// Created by duc on 5/6/2022.
//
#include "deckOfCards.h"
#include <iostream>

Deck merge(Deck, Deck);


Deck::Deck() {
    size = 0;
    pos = -1;
}

void Deck::addCard(Card oCard)
{
    if(size > MaxSize)  return;
    list[size] = oCard;
    size ++;
}
void Deck::generateDeck() {
    makeEmpty();

    for (Ranks i = ACE; i <= KING; i = Ranks(i+1)){
        for (Suits j = CLUB; j <= SPADE; j = Suits(j+1)){
            addCard(Card(i,j));
        }
    }
    std::cout << " Successfully generate deck with " << size << " cards\n";}

void Deck::printDeck(){
    if (isEmpty())   std::cout << "Empty Deck!!!\n";
    else{
        std::cout << "There are " << size << " cards left in the deck\n";
        for (int i = 0; i < size; i++){

            std::cout << list[i].toString() << "\n";
        }
    }
}

void Deck::makeEmpty() {
    size = 0;
}

bool Deck::isEmpty(){
    if (size == 0)   return true;
    else  return false;
}



void Deck::getCard() {
    if(!isEmpty())
        size--;
}

void Deck::shuffle() {
    {
        srand(time(0));
        for(int i=1; i<52; i++)
        {
            int j = rand()%(52-i) + i;
            Card tmp = list[i-1];
            list[i-1] = list[j];
            list[j] = tmp;
        }
    }
}











