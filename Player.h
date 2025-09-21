#pragma once
#include<SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{

private :

    sf::Texture Texture;
        std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 0.5f;
    float playerSpeed = 2.00f;
    sf::RectangleShape boundingRectangle;

    sf::Vector2i size;

public:
    sf::Sprite Sprite;

public:
    void Initialize();
    void Load();
    void Update(float deltaTime,Enemy &enemy);
    void Draw(sf::RenderWindow &window);
};