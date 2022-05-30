/*
     CS281 – Spring 2022
              Card Game Project
              Christopher Simaan & Duc Nguyen
              5/21/2022
              Deck Logic
*/

#include "Deck.h"
#include <iostream>
#include <random>
#include <string>

//Libraries that make cards work 
//properly in Windows Terminal
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#endif


Deck merge(Deck, Deck);


Deck::Deck() {
    deckSize = 0;
    pos = -1;
}

void Deck::addCard(Card oCard) {
    if (deckSize > MaxSize) return;
    list[deckSize] = oCard;
    deckSize++;
}

void Deck::generateDeck() {
    makeEmpty();

    for (Ranks i = ACE; i <= KING; i = Ranks(i + 1)) {
        for (Suits j = CLUB; j <= SPADE; j = Suits(j + 1)) {
            addCard(Card(i, j));
        }
    }
    std::cout << " Successfully generate deck with " << deckSize << " cards\n";
}

void Deck::generateCasinoDeck() {
    makeEmpty();

    for (int i = 0; i < 6; i++) {
        for (Ranks j = ACE; j <= KING; j = Ranks(j + 1)) {
            for (Suits k = CLUB; k <= SPADE; k = Suits(k + 1)) {
                addCard(Card(j, k));
            }
        }
    }
}

bool Deck::checkShouldReshuffle()
{
    if (deckSize <= 60) {
        return true;
    }
    else {
        return false;
    }
}

void Deck::printDeck() {
    if (isEmpty()) std::cout << "Empty Deck!!!\n";
    else {
        std::cout << "There are " << deckSize << " cards left in the deck\n";
        for (int i = 0; i < deckSize; i++) {

            std::cout << (i+1) << ". " << list[i].toString() << "\n";
        }
    }
}

void Deck::makeEmpty() {
    deckSize = 0;
}

bool Deck::isEmpty() {
    if (deckSize == 0) {
        return true;
    } else {
        return false;
    }
}

Card Deck::getCard() {
    if (!isEmpty()) {

#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        setvbuf(stdout, nullptr, _IOFBF, 1000);
#endif

        //std::cout << list[deckSize - 1].toString() << std::endl;

        std::string displayCard = list[deckSize - 1].cardGraphic();

        Card pulledCard = list[deckSize - 1];
        pulledCard.cardGraphic();

        deckSize--;

        return pulledCard;

        //return pulledCard.toString();
    } else {
        std::cout << "No Cards In Deck" << std::endl;
    }

}

void Deck::shuffle() {
    {
        if (isEmpty()) {
            std::cout << "Deck is Empty!" << std::endl;
        }
        else {
            srand(time(0));

            for (int i = 1; i < deckSize; i++) {
                int j = rand() % (deckSize - i) + i;
                Card tmp = list[i - 1];
                list[i - 1] = list[j];
                list[j] = tmp;
            }
        }
    }
}


