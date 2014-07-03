// see license.txt

#include <SFML/Graphics.hpp>
#include "header/build.h"
#include "header/log.h"
#include "header/animation.h"
#include "header/spritesheet.h"

int main ()
{
    sf::RenderWindow Window( sf::VideoMode(640, 480), "2D Platformer", sf::Style::Titlebar );

    // test spritesheets
    platSpriteSheet Sheet;
    Sheet.setup( "assets/tiles.png", 32, 32 );

    // test animatinos
    platAnimation Anim( 5, sf::seconds( 0.5 ) );
    Anim.start();

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

        Window.clear();
        Sheet.draw( Anim.frame() , sf::Vector2f( 0, 20 ), &Window );
        Window.display();

    } // game loop

    return 0;
} // main function