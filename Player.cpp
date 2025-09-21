#include "Player.h"
#include "Enemy.h"
#include "Math.h"
#include <iostream>

void Player::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineThickness(1.00f);
    boundingRectangle.setOutlineColor(sf::Color::Red);

    
    size = sf::Vector2i(64,64);
}

void Player::Load()
{

    if (Texture.loadFromFile("/Users/deepdubey/Desktop/SFML_Test/BODY_skeleton copy.png"))
    {

        std::cout << "Player Loaded Successfully!" << std::endl;

        Sprite.setTexture(Texture);

        int xIndex = 0;
        int yIndex = 1;

        Sprite.setTextureRect(sf::IntRect(xIndex * size.x, yIndex * size.y, size.x, size.y));
                Sprite.setScale(sf::Vector2f(1.1f, 1.1f));

    boundingRectangle.setSize(sf::Vector2f(size.x* Sprite.getScale().x,size.y * Sprite.getScale().y));

    }
    else
    {
        std::cout << "Player Load unsuccessful!" << std::endl;
    }
}

void Player::Update(float deltaTime,Enemy &enemy)
{
        sf::Vector2f Position = Sprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            Sprite.setPosition(Position + sf::Vector2f(0.25f, 0.00f) * playerSpeed * deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            Sprite.setPosition(Position + sf::Vector2f(-0.25f, 0.00f) * playerSpeed * deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            Sprite.setPosition(Position + sf::Vector2f(0.00f, 0.25f) * playerSpeed * deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            Sprite.setPosition(Position + sf::Vector2f(0.00f, -0.25f) * playerSpeed * deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            Sprite.setPosition(Position + sf::Vector2f(0.25f, -0.25f) * playerSpeed * deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            Sprite.setPosition(Position + sf::Vector2f(-0.25f, -0.25f) * playerSpeed * deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            Sprite.setPosition(Position + sf::Vector2f(0.25f, 0.25f) * playerSpeed * deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            Sprite.setPosition(Position + sf::Vector2f(-0.25f, 0.25f) * playerSpeed * deltaTime);

                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

            bullets.push_back(sf::RectangleShape(sf::Vector2f(12.00f, 7.00f)));

            int i = bullets.size() - 1;

            bullets[i].setFillColor(sf::Color::Green);
            bullets[i].setPosition(Sprite.getPosition());
        }

        for (int i = 0; i < bullets.size(); i++)
        {

            sf::Vector2f direction = enemy.Sprite.getPosition() - bullets[i].getPosition();

            direction = Math:: VectorNormalized(direction);

            bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed * deltaTime);
        }
        boundingRectangle.setPosition(Sprite.getPosition());

        if(Math::CheckRectCollision(Sprite.getGlobalBounds(),enemy.Sprite.getGlobalBounds())){
            std::cout<<"Colllison detected!"<<std::endl;
        }
}

void Player::Draw(sf::RenderWindow &window)
{      
      for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }

    window.draw(boundingRectangle);
    window.draw(Sprite);
}
