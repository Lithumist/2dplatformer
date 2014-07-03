// see license.txt
// spritesheet.h
// declares class to load and render sprites from a spritesheet

#include <SFML/Graphics.hpp>
#include <string>

class platSpriteSheet
{
    public:
        platSpriteSheet ();
        platSpriteSheet ( std::string argFilename, int argSpriteWidth, int argSpriteHeight );
        bool setup ( std::string argFilename, int argSpriteWidth, int argSpriteHeight );

        void draw ( int argIndex, sf::Vector2f argPos, sf::RenderWindow* argTarget );

    private:
        sf::Texture txSheet;
        int SpriteWidth, SpriteHeight;
        int SpritesHor, SpritesVer;
        bool flagReady;
};