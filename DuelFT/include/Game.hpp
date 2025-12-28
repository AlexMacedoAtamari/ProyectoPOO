#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Card.hpp"
#include "CardManager.hpp"
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

    // Textura de los fondos
    Texture textFonNin;
    Texture textFonPir;

    // Sprite de los fondos
    Sprite spFondNin;
    Sprite spFondPir;

    // Método para cargar los archivos
    void loadNinjas();
    void loadPiratas();
    void loadFondo();
    void loadFuente();

    // Inicio de la carta actual por jugador
    int cartaActualJugador1 = 0;
    int cartaActualJugador2 = 0;

    // Para cartas que ya se usaron
    int indiceInicioNinjas = 0;
    int indiceInicioPiratas = 0;

    Font fuente;

    CardManager cardManager;

    // Comprobar los vecinos
    class Pos {
    public:
        int fila;
        int columna;

        Pos(int f, int c) : fila(f), columna(c) {}
    };
    vector<Pos> detectarVecinosOrtogonales(int fila, int columna);

    /*// Usando getCardData según cada jugador
    CardData& getCardData(int jugador, int idCarta);*/

    // Usando getCardData según cada jugador por tipo
    CardData& getCardDataPorTipo(int tipoCarta, int idCarta);

    // Comparación de los atributos de las cartas
    bool compararAtributos(
        int filaCentral,
        int columnaCentral,
        int filaVecino,
        int columnaVecino
    );

    // Método para convertir cartas
    void convertirCartasAdyacentes(int fila, int columna);

    Text textoJugador;

    vector<int> ordenNinjas;
    vector<int> ordenPiratas;

    int calcularPuntajeJugador(int jugador);

    bool finPartida = false;
    int puntajeP1 = 0;
    int puntajeP2 = 0;

    bool tableroLleno();

    bool mostrarOverlayFinal;
    RectangleShape botonResultados;
    Text textoBotonResultados;

    // Boton para regresar a la pantalla de victoria
    RectangleShape botonVolverFinal;
    Text textoBotonVolverFinal;

    // Boton para crear nueva partida
    RectangleShape botonNuevaPartida;
    Text textoBotonNuevaPartida;

    // Boton para salir del juego
    RectangleShape botonSalir;
    Text textoBotonSalir;

    void reiniciarJuego();


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
