#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "RobotBuilder.hpp"
#include "Robot.hpp"
#include "Types.hpp"
#include "GpioPort.hpp"

struct RobotBuilderTestSuite : public ::testing::Test
{
    void expectCallsForBuilder();
    ArduinoWrapperMock wrapperMock;
};

void RobotBuilderTestSuite::expectCallsForBuilder()
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



TEST_F(RobotBuilderTestSuite, buildRobot)
{
    expectCallsForBuilder();
    RobotBuilder builder{wrapperMock};
}
