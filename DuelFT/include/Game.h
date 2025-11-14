#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game {
public:
    Player p1, p2;
    Board board;
    int turn;

    Game();
    void startGame();
};

#endif
