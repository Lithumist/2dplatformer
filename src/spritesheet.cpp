// see license.txt
// spritesheet.cpp

#include "header/spritesheet.h"
#include "header/log.h"

platSpriteSheet::platSpriteSheet () {
    flagReady = false;
}

platSpriteSheet::platSpriteSheet ( std::string argFilename, int argSpriteWidth, int argSpriteHeight ) {
    setup( argFilename, argSpriteWidth, argSpriteHeight );
}

bool platSpriteSheet::setup ( std::string argFilename, int argSpriteWidth, int argSpriteHeight )
{
    flagReady = false;

    if ( !txSheet.loadFromFile( argFilename ) ) {
        return false;
    }

    if ( txSheet.getSize().x % argSpriteWidth  != 0 ||
         txSheet.getSize().y % argSpriteHeight != 0 ) {
        log( "Error loading spritesheet '" + argFilename + "'. Individual sprite dimensions do not match sheet dimensions.", LOG_ERROR );
        return false;
    }

    SpriteWidth = argSpriteWidth;
    SpriteHeight = argSpriteHeight;

    SpritesHor = txSheet.getSize().x / argSpriteWidth;
    SpritesVer = txSheet.getSize().y / argSpriteHeight;

    flagReady = true;
    return true;
}

void platSpriteSheet::draw ( int argIndex, sf::Vector2f argPos, sf::RenderWindow* argTarget )
{
    if ( !flagReady ) return;

    // calculate top left coordinates of sprite within spritesheet
    int X, Y;
    Y = SpriteHeight  * ( argIndex / SpritesHor );
    X = SpriteWidth   * ( argIndex - ( (Y/SpriteHeight) * SpritesHor ) );

    // generate the sprite
    sf::Sprite sprSprite  ( txSheet, sf::IntRect( X, Y, SpriteWidth, SpriteHeight ) );
    sprSprite.setPosition ( argPos );

    // draw
    argTarget->draw( sprSprite );
}