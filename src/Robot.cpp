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

uint8_t* Robot::handleMessage(uint8_t* payload)
{
    std::ostringstream msg;
    msg << "Received command: ";

    if(payload[0] == '#')
    {
    //    uint32_t correction  = (uint32_t) strtol((const char *) &payload[1], NULL, 16);
    uint32_t correction = 1;
        // robot_ptr->setCorrection(correction);
       msg << "Correction " << correction;
    }
    else if (payload[0] == 'F') 
    { 
        msg <<  "Forward";
    }
    else if (payload[0] == 'L')
    {
        msg <<  "Left";
    }
    else if (payload[0] == 'R')
    { 
        msg << "Right";
    }
    else if (payload[0] == 'B')
    { 
        msg << "Backward"; 
    }
    else if (payload[0] == 'S')
    { 
        msg << "Stop"; 
    }
    else if (payload[0] == 'D')
    {  
        //int dist =  getDistance();
        //char arr[10] = "";
        //itoa(dist, arr,10);
        //Serial.print(" Distance ");
        //   webSocket.sendTXT(num, arr);
     }
    std::string str = msg.str();
    return  reinterpret_cast<uint8_t*>(&str[0]);
}


