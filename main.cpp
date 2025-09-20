#include "Math.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
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

    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }
        //-------------------------------------UPDATE----------------------------

        player.Update(enemy);
        enemy.update();

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