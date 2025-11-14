#include "Board.h"
#include <iostream>

Board::Board() {
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            grid[i][j] = nullptr;
}

bool Board::placeCard(Card* card, int r, int c) {
    return true;
}

void Board::displayBoard() {
    std::cout << "Tablero temporal...\n";
}
