#include "Game.h"

Game::Game(float windowWidth)
    : m_paletka(windowWidth / 2.f, 550.f, 120.f, 20.f, 8),
    m_pilka(400.f, 300.f, 4.f, -4.f, 10.f)
{
    ROZMIAR_BLOKU_X = (windowWidth - (ILOSC_KOLUMN - 1) * PRZERWA) / ILOSC_KOLUMN;

    for (int y = 0; y < ILOSC_WIERSZY; y++) {
        for (int x = 0; x < ILOSC_KOLUMN; x++) {
            float posX = x * (ROZMIAR_BLOKU_X + PRZERWA);
            float posY = OFFSET_Y + y * (ROZMIAR_BLOKU_Y + PRZERWA);

            int L = 3;

            m_bloki.emplace_back(sf::Vector2f(posX, posY),
                sf::Vector2f(ROZMIAR_BLOKU_X, ROZMIAR_BLOKU_Y),
                L);
        }
    }
}

void Game::update(sf::Time dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        m_paletka.moveLeft();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        m_paletka.moveRight();
    m_paletka.clampToBounds(800.f);

    m_pilka.move();

    if (m_pilka.left() < 0 || m_pilka.right() > 800.f)
        m_pilka.bounceX();
    if (m_pilka.top() < 0)
        m_pilka.bounceY();

    m_pilka.collidePaddle(m_paletka.getShape());

    for (auto& b : m_bloki) {
        if (!b.destroyed() && m_pilka.collideBrick(b.getShape()))
            b.hit();
    }
}

void Game::render(sf::RenderTarget& target)
{
    m_paletka.draw(static_cast<sf::RenderWindow&>(target));
    m_pilka.draw(static_cast<sf::RenderWindow&>(target));
    for (auto& b : m_bloki)
        b.draw(target);
}
