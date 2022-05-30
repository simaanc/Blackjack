/*
     CS281 – Spring 2022
              Card Game Project
              Christopher Simaan & Duc Nguyen
              5/21/2022
              Hand Logic
*/

#include <iostream>
#include "Hand.h"

Hand::Hand() {

}

Hand::Hand(Card *card1, Card *card2) {

}


Hand::~Hand() {
    clear();
}

bool Hand::drawCard(Deck *deck) {
    if (canDraw()) {
        //std::cout << deck.getCard();

        hand[handSize] = deck->getCard();

        //std::cout << hand[handSize].cardGraphic();

        handSize++;

        return true;
    } else
        return false;
}

void Hand::addCard(Card card)
{
    hand[handSize] = card;
    handSize++;
}

void Hand::removeCard()
{
    handSize--;
}


int Hand::getCardCount() {
    return 0;
}

int Hand::getElevenScore() {
    int score = 0;

    for (int i = 0; i <= handSize-1; i++) {
        //std::cout << hand[i].getRank() << "\n";
        switch (hand[i].getRank()) {
        case ACE:
            score = score + 11;
            break;
        case TWO:
            score = score + 2;
            break;
        case THREE:
            score = score + 3;
            break;
        case FOUR:
            score = score + 4;
            break;
        case FIVE:
            score = score + 5;
            break;
        case SIX:
            score = score + 6;
            break;
        case SEVEN:
            score = score + 7;
            break;
        case EIGHT:
            score = score + 8;
            break;
        case NINE:
            score = score + 9;
            break;
        case TEN:
            score = score + 10;
            break;
        case KING:
            score = score + 10;
            break;
        case QUEEN:
            score = score + 10;
            break;
        case JACK:
            score = score + 10;
            break;
        }
    }

    return score;
}

int Hand::getOneScore() {
    int score = 0;

    for (int i = 0; i <= handSize-1; i++) {
        //std::cout << "\n" << hand[i].getRank();

        switch (hand[i].getRank()) {
        case ACE:
            score = score + 1;
            break;
        case TWO:
            score = score + 2;
            break;
        case THREE:
            score = score + 3;
            break;
        case FOUR:
            score = score + 4;
            break;
        case FIVE:
            score = score + 5;
            break;
        case SIX:
            score = score + 6;
            break;
        case SEVEN:
            score = score + 7;
            break;
        case EIGHT:
            score = score + 8;
            break;
        case NINE:
            score = score + 9;
            break;
        case TEN:
            score = score + 10;
            break;
        case KING:
            score = score + 10;
            break;
        case QUEEN:
            score = score + 10;
            break;
        case JACK:
            score = score + 10;
            break;
        }
    }
    return score;
}

int Hand::getHandSize()
{
    return handSize;
}

int Hand::getCardValue(int card)
{
    int value;
    switch (hand[card].getRank()) {
    case ACE:
        value = 1;
        break;
    case TWO:
        value = 2;
        break;
    case THREE:
        value = 3;
        break;
    case FOUR:
        value = 4;
        break;
    case FIVE:
        value = 5;
        break;
    case SIX:
        value = 6;
        break;
    case SEVEN:
        value = 7;
        break;
    case EIGHT:
        value = 8;
        break;
    case NINE:
        value = 9;
        break;
    case TEN:
        value = 10;
        break;
    case KING:
        value = 10;
        break;
    case QUEEN:
        value = 10;
        break;
    case JACK:
        value = 10;
        break;
    }

    return value;
}

void Hand::clear() {
    //memset(hand, 0, sizeof hand);
    handSize = 0;
}

bool Hand::isBustOne() {
    if (getOneScore() > 21)
        return true;
    else
        return false;
}

bool Hand::isBustEleven() {
    if (getElevenScore() > 21)
        return true;
    else
        return false;
}

bool Hand::isCharlie() {
    if (handSize == maxSize and isPlayer) {
        return true;
    } else {
        return false;
    }
}

