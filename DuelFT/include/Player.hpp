#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "Card.hpp"

class Player {
public:
    std::string name;
    int coins;
    std::vector<Card> deck;

    Player();
};

#endif
