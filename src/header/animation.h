// see license.txt
// animation.h
// declares a class for handling the timing for frame by frame animation

#include <SFML/System.hpp>

class platAnimation
{
    public:
        platAnimation ();
        platAnimation ( int argNumFrames, sf::Time argFrameTime );
        void setup ( int argNumFrames, sf::Time argFrameTime );

        int frame ();

        void start ();
        void pause ();

    private:
        bool flagRunning;
        int NumFrames;
        sf::Time FrameTime;
        sf::Clock FrameClock;
        int Frame;
};