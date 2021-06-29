#include "Robot.hpp"

Robot::Robot(Driver& p_driver) : m_driver(p_driver)
{
}

void Robot::setLeftCorrection(unsigned int corr)
{
    m_driver.m_leftMotor.setCorrection(corr);
}
void Robot::setRightCorrection(unsigned int corr)
{
    m_driver.m_rightMotor.setCorrection(corr);
}

void Robot::goBackward(unsigned int speed)
{
    m_driver.backward(speed);
}
void Robot::goBackward()
{
    m_driver.backward();
}


void Robot::goForward(unsigned int speed)
{
    m_driver.forward(speed);
}
void Robot::goForward()
{
    m_driver.forward();
}


void Robot::turnRight()
{
    m_driver.turnRight();
}

void Robot::turnLeft()
{
    m_driver.turnLeft();
}

void Robot::stepForward()
{
}

void Robot::stepBackward()
{
}

void Robot::run()
{
}

void Robot::stay()
{
    m_driver.stay();
}

int Robot::handleMessage(const char command)
{

//do map with commands here
    if(command == '#')
    {
    //    uint32_t correction  = (uint32_t) strtol((const char *) &command[1], NULL, 16);
    //uint32_t correction = 1;
        // robot_ptr->setCorrection(correction);
    //   msg << "Correction " << correction;
    }
    else if (command == 'F') 
    { 
       return 1;
    }
    else if (command == 'L')
    {

       return 1;
    }
    else if (command == 'R')
    { 
       return 1;
    }
    else if (command == 'B')
    { 
       return 1;
    }
    else if (command == 'S')
    { 
       return 1;
    }
    else if (command == 'D')
    {  
       //int dist =  getDistance();
       //char arr[10] = "";
       //itoa(dist, arr,10);
       //Serial.print(" Distance ");
       //webSocket.sendTXT(num, arr);
     }
    return  0;
}


