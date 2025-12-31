#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

/// Estudiantes:     Macedo Atamari Alex Darwin
///                  Palacios Hurtado Royer Johan

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
    window.create(VideoMode(1920,1080),"Duel FT",Style::Fullscreen);
    window.setFramerateLimit(60);

    // Llamamos a load para cargar recursos
    load();

    // Ver resultados
    mostrarOverlayFinal = true;
}

// Definimos qué hara load
void Game::load(){
    // Llamamos estos métodos para cargar las cartas
    loadNinjas();
    loadPiratas();
    loadFondo();
    loadFuente();
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

    ordenNinjas.clear();
    for (int i = 0; i < ninjas_all; i++)
        ordenNinjas.push_back(i);

    // random_shuffle(ninjasSprites.begin(), ninjasSprites.end());
    random_shuffle(ordenNinjas.begin(), ordenNinjas.end());
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

    ordenPiratas.clear();
    for (int i = 0; i < piratas_all; i++)
        ordenPiratas.push_back(i);

    // Para hacer aleatorio las cartas mostradas
    random_shuffle(ordenPiratas.begin(), ordenPiratas.end());
}

void Game::loadFondo(){
    // Carga de textura para el sprite del fondo (Ninja)
    textFonNin.loadFromFile("imagenes/Fondos/FondNinja.jpg");
    spFondNin.setTexture(textFonNin);
    spFondNin.setTextureRect(IntRect(0,340,1920,1080));
    spFondNin.setPosition(0,0);

    // Carga de textura para el sprite del fondo (Pirata)
    textFonPir.loadFromFile("imagenes/Fondos/FondPirata.jpg");
    spFondPir.setTexture(textFonPir);
    spFondPir.setTextureRect(IntRect(0,700,1920,1080));
    spFondPir.setPosition(0,492);
}

