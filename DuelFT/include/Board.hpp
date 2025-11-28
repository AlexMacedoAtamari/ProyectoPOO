#ifndef BOARD_HPP
#define BOARD_HPP

struct Cell {
    bool ocupada;
    int idCarta;   // -1 si no hay carta
    int jugador;   // 0 = nadie, 1 = jugador 1, 2 = jugador 2
};

class Board {
public:
    static const int FILAS = 6;
    static const int COLUMNAS = 6;

private:

    Cell celdas[FILAS][COLUMNAS];

public:
    Board();

    bool colocarCarta(int fila, int columna, int idCarta, int jugador);
    bool estaOcupada(int fila, int columna) const;
    Cell getCell(int fila, int columna) const;
};

#endif
