project(Blackjack)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blackjack source.cpp Cards.cpp Deck.cpp Player.cpp Player.h Dealer.cpp Dealer.h Hand.cpp Hand.h Deck.cpp Deck.h)
