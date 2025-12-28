#ifndef CARD_DATA_HPP
#define CARD_DATA_HPP

#include <string>

using namespace std;

class CardData {
public:

    string name;

    int north;
    int south;
    int east;
    int west;

    string type;
    int coins;
    string attribute;
    string effect;

    int id;

    // Para el conteo final
    int endvalor;

};

#endif
