#ifndef IGPIOPORT_HPP
#define IGPIOPORT_HPP

#include "Arduino_Types.hpp"
#include "NodemcuV2_Types.hpp"

class IGpioPort
{
public:
    virtual ~IGpioPort() { }
    virtual void write(GpioDigitalValue) const = 0;
    virtual void write(unsigned) const = 0;
    virtual GpioPin getGpioPort() const = 0;
    virtual GpioMode getMode() const = 0;
};


#endif // IGPIOPORT_HPP
