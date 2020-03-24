#pragma once

#include <iostream>
#include <sstream>

#ifdef NDEBUG
    #define LOG(...) LogWrapper(__FILE__, __LINE__, __VA_ARGS__)
#else
    #define LOG(...) Empty()
#endif


//to do - flag for serial.print with F() https://arduino.stackexchange.com/questions/19330/store-string-using-f-macro
// Serial.println("\r\n");

void Empty() {}

void Log_Recursive(const char* file, int line, std::ostringstream& msg);


// Log_Recursive wrapper that creates the ostringstream
template<typename... Args>
void LogWrapper(const char* file, int line, const Args&... args)
{
    std::ostringstream msg;
    Log_Recursive(file, line, msg, args...);
}

// "Recursive" variadic function
template<typename T, typename... Args>
void Log_Recursive(const char* file, int line, std::ostringstream& msg,
                   T value, const Args&... args)
{
    msg << value;
    Log_Recursive(file, line, msg, args...);
}

// Terminator
void Log_Recursive(const char* file, int line, std::ostringstream& msg)
{
   std::cout << file << "(" << line << "): " << msg.str() << std::endl;
}


