#include <iostream>
#include "deckOfCards.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Deck obj1;
    std::cout << "Deck before generate!!\n" ;
    obj1.printDeck();
    obj1.generateDeck(); //testing
    std::cout << "Deck after generate!!\n";
    obj1.printDeck();
    obj1.shuffle();
    obj1.shuffle();
    obj1.shuffle();
    obj1.shuffle();
    std::cout <<"Deck after shuffle 1 time!!\n";
    obj1.printDeck();
    std:: cout << "Deck after get 1 card!!\n";
    obj1.getCard();
    obj1.printDeck();
    return 0;

}
