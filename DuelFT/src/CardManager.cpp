#include "CardManager.hpp"
#include <iostream>

// Al crear CardManager, automáticamente se cargan
// todas las cartas Ninja y Pirata.
CardManager::CardManager() {
    loadNinjas();
    loadPiratas();
}

// Se carga todas las cartas Ninja
// Cada carta coincide EXACTAMENTE con sus imágenes:
// imagen 1 → carta ID 0
// imagen 2 → carta ID 1
// ...
// imagen 19 → carta ID 18

void CardManager::loadNinjas() {

    ninjas.clear();
    ninjas.reserve(19);

    CardData c;

    // ==========================================================
    // NINJA 1
    // ==========================================================
    c.id = 0;
    c.name = "NINJA APRENDIZ";
    c.north = 3; c.south = 2; c.east = 2; c.west = 1;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Marron/Amarilla con X";
    c.effect = "Si gana un enfrentamiento obtienes +1 moneda.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 2
    // ==========================================================
    c.id = 1;
    c.name = "NINJA APRENDIZ";
    c.north = 1; c.south = 2; c.east = 2; c.west = 3;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Marron/Amarilla con X";
    c.effect = "Si gana un enfrentamiento obtienes +1 moneda.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 3
    // ==========================================================
    c.id = 2;
    c.name = "NINJA APRENDIZ";
    c.north = 1; c.south = 2; c.east = 3; c.west = 2;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Marron/Amarilla con X";
    c.effect = "Si gana un enfrentamiento obtienes +1 moneda.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 4
    // ==========================================================
    c.id = 3;
    c.name = "MERODEADOR";
    c.north = 2; c.south = 1; c.east = 2; c.west = 3;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Marron/Amarilla con X";
    c.effect = "Gana +1 moneda si lo colocas en un sitio neutral";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 5 – MERODEADOR
    // ==========================================================
    c.id = 4;
    c.name = "MERODEADOR";
    c.north = 1; c.south = 3; c.east = 2; c.west = 2;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Marron/Amarilla con X";
    c.effect = "Gana +1 moneda si lo colocas en un sitio neutral.";
    // Explicación:
    // → Si la celda donde se coloca no pertenece a nadie, coins += 1.
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 6 – MERODEADOR
    // ==========================================================
    c.id = 5;
    c.name = "MERODEADOR";
    c.north = 2; c.south = 3; c.east = 1; c.west = 2;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Marron/Amarilla con X";
    c.effect = "Gana +1 moneda si lo colocas en un sitio neutral.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 7 – LADRON SOMBRIO
    // ==========================================================
    c.id = 6;
    c.name = "LADRON SOMBRIO";
    c.north = 1; c.south = 1; c.east = 2; c.west = 4;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Marron/Amarilla con X";
    c.effect = "Roba +1 moneda a tu oponente si ganas un enfrentamiento.";
    // Explicación:
    // → Si gana combate: coins_jugador++, coins_oponente--
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 8 – LADRON SOMBRIO
    // ==========================================================
    c.id = 7;
    c.name = "LADRON SOMBRIO";
    c.north = 4; c.south = 1; c.east = 2; c.west = 1;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Marron/Amarilla con X";
    c.effect = "Roba +1 moneda a tu oponente si ganas un enfrentamiento.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 9 – LADRON SOMBRIO
    // ==========================================================
    c.id = 8;
    c.name = "LADRON SOMBRIO";
    c.north = 1; c.south = 4; c.east = 1; c.west = 2;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Marron/Amarilla con X";
    c.effect = "Roba +1 moneda a tu oponente si ganas un enfrentamiento.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 10 – ASESINO SILENCIOSO
    // ==========================================================
    c.id = 9;
    c.name = "ASESINO SILENCIOSO";
    c.north = 5; c.south = 2; c.east = 1; c.west = 4;
    c.type = "Ataque";
    c.coins = +2;
    c.endvalor = 2;
    c.attribute = "Triangulo Amarillo";
    c.effect = "Si ganas un enfrentamiento, conviertes a otra ficha adyacente automaticamente.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 11 – ASESINO SILENCIOSO
    // ==========================================================
    c.id = 10;
    c.name = "ASESINO SILENCIOSO";
    c.north = 2; c.south = 4; c.east = 5; c.west = 1;
    c.type = "Ataque";
    c.coins = +2;
    c.endvalor = 2;
    c.attribute = "Triangulo Amarillo";
    c.effect = "Si ganas un enfrentamiento, conviertes a otra ficha adyacente automaticamente.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 12 – MAESTRA DEL VENENO
    // ==========================================================
    c.id = 11;
    c.name = "MAESTRA DEL VENENO";
    c.north = 3; c.south = 3; c.east = 4; c.west = 2;
    c.type = "Ataque";
    c.coins = 0;
    c.endvalor = 2;
    c.attribute = "Triangulo Amarillo";
    c.effect = "La ficha convertida obtiene -1 en todos sus lados por 1 turno.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 13 – MAESTRA DEL VENENO
    // ==========================================================
    c.id = 12;
    c.name = "MAESTRA DEL VENENO";
    c.north = 4; c.south = 2; c.east = 3; c.west = 3;
    c.type = "Ataque";
    c.coins = 0;
    c.endvalor = 2;
    c.attribute = "Triangulo Amarillo";
    c.effect = "La ficha convertida obtiene -1 en todos sus lados por 1 turno.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 14 – NINJA INFILTRADO
    // ==========================================================
    c.id = 13;
    c.name = "NINJA INFILTRADO";
    c.north = 4; c.south = 2; c.east = 4; c.west = 2;
    c.type = "Ataque";
    c.coins = +2;
    c.endvalor = 2;
    c.attribute = "Triangulo Amarillo";
    c.effect = "Puede colocarse como una ficha del bando enemigo hasta que la reveles.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 15 – NINJA INFILTRADO
    // ==========================================================
    c.id = 14;
    c.name = "NINJA INFILTRADO";
    c.north = 2; c.south = 4; c.east = 2; c.west = 4;
    c.type = "Ataque";
    c.coins = +2;
    c.endvalor = 2;
    c.attribute = "Triangulo Amarillo";
    c.effect = "Puede colocarse como una ficha del bando enemigo hasta que la reveles.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 16 – MAESTRO DE SOMBRAS
    // ==========================================================
    c.id = 15;
    c.name = "MAESTRO DE SOMBRAS";
    c.north = 3; c.south = 3; c.east = 4; c.west = 2;
    c.type = "Ataque";
    c.coins = +3;
    c.endvalor = 3;
    c.attribute = "Estrella Amarilla";
    c.effect = "Intercambia esta ficha con cualquier otra aliada en el tablero.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 17 – GUERRERO KAGUE
    // ==========================================================
    c.id = 16;
    c.name = "GUERRERO KAGUE";
    c.north = 1; c.south = 1; c.east = 5; c.west = 5;
    c.type = "Apoyo";
    c.coins = +3;
    c.endvalor = 3;
    c.attribute = "Estrella Amarilla";
    c.effect = "Bloquea conversiones enemigas en casillas adyacentes.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 18 – ESPIA IMPERIAL
    // ==========================================================
    c.id = 17;
    c.name = "ESPIA IMPERIAL";
    c.north = 5; c.south = 5; c.east = 1; c.west = 2;
    c.type = "Ataque";
    c.coins = +3;
    c.endvalor = 3;
    c.attribute = "Estrella Amarilla";
    c.effect = "Toma control de una ficha enemiga 1 turno.";
    ninjas.push_back(c);

    // ==========================================================
    // NINJA 19 – LADRON DE ALMAS
    // ==========================================================
    c.id = 18;
    c.name = "LADRON DE ALMAS";
    c.north = 3; c.south = 3; c.east = 2; c.west = 4;
    c.type = "Apoyo";
    c.coins = +1;
    c.endvalor = 3;
    c.attribute = "Estrella Amarilla";
    c.effect = "Desactiva habilidades en casillas adyacentes por 1 turno.";
    ninjas.push_back(c);
}


