#ifndef CARD_MANAGER_HPP
#define CARD_MANAGER_HPP

#include <vector>
#include "CardData.hpp"

// ---------------------------------------------------------------------------
// CardManager
//
// Esta clase administra TODAS LAS CARTAS del juego:
//
//  - ninjas  → vector que guarda datos de cartas ninja
//  - piratas → vector que guarda datos de cartas pirata
//
// Aquí solo DECLARO la estructura de la clase.
// Las funciones se IMPLEMENTAN en CardManager.cpp
// ---------------------------------------------------------------------------
class CardManager {

public:

    // Listas donde guardaré todas las cartas
    std::vector<CardData> ninjas;
    std::vector<CardData> piratas;

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