bool Hand::canDraw() {
    if (handSize <= maxSize-1)
        return true;
    else {
        std::cout << "Can't Draw Any More Than 5 Cards\n";
        return false;
    }
}

bool Hand::isBlackJack() {
    if (handSize == 2 && getElevenScore() == 21)
        return true;
    else
        return false;
}

void Hand::getCardsInHand() {
    if (handSize > 0) {
        std::cout << getHandGraphic();
    }
    else std::cout << "\nNothing\n";
}

std::string Hand::getHandGraphic() {
    std::string convertRanks[13] = {"A", "2", "3", "4", "5", "6", "7",
                                    "8", "9", "10", "J", "Q", "K"};
    std::string convertSuits[4] = {"♣", "♦", "♥", "♠"};

    //Top
    std::string top = "┌─────────┐ ";

    //Side
    std::string side = "│         │ ";

    //Buttom
    std::string bottom = "└─────────┘ ";


    std::string sidetop1;
    std::string suit1;
    std::string sidebottom1;

    std::string sidetop2;
    std::string suit2;
    std::string sidebottom2;

    std::string sidetop3;
    std::string suit3;
    std::string sidebottom3;

    std::string sidetop4;
    std::string suit4;
    std::string sidebottom4;

    std::string sidetop5;
    std::string suit5;
    std::string sidebottom5;

    std::string color1;
    std::string color2;
    std::string color3;
    std::string color4;
    std::string color5;

    std::string newline = "\n";

    if (handSize == 1) {
        if (hand[0].getSuits() == 1 or hand[0].getSuits() == 2) {
            color1 = "\033[0;31m";
        }
        else {
            color1 = "\033[0m";
        }

        if (hand[0].getRank() == 9) {
            sidetop1 = "│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m      │ ";
            suit1 = "│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "│      " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        }
        else {
            sidetop1 = "│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m       │ ";
            suit1 = "│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "│       " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        }


        return
            top + newline +
            sidetop1 + newline +
            side + newline +
            suit1 + newline +
            side + newline +
            sidebottom1 + newline +
            bottom + newline;
        
    } else if (handSize == 2) {

        if (hand[0].getSuits() == 1 or hand[0].getSuits() == 2) {
            color1 = "\033[0;31m";
        } else {
            color1 = "\033[0m";
        }

        if (hand[1].getSuits() == 1 or hand[1].getSuits() == 2) {
            color2 = "\033[0;31m";
        } else {
            color2 = "\033[0m";
        }

        if (hand[0].getRank() == 9) {
            sidetop1 = "│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m      │ ";
            suit1 = "│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "│      " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        } else {
            sidetop1 = "│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m       │ ";
            suit1 = "│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "│       " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        }

        if (hand[1].getRank() == 9) {
            sidetop2 = "│ " + color2 + convertRanks[hand[1].getRank()] + "\033[0m      │ ";
            suit2 = "│    " + color2 + convertSuits[hand[1].getSuits()] + "\033[0m    │ ";
            sidebottom2 = "│      " + color2 + convertRanks[hand[1].getRank()] + "\033[0m │ ";

        } else {
            sidetop2 = "│ " + color2 + convertRanks[hand[1].getRank()] + "\033[0m       │ ";
            suit2 = "│    " + color2 + convertSuits[hand[1].getSuits()] + "\033[0m    │ ";
            sidebottom2 = "│       " + color2 + convertRanks[hand[1].getRank()] + "\033[0m │ ";

        }

        return
                top + top + newline +
                sidetop1 + sidetop2 + newline +
                side + side + newline +
                suit1 + suit2 + newline +
                side + side + newline +
                sidebottom1 + sidebottom2 + newline +
                bottom + bottom + newline;
    } else if (handSize == 3) {

        if (hand[0].getSuits() == 1 or hand[0].getSuits() == 2) {
            color1 = "\033[0;31m";
        } else {
            color1 = "\033[0m";
        }

        if (hand[1].getSuits() == 1 or hand[1].getSuits() == 2) {
            color2 = "\033[0;31m";
        } else {
            color2 = "\033[0m";
        }
        if (hand[2].getSuits() == 1 or hand[2].getSuits() == 2) {
            color3 = "\033[0;31m";
        } else {
            color3 = "\033[0m";
        }

        //CARD 1
        if (hand[0].getRank() == 9) {
            sidetop1 = "│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m      │ ";
            suit1 = "│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "│      " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        } else {
            sidetop1 = "│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m       │ ";
            suit1 = "│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "│       " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        }

        //CARD 2
        if (hand[1].getRank() == 9) {
            sidetop2 = "│ " + color2 + convertRanks[hand[1].getRank()] + "\033[0m      │ ";
            suit2 = "│    " + color2 + convertSuits[hand[1].getSuits()] + "\033[0m    │ ";
            sidebottom2 = "│      " + color2 + convertRanks[hand[1].getRank()] + "\033[0m │ ";

        } else {
            sidetop2 = "│ " + color2 + convertRanks[hand[1].getRank()] + "\033[0m       │ ";
            suit2 = "│    " + color2 + convertSuits[hand[1].getSuits()] + "\033[0m    │ ";
            sidebottom2 = "│       " + color2 + convertRanks[hand[1].getRank()] + "\033[0m │ ";

        }

        //CARD 3
        if (hand[2].getRank() == 9) {
            sidetop3 = "│ " + color3 + convertRanks[hand[2].getRank()] + "\033[0m      │ ";
            suit3 = "│    " + color3 + convertSuits[hand[2].getSuits()] + "\033[0m    │ ";
            sidebottom3 = "│      " + color3 + convertRanks[hand[2].getRank()] + "\033[0m │ ";

        } else {
            sidetop3 = "│ " + color3 + convertRanks[hand[2].getRank()] + "\033[0m       │ ";
            suit3 = "│    " + color3 + convertSuits[hand[2].getSuits()] + "\033[0m    │ ";
            sidebottom3 = "│       " + color3 + convertRanks[hand[2].getRank()] + "\033[0m │ ";

        }

        return
                top + top + top + newline +
                sidetop1 + sidetop2 + sidetop3 + newline +
                side + side + side + newline +
                suit1 + suit2 + suit3 + newline +
                side + side + side + newline +
                sidebottom1 + sidebottom2 + sidebottom3 + newline +
                bottom + bottom + bottom + newline;
    } else if (handSize == 4) {

        if (hand[0].getSuits() == 1 or hand[0].getSuits() == 2) {
            color1 = "\033[0;31m";
        } else {
            color1 = "\033[0m";
        }
        if (hand[1].getSuits() == 1 or hand[1].getSuits() == 2) {
            color2 = "\033[0;31m";
        } else {
            color2 = "\033[0m";
        }
        if (hand[2].getSuits() == 1 or hand[2].getSuits() == 2) {
            color3 = "\033[0;31m";
        } else {
            color3 = "\033[0m";
        }
        if (hand[3].getSuits() == 1 or hand[3].getSuits() == 2) {
            color4 = "\033[0;31m";
        } else {
            color4 = "\033[0m";
        }

        //CARD 1
        if (hand[0].getRank() == 9) {
            sidetop1 = "│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m      │ ";
            suit1 = "│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "│      " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        } else {
            sidetop1 = "│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m       │ ";
            suit1 = "│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "│       " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        }

        //CARD 2
        if (hand[1].getRank() == 9) {
            sidetop2 = "│ " + color2 + convertRanks[hand[1].getRank()] + "\033[0m      │ ";
            suit2 = "│    " + color2 + convertSuits[hand[1].getSuits()] + "\033[0m    │ ";
            sidebottom2 = "│      " + color2 + convertRanks[hand[1].getRank()] + "\033[0m │ ";

        } else {
            sidetop2 = "│ " + color2 + convertRanks[hand[1].getRank()] + "\033[0m       │ ";
            suit2 = "│    " + color2 + convertSuits[hand[1].getSuits()] + "\033[0m    │ ";
            sidebottom2 = "│       " + color2 + convertRanks[hand[1].getRank()] + "\033[0m │ ";

        }

        //CARD 3
        if (hand[2].getRank() == 9) {
            sidetop3 = "│ " + color3 + convertRanks[hand[2].getRank()] + "\033[0m      │ ";
            suit3 = "│    " + color3 + convertSuits[hand[2].getSuits()] + "\033[0m    │ ";
            sidebottom3 = "│      " + color3 + convertRanks[hand[2].getRank()] + "\033[0m │ ";

        } else {
            sidetop3 = "│ " + color3 + convertRanks[hand[2].getRank()] + "\033[0m       │ ";
            suit3 = "│    " + color3 + convertSuits[hand[2].getSuits()] + "\033[0m    │ ";
            sidebottom3 = "│       " + color3 + convertRanks[hand[2].getRank()] + "\033[0m │ ";

        }

        //CARD 4
        if (hand[3].getRank() == 9) {
            sidetop4 = "│ " + color4 + convertRanks[hand[3].getRank()] + "\033[0m      │ ";
            suit4 = "│    " + color4 + convertSuits[hand[3].getSuits()] + "\033[0m    │ ";
            sidebottom4 = "│      " + color4 + convertRanks[hand[3].getRank()] + "\033[0m │ ";

        } else {
            sidetop4 = "│ " + color4 + convertRanks[hand[3].getRank()] + "\033[0m       │ ";
            suit4 = "│    " + color4 + convertSuits[hand[3].getSuits()] + "\033[0m    │ ";
            sidebottom4 = "│       " + color4 + convertRanks[hand[3].getRank()] + "\033[0m │ ";

        }

        return
                top + top + top + top + newline +
                sidetop1 + sidetop2 + sidetop3 + sidetop4 + newline +
                side + side + side + side + newline +
                suit1 + suit2 + suit3 + suit4 + newline +
                side + side + side + side + newline +
                sidebottom1 + sidebottom2 + sidebottom3 + sidebottom4 + newline +
                bottom + bottom + bottom + bottom + newline;
    } else if (handSize == 5) {

        std::string newline = "\n";

        if (hand[0].getSuits() == 1 or hand[0].getSuits() == 2) {
            color1 = "\033[0;31m";
        } else {
            color1 = "\033[0m";
        }
        if (hand[1].getSuits() == 1 or hand[1].getSuits() == 2) {
            color2 = "\033[0;31m";
        } else {
            color2 = "\033[0m";
        }
        if (hand[2].getSuits() == 1 or hand[2].getSuits() == 2) {
            color3 = "\033[0;31m";
        } else {
            color3 = "\033[0m";
        }
        if (hand[3].getSuits() == 1 or hand[3].getSuits() == 2) {
            color4 = "\033[0;31m";
        } else {
            color4 = "\033[0m";
        }
        if (hand[4].getSuits() == 1 or hand[4].getSuits() == 2) {
            color5 = "\033[0;31m";
        } else {
            color5 = "\033[0m";
        }

        //CARD 1
        if (hand[0].getRank() == 9) {
            sidetop1 = "\033[0m│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m      │ ";
            suit1 = "\033[0m│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "\033[0m│      " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        } else {
            sidetop1 = "\033[0m│ " + color1 + convertRanks[hand[0].getRank()] + "\033[0m       │ ";
            suit1 = "\033[0m│    " + color1 + convertSuits[hand[0].getSuits()] + "\033[0m    │ ";
            sidebottom1 = "\033[0m│       " + color1 + convertRanks[hand[0].getRank()] + "\033[0m │ ";

        }

        //CARD 2
        if (hand[1].getRank() == 9) {
            sidetop2 = "\033[0m│ " + color2 + convertRanks[hand[1].getRank()] + "\033[0m      │ ";
            suit2 = "\033[0m│    " + color2 + convertSuits[hand[1].getSuits()] + "\033[0m    │ ";
            sidebottom2 = "\033[0m│      " + color2 + convertRanks[hand[1].getRank()] + "\033[0m │ ";

        } else {
            sidetop2 = "\033[0m│ " + color2 + convertRanks[hand[1].getRank()] + "\033[0m       │ ";
            suit2 = "\033[0m│    " + color2 + convertSuits[hand[1].getSuits()] + "\033[0m    │ ";
            sidebottom2 = "\033[0m│       " + color2 + convertRanks[hand[1].getRank()] + "\033[0m │ ";

        }

        //CARD 3
        if (hand[2].getRank() == 9) {
            sidetop3 = "\033[0m│ " + color3 + convertRanks[hand[2].getRank()] + "\033[0m      │ ";
            suit3 = "\033[0m│    " + color3 + convertSuits[hand[2].getSuits()] + "\033[0m    │ ";
            sidebottom3 = "\033[0m│      " + color3 + convertRanks[hand[2].getRank()] + "\033[0m │ ";

        } else {
            sidetop3 = "\033[0m│ " + color3 + convertRanks[hand[2].getRank()] + "\033[0m       │ ";
            suit3 = "\033[0m│    " + color3 + convertSuits[hand[2].getSuits()] + "\033[0m    │ ";
            sidebottom3 = "\033[0m│       " + color3 + convertRanks[hand[2].getRank()] + "\033[0m │ ";

        }

        //CARD 4
        if (hand[3].getRank() == 9) {
            sidetop4 = "\033[0m│ " + color4 + convertRanks[hand[3].getRank()] + "\033[0m      │ ";
            suit4 = "\033[0m│    " + color4 + convertSuits[hand[3].getSuits()] + "\033[0m    │ ";
            sidebottom4 = "\033[0m│      " + color4 + convertRanks[hand[3].getRank()] + "\033[0m │ ";

        } else {
            sidetop4 = "\033[0m│ " + color4 + convertRanks[hand[3].getRank()] + "\033[0m       │ ";
            suit4 = "\033[0m│    " + color4 + convertSuits[hand[3].getSuits()] + "\033[0m    │ ";
            sidebottom4 = "\033[0m│       " + color4 + convertRanks[hand[3].getRank()] + "\033[0m │ ";

        }

        //CARD 5
        if (hand[4].getRank() == 9) {
            sidetop5 = "\033[0m│ " + color5 + convertRanks[hand[4].getRank()] + "\033[0m      │ ";
            suit5 = "\033[0m│    " + color5 + convertSuits[hand[4].getSuits()] + "\033[0m    │ ";
            sidebottom5 = "\033[0m│      " + color5 + convertRanks[hand[4].getRank()] + "\033[0m │ ";

        } else {
            sidetop5 = "\033[0m│ " + color5 + convertRanks[hand[4].getRank()] + "\033[0m       │ ";
            suit5 = "\033[0m│    " + color5 + convertSuits[hand[4].getSuits()] + "\033[0m    │ ";
            sidebottom5 = "\033[0m│       " + color5 + convertRanks[hand[4].getRank()] + "\033[0m │ ";

        }

        return
                top + top + top + top + top + newline +
                sidetop1 +  sidetop2 +  sidetop3 +  sidetop4 + sidetop5 + newline +
                side + side + side + side + side + newline +
                suit1 + suit2 + suit3 + suit4 + suit5 + newline +
                side + side + side + side + side +newline +
                sidebottom1 + sidebottom2 + sidebottom3 + sidebottom4 + sidebottom5 + newline +
                bottom + bottom + bottom + bottom + bottom + newline;
    }
}

Card Hand::getCardForSplit()
{
    return Card(hand[1].getRank(), hand[1].getSuits());
}
