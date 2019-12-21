#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "GpioPortMock.hpp"
#include "GpioPort.hpp"
#include "GpioException.hpp"
#include "Types.hpp"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::StrictMock;

class GpioPortTestSuite : public ::testing::Test
{
public:
    GpioPortTestSuite()
        : gpioPortOutput(wrapperMock, GpioNodemcuV2::GpioNodemcuV2_D1, GpioMode::GpioMode_Output),
          gpioPortInput(wrapperMock, GpioNodemcuV2::GpioNodemcuV2_D5, GpioMode::GpioMode_Input),
          gpioPortPwm(wrapperMock, GpioNodemcuV2::GpioNodemcuV2_D4, GpioMode::GpioMode_Pwm)
    {
    }

    NiceMock<ArduinoWrapperMock> wrapperMock;
    GpioPort gpioPortOutput;
    GpioPort gpioPortInput;
    GpioPort gpioPortPwm;
};

TEST_F(GpioPortTestSuite, checkWpiNumberAndGpioMode)
{
    EXPECT_EQ(gpioPortOutput.getGpioPort(), GpioNodemcuV2::GpioNodemcuV2_D1);
    EXPECT_EQ(gpioPortOutput.getMode(), GpioMode::GpioMode_Output);
    EXPECT_EQ(gpioPortInput.getMode(), GpioMode::GpioMode_Input);
    EXPECT_EQ(gpioPortPwm.getMode(), GpioMode::GpioMode_Pwm);
}

// Todo: add tests with exceptions etc...
