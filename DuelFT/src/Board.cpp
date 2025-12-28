#include "Board.hpp"

Board::Board() {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            celdas[i][j].ocupada = false;
            celdas[i][j].idCarta = -1;
            celdas[i][j].jugador = 0;
            celdas[i][j].tipoCarta = 0;
        }
    }
    reset();
}

bool Board::colocarCarta(int fila, int columna, int idCarta, int jugador, int tipoCarta) {
    if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
        return false;
    }

    if (celdas[fila][columna].ocupada) {
        return false;
    }

    celdas[fila][columna].ocupada = true;
    celdas[fila][columna].idCarta = idCarta;
    celdas[fila][columna].jugador = jugador;
    celdas[fila][columna].tipoCarta = tipoCarta ;

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

void Board::cambiarJugador(int fila, int columna, int nuevoJugador)
{
    if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS)
        return;

    if (!celdas[fila][columna].ocupada)
        return;

    celdas[fila][columna].jugador = nuevoJugador;
}

bool Board::estaLleno() const {
    for (int f = 0; f < FILAS; ++f) {
        for (int c = 0; c < COLUMNAS; ++c) {
            if (!celdas[f][c].ocupada)
                return false;
        }
    }
    return true;
}

void Board::reset()
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            celdas[i][j].ocupada = false;
            celdas[i][j].idCarta = -1;
            celdas[i][j].jugador = 0;
            celdas[i][j].tipoCarta = 0;
        }
    }
}
