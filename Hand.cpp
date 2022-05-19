//
// Created by Chris Simaan on 5/15/22.
//

#include <iostream>
#include "Hand.h"

Hand::Hand() {

}

Hand::Hand(Card *card1, Card *card2) {

}


Hand::~Hand() {

}

bool Hand::drawCard(Deck *deck) {
    if (canDraw()) {
        //std::cout << deck.getCard();

        hand[handSize] = deck->getCard();

        std::cout << hand[handSize].cardGraphic();

        handSize++;

        return true;
    } else
        return false;
}


int Hand::getCardCount() {
    return 0;
}

int Hand::getElevenScore() {
    return 0;
}

int Hand::getOneScore() {
    return 0;
}

void Hand::clear() {

}

bool Hand::isBust() {
    return false;
}

bool Hand::isCharlie() {
    return false;
}

bool Hand::canDraw() {
    if (handSize <= maxSize)
        return true;
    else {
        std::cout << "Can't Draw Any More Than 5 Cards\n";
        return false;
    }
}

bool Hand::isBlackJack() {
    return false;
}

void Hand::getCardsInHand() {
    if (handSize >= 0) {
        std::cout << getHandGraphic();
    }
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

    if (handSize == 1) {
        std::string color;
        if (hand[0].getSuits() == 1 or hand[0].getSuits() == 2) {
            color = "\033[0;31m";
        } else {
            color = "\033[0m";
        }

        if (hand[0].getRank() == 9) {
            std::string sidetop = "│ " + color + convertRanks[hand[0].getRank()] + "\033[0m      │\n";
            std::string suit = "│    " + color + convertSuits[hand[0].getSuits()] + "\033[0m    │\n";
            std::string sidebottom = "│      " + color + convertRanks[hand[0].getRank()] + "\033[0m │\n";

            return top + sidetop + side + suit + side + sidebottom + bottom;
        } else {
            std::string sidetop = "│ " + color + convertRanks[hand[0].getRank()] + "\033[0m       │\n";
            std::string suit = "│    " + color + convertSuits[hand[0].getSuits()] + "\033[0m    │\n";
            std::string sidebottom = "│       " + color + convertRanks[hand[0].getRank()] + "\033[0m │\n";

            return top + sidetop + side + suit + side + sidebottom + bottom;
        }
    } else if (handSize == 2) {

        std::string sidetop1;
        std::string suit1;
        std::string sidebottom1;

        std::string sidetop2;
        std::string suit2;
        std::string sidebottom2;

        std::string color1;
        std::string color2;

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
                bottom + bottom;
    } else if (handSize == 3) {

        std::string sidetop1;
        std::string suit1;
        std::string sidebottom1;

        std::string sidetop2;
        std::string suit2;
        std::string sidebottom2;

        std::string sidetop3;
        std::string suit3;
        std::string sidebottom3;

        std::string color1;
        std::string color2;
        std::string color3;

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
                bottom + bottom + bottom;
    } else if (handSize == 4) {

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

        std::string color1;
        std::string color2;
        std::string color3;
        std::string color4;

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
                bottom + bottom + bottom + bottom;
    } else if (handSize == 5) {
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
                bottom + bottom + bottom + bottom + bottom;
    }
}
