#include "Game.hpp"

Game::Game() {
    turno = 1; // Empieza el jugador 1
}

Board& Game::getBoard() {
    return board;
}

int Game::getTurno() const {
    return turno;
}

void Game::cambiarTurno() {
    if (turno == 1) {
        turno = 2;
    } else {
        turno = 1;
    }
}

