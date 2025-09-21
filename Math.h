#pragma once
#include<SFML/Graphics.hpp>

class Math{

    public:

    static sf::Vector2f VectorNormalized(sf::Vector2f Vector);

    static bool CheckRectCollision(sf::FloatRect rect1,sf::FloatRect rect2);

};