#pragma once

#include <stdexcept>
#include <string>
#include "Types.hpp"

class GpioException : public std::logic_error
{
public:
    GpioException(std::string p_msg, GpioNodemcuV2 p_pin, GpioMode p_mode);
    const char* what() const throw() override;

private:
    GpioNodemcuV2 m_pin;
    GpioMode m_mode;
};
