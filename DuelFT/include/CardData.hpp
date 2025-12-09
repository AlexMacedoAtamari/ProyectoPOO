#ifndef CARD_DATA_HPP
#define CARD_DATA_HPP

#include <string>

struct CardData {

    std::string name;

    int north;
    int south;
    int east;
    int west;

    std::string type;
    int coins;
    std::string attribute;
    std::string effect;

    int id;
};

#endif
