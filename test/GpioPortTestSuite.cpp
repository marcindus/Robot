#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "GpioPortMock.hpp"
#include "GpioPort.hpp"
#include "GpioException.hpp"
#include "Types.hpp"
/*
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
*/
TEST(GpioPortTestSuite, checkWpiNumberAndGpioMode)
{

    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D1, GpioMode::Output));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D4, GpioMode::Pwm));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D5, GpioMode::Input));

    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D4, GpioMode::Input));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D5, GpioMode::Input));
    EXPECT_CALL(wrapperMock, pinMode(GpioNodemcuV2::D1, GpioMode::Input));

    ArduinoWrapperMock wrapperMock;

    GpioPort gpioPortOutput(wrapperMock, GpioNodemcuV2::D1, GpioMode::Output);
    GpioPort gpioPortInput(wrapperMock, GpioNodemcuV2::D5, GpioMode::Input);
    GpioPort gpioPortPwm(wrapperMock, GpioNodemcuV2::D4, GpioMode::Pwm);

    EXPECT_EQ(gpioPortOutput.getGpioPort(), GpioNodemcuV2::D1);
    EXPECT_EQ(gpioPortOutput.getMode(), GpioMode::Output);
    EXPECT_EQ(gpioPortInput.getMode(), GpioMode::Input);
    EXPECT_EQ(gpioPortPwm.getMode(), GpioMode::Pwm);
}

// Todo: add tests with exceptions etc...
