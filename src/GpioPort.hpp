#ifndef GPIOPORT_HPP
#define GPIOPORT_HPP
 
#include "IGpioPort.hpp"

class GpioPort : public IGpioPort
{
    public:
    ~IGpioPort() { }
    void write(GpioDigitalValue) const override ;
    void write(unsigned) const override;
    GpioPin getGpioPort() const override;
    GpioMode getMode() const override ;

};

#endif  // GPIOPORT_HPP

