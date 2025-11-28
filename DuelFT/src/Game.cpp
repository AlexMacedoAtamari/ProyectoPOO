#include "Game.hpp"
#include "Board.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace sf;

Game::Game() {
    srand(time(NULL)); // Inicia el reloj para las cartas aleatorias
    turno = 1; // Empieza el jugador 1
    init();
}

Board& Game::getBoard() {
    return board;
}

int Game::getTurno() const {
    return turno;
}

void Game::cambiarTurno() {
    if (turno == 1) {
        turno = 2;
    } else {
        turno = 1;
    }
}


// Definimos qué hará inicializar
void Game::init(){
    // Creamos la ventana resolución Full HD
    window.create(VideoMode(1920,1080),"Duel FT");
    window.setFramerateLimit(60);

    // Llamamos a load para cargar recursos
    load();
}

// Definimos qué hara load
void Game::load(){
    // Llamamos estos métodos para cargar las cartas
    loadNinjas();
    loadPiratas();
    loadFondo();
}

void Game::loadNinjas(){
    // Ancho y alto para escalar las cartas
    float w = 0.2f;
    float h = 0.2f;

    int colum = 3;         // Columna de cartas
    int spaceX = 160;      // Separación horizontal
    int spaceY = 160;      // Separación vertical

    // Posición de la primera carta
    float startX = 1350.0f;
    float startY = 100.0f;

    int ninjas_all = 19;

    // Reserva de memoria
    ninjasTextures.reserve(ninjas_all);
    ninjasSprites.reserve(ninjas_all);

    // Bucle para cargar texturas
    for (int i = 0; i < ninjas_all; i++) {

        // Se coloca el texto de tal manera que solo un número varía
        string filename = "imagenes/Ninjas/" + to_string(i+1) + ".png";
        // Cargamos las texturas (debido a que los nombres están enumerados)
        n.textNinjas.loadFromFile(filename);
        // Guardamos la textura en un vetor definido
        ninjasTextures.push_back(n.textNinjas);

        // Creamos los sprites en función de las texturas
        n.spNinjas.setTexture(ninjasTextures[i]);
        // Escalamos los sprite para conveniencia del tablero
        n.spNinjas.setScale(w, h);

        // Guardamos sprite en un vector definido
        ninjasSprites.push_back(n.spNinjas);
    }
    // Para hacer aleatorio las cartas mostradas
    random_shuffle(ninjasSprites.begin(), ninjasSprites.end());
    for (int i = 0; i < ninjasSprites.size(); i++) {
        // Calculamos fila y columna
        int fila = i / colum;
        int col = i % colum;
        // Asignamos posición de la carta inicial
        ninjasSprites[i].setPosition(startX + col * spaceX, startY + fila * spaceY);
    }
}

void Game::loadPiratas(){

    // Ancho y alto para escalar las cartas
    float w = 0.2f;
    float h = 0.2f;

    int colum = 3;         // Columna de cartas
    int spaceX = 160;      // Separación horizontal
    int spaceY = 160;      // Separación vertical

    // Posición de la primera carta
    float startX = 1350.0f;
    float startY = 580.0f;

    int piratas_all = 19;

    // Reserva de memoria
    piratasTextures.reserve(piratas_all);
    piratasSprites.reserve(piratas_all);

    // Bucle para cargar texturas
    for (int i = 0; i < piratas_all; i++) {

        // Se coloca el texto de tal manera que solo un número varía
        string filename = "imagenes/Piratas/" + to_string(i+1) + ".png";
        // Cargamos las texturas (debido a que los nombres están enumerados)
        p.textPiratas.loadFromFile(filename);
        // Guardamos la textura en un vetor definido
        piratasTextures.push_back(p.textPiratas);

        // Creamos los sprites en función de las texturas
        p.spPiratas.setTexture(piratasTextures[i]);
        // Escalamos los sprite para conveniencia del tablero
        p.spPiratas.setScale(w, h);

        // Guardamos sprite en un vector definido
        piratasSprites.push_back(p.spPiratas);
    }
    // Para hacer aleatorio las cartas mostradas
    random_shuffle(piratasSprites.begin(), piratasSprites.end());
    for (int i = 0; i < piratasSprites.size(); i++) {
        // Calculamos fila y columna
        int fila = i / colum;
        int col = i % colum;
        // Asignamos posición de la carta inicial
        piratasSprites[i].setPosition(startX + col * spaceX, startY + fila * spaceY);
    }
}

void Game::loadFondo(){
    // Carga de textura para el sprite del fondo (Ninja)
    textFonNin.loadFromFile("imagenes/Fondos/FondNinja.jpg");
    //textFonNin.setSmooth(true);
    spFondNin.setTexture(textFonNin);
    spFondNin.setTextureRect(IntRect(0,340,1920,1080));
    //spFondNin.setScale(2.7f,2.7f);
    spFondNin.setPosition(0,0);

    // Carga de textura para el sprite del fondo (Pirata)
    textFonPir.loadFromFile("imagenes/Fondos/FondPirata.jpg");
    //textFonNin.setSmooth(true);
    spFondPir.setTexture(textFonPir);
    spFondPir.setTextureRect(IntRect(0,700,1920,1080));
    //spFondPir.setScale(2.7f,2.7f);
    spFondPir.setPosition(0,492);
}

