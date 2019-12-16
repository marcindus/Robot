#ifndef  ROBOT_HPP
#define  ROBOT_HPP

#include "Driver.hpp"

class Robot
{
public:

     Robot(Driver& p_driver);
     void goBackward(unsigned int speed);
     void goForward(unsigned int speed);
     void turnRight();
     void turnLeft();
     void stepForward();
     void stepBackward();
     void run();
     void stay();

private:
    Driver&  m_driver;
    //Wifi
    //Sensors
    //Steering interface
};

#endif //   ROBOT_HPP
