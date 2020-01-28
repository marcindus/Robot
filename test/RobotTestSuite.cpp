
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "RobotBuilder.hpp"
#include "Robot.hpp"
#include "Types.hpp"
#include "GpioPort.hpp"

TEST(RobotBuilderTestSuite, buildRobot) {
    
    ArduinoWrapperMock wrapperMock;
    RobotBuilder builder(wrapperMock);
    std::unique_ptr<Robot> m_sut(builder.build());

}


TEST(RobotBuilderTestSuite, robotGoForward)
{
    unsigned int speed = 700;
    ArduinoWrapperMock wrapperMock;

    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D1, GpioMode::Pwm));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D3, GpioMode::Output));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D2, GpioMode::Pwm));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D4, GpioMode::Output));

    EXPECT_CALL(wrapperMock, analogWrite(GpioNodemcuV2::D1, speed));
    EXPECT_CALL(wrapperMock, analogWrite(GpioNodemcuV2::D2, speed));
    EXPECT_CALL(wrapperMock, digitalWrite(GpioNodemcuV2::D3, GpioDigitalValue::GpioValue_Low));
    EXPECT_CALL(wrapperMock, digitalWrite(GpioNodemcuV2::D4, GpioDigitalValue::GpioValue_Low));

    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D4, GpioMode::Input));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D2, GpioMode::Input));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D3, GpioMode::Input));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D1, GpioMode::Input));

    RobotBuilder builder(wrapperMock);
    std::unique_ptr<Robot> m_sut(builder.build());
    m_sut->goForward(speed);
}

