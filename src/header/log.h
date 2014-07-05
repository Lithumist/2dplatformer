// see license.txt
// log.h
// declares functions that output info to various streams/destinations

#ifndef LOG_H
#define LOG_H

#include <string>

// logging types
#define LOG_INFO    1
#define LOG_DEBUG   2
#define LOG_WARNING 4
#define LOG_ERROR   8

void log ( std::string argMsg, unsigned int argTag = LOG_INFO|LOG_DEBUG );

#endif