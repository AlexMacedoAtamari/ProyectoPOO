#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

Game::Game() {
    init();
    turn = 1;
}

void Game::init() {
    std::cout << "Iniciando juego DUELFT...\n";

    // Iniciando la ventana de juego
    window.create(VideoMode(800,600),"Duel FT");

    // Cargando la textura del fondo del juego
    textBackground.loadFromFile("imagenes/tablero-verde.png");
    // Cargando el Sprite del fondo del juego
    spBackground.setTexture(textBackground);
    // Escalando el tablero
    Vector2u textureSize = textBackground.getSize();
    Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    spBackground.setScale(scaleX,scaleY);
}

void Game::run(){
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(spBackground);
        window.display();
    }

}