void Game::loadFuente(){
    fuente.loadFromFile("fuentes/arial.ttf");

    // Texto para el player
    textoJugador.setFont(fuente);
    textoJugador.setCharacterSize(20);
    textoJugador.setStyle(Text::Bold);

    // BOTÓN "VER RESULTADOS"
    botonResultados.setSize(Vector2f(260, 60));
    botonResultados.setFillColor(Color(50, 50, 50, 220));
    botonResultados.setOutlineThickness(2);
    botonResultados.setOutlineColor(Color::White);
    botonResultados.setPosition(830, 580);

    textoBotonResultados.setFont(fuente);
    textoBotonResultados.setString("VER RESULTADOS");
    textoBotonResultados.setCharacterSize(24);
    textoBotonResultados.setStyle(Text::Bold);
    textoBotonResultados.setFillColor(Color::White);

    FloatRect tb = textoBotonResultados.getLocalBounds();
    textoBotonResultados.setOrigin(tb.width / 2, tb.height / 2);
    textoBotonResultados.setPosition(
        botonResultados.getPosition().x + botonResultados.getSize().x / 2,
        botonResultados.getPosition().y + botonResultados.getSize().y / 2
    );

    // BOTÓN "VOLVER A LA PANTALLA FINAL"
    botonVolverFinal.setSize(Vector2f(300, 45));
    botonVolverFinal.setFillColor(Color(30, 30, 30, 220));
    botonVolverFinal.setOutlineThickness(2);
    botonVolverFinal.setOutlineColor(Color::White);
    botonVolverFinal.setPosition(1600, 20);

    textoBotonVolverFinal.setFont(fuente);
    textoBotonVolverFinal.setString("VOLVER A LA PANTALLA FINAL");
    textoBotonVolverFinal.setCharacterSize(18);
    textoBotonVolverFinal.setStyle(Text::Bold);
    textoBotonVolverFinal.setFillColor(Color::White);

    FloatRect tb1 = textoBotonVolverFinal.getLocalBounds();
    textoBotonVolverFinal.setOrigin(tb.width / 2, tb.height / 2);
    textoBotonVolverFinal.setPosition(
        botonVolverFinal.getPosition().x + botonVolverFinal.getSize().x / 2 - 25,
        botonVolverFinal.getPosition().y + botonVolverFinal.getSize().y / 2
    );

    // BOTÓN "NUEVA PARTIDA"
    botonNuevaPartida.setSize(Vector2f(300, 45));
    botonNuevaPartida.setFillColor(Color(20, 100, 20, 220));
    botonNuevaPartida.setOutlineThickness(2);
    botonNuevaPartida.setOutlineColor(Color::White);
    botonNuevaPartida.setPosition(1600, 80);

    textoBotonNuevaPartida.setFont(fuente);
    textoBotonNuevaPartida.setString("NUEVA PARTIDA");
    textoBotonNuevaPartida.setCharacterSize(18);
    textoBotonNuevaPartida.setStyle(Text::Bold);
    textoBotonNuevaPartida.setFillColor(Color::White);

    FloatRect nb = textoBotonNuevaPartida.getLocalBounds();
    textoBotonNuevaPartida.setOrigin(nb.width / 2, nb.height / 2);
    textoBotonNuevaPartida.setPosition(
        botonNuevaPartida.getPosition().x + botonNuevaPartida.getSize().x / 2,
        botonNuevaPartida.getPosition().y + botonNuevaPartida.getSize().y / 2
    );

    // BOTÓN "SALIR DEL JUEGO"
    botonSalir.setSize(Vector2f(300, 45));
    botonSalir.setFillColor(Color(120, 20, 20, 220));
    botonSalir.setOutlineThickness(2);
    botonSalir.setOutlineColor(Color::White);
    botonSalir.setPosition(1600, 140);

    textoBotonSalir.setFont(fuente);
    textoBotonSalir.setString("SALIR DEL JUEGO");
    textoBotonSalir.setCharacterSize(18);
    textoBotonSalir.setStyle(Text::Bold);
    textoBotonSalir.setFillColor(Color::White);

    FloatRect sb = textoBotonSalir.getLocalBounds();
    textoBotonSalir.setOrigin(sb.width / 2, sb.height / 2);
    textoBotonSalir.setPosition(
        botonSalir.getPosition().x + botonSalir.getSize().x / 2,
        botonSalir.getPosition().y + botonSalir.getSize().y / 2
    );


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
                    int id;

                    if (getTurno() == 1)
                        id = ordenNinjas[cartaActualJugador1];
                    else
                        id = ordenPiratas[cartaActualJugador2];


                    int tipo = (getTurno() == 1) ? 1 : 2; // 1 = Ninja, 2 = Pirata

                    // colocar carta usando tus funciones reales
                    bool colocado = getBoard().colocarCarta(
                        row,
                        col,
                        id,                // id carta dummy
                        getTurno(),   // jugador actual
                        tipo
                    );

                    if (colocado)
                    {
                        convertirCartasAdyacentes(row, col);

                        cout << "Colocada en (" << row << ", " << col
                            << ") por jugador " << getTurno() << "\n";

                        if (getTurno() == 1) {
                            cartaActualJugador1++;
                            indiceInicioNinjas++;
                        }
                        else {
                            cartaActualJugador2++;
                            indiceInicioPiratas++;
                        }

                        cambiarTurno();
                    }
                }
            }

            if (finPartida && mostrarOverlayFinal)
            {
                Vector2f mouse(event.mouseButton.x, event.mouseButton.y);

                if (botonResultados.getGlobalBounds().contains(mouse))
                {
                    mostrarOverlayFinal = false;
                    return; // Evita que el click haga otra cosa
                }
            }
            // BOTÓN "VOLVER A LA PANTALLA FINAL"
            if (finPartida && !mostrarOverlayFinal)
            {
                Vector2f mouse(event.mouseButton.x, event.mouseButton.y);

                if (botonVolverFinal.getGlobalBounds().contains(mouse))
                {
                    mostrarOverlayFinal = true;
                    return;
                }

                if (botonNuevaPartida.getGlobalBounds().contains(mouse))
                {
                    reiniciarJuego();
                    return;
                }

                if (botonSalir.getGlobalBounds().contains(mouse))
                {
                    window.close();
                    return;
                }
            }

        }
        if (event.type == Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Escape)
        {
            window.close();
        }

    }
}

