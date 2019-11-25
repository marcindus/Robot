#ifndef IARDUINOWRAPPER_HPP
#define IARDUINOWRAPPER_HPP

class IArduinoWrapper
{
    public:
        virtual ~IArduinoWrapper() {};

        virtual void analogWrite(int pin, int value) const = 0;
        virtual void digitalWrite(int pin, int value) const = 0;
        virtual void pinMode(int pin, int mode) const = 0;

};



#endif // IARDUINOWRAPPER_HPP
