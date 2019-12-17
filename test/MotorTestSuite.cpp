#include <gtest/gtest.h>
#include "GpioPortMock.hpp"
#include "Motor.hpp"
#include "Types.hpp"
#include "Driver.hpp"

using ::testing::Return;


class  MotorTestSuite : public ::testing::Test
{
public:
    MotorTestSuite() :
       m_gpioSpeedPortMock(new GpioPortMock),
       m_gpioDirectionPortMock(new GpioPortMock),
       m_rawSpeedGpioPtr(m_gpioSpeedPortMock.get()),
       m_rawDirectionGpioPtr(m_gpioDirectionPortMock.get()),
       m_sut(std::move(m_gpioSpeedPortMock),
             std::move(m_gpioDirectionPortMock),
             correction,
             minSpeed)
{
}
    std::unique_ptr<GpioPortMock> m_gpioSpeedPortMock;
    std::unique_ptr<GpioPortMock> m_gpioDirectionPortMock;
    GpioPortMock* m_rawSpeedGpioPtr;
    GpioPortMock* m_rawDirectionGpioPtr;
    unsigned int correction = 200;
    unsigned int  speed = 800;
    unsigned int minSpeed = 600;
    unsigned int lowerThancorrection = 100;
    Motor m_sut;
};

TEST_F(MotorTestSuite, motorRunsForwardWithCorrectedSpeed)
{
    EXPECT_CALL(*m_rawSpeedGpioPtr, write(speed-correction));
    EXPECT_CALL(*m_rawDirectionGpioPtr, write(GpioDigitalValue::GpioValue_Low));
    m_sut.runForward(speed);
    EXPECT_EQ(m_sut.isRunning(), true);
    EXPECT_EQ(m_sut.getDirection(), MotorDirection::Forward);
}

TEST_F(MotorTestSuite, motorRunsBackwardCorrectedSpeed)
{
    EXPECT_CALL(*m_rawSpeedGpioPtr, write(speed-correction));
    EXPECT_CALL(*m_rawDirectionGpioPtr, write(GpioDigitalValue::GpioValue_High));
    m_sut.runBackward(speed);
    EXPECT_EQ(m_sut.isRunning(), true);
    EXPECT_EQ(m_sut.getDirection(), MotorDirection::Backward);
}

TEST_F(MotorTestSuite, motorRunsBackwardWithMinimalSpeed)
{
    EXPECT_CALL(*m_rawSpeedGpioPtr, write(minSpeed));
    EXPECT_CALL(*m_rawDirectionGpioPtr, write(GpioDigitalValue::GpioValue_High));
    m_sut.runBackward(lowerThancorrection);
    EXPECT_EQ(m_sut.isRunning(), true);
    EXPECT_EQ(m_sut.getDirection(), MotorDirection::Backward);
}



TEST_F(MotorTestSuite, motorStop)
{
    EXPECT_CALL(*m_rawSpeedGpioPtr, write(0));
    m_sut.stop();
    EXPECT_EQ(m_sut.isRunning(), false);
    EXPECT_EQ(m_sut.getDirection(), MotorDirection::Forward);
}

