#include <iostream>
#include "Deck.h"
#include "Hand.h"

int menu();
void clearScreen();
void pauseScreen();

int main() {
    std::cout << "Hello, World!" << std::endl;

    Deck deck;
    Hand hand;

    int input = 0;

    //std::cout << "Deck before generate!!\n";
    //deck.printDeck();
    //deck.generateDeck(); //testing
    //std::cout << "Deck after generate!!\n";
    ////deck.printDeck();
    //deck.shuffle();
    ////deck.printDeck();

    ////Drawing Cards
    //hand.drawCard(&deck);
    //hand.drawCard(&deck);
    //hand.drawCard(&deck);
    //hand.drawCard(&deck);
    //hand.drawCard(&deck);
    //hand.drawCard(&deck);
    //hand.drawCard(&deck);
    //hand.drawCard(&deck);
    //hand.drawCard(&deck);

    //std::cout << "\nYour Hand:\n";
    //hand.getCardsInHand();
    //deck.printDeck();


    do {
        input = menu();
        switch (input) {
        case 1:
            deck.generateDeck();
            std::cout << "Generated Deck";

            pauseScreen();
            break;
        case 2:
            deck.shuffle();
            std::cout << "Shuffle Deck";

            pauseScreen();
            break;
        case 3:
            deck.printDeck();

            pauseScreen();
            break;        
        case 4:
            std::cout << deck.getCard().cardGraphic();

            pauseScreen();
            break;        
        case 5:
            deck.makeEmpty();

            pauseScreen();
            break;
        case 6:
            std::cout << "Goodbye";
            pauseScreen();
        }
        clearScreen();
    } while (input != 6);

    return 0;

}

int menu() {
    int input;
    std::cout << "Enter the number for the eoperation you wish to perform from the menu." << std::endl
        << "1. Generate Deck" << std::endl
        << "2. Shuffle Deck" << std::endl
        << "3. Print Deck" << std::endl
        << "4. Get Card" << std::endl
        << "5. Make Deck Empty" << std::endl
        << "6. Exit program" << std::endl
        << std::endl;
    std::cout << "Enter Choice: ";
    std::cin >> input;
    while (input < 1 or input > 6) {
        std::cout << "Enter a valid Choice from the menu: ";
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        std::cin >> input;
    }
    return input;
}
void clearScreen() {
    system("CLS");
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}
void pauseScreen() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "\n---Enter to Continue!---\n";
    std::cin.get();
}
