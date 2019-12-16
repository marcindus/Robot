#include <gtest/gtest.h>
#include "GpioPortMock.hpp"
#include "Motor.hpp"
#include "Types.hpp"
#include "Driver.hpp"

using ::testing::Return;


class  DriverTestSuite : public ::testing::Test
{
public:
    DriverTestSuite() :
       m_A_gpioSpeedPortMock(new GpioPortMock),
       m_A_gpioDirectionPortMock(new GpioPortMock),
       m_B_gpioSpeedPortMock(new GpioPortMock),
       m_B_gpioDirectionPortMock(new GpioPortMock),
       m_A_rawSpeedGpioPtr(m_A_gpioSpeedPortMock.get()),
       m_A_rawDirectionGpioPtr(m_A_gpioDirectionPortMock.get()),
       m_B_rawSpeedGpioPtr(m_B_gpioSpeedPortMock.get()),
       m_B_rawDirectionGpioPtr(m_B_gpioDirectionPortMock.get()),
       m_leftMotor(std::move(m_A_gpioSpeedPortMock), 
       m_leftMotor(std::move(m_A_gpioSpeedPortMock),
                   std::move(m_A_gpioDirectionPortMock),
                   correction,
                   minSpeed),
       m_rightMotor(std::move(m_B_gpioSpeedPortMock),
                    std::move(m_B_gpioDirectionPortMock),
                    correction, minSpeed),
       m_sut_driver(m_leftMotor, m_rightMotor)
{
}
    std::unique_ptr<GpioPortMock> m_A_gpioSpeedPortMock;
    std::unique_ptr<GpioPortMock> m_A_gpioDirectionPortMock;
    std::unique_ptr<GpioPortMock> m_B_gpioSpeedPortMock;
    std::unique_ptr<GpioPortMock> m_B_gpioDirectionPortMock;
    GpioPortMock* m_A_rawSpeedGpioPtr;
    GpioPortMock* m_A_rawDirectionGpioPtr;
    GpioPortMock* m_B_rawSpeedGpioPtr;
    GpioPortMock* m_B_rawDirectionGpioPtr;
    unsigned int correction = 200;
    unsigned int  speed = 800;
    unsigned int minSpeed = 600;
    Motor m_leftMotor;
    Motor m_rightMotor;
    Driver m_sut_driver;
};


TEST_F(DriverTestSuite, driverRunsForward)
{
    EXPECT_CALL(*m_A_rawSpeedGpioPtr, write(speed));
    EXPECT_CALL(*m_B_rawSpeedGpioPtr, write(speed));
    EXPECT_CALL(*m_A_rawDirectionGpioPtr, write(GpioDigitalValue::GpioValue_Low));
    EXPECT_CALL(*m_B_rawDirectionGpioPtr, write(GpioDigitalValue::GpioValue_Low));

    m_sut_driver.forward(speed);
    EXPECT_EQ(m_rightMotor.isRunning(), true);
    EXPECT_EQ(m_leftMotor.isRunning(), true);
    EXPECT_EQ(m_rightMotor.getDirection(), MotorDirection::Forward);
    EXPECT_EQ(m_leftMotor.getDirection(), MotorDirection::Forward);
}
