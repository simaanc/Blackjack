#include <iostream>
#include "Deck.h"
#include "Hand.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Deck deck;
    Hand hand;
    std::cout << "Deck before generate!!\n";
    deck.printDeck();
    deck.generateDeck(); //testing
    std::cout << "Deck after generate!!\n";
    //deck.printDeck();
    deck.shuffle();
    //deck.printDeck();

    //Drawing Cards
    hand.drawCard(&deck);
    hand.drawCard(&deck);
    hand.drawCard(&deck);
    hand.drawCard(&deck);
    hand.drawCard(&deck);

    std::cout << "\nYour Hand:\n";
    hand.getCardsInHand();
    //deck.printDeck();

    return 0;

}
