#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;

using std::string;
using std::to_string;
using std::move;

#define CREATE_INFO(message) Logger::log(message, InfoADD)
#define INFO(message) Logger::log(message, Info)
#define ERROR(message) Logger::log(message, Error)
#define WARNING(message) Logger::log(message, Warning)
#define LOG_DEFAULT(message) Logger::log(message, DefaultLogger)
#define LOG_OWN(message, color) Logger::log(message, Own, color)
#define DEFAULT_EMPTY_STRING "Unknown"
#define DEFAULT_EMPTY_FLOAT 0.0
#define DEFAULT_EMPTY_NUMBER 0

#endif