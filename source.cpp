#include <iostream>
#include "deckOfCards.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Deck obj1;
    obj1.printDeck();
    obj1.generateDeck(); //testing
    obj1.printDeck();
    obj1.makeEmpty();
    obj1.printDeck();
    return 0;

}
