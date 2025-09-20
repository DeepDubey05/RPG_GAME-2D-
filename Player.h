#pragma once
#include<SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{

private :

    sf::Texture Texture;
        std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 2.5f;

public:
    sf::Sprite Sprite;

public:
    void Initialize();
    void Load();
    void Update(Enemy &enemy);
    void Draw(sf::RenderWindow &window);
};