#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "RobotBuilder.hpp"
#include "Robot.hpp"
#include "Types.hpp"
#include "GpioPort.hpp"

struct RobotTestSuite : public ::testing::Test
{
    void expectCallsBuilder();
    ArduinoWrapperMock wrapperMock;
};

void RobotTestSuite::expectCallsBuilder()
{
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D1, GpioMode::Pwm));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D3, GpioMode::Output));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D2, GpioMode::Pwm));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D4, GpioMode::Output));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D4, GpioMode::Input));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D2, GpioMode::Input));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D3, GpioMode::Input));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D1, GpioMode::Input));
}

TEST_F(RobotTestSuite, robotGoForward)
{
    unsigned int speed = 700;

    expectCallsBuilder();
    EXPECT_CALL(wrapperMock, analogWrite(GpioNodemcuV2::D1, speed));
    EXPECT_CALL(wrapperMock, analogWrite(GpioNodemcuV2::D2, speed));
    EXPECT_CALL(wrapperMock, digitalWrite(GpioNodemcuV2::D3, GpioDigitalValue::GpioValue_Low));
    EXPECT_CALL(wrapperMock, digitalWrite(GpioNodemcuV2::D4, GpioDigitalValue::GpioValue_Low));

    RobotBuilder builder{wrapperMock};
    std::unique_ptr<Robot> m_sut(builder.build());
    m_sut->goForward(speed);
}

TEST_F(RobotTestSuite, setCorrectionForLeftMotor)
{
    unsigned int speed = 1000;
    unsigned int corr = 200;

    expectCallsBuilder();
    EXPECT_CALL(wrapperMock, analogWrite(GpioNodemcuV2::D1, speed-corr));
    EXPECT_CALL(wrapperMock, analogWrite(GpioNodemcuV2::D2, speed-corr));
    EXPECT_CALL(wrapperMock, digitalWrite(GpioNodemcuV2::D3, GpioDigitalValue::GpioValue_Low));
    EXPECT_CALL(wrapperMock, digitalWrite(GpioNodemcuV2::D4, GpioDigitalValue::GpioValue_Low));

    RobotBuilder builder{wrapperMock};
    std::unique_ptr<Robot> m_sut(builder.build());
    m_sut->setLeftCorrection(corr);
    m_sut->goForward(speed-corr);
}

TEST_F(RobotTestSuite, setCorrectionForLeftMotorSpeedLowerThanMinimumSpeed)
{
    unsigned int speed = 800;
    unsigned int corr = 200;
    unsigned int minimum_speed = 700;
    expectCallsBuilder();
    EXPECT_CALL(wrapperMock, analogWrite(GpioNodemcuV2::D1, minimum_speed));
    EXPECT_CALL(wrapperMock, analogWrite(GpioNodemcuV2::D2, minimum_speed));
    EXPECT_CALL(wrapperMock, digitalWrite(GpioNodemcuV2::D3, GpioDigitalValue::GpioValue_Low));
    EXPECT_CALL(wrapperMock, digitalWrite(GpioNodemcuV2::D4, GpioDigitalValue::GpioValue_Low));

    RobotBuilder builder{wrapperMock};
    std::unique_ptr<Robot> m_sut(builder.build());
    m_sut->setLeftCorrection(corr);
    m_sut->goForward(speed);
}

