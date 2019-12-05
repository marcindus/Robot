#include <gtest/gtest.h>
#include "GpioPortMock.hpp"
#include "Motor.hpp"
#include "Types.hpp"

using ::testing::Return;


class  MotorTestSuite : public ::testing::Test
{
public:
    MotorTestSuite() :
       m_gpioSpeedPortMock(new GpioPortMock),
       m_gpioDirectionPortMock(new GpioPortMock),
       m_rawSpeedGpioPtr(m_gpioSpeedPortMock.get()),
       m_rawDirectionGpioPtr(m_gpioDirectionPortMock.get()),
       m_sut(std::move(m_gpioSpeedPortMock), std::move(m_gpioDirectionPortMock), correction)
{
}

    std::unique_ptr<GpioPortMock> m_gpioSpeedPortMock;
    std::unique_ptr<GpioPortMock> m_gpioDirectionPortMock;
    GpioPortMock* m_rawSpeedGpioPtr;
    GpioPortMock* m_rawDirectionGpioPtr;
    unsigned int correction = 200;
    Motor m_sut;
};


TEST_F(MotorTestSuite, whenMotorRunIsCalledThenisRunningShouldReturnTrue)
{
    unsigned int  speed = 800;
    EXPECT_CALL(*m_rawSpeedGpioPtr, write(800));
    EXPECT_CALL(*m_rawDirectionGpioPtr, write(GpioDigitalValue::GpioValue_Low));
    m_sut.runForward(speed);
    EXPECT_EQ(m_sut.isRunning(), true);
    EXPECT_EQ(m_sut.getDirection(), MotorDirection::Forward);
}

