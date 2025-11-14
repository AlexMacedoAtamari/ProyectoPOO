#ifndef BOARD_H
#define BOARD_H

#include "Card.h"

class Board {
public:
    Card* grid[6][6];

    Board();
    bool placeCard(Card* card, int r, int c);
    void displayBoard();
};

#endif
