// see license.txt

#include <SFML/Graphics.hpp>
#include "header/build.h"
#include "header/log.h"
#include "header/animation.h"

int main ()
{
    sf::RenderWindow Window( sf::VideoMode(640, 480), "2D Platformer", sf::Style::Titlebar );

    while ( Window.isOpen() )
    {
        sf::Event Event;
        while ( Window.pollEvent( Event ) ) {

            if ( Event.type == sf::Event::KeyPressed ) {
                if ( Event.key.code == sf::Keyboard::Escape ) {
                    Window.close();
                }
            }

            if ( Event.type == sf::Event::Closed ) {
                Window.close();
            }

        } // event loop
    } // game loop

    return 0;
} // main function