vector<Pos> Game::detectarVecinosOrtogonales(int fila, int columna)
{
    vector<Pos> vecinos;

    // ARRIBA (N)
    if (fila > 0 && board.estaOcupada(fila - 1, columna))
    {
        vecinos.emplace_back(fila - 1, columna);
    }

    // ABAJO (S)
    if (fila < Board::FILAS - 1 && board.estaOcupada(fila + 1, columna))
    {
        vecinos.emplace_back(fila + 1, columna);
    }

    // IZQUIERDA (W)
    if (columna > 0 && board.estaOcupada(fila, columna - 1))
    {
        vecinos.emplace_back(fila, columna - 1);
    }

    // DERECHA (E)
    if (columna < Board::COLUMNAS - 1 && board.estaOcupada(fila, columna + 1))
    {
        vecinos.emplace_back(fila, columna + 1);
    }

    return vecinos;
}

bool Game::compararAtributos(
    int filaCentral,
    int columnaCentral,
    int filaVecino,
    int columnaVecino
)
{
    Cell central = board.getCell(filaCentral, columnaCentral);
    Cell vecino  = board.getCell(filaVecino, columnaVecino);

    // Si son del mismo jugador, no hay comparación
    if (central.jugador == vecino.jugador)
        return false;

    CardData& cartaCentral = getCardDataPorTipo(central.tipoCarta, central.idCarta);
    CardData& cartaVecina  = getCardDataPorTipo(vecino.tipoCarta, vecino.idCarta);

    // Vecino ARRIBA
    if (filaVecino == filaCentral - 1 && columnaVecino == columnaCentral)
        return cartaCentral.north >= cartaVecina.south;

    // Vecino ABAJO
    if (filaVecino == filaCentral + 1 && columnaVecino == columnaCentral)
        return cartaCentral.south >= cartaVecina.north;

    // Vecino IZQUIERDA
    if (filaVecino == filaCentral && columnaVecino == columnaCentral - 1)
        return cartaCentral.west >= cartaVecina.east;

    // Vecino DERECHA
    if (filaVecino == filaCentral && columnaVecino == columnaCentral + 1)
        return cartaCentral.east >= cartaVecina.west;

    return false;
}

void Game::convertirCartasAdyacentes(int fila, int columna)
{
    vector<Pos> vecinos = detectarVecinosOrtogonales(fila, columna);
    vector<Pos> aConvertir;

    Cell cartaCentral = board.getCell(fila, columna);

    for (auto& v : vecinos)
    {
        Cell cartaVecina = board.getCell(v.fila, v.columna);

        // Seguridad extra
        if (!cartaVecina.ocupada)
            continue;

        // No convertir cartas propias
        if (cartaVecina.jugador == cartaCentral.jugador)
            continue;

        // Comparación de atributos (PUNTO 3)
        if (compararAtributos(fila, columna, v.fila, v.columna))
        {
            aConvertir.push_back(v);
        }
    }

    // CONVERSIÓN SIMULTÁNEA
    for (auto& pos : aConvertir)
    {
        board.cambiarJugador(
            pos.fila,
            pos.columna,
            cartaCentral.jugador
        );
    }
}

CardData& Game::getCardDataPorTipo(int tipoCarta, int idCarta)
{
    if (tipoCarta == 1)      // Ninja
        return cardManager.getNinja(idCarta);
    else                     // Pirata
        return cardManager.getPirata(idCarta);
}

bool Game::tableroLleno() {
    return board.estaLleno();
}

int Game::calcularPuntajeJugador(int jugador) {
    int total = 0;

    for (int f = 0; f < Board::FILAS; ++f) {
        for (int c = 0; c < Board::COLUMNAS; ++c) {

            Cell cell = board.getCell(f, c);

            if (!cell.ocupada)
                continue;

            if (cell.jugador != jugador)
                continue;

            CardData& carta =
                getCardDataPorTipo(cell.tipoCarta, cell.idCarta);

            total += carta.endvalor;
        }
    }

    return total;
}

