#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"

class Game {
private:
    Board board;
    int turno;  // 1 o 2

public:
    Game();

    Board& getBoard();
    int getTurno() const;
    void cambiarTurno();
};

#endif
