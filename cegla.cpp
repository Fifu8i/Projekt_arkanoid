#include "cegla.h"

const std::array<sf::Color, 4> Brick::colorLUT = {
    sf::Color::Transparent,
    sf::Color::Red,
    sf::Color::Yellow,
    sf::Color::Blue
};

Brick::Brick(sf::Vector2f pos, sf::Vector2f size, int hits)
    : hp(hits), zniszczona(false)
{
    shape.setPosition(pos);
    shape.setSize(size);
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(sf::Color::Black);

    if (hp >= 0 && hp < static_cast<int>(colorLUT.size()))
        shape.setFillColor(colorLUT[hp]);
}

void Brick::hit() {
    if (zniszczona) return;

    hp--;
    if (hp <= 0) {
        hp = 0;
        zniszczona = true;
    }

    if (hp >= 0 && hp < static_cast<int>(colorLUT.size()))
        shape.setFillColor(colorLUT[hp]);
}

bool Brick::destroyed() const {
    return zniszczona;
}

void Brick::draw(sf::RenderTarget& target) const {
    if (!zniszczona)
        target.draw(shape);
}