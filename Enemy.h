#pragma once
#include<SFML/Graphics.hpp>

class Enemy{

    private:
    sf::Texture Texture;

    public:
    sf::Sprite Sprite;

    public:

    void initialize();
    void load();
    void update();
    void draw(sf::RenderWindow &window);
    
};