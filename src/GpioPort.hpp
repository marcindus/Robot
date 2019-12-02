#ifndef GPIOPORT_HPP
#define GPIOPORT_HPP

#include "IGpioPort.hpp"
#include "ArduinoWrapper.hpp"

class GpioPort : public IGpioPort
{
public:

    GpioPort(IArduinoWrapper& p_arduinoWrapper,  GpioNodemcuV2 p_pin, GpioMode p_mode);
    ~GpioPort();

    void write(GpioDigitalValue p_value) const override ;
    void write(unsigned int p_signal) const override;
    GpioNodemcuV2 getGpioPort() const override;
    GpioMode getMode() const override ;

private:

    IArduinoWrapper& m_arduinoWrapper;
    GpioNodemcuV2 m_gpioPin;
    GpioMode m_gpioMode;

};

#endif  // GPIOPORT_HPP

