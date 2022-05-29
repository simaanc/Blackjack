//
// Created by duc on 5/4/2022.
//
#pragma once

#include <string>

enum Ranks {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};
enum Suits {
    CLUB, DIAMOND, HEART, SPADE
};

class Card {
private:
    Suits suit;
    Ranks rank;
public:
    Card();  //default constructor

    Card(Ranks rank, Suits suit);   //constructor

    Ranks getRank() const {
        return rank;
    }

    Suits getSuits() const {
        return suit;
    }

    std::string cardGraphic();

    std::string toString() const;

};


class Deck {
private:
    static const int MaxSize = 312;
    Card list[MaxSize];
    int deckSize, pos;
public:
    Deck();

    void addCard(Card);

    void generateDeck();

    void generateCasinoDeck();

    bool checkShouldReshuffle();

    void printDeck();

    void makeEmpty();

    bool isEmpty();

    Card getCard();

    void shuffle();

};