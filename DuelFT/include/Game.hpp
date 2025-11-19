#ifndef GAME_H
#define GAME_H

#include "Player.hpp"
#include "Board.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class Game {
private:
    RenderWindow window;
    Texture textBackground;
    Sprite spBackground;

public:
    Player p1, p2;
    Board board;
    int turn;

    Game();
    void init();
    void run();

};

#endif
