#ifndef CARD_MANAGER_HPP
#define CARD_MANAGER_HPP

#include <vector>
#include "CardData.hpp"

using namespace std;

// La clase CardManeger administra TODAS LAS CARTAS del juego:
//  - ninjas  → vector que guarda datos de cartas ninja
//  - piratas → vector que guarda datos de cartas pirata

class CardManager {

public:

    // Listas donde se guardan las cartas
    vector<CardData> ninjas;
    vector<CardData> piratas;

    // Constructor: al crear un CardManager se cargan las cartas
    CardManager();

    // Funciones que cargarán las cartas por facción
    void loadNinjas();
    void loadPiratas();

    // Funciones para obtener una carta por ID
    CardData& getNinja(int id);
    CardData& getPirata(int id);

};

#endif
