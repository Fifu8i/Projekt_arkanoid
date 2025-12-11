#include "pilka.h"

Pilka::Pilka(float x, float y, float vx, float vy, float r)
    : velocity(vx, vy), radius(r)
{
    shape.setRadius(r);
    shape.setOrigin(r, r);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
}

void Pilka::move() {
    shape.move(velocity);
}

void Pilka::draw(sf::RenderWindow& win) {
    win.draw(shape);
}

float Pilka::left() const { return shape.getPosition().x - radius; }
float Pilka::right() const { return shape.getPosition().x + radius; }
float Pilka::top() const { return shape.getPosition().y - radius; }
float Pilka::bottom() const { return shape.getPosition().y + radius; }

void Pilka::bounceX() { velocity.x = -velocity.x; }
void Pilka::bounceY() { velocity.y = -velocity.y; }

bool Pilka::collidePaddle(const sf::RectangleShape& pad) {
    if (shape.getGlobalBounds().intersects(pad.getGlobalBounds())) {
        bounceY();
        return true;
    }
    return false;
}

bool Pilka::collideBrick(const sf::RectangleShape& brick) {
    if (shape.getGlobalBounds().intersects(brick.getGlobalBounds())) {
        bounceY();
        return true;
    }
    return false;
}

void Pilka::reset(const sf::Vector2f& pos, const sf::Vector2f& vel) {
    shape.setPosition(pos);
    velocity = vel;
}