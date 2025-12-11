#include <SFML/Graphics.hpp>
#include "Game.h"

enum class GameState { Menu, Playing, Exiting };

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");
    window.setFramerateLimit(60);

    Game game(window.getSize().x);

    GameState currentState = GameState::Menu;
    int selectedItem = 0;
    sf::Clock deltaClock;

    sf::RectangleShape newGameButton(sf::Vector2f(200, 50));
    newGameButton.setPosition(300, 200);
    sf::RectangleShape exitButton(sf::Vector2f(200, 50));
    exitButton.setPosition(300, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (currentState == GameState::Menu && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
                    selectedItem = 0;
                if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                    selectedItem = 1;
                if (event.key.code == sf::Keyboard::Enter) {
                    if (selectedItem == 0)
                        currentState = GameState::Playing;
                    else if (selectedItem == 1)
                        window.close();
                }
            }

            if (currentState == GameState::Playing && event.type == sf::Event::KeyPressed
                && event.key.code == sf::Keyboard::Escape)
                currentState = GameState::Menu;
        }

        sf::Time dt = deltaClock.restart();
        if (currentState == GameState::Playing)
            game.update(dt);

        window.clear();

        if (currentState == GameState::Menu) {
            newGameButton.setFillColor(selectedItem == 0 ? sf::Color::Yellow : sf::Color::White);
            exitButton.setFillColor(selectedItem == 1 ? sf::Color::Yellow : sf::Color::White);
            window.draw(newGameButton);
            window.draw(exitButton);
        }
        else if (currentState == GameState::Playing)
            game.render(window);

        window.display();
    }
    return 0;
}
