
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "RobotBuilder.hpp"
#include "Robot.hpp"
#include "Types.hpp"
#include "GpioPort.hpp"



TEST(RobotBuilderTestSuite, robotGoForward)
{
    unsigned int speed = 700;
    ArduinoWrapperMock wrapperMock;

    EXPECT_CALL(wrapperMock, _pinMode(GpioNodemcuV2::D1, GpioMode::GpioMode_Pwm));
    EXPECT_CALL(wrapperMock, _pinMode(GpioNodemcuV2::D3, GpioMode::GpioMode_Output));
    EXPECT_CALL(wrapperMock, _pinMode(GpioNodemcuV2::D2, GpioMode::GpioMode_Pwm));
    EXPECT_CALL(wrapperMock, _pinMode(GpioNodemcuV2::D4, GpioMode::GpioMode_Output));

    EXPECT_CALL(wrapperMock, _analogWrite(GpioNodemcuV2::D1, speed));
    EXPECT_CALL(wrapperMock, _analogWrite(GpioNodemcuV2::D2, speed));
    EXPECT_CALL(wrapperMock, _digitalWrite(GpioNodemcuV2::D3, GpioDigitalValue::GpioValue_Low));
    EXPECT_CALL(wrapperMock, _digitalWrite(GpioNodemcuV2::D4, GpioDigitalValue::GpioValue_Low));

    EXPECT_CALL(wrapperMock, _pinMode(GpioNodemcuV2::D4, GpioMode::GpioMode_Input));
    EXPECT_CALL(wrapperMock, _pinMode(GpioNodemcuV2::D2, GpioMode::GpioMode_Input));
    EXPECT_CALL(wrapperMock, _pinMode(GpioNodemcuV2::D3, GpioMode::GpioMode_Input));
    EXPECT_CALL(wrapperMock, _pinMode(GpioNodemcuV2::D1, GpioMode::GpioMode_Input));

    RobotBuilder builder(wrapperMock);
    std::unique_ptr<Robot> m_sut(builder.build());
    m_sut->goForward(speed);
}