void Game::run(){

    while (window.isOpen())
    {
        handlePlayerInput();
        draw();
        update();
    }
}

// Variables globales
const int OFFSET_X = 280;
const int OFFSET_Y = 25;
const int CELL_WIDTH = 156;
const int CELL_HEIGHT = 156;

const int PANEL_RIGHT_X = 1216;
const int PANEL_RIGHT_WIDTH = 704;

const int PANEL_SUPERIOR_HEIGHT = 200;
const int PANEL_INFERIOR_HEIGHT = 880;

void Game::handlePlayerInput(){
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();

        if (event.type == Event::MouseButtonPressed &&
            event.mouseButton.button == Mouse::Left)
        {
            int mouseX = event.mouseButton.x;
            int mouseY = event.mouseButton.y;

            // validar clic dentro del tablero
            if (mouseX >= OFFSET_X && mouseX < OFFSET_X + 6*CELL_WIDTH &&
                mouseY >= OFFSET_Y && mouseY < OFFSET_Y + 6*CELL_HEIGHT)
            {
                int col = (mouseX - OFFSET_X) / CELL_WIDTH;
                int row = (mouseY - OFFSET_Y) / CELL_HEIGHT;
                if (col >= 0 && col < 6 && row >= 0 && row < 6)
                {
                    // colocar carta usando tus funciones reales
                    bool colocado = getBoard().colocarCarta(
                        row,
                        col,
                        1,                // id carta dummy
                        getTurno()   // jugador actual
                    );

                    if (colocado)
                    {
                        cout << "Colocada en (" << row << ", " << col
                                  << ") por jugador " << getTurno() << "\n";

                        cambiarTurno();
                    }
                }
            }
        }
    }
}

void Game::draw(){

    // Definiendo colores
    Color backgroundColor(26, 26, 29);
    Color panelSuperiorColor(32, 32, 36);
    Color panelInferiorColor(20, 20, 22);
    Color borderColor(78, 204, 163);
    Color cellColor1(200, 230, 220, 240);
    Color cellColor2(180, 220, 210, 240);
    Color gridLineColor(60, 60, 60);
    Color player1Color(100, 150, 255);
    Color player2Color(255, 100, 100);

    window.clear(backgroundColor);

    // Dibujando el fondo
    window.draw(spFondNin);
    window.draw(spFondPir);

    // ESPACIO IZQUIERDO
    RectangleShape leftSpace(Vector2f(280, 1080));
    leftSpace.setPosition(0, 0);
    leftSpace.setFillColor(backgroundColor);
    //window.draw(leftSpace);

    // TABLERO
    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col < 6; ++col)
        {
            RectangleShape cell(Vector2f(CELL_WIDTH, CELL_HEIGHT));
            cell.setPosition(OFFSET_X + col * CELL_WIDTH, OFFSET_Y + row * CELL_HEIGHT);

            if ((row + col) % 2 == 0)
                cell.setFillColor(cellColor1);
            else
                cell.setFillColor(cellColor2);

            cell.setOutlineColor(gridLineColor);
            cell.setOutlineThickness(1.f);
            window.draw(cell);

            // obtener celda real (tus clases)
            Cell currentCell = getBoard().getCell(row, col);

            if (currentCell.ocupada)
            {
                CircleShape token(50.f);
                token.setPosition(
                    OFFSET_X + col * CELL_WIDTH + 20,
                    OFFSET_Y + row * CELL_HEIGHT + 40
                );

                if (currentCell.jugador == 1)
                    token.setFillColor(player1Color);
                else
                    token.setFillColor(player2Color);

                window.draw(token);
            }
        }
    }

    // PANEL SUPERIOR (Derecha)
    RectangleShape panelSuperior(Vector2f(PANEL_RIGHT_WIDTH, PANEL_SUPERIOR_HEIGHT));
    panelSuperior.setPosition(PANEL_RIGHT_X, 0);
    panelSuperior.setFillColor(panelSuperiorColor);
    //window.draw(panelSuperior);

    RectangleShape borderSuperior(Vector2f(PANEL_RIGHT_WIDTH, 3));
    borderSuperior.setPosition(PANEL_RIGHT_X, PANEL_SUPERIOR_HEIGHT);
    borderSuperior.setFillColor(borderColor);
    //window.draw(borderSuperior);

    // PANEL INFERIOR (Derecha)
    RectangleShape panelInferior(Vector2f(PANEL_RIGHT_WIDTH, PANEL_INFERIOR_HEIGHT));
    panelInferior.setPosition(PANEL_RIGHT_X, PANEL_SUPERIOR_HEIGHT);
    panelInferior.setFillColor(panelInferiorColor);
    //window.draw(panelInferior);

    // Dibuja una cantidad específica de cartas (Ninjas)
    int cantidadNinjas = 6;
    for (int i = 0; i < cantidadNinjas && i < ninjasSprites.size(); i++) {
        window.draw(ninjasSprites[i]);
    }

    // Dibuja una cantidad específica de cartas (Piratas)
    int cantidadPiratas = 6;
    for (int i = 0; i < cantidadPiratas && i < piratasSprites.size(); i++) {
        window.draw(piratasSprites[i]);
    }

}

void Game::update(){
    // Actualiza la ventana
    window.display();
}
