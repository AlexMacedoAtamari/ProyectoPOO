#include "Board.hpp"

Board::Board() {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            celdas[i][j].ocupada = false;
            celdas[i][j].idCarta = -1;
            celdas[i][j].jugador = 0;
        }
    }
}

bool Board::colocarCarta(int fila, int columna, int idCarta, int jugador) {
    if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
        return false;
    }

    if (celdas[fila][columna].ocupada) {
        return false;
    }

    celdas[fila][columna].ocupada = true;
    celdas[fila][columna].idCarta = idCarta;
    celdas[fila][columna].jugador = jugador;

    return true;
}

bool Board::estaOcupada(int fila, int columna) const {
    if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
        return false;
    }
    return celdas[fila][columna].ocupada;
}

Cell Board::getCell(int fila, int columna) const {
    Cell vacia;
    vacia.ocupada = false;
    vacia.idCarta = -1;
    vacia.jugador = 0;

    if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
        return vacia;
    }

    return celdas[fila][columna];
}



