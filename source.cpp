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
    std::cout <<"Deck after shuffle 1 time!!\n";
    obj1.printDeck();
    return 0;

}
