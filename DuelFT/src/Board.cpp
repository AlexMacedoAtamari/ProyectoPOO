#include "Board.hpp"
#include <iostream>

using namespace std;

Board::Board() {
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            grid[i][j] = nullptr;
}

bool Board::placeCard(Card* card, int r, int c) {
    return true;
}

void Board::displayBoard() {
    cout << "Tablero temporal...\n";
}