// Se carga todas las cartas Pirata

void CardManager::loadPiratas() {

    piratas.clear();
    piratas.reserve(19);

    CardData c;

    // ----------------------------------------------------------
    // PIRATA 1 – NOVATO
    // ----------------------------------------------------------
    c.id = 0;
    c.name = "NOVATO";
    c.north = 3; c.south = 2; c.east = 2; c.west = 1;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Roja/Amarilla con X";
    c.effect = "Si gana un enfrentamiento obtienes +2 monedas.";
    piratas.push_back(c);

    // PIRATA 2
    c.id = 1;
    c.name = "NOVATO";
    c.north = 1; c.south = 2; c.east = 2; c.west = 3;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Roja/Amarilla con X";
    c.effect = "Si gana un enfrentamiento obtienes +2 monedas.";
    piratas.push_back(c);

    // PIRATA 3
    c.id = 2;
    c.name = "NOVATO";
    c.north = 1; c.south = 2; c.east = 3; c.west = 2;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Roja/Amarilla con X";
    c.effect = "Si gana un enfrentamiento obtienes +2 monedas.";
    piratas.push_back(c);

    // PIRATA 4 – CORSARIO
    c.id = 3;
    c.name = "CORSARIO";
    c.north = 2; c.south = 1; c.east = 2; c.west = 3;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Roja/Amarilla con X";
    c.effect = "Gana +1 a la izquierda si se coloca junto a un aliado.";
    piratas.push_back(c);

    // PIRATA 5
    c.id = 4;
    c.name = "CORSARIO";
    c.north = 1; c.south = 3; c.east = 2; c.west = 2;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Roja/Amarilla con X";
    c.effect = "Gana +1 a la izquierda si se coloca junto a un aliado.";
    piratas.push_back(c);

    // PIRATA 6
    c.id = 5;
    c.name = "CORSARIO";
    c.north = 3; c.south = 2; c.east = 1; c.west = 2;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Roja/Amarilla con X";
    c.effect = "Gana +1 a la izquierda si se coloca junto a un aliado.";
    piratas.push_back(c);

    // PIRATA 7 – GRUMETE
    c.id = 6;
    c.name = "GRUMETE";
    c.north = 1; c.south = 1; c.east = 2; c.west = 4;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Roja/Amarilla con X";
    c.effect = "Refuerza +1 a una ficha aliada adyacente.";
    piratas.push_back(c);

    // PIRATA 8 – GRUMETE
    c.id = 7;
    c.name = "GRUMETE";
    c.north = 4; c.south = 1; c.east = 2; c.west = 1;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Roja/Amarilla con X";
    c.effect = "Refuerza +1 a una ficha aliada adyacente.";
    piratas.push_back(c);

    // PIRATA 9 – GRUMETE
    c.id = 8;
    c.name = "GRUMETE";
    c.north = 1; c.south = 4; c.east = 1; c.west = 2;
    c.type = "Apoyo";
    c.coins = 0;
    c.endvalor = 1;
    c.attribute = "Bandera Roja/Amarilla con X";
    c.effect = "Refuerza +1 a una ficha aliada adyacente.";
    piratas.push_back(c);

    // PIRATA 10 – CAÑONERO
    c.id = 9;
    c.name = "CAÑONERO";
    c.north = 5; c.south = 0; c.east = 3; c.west = 4;
    c.type = "Ataque";
    c.coins = +1;
    c.endvalor = 2;
    c.attribute = "Triangulo Rojo";
    c.effect = "Inflige -2 al lado más alto de una ficha enemiga adyacente.";
    piratas.push_back(c);

    // PIRATA 11 – CAÑONERO
    c.id = 10;
    c.name = "CAÑONERO";
    c.north = 0; c.south = 3; c.east = 4; c.west = 5;
    c.type = "Ataque";
    c.coins = +1;
    c.endvalor = 2;
    c.attribute = "Triangulo Rojo";
    c.effect = "Inflige -2 al lado más alto de una ficha enemiga adyacente.";
    piratas.push_back(c);

    // PIRATA 12 – BUCANERO
    c.id = 11;
    c.name = "BUCANERO";
    c.north = 3; c.south = 3; c.east = 3; c.west = 3;
    c.type = "Ataque";
    c.coins = +1;
    c.endvalor = 2;
    c.attribute = "Triangulo Rojo";
    c.effect = "Si se coloca en casilla neutral obtiene +2 arriba y abajo.";
    piratas.push_back(c);

    // PIRATA 13 – BUCANERO
    c.id = 12;
    c.name = "BUCANERO";
    c.north = 3; c.south = 3; c.east = 3; c.west = 3;
    c.type = "Ataque";
    c.coins = +1;
    c.endvalor = 2;
    c.attribute = "Triangulo Rojo";
    c.effect = "Si se coloca en casilla neutral obtiene +2 arriba y abajo.";
    piratas.push_back(c);

    // PIRATA 14 – CONTRAMAESTRE
    c.id = 13;
    c.name = "CONTRAMAESTRE";
    c.north = 4; c.south = 2; c.east = 4; c.west = 2;
    c.type = "Ataque";
    c.coins = +2;
    c.endvalor = 2;
    c.attribute = "Triangulo Rojo";
    c.effect = "Las fichas piratas adyacentes ganan +2 por un turno.";
    piratas.push_back(c);

    // PIRATA 15 – CONTRAMAESTRE
    c.id = 14;
    c.name = "CONTRAMAESTRE";
    c.north = 2; c.south = 4; c.east = 2; c.west = 4;
    c.type = "Ataque";
    c.coins = +2;
    c.endvalor = 2;
    c.attribute = "Triangulo Rojo";
    c.effect = "Las fichas piratas adyacentes ganan +2 por un turno.";
    piratas.push_back(c);

    // PIRATA 16 – BRUTO DEL MAR
    c.id = 15;
    c.name = "BRUTO DEL MAR";
    c.north = 6; c.south = 1; c.east = 3; c.west = 2;
    c.type = "Ataque";
    c.coins = +3;
    c.endvalor = 3;
    c.attribute = "Estrella Amarilla";
    c.effect = "Si convierte una ficha enemiga, puede moverla y atacar de nuevo.";
    piratas.push_back(c);

    // PIRATA 17 – SABIO PIRATA
    c.id = 16;
    c.name = "SABIO PIRATA";
    c.north = 1; c.south = 1; c.east = 5; c.west = 5;
    c.type = "Apoyo";
    c.coins = +1;
    c.endvalor = 3;
    c.attribute = "Estrella Amarilla";
    c.effect = "Puedes vender una ficha de tu mano para ganar +3 monedas.";
    piratas.push_back(c);

    // PIRATA 18 – CAPITAN FEROZ
    c.id = 17;
    c.name = "CAPITAN FEROZ";
    c.north = 2; c.south = 5; c.east = 1; c.west = 4;
    c.type = "Ataque";
    c.coins = +3;
    c.endvalor = 3;
    c.attribute = "Estrella Amarilla";
    c.effect = "Al convertir una ficha convierte también la siguiente.";
    piratas.push_back(c);

    // PIRATA 19 – COMPAÑERO LEAL
    c.id = 18;
    c.name = "COMPAÑERO LEAL";
    c.north = 2; c.south = 3; c.east = 6; c.west = 2;
    c.type = "Apoyo";
    c.coins = +3;
    c.endvalor = 3;
    c.attribute = "Estrella Amarilla";
    c.effect = "Puedes pagar su habilidad para reemplazar una ficha aliada por esta.";
    piratas.push_back(c);

}

// Acceso rápido a las cartas por ID

CardData& CardManager::getNinja(int id) {
    return ninjas[id];
}

CardData& CardManager::getPirata(int id) {
    return piratas[id];
}
