#include "Enemy.h"
#include<iostream>

void Enemy::initialize(){


}

void Enemy::load(){

    if (Texture.loadFromFile("/Users/deepdubey/Desktop/SFML_Test/BODY_skeleton copy.png"))
    {

        std::cout << " Loaded Successfully!" << std::endl;

        Sprite.setTexture(Texture);
        Sprite.setPosition(sf::Vector2f(400, 300));

        int xIndex = 0;
        int yIndex = 1;

        Sprite.setTextureRect(sf::IntRect(xIndex * 64, yIndex * 64, 64, 64));
        Sprite.setScale(sf::Vector2f(1.1f, 1.1f));
    }
    else
    {
        std::cout << " Load unsuccessful!" << std::endl;
    }


}

void Enemy::update(){


}

void Enemy::draw(sf::RenderWindow &window){

    window.draw(Sprite);

}