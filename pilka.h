#pragma once
#include <SFML/Graphics.hpp>

class Pilka {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float radius;

public:
    Pilka(float x, float y, float vx, float vy, float r);

    void move();
    void draw(sf::RenderWindow& win);

    float left() const;
    float right() const;
    float top() const;
    float bottom() const;

    void bounceX();
    void bounceY();

    bool collidePaddle(const sf::RectangleShape& pad);
    bool collideBrick(const sf::RectangleShape& brick);

    float getX() const { return shape.getPosition().x; }
    float getY() const { return shape.getPosition().y; }
    float getRadius() const { return radius; }
    sf::FloatRect getGlobalBounds() const { return shape.getGlobalBounds(); }

    sf::CircleShape& getShape() { return shape; }
    const sf::CircleShape& getShape() const { return shape; }

    sf::Vector2f getVelocity() const { return velocity; }
    void reset(const sf::Vector2f& pos, const sf::Vector2f& vel);
};