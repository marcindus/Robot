#include "GpioException.hpp"
#include <sstream>

GpioException::GpioException(std::string p_msg, GpioNodemcuV2 p_pin, GpioMode p_mode)
    : logic_error(p_msg), m_pin(p_pin), m_mode(p_mode)
{
}

const char* GpioException::what() const throw()
{
    std::ostringstream o;
    o << logic_error::what() << ", gpio  port " << static_cast<unsigned>(m_pin) << ", port mode "
      << static_cast<unsigned>(m_mode) << std::endl;
    return o.str().c_str();
}
