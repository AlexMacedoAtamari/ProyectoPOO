#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Board.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "DuelFT");
    window.setFramerateLimit(60);

    Game game;

    const int OFFSET_X = 280;
    const int OFFSET_Y = 0;
    const int CELL_WIDTH = 140;
    const int CELL_HEIGHT = 180;

    const int PANEL_RIGHT_X = 1120;
    const int PANEL_RIGHT_WIDTH = 800;

    const int PANEL_SUPERIOR_HEIGHT = 200;
    const int PANEL_INFERIOR_HEIGHT = 880;

    sf::Color backgroundColor(26, 26, 29);
    sf::Color panelSuperiorColor(32, 32, 36);
    sf::Color panelInferiorColor(20, 20, 22);
    sf::Color borderColor(78, 204, 163);
    sf::Color cellColor1(200, 230, 220);
    sf::Color cellColor2(180, 220, 210);
    sf::Color gridLineColor(60, 60, 60);
    sf::Color player1Color(100, 150, 255);
    sf::Color player2Color(255, 100, 100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left)
            {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;

                // validar clic dentro del tablero
                if (mouseX >= OFFSET_X && mouseX < OFFSET_X + 840 &&
                    mouseY >= OFFSET_Y && mouseY < OFFSET_Y + 1080)
                {
                    int col = (mouseX - OFFSET_X) / CELL_WIDTH;
                    int row = (mouseY - OFFSET_Y) / CELL_HEIGHT;

                    if (col >= 0 && col < 6 && row >= 0 && row < 6)
                    {
                        // colocar carta usando tus funciones reales
                        bool colocado = game.getBoard().colocarCarta(
                            row,
                            col,
                            1,                // id carta dummy
                            game.getTurno()   // jugador actual
                        );

                        if (colocado)
                        {
                            std::cout << "Colocada en (" << row << ", " << col
                                      << ") por jugador " << game.getTurno() << "\n";

                            game.cambiarTurno();
                        }
                    }
                }
            }
        }

        window.clear(backgroundColor);

        // ESPACIO IZQUIERDO
        sf::RectangleShape leftSpace(sf::Vector2f(280, 1080));
        leftSpace.setPosition(0, 0);
        leftSpace.setFillColor(backgroundColor);
        window.draw(leftSpace);

        // TABLERO
        for (int row = 0; row < 6; ++row)
        {
            for (int col = 0; col < 6; ++col)
            {
                sf::RectangleShape cell(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
                cell.setPosition(OFFSET_X + col * CELL_WIDTH, OFFSET_Y + row * CELL_HEIGHT);

                if ((row + col) % 2 == 0)
                    cell.setFillColor(cellColor1);
                else
                    cell.setFillColor(cellColor2);

                cell.setOutlineColor(gridLineColor);
                cell.setOutlineThickness(1.f);
                window.draw(cell);

                // obtener celda real (tus clases)
                Cell currentCell = game.getBoard().getCell(row, col);

                if (currentCell.ocupada)
                {
                    sf::CircleShape token(50.f);
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

        // PANEL SUPERIOR
        sf::RectangleShape panelSuperior(sf::Vector2f(PANEL_RIGHT_WIDTH, PANEL_SUPERIOR_HEIGHT));
        panelSuperior.setPosition(PANEL_RIGHT_X, 0);
        panelSuperior.setFillColor(panelSuperiorColor);
        window.draw(panelSuperior);

        sf::RectangleShape borderSuperior(sf::Vector2f(PANEL_RIGHT_WIDTH, 3));
        borderSuperior.setPosition(PANEL_RIGHT_X, PANEL_SUPERIOR_HEIGHT);
        borderSuperior.setFillColor(borderColor);
        window.draw(borderSuperior);

        // PANEL INFERIOR
        sf::RectangleShape panelInferior(sf::Vector2f(PANEL_RIGHT_WIDTH, PANEL_INFERIOR_HEIGHT));
        panelInferior.setPosition(PANEL_RIGHT_X, PANEL_SUPERIOR_HEIGHT);
        panelInferior.setFillColor(panelInferiorColor);
        window.draw(panelInferior);

        window.display();
    }

    return 0;
}
