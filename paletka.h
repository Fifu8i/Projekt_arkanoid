#pragma once
#include <SFML/Graphics.hpp>

class Paletka {
private:
    float x, y;
    float szerokosc, wysokosc;
    float predkosc;
    sf::RectangleShape shape;

public:
    Paletka(float x, float y, float szerokosc, float wysokosc, float predkosc);

    void draw(sf::RenderWindow& win);
    void moveLeft();
    void moveRight();
    void clampToBounds(float width);

    sf::RectangleShape& getShape() { return shape; }
    const sf::RectangleShape& getShape() const { return shape; }

    float getX() const;
    float getY() const;
    float getSzerokosc() const;
    float getWysokosc() const;
    void setPosition(const sf::Vector2f& pos);
};