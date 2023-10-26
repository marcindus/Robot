#pragma once

#include <iostream>

#define LOG(...) LogWithLine(__LINE__, __VA_ARGS__)

template <typename T>
void printWithSpace(const T& value)
{
    std::cout << value << " ";
}

template <typename... Ts>
void Log(const Ts&... values)
{
    (printWithSpace(values), ...);
}

template <typename... Ts>
std::ostream& LogWithLine(int line, const Ts&... values)
{
    std::cout << "Line " << line << ": ";
    if constexpr (sizeof...(Ts) > 0)
    {
        Log(values...);
    }
    std::cout << std::endl;
    return std::cout;
}


//to do - flag for serial.print with F() https://arduino.stackexchange.com/questions/19330/store-string-using-f-macro
// Serial.println("\r\n");
