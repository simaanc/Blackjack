cmake_minimum_required(VERSION 3.21)
project(Blackjack)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blackjack source.cpp Cards.cpp deck.cpp Player.cpp Player.h Dealer.cpp Dealer.h Hand.cpp Hand.h Deck.cpp Deck.h)
