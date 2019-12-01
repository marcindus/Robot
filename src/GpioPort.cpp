#include "GpioPort.hpp"

{
    GpioPort::~IGpioPort() { }
    void  GpioPort::write(GpioDigitalValue) const override ;
    void  GpioPort::write(unsigned) const override;
    GpioPin  GpioPort::getGpioPort() const override;
    GpioMode  GpioPort::getMode() const override ;

};



