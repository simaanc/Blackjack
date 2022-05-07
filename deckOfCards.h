//
// Created by duc on 5/4/2022.
//

#ifndef BLACKJACK_DECKOFCARDS_H
#define BLACKJACK_DECKOFCARDS_H

#include <string>
enum Ranks{ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Suits{CLUB, DIAMOND, HEART, SPADE};

class Card{
private:
    Suits suit;
    Ranks rank;
public:
    Card();  //default constructor
    Card(Ranks rank, Suits suit);   //constructor

    Ranks getRank() const{
        return rank;
    }

    Suits getSuits() const{
        return suit;
    }

    std::string toString() const;

};



class Deck{
private:
    static const int MaxSize = 52;
    Card list[MaxSize];
    int size;
public:
    Deck();
    void addCard(Card);
    void generateDeck();
    void printDeck();

};
#endif //BLACKJACK_DECKOFCARDS_H
