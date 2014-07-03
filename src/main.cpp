// see license.txt

#include <SFML/Graphics.hpp>
#include "header/build.h"
#include "header/log.h"
#include "header/animation.h"

int main () {
    log( "Tesing Animation!", LOG_INFO|LOG_DEBUG );

    platAnimation MyAnim( 10, sf::seconds(1) );
    MyAnim.start();

    sf::Clock MyClock;
    MyClock.restart();

    while ( 1 ) {
        if ( MyClock.getElapsedTime().asSeconds() >= 0.5 ) {
            MyClock.restart();
            log( std::to_string(MyAnim.frame()) );
        }
    }

    system("Pause");
    return 0;
}