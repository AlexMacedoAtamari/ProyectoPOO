#ifndef CARD_HPP
#define CARD_HPP
#include <SFML/Graphics.hpp>

using namespace sf;

class Game;

class Card {
public:
    int id;

    Card() {
        id = 0;
    }
};

class Ninjas : public Card {
private:

    // Se agregan imagenes para usar como texturas

    Texture textNinjas;


    // Se agregan los sprite para las cartas

    Sprite spNinjas;

    // Declaramos clase friend para poder usar sus atributos

    friend class Game;

};

class Piratas : public Card {
private:

    // Se agregan imagenes para usar como texturas

    Texture textPiratas;

    // Se agregan los sprite para las cartas

    Sprite spPiratas;

    // Declaramos clase friend para poder usar sus atributos

    friend class Game;

};

#endif
