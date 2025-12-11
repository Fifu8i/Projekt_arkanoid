#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class Brick {
private:
    sf::RectangleShape shape;
    int hp;
    bool zniszczona;
    static const std::array<sf::Color, 4> colorLUT;

public:
    Brick(sf::Vector2f pos, sf::Vector2f size, int hits);

    void hit();
    bool destroyed() const;
    void draw(sf::RenderTarget& target) const;

    sf::RectangleShape& getShape() { return shape; }
    const sf::RectangleShape& getShape() const { return shape; }
    int getHP() const { return hp; }
};