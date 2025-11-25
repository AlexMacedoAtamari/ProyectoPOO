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

    Texture textNinja_1;
    Texture textNinja_2;
    Texture textNinja_3;
    Texture textNinja_4;
    Texture textNinja_5;
    Texture textNinja_6;
    Texture textNinja_7;
    Texture textNinja_8;
    Texture textNinja_9;
    Texture textNinja_10;

    // Se agregan los sprite para las cartas

    Sprite spNinjas;

    Sprite spNinja_1;
    Sprite spNinja_2;
    Sprite spNinja_3;
    Sprite spNinja_4;
    Sprite spNinja_5;
    Sprite spNinja_6;
    Sprite spNinja_7;
    Sprite spNinja_8;
    Sprite spNinja_9;
    Sprite spNinja_10;

    // Declaramos clase friend para poder usar sus atributos

    friend class Game;

};

class Piratas : public Card {
private:

    // Se agregan imagenes para usar como texturas

    Texture textPiratas;

    Texture textPirata_1;
    Texture textPirata_2;
    Texture textPirata_3;
    Texture textPirata_4;
    Texture textPirata_5;
    Texture textPirata_6;
    Texture textPirata_7;
    Texture textPirata_8;
    Texture textPirata_9;
    Texture textPirata_10;

    // Se agregan los sprite para las cartas

    Sprite spPiratas;

    Sprite spPirata_1;
    Sprite spPirata_2;
    Sprite spPirata_3;
    Sprite spPirata_4;
    Sprite spPirata_5;
    Sprite spPirata_6;
    Sprite spPirata_7;
    Sprite spPirata_8;
    Sprite spPirata_9;
    Sprite spPirata_10;

    // Declaramos clase friend para poder usar sus atributos

    friend class Game;

};

#endif
