#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow yes(sf::VideoMode(1000, 1000), "Hii again!"); // it will create a window which will open for a second and will close

    // to solve this problem we will be using loops more specifically while loop

    // first while loop !

    while (yes.isOpen())
    { // yes is an object and is calling member function of RenderWindow and this isOpen() checks if the window is open or not!! and the loop continues

        // lets say your device runs 60 fps so we will be going 60 times in a second through this loop!!

        // one more thing -> it is that if the device is running at some refresh rate and the game is running at higher refresh rate
        //  then it will cause tearing. thats why a thing called V-Sync is used.

        // Second while loop ->Event Loop

        //----------------------------------------------UPDATE-------------------------------------------------------------
        
        sf::Event eve;
        
        while (yes.pollEvent(eve)) // we will be able to interact with it and minimize and all but we will not be able to close it!
        {
            if (eve.type == sf::Event::Closed)
            {
                yes.close();
            }
        }
        //----------------------------------------------UPDATE-------------------------------------------------------------
        

        //----------------------------------------------DRAW-------------------------------------------------------------
        
        //Whats happening here is basically we are 1)clearing the window and giving it a color  2)Drawing happens in back buffers
        //3)when u are done drawing u copy stuff from back buffer to the screen with the help of display
        yes.clear(sf::Color::Cyan);
        //Drawing part happens here!
        yes.display();
        // update(); // updates when you click or press anything!
        // draw();   // in every second the drawing or frames gets redrawn many times!
        //----------------------------------------------DRAW-------------------------------------------------------------

    }

    return 0;
}

