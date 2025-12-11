#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "paletka.h"
#include "pilka.h"
#include "cegla.h"

class Game {
private:
    Paletka m_paletka;
    Pilka m_pilka;
    std::vector<Brick> m_bloki;

    const int ILOSC_KOLUMN = 6;
    const int ILOSC_WIERSZY = 7;
    const float ROZMIAR_BLOKU_Y = 25.f;
    const float PRZERWA = 2.f;
    const float OFFSET_Y = 50.f;

    float ROZMIAR_BLOKU_X;

public:
    Game(float windowWidth); 

    void update(sf::Time dt); 
    void render(sf::RenderTarget& target); 
};
