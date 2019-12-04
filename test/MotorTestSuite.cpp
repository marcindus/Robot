#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "GpioPort.hpp"
#include "GpioException.hpp"
#include "Types.hpp"

using ::testing::Return;
using ::testing::NiceMock;

/*
class  MotorTestSuite : public ::testing::Test
{
public:
    MotorTestSuite() :
        gpioPortPwm(wrapperMock, GpioNodemcuV2::GpioNodemcuV2_D4, GpioMode::GpioMode_Pwm)
    {
    }

    NiceMock<ArduinoWrapperMock> wrapperMock;
    Motor m_sut;
};


TEST_F(GpioPortTestSuite, checkWpiNumberAndGpioMode)
{
    EXPECT_EQ(gpioPortOutput.getGpioPort(), GpioNodemcuV2::GpioNodemcuV2_D1);
    EXPECT_EQ(gpioPortOutput.getMode(), GpioMode::GpioMode_Output);
    EXPECT_EQ(gpioPortInput.getMode(), GpioMode::GpioMode_Input);
    EXPECT_EQ(gpioPortPwm.getMode(), GpioMode::GpioMode_Pwm);
}

*/
