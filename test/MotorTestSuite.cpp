#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "GpioPortMock.hpp"
#include "Motor.hpp"
#include <memory>

using ::testing::Return;
using ::testing::NiceMock;


class  MotorTestSuite : public ::testing::Test
{
public:
    MotorTestSuite() : 
        m_gpioPortMock(new GpioPortMock), 
        m_rawGpioPtr(m_gpioPortMock.get()),
        m_sut(std::move(m_gpioPortMock)
    {
    }
    std::unique_ptr<GpioPortMock> m_gpioPortMock;
    GpioPortMock* m_rawGpioPtr;
    Motor m_sut;
};


TEST_F(MotorTestSuite, whenMotorRunIsCalledThenisRunningShouldReturnTrue)
{
  EXPECT_CALL(*m_portRawPtr, write(GpioValue::GpioValue_High));
  m_sut.runForward();
  EXPECT_EQ(m_sut.isRunning(), true);
}

