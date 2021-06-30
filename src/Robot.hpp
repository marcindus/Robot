#pragma once

#include <map>
#include <functional>
#include <string.h>
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
    int handleMessage(const char* command);
    Driver& m_driver;
};

class RobotCommand
{
public:
    RobotCommand(const char* str) : command(str){};

    friend bool operator==(const RobotCommand& lhs, const RobotCommand& rhs)
    {
        return strcmp(lhs.command, rhs.command);
    }

    friend bool operator!=(const RobotCommand& lhs, const RobotCommand& rhs) { return !(lhs == rhs); }

    friend bool operator>(const RobotCommand& lhs, const RobotCommand& rhs)
    {
        return strcmp(lhs.command, rhs.command) > 0;
    }

    friend bool operator<(const RobotCommand& lhs, const RobotCommand& rhs)
    {
        return strcmp(lhs.command, rhs.command) < 0;
    }

protected:
    const char* command;
};