void Game::reiniciarJuego()
{
    board.reset();              // Vaciar tablero
    turno = 1;

    cartaActualJugador1 = 0;
    cartaActualJugador2 = 0;
    indiceInicioNinjas = 0;
    indiceInicioPiratas = 0;

    puntajeP1 = 0;
    puntajeP2 = 0;

    finPartida = false;
    mostrarOverlayFinal = false;

    random_shuffle(ordenNinjas.begin(), ordenNinjas.end());
    random_shuffle(ordenPiratas.begin(), ordenPiratas.end());

    cout << "Nueva partida iniciada\n";
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

            // Obtener celda real (tus clases)
            Cell currentCell = getBoard().getCell(row, col);

            if (currentCell.ocupada)
            {
                Sprite* sprite = nullptr;

                // Elegir sprite por TIPO DE CARTA (NO por jugador)
                if (currentCell.tipoCarta == 1) // Ninja
                    sprite = &ninjasSprites[currentCell.idCarta];
                else if (currentCell.tipoCarta == 2) // Pirata
                    sprite = &piratasSprites[currentCell.idCarta];

                // Posicionar carta
                sprite->setPosition(
                    OFFSET_X + col * CELL_WIDTH,
                    OFFSET_Y + row * CELL_HEIGHT
                );

                window.draw(*sprite);

                // Texto del jugador
                if (currentCell.jugador == 1)
                {
                    textoJugador.setString("P1");
                    textoJugador.setFillColor(Color::Blue);
                }
                else if (currentCell.jugador == 2)
                {
                    textoJugador.setString("P2");
                    textoJugador.setFillColor(Color::Red);
                }

                FloatRect bounds = textoJugador.getLocalBounds();
                textoJugador.setOrigin(bounds.width / 2, 0);

                // Posición del texto
                Vector2f posTexto(
                    OFFSET_X + col * CELL_WIDTH + CELL_WIDTH - 20,
                    OFFSET_Y + row * CELL_HEIGHT + 4
                );

                textoJugador.setPosition(posTexto);

                // FONDO OSCURO TRANSPARENTE
                RectangleShape fondoJugador;
                fondoJugador.setSize(Vector2f(
                    bounds.width + 12,
                    bounds.height + 8
                ));

                fondoJugador.setOrigin(
                    fondoJugador.getSize().x / 2,
                    0
                );

                fondoJugador.setPosition(
                    posTexto.x,
                    posTexto.y
                );

                fondoJugador.setFillColor(Color(0, 0, 0, 150)); // Negro semi-transparente

                // DIBUJO (orden importante)
                window.draw(fondoJugador);
                window.draw(textoJugador);


                if (finPartida && currentCell.ocupada) {

                    CardData& carta =
                        getCardDataPorTipo(currentCell.tipoCarta, currentCell.idCarta);

                    Text textoValor;
                    textoValor.setFont(fuente);
                    textoValor.setCharacterSize(36);
                    textoValor.setStyle(Text::Bold);

                    if (currentCell.jugador == 1) {
                        textoValor.setString("P1 + " + to_string(carta.endvalor));
                        textoValor.setFillColor(Color(80, 150, 255)); // Azul
                    }
                    else {
                        textoValor.setString("P2 + " + to_string(carta.endvalor));
                        textoValor.setFillColor(Color(255, 100, 100)); // Rojo
                    }

                    FloatRect textBounds = textoValor.getLocalBounds();
                    textoValor.setOrigin(
                        textBounds.left + textBounds.width / 2,
                        textBounds.top  + textBounds.height / 2
                    );

                    Vector2f centroCarta(
                        OFFSET_X + col * CELL_WIDTH + CELL_WIDTH / 2,
                        OFFSET_Y + row * CELL_HEIGHT + CELL_HEIGHT / 2
                    );

                    textoValor.setPosition(centroCarta);

                    // FONDO OSCURO TRANSPARENTE
                    RectangleShape fondoTexto;
                    fondoTexto.setSize(Vector2f(
                        textBounds.width  + 20,
                        textBounds.height + 16
                    ));

                    fondoTexto.setOrigin(
                        fondoTexto.getSize().x / 2,
                        fondoTexto.getSize().y / 2
                    );

                    fondoTexto.setPosition(centroCarta);
                    fondoTexto.setFillColor(Color(0, 0, 0, 160)); // Negro semi-transparente

                    // DIBUJO (orden IMPORTANTE)
                    window.draw(fondoTexto);
                    window.draw(textoValor);
                }
            }

        }
    }

    // Dibujando cartas del mazo disponible
    int cantidadNinjas = 6;
    int colum = 3;
    int spaceX = 160;
    int spaceY = 160;
    float startX = 1350.0f;
    float startY = 100.0f;

    for (int i = 0; i < cantidadNinjas && (indiceInicioNinjas + i) < ninjasSprites.size(); i++) {
        int fila = i / colum;
        int col = i % colum;

        int idReal = ordenNinjas[indiceInicioNinjas + i];

        ninjasSprites[idReal].setPosition(
            startX + col * spaceX,
            startY + fila * spaceY
        );

        window.draw(ninjasSprites[idReal]);

    }

    // Dibujando frase "Proximo Ninja"
    if (getTurno() == 1 && indiceInicioNinjas < ninjasSprites.size()) {
        Text textoProximaNinja;
        textoProximaNinja.setFont(fuente);
        textoProximaNinja.setString("PROXIMO NINJA");
        textoProximaNinja.setCharacterSize(20);
        textoProximaNinja.setFillColor(Color::Blue);
        textoProximaNinja.setStyle(Text::Bold);

        // Posición simple: justo arriba de donde empieza el grid
        textoProximaNinja.setPosition(startX, startY - 40);

        window.draw(textoProximaNinja);
    }

    // Dibujando cartas del mazo disponible
    int cantidadPiratas = 6;
    float startXPir = 1350.0f;
    float startYPir = 580.0f;

    for (int i = 0; i < cantidadPiratas && (indiceInicioPiratas + i) < piratasSprites.size(); i++) {
        int fila = i / colum;
        int col = i % colum;

        int idReal = ordenPiratas[indiceInicioPiratas + i];

        piratasSprites[idReal].setPosition(
            startXPir + col * spaceX,
            startYPir + fila * spaceY
        );

        window.draw(piratasSprites[idReal]);

    }


    // Dibujando frase "Proximo Pirata"
    if (getTurno() == 2 && indiceInicioPiratas < piratasSprites.size()) {
        Text textoProximaPirata;
        textoProximaPirata.setFont(fuente);
        textoProximaPirata.setString("PROXIMO PIRATA");
        textoProximaPirata.setCharacterSize(20);
        textoProximaPirata.setFillColor(Color::Red);
        textoProximaPirata.setStyle(Text::Bold);

        textoProximaPirata.setPosition(startXPir, startYPir - 40);

        window.draw(textoProximaPirata);
    }

    if (finPartida && mostrarOverlayFinal) {

        // OVERLAY OSCURO
        RectangleShape overlay;
        overlay.setSize(Vector2f(1920, 1080));
        overlay.setFillColor(Color(0, 0, 0, 180)); // Negro transparente
        window.draw(overlay);

        string titulo;

        if (puntajeP1 > puntajeP2)
            titulo = "¡GANA EL JUGADOR 1!";
        else if (puntajeP2 > puntajeP1)
            titulo = "¡GANA EL JUGADOR 2!";
        else
            titulo = "¡EMPATE!";

        Text textoVictoria;
        textoVictoria.setFont(fuente);
        textoVictoria.setCharacterSize(60);
        textoVictoria.setStyle(Text::Bold);
        textoVictoria.setString(titulo);
        textoVictoria.setFillColor(Color::White);

        FloatRect b = textoVictoria.getLocalBounds();
        textoVictoria.setOrigin(b.width / 2, b.height / 2);
        textoVictoria.setPosition(960, 360);

        window.draw(textoVictoria);

        Text textoPuntajes;
        textoPuntajes.setFont(fuente);
        textoPuntajes.setCharacterSize(32);
        textoPuntajes.setStyle(Text::Bold);
        textoPuntajes.setFillColor(Color::White);

        textoPuntajes.setString(
            "P1: " + to_string(puntajeP1) +
            "     |     P2: " + to_string(puntajeP2)
        );

        FloatRect b2 = textoPuntajes.getLocalBounds();
        textoPuntajes.setOrigin(b2.width / 2, b2.height / 2);
        textoPuntajes.setPosition(960, 450);

        window.draw(textoPuntajes);

        // ===== BOTÓN =====
        window.draw(botonResultados);
        window.draw(textoBotonResultados);
    }

    // BOTÓN "VOLVER A PANTALLA FINAL", "NUEVA PARTIDA" Y "SALIR"
    if (finPartida && !mostrarOverlayFinal)
    {
        window.draw(botonVolverFinal);
        window.draw(textoBotonVolverFinal);

        window.draw(botonNuevaPartida);
        window.draw(textoBotonNuevaPartida);

        window.draw(botonSalir);
        window.draw(textoBotonSalir);
    }


}

void Game::update(){
    // Actualiza la ventana
    if (!finPartida && tableroLleno()) {
        puntajeP1 = calcularPuntajeJugador(1);
        puntajeP2 = calcularPuntajeJugador(2);
        finPartida = true;
    }

    window.display();

}
