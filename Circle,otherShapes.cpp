#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow win(sf::VideoMode(800, 600), "RPG Game!");
    sf::CircleShape c(60.00f);
    c.setFillColor(sf::Color::White);
    c.setOutlineThickness(10.00f);
    c.setOutlineColor(sf::Color::Yellow);
    // c.setPosition(sf::Vector2f(340.00f,240.00f));
    c.setOrigin(sf::Vector2f(60.00f,60.00f));
    c.setPosition(sf::Vector2f(400,300));

    sf::RectangleShape r(sf::Vector2f(80,60));
    r.setFillColor(sf::Color::Blue);
    r.setOutlineThickness(10.00f);
    r.setOutlineColor(sf::Color::Green);
    r.setPosition(sf::Vector2f(360.00f,260.00f));
    r.setRotation(90.00f);

    sf::CircleShape tri(60.00f,3);
    tri.setFillColor(sf::Color::Cyan);

    sf::CircleShape p(60.00f,5);
    p.setFillColor(sf::Color::White);
    p.setPosition(sf::Vector2f(60.00f,60.00f));

    while (win.isOpen())
    {

        sf::Event event;

        while (win.pollEvent(event))
        {
            if (event.type == event.Closed)
            {
                win.close();
            }
        }

        win.clear(sf::Color::Black);

        win.draw(c);
        win.draw(r);
        win.draw(tri);
        win.draw(p);

        win.display();

    }

    return 0;
}