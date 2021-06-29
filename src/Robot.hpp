#pragma once

#include "Driver.hpp"
#include "ArduinoWrapper.hpp"


class Robot
{
public:
    Robot(Driver& p_driver);
    void goBackward(unsigned int speed);
    void goForward(unsigned int speed);
    void goBackward();
    void goForward();
    void turnRight();
    void turnLeft();
    void stepForward();
    void stepBackward();
    void run();
    void stay();
    void setLeftCorrection(unsigned int corr);
    void setRightCorrection(unsigned int corr);
    ArduinoStringWrapper handleMessage(const ArduinoStringWrapper& payload); 
    Driver& m_driver;
};
