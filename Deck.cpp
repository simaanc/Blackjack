//
// Created by duc on 5/6/2022.
//
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

void Deck::printDeck() {
    if (isEmpty()) std::cout << "Empty Deck!!!\n";
    else {
        std::cout << "There are " << deckSize << " cards left in the deck\n";
        for (int i = 0; i < deckSize; i++) {

            std::cout << list[i].toString() << "\n";
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

        std::cout << list[deckSize - 1].toString() << std::endl;

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
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 6);

        for (int i = 1; i < 52; i++) {
            int j = dis(gen) % (52 - i) + i;
            Card tmp = list[i - 1];
            list[i - 1] = list[j];
            list[j] = tmp;
        }
    }
}


