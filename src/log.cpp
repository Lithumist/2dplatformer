// see license.txt
// log.cpp

#include "header/log.h"
#include "header/build.h"
#include <iostream>

void log ( std::string argMsg, unsigned int argTag )
{
    // prefix the message
    argMsg = " " + argMsg;
    if ( argTag & LOG_INFO )    argMsg = "[I]" + argMsg;
    if ( argTag & LOG_DEBUG )   argMsg = "[D]" + argMsg;
    if ( argTag & LOG_WARNING ) argMsg = "[W]" + argMsg;
    if ( argTag & LOG_ERROR )   argMsg = "[E]" + argMsg;

    if ( BUILD_IS_DEBUG ) {
        // output everything to console if in debug mode
        std::cout << argMsg << std::endl;
    } else {
        // TODO -> decide how/where shit will go if not in debug mode
    }


}