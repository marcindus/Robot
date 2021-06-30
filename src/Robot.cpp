#include "Robot.hpp"
#include <iostream>

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

int Robot::handleMessage(const char* command_str)
{
    RobotCommand command(command_str);
    std::map<RobotCommand, std::function<void()>> commands;

    commands[RobotCommand("F")] = [this]() {
        goForward();
        return 1;
    };
    commands[RobotCommand("B")] = [this]() {
        goBackward();
        return 1;
    };
    commands[RobotCommand("L")] = [this]() {
        turnLeft();
        return 1;
    };
    commands[RobotCommand("R")] = [this]() {
        turnRight();
        return 1;
    };
    commands[RobotCommand("S")] = [this]() {
        stay();
        return 1;
    };

    commands.at(command)();
    /*
       try
        {
            *out = operations.at(oper)(a, b);
        }
        catch (const std::out_of_range& ex)
        {
            return ErrorCode::BadCharacter;
        }
        catch (const CalculationException& ex)
        {
            return ex.errorCode;
        }
        return ErrorCode::OK;

    */
    /*
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
    */
    return 0;
}
