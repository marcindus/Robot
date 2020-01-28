#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "GpioPortMock.hpp"
#include "GpioPort.hpp"
#include "GpioException.hpp"
#include "Types.hpp"

TEST(GpioPortTestSuite, checkWpiNumberAndGpioMode)
{

    ArduinoWrapperMock wrapperMock;

    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D1, GpioMode::Output));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D4, GpioMode::Pwm));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D5, GpioMode::Input)).Times(2);
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D4, GpioMode::Input));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D1, GpioMode::Input));

    GpioPort gpioPortOutput(wrapperMock, GpioNodemcuV2::D1, GpioMode::Output);
    GpioPort gpioPortInput(wrapperMock, GpioNodemcuV2::D5, GpioMode::Input);
    GpioPort gpioPortPwm(wrapperMock, GpioNodemcuV2::D4, GpioMode::Pwm);

    EXPECT_EQ(gpioPortOutput.getGpioPort(), GpioNodemcuV2::D1);
    EXPECT_EQ(gpioPortOutput.getMode(), GpioMode::Output);
    EXPECT_EQ(gpioPortInput.getMode(), GpioMode::Input);
    EXPECT_EQ(gpioPortPwm.getMode(), GpioMode::Pwm);
}

// Todo: add tests with exceptions etc...
