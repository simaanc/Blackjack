//
// Created by duc on 5/4/2022.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

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
    static const int MaxSize = 52;
    Card list[MaxSize];
    int size, pos;
public:
    Deck();

    void addCard(Card);

    void generateDeck();

    void printDeck();

    void makeEmpty();

    bool isEmpty();

    void getCard();

    void shuffle();

};

#endif //BLACKJACK_DECK_H
