#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Card.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Game {
private:
    Board board;
    int turno;  // 1 o 2

    // Declaramos RenderWindow
    RenderWindow window;

    // Declaramos a la clase Ninja
    Ninjas n;

    // Declaramos a la clase Piratas
    Piratas p;

    // Definimos vectores para los ninjas
    vector<Texture> ninjasTextures;
    vector<Sprite> ninjasSprites;

    // Definimos vectores para los piratas
    vector<Texture> piratasTextures;
    vector<Sprite> piratasSprites;

    // Método para cargar los archivos
    void loadNinjas();
    void loadPiratas();

public:
    Game();

    Board& getBoard();
    int getTurno() const;
    void cambiarTurno();

    // Métodos del juego
    void init();
    void load();
    void run();
    void handlePlayerInput();
    void draw();
    void update();

};

#endif
