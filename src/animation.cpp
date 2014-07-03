// see license.txt
// animation.cpp

#include "header/animation.h"

platAnimation::platAnimation () {
    setup( 0, sf::milliseconds(0) );
}

platAnimation::platAnimation ( int argNumFrames, sf::Time argFrameTime ) {
    setup( argNumFrames, argFrameTime );
}

void platAnimation::setup ( int argNumFrames, sf::Time argFrameTime ) {
    NumFrames = argNumFrames;
    FrameTime = argFrameTime;
    Frame = 0;
    flagRunning = false;
}

int platAnimation::frame ()
{
    if ( flagRunning ) {
        int FramesToAdvance = FrameClock.getElapsedTime().asMilliseconds() / FrameTime.asMilliseconds();
        int oldFrame = Frame;
        Frame += FramesToAdvance;
        if ( Frame >= NumFrames ) {
            Frame = Frame % NumFrames;
        }
        if ( oldFrame != Frame ) {
            FrameClock.restart();
        }
    }

    return Frame;
}

void platAnimation::start () {
    flagRunning = true;
    FrameClock.restart();
}

void platAnimation::pause () {
    flagRunning = false;
}