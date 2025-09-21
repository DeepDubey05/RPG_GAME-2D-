#pragma once
#include<SFML/Graphics.hpp>

class Enemy{

    private:
    sf::Texture Texture;

    sf::RectangleShape enemyBoundingRectangle;

    sf::Vector2i enemySize;

    public:
    sf::Sprite Sprite;

    public:

    void initialize();
    void load();
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
    
};