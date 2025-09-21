#include "Enemy.h"
#include<iostream>

void Enemy::initialize(){

    enemyBoundingRectangle.setFillColor(sf::Color::Transparent);
    enemyBoundingRectangle.setOutlineColor(sf::Color::Green);
    enemyBoundingRectangle.setOutlineThickness(1.00f);

    enemySize.x = 64,
    enemySize.y = 64;
}

void Enemy::load(){

    if (Texture.loadFromFile("/Users/deepdubey/Desktop/SFML_Test/BODY_skeleton copy.png"))
    {

        std::cout << " Loaded Successfully!" << std::endl;

        Sprite.setTexture(Texture);
        Sprite.setPosition(sf::Vector2f(400, 300));

        int xIndex = 0;
        int yIndex = 1;

        Sprite.setTextureRect(sf::IntRect(xIndex * enemySize.x, yIndex * enemySize.y, enemySize.x, enemySize.y));
        Sprite.setScale(sf::Vector2f(1.1f, 1.1f));
        enemyBoundingRectangle.setSize(sf::Vector2f(enemySize.x * enemyBoundingRectangle.getScale().x,enemySize.y * enemyBoundingRectangle.getScale().y));
    }
    else
    {
        std::cout << " Load unsuccessful!" << std::endl;
    }

}

void Enemy::update(float deltaTime){

    enemyBoundingRectangle.setPosition(Sprite.getPosition());

}

void Enemy::draw(sf::RenderWindow &window){

    window.draw(enemyBoundingRectangle);
    window.draw(Sprite);

}