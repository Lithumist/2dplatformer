// see license.txt
// level.h
// declares a level class. Can play individual levels

#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <SFML/Graphics.hpp>

class platLevel
{
    public:
        platLevel ();
        
        bool load ( std::string argFilename );

        void play ();
        void pause ();
        void stop ();
};

#endif