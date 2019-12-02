#ifndef IGPIOPORT_HPP
#define IGPIOPORT_HPP

#include "Types.hpp"

class IGpioPort
{
public:
    virtual ~IGpioPort() { }
    virtual void write(GpioDigitalValue) const = 0;
    virtual void write(unsigned int) const = 0;
    virtual GpioNodemcuV2 getGpioPort() const = 0;
    virtual GpioMode getMode() const = 0;
};


#endif // IGPIOPORT_HPP
