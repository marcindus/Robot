#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "GpioPortMock.hpp"
#include "GpioPort.hpp"
#include "GpioException.hpp"
#include "Types.hpp"

class GpioPortTestSuite : public ::testing::Test
{
public:
    GpioPortTestSuite()
        : gpioPortOutput(wrapperMock, GpioNodemcuV2::D1, GpioMode::Output),
          gpioPortInput(wrapperMock, GpioNodemcuV2::D5, GpioMode::Input),
          gpioPortPwm(wrapperMock, GpioNodemcuV2::D4, GpioMode::Pwm)
    {
    }

    ArduinoWrapperMock wrapperMock;
    GpioPort gpioPortOutput;
    GpioPort gpioPortInput;
    GpioPort gpioPortPwm;
};

TEST_F(GpioPortTestSuite, checkWpiNumberAndGpioMode)
{
    EXPECT_EQ(gpioPortOutput.getGpioPort(), GpioNodemcuV2::D1);
    EXPECT_EQ(gpioPortOutput.getMode(), GpioMode::Output);
    EXPECT_EQ(gpioPortInput.getMode(), GpioMode::Input);
    EXPECT_EQ(gpioPortPwm.getMode(), GpioMode::Pwm);
}

// Todo: add tests with exceptions etc...
