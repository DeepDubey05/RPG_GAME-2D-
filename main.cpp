#include "Math.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    Player player;
    Enemy enemy;
    //-------------------------------------INITIALIZATION----------------------------

    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World!");

    enemy.initialize();

    player.Initialize();
    //-------------------------------------INITIALIZATION----------------------------

    //------------------------------------LOAD------------------------------

    player.Load();
    enemy.load();

    //------------------------------------LOAD------------------------------

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time deltaTimeTimer = clock.restart();
       float deltaTime = deltaTimeTimer.asMilliseconds();
        sf::Event event;

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }        
        //-------------------------------------UPDATE----------------------------

        enemy.update(deltaTime);
        player.Update(deltaTime,enemy);

        //-------------------------------------UPDATE----------------------------

        //-------------------------------------DRAW----------------------------
        window.clear(sf::Color::Black);

        player.Draw(window);
        enemy.draw(window);
        window.display();
        //-------------------------------------DRAW----------------------------
    }
    return 0;
}