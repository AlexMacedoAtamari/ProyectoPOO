#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    int north, east, south, west;
    std::string type;
    std::string effect;
    int owner;

    Card();
};

#endif
