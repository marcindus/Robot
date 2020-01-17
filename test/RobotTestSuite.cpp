
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "RobotBuilder.hpp"
#include "Robot.hpp"
#include "Types.hpp"
#include "GpioPort.hpp"

using ::testing::NiceMock;
using ::testing::Return;
using ::testing::StrictMock;

class RobotBuilderTestSuite : public ::testing::Test
{
public:
    RobotBuilderTestSuite() : builder(wrapperMock), m_sut(builder.build()) {}

    ArduinoWrapperMock wrapperMock;
    RobotBuilder builder;
    std::unique_ptr<Robot> m_sut;
};

TEST_F(RobotBuilderTestSuite, sanity)
{
    m_sut->goForward(700);

/*    EXPECT_CALL(wrapperMock, _pinMode(Pin::D1, Mode::Pwm));
    EXPECT_CALL(wrapperMock, _pinMode(Pin::D3, Mode::Output));
    EXPECT_CALL(wrapperMock, _pinMode(Pin::D2, Mode::Pwm));
    EXPECT_CALL(wrapperMock, _pinMode(Pin::D4, Mode::Output)); */
    EXPECT_CALL(wrapperMock, _analogWrite(GpioNodemcuV2::GpioNodemcuV2_D2, 700));
//    EXPECT_CALL(wrapperMock, _digitalWrite(Pin::D3, Low));
//    EXPECT_CALL(wrapperMock, _analogWrite(Pin::D2, 700));
//    EXPECT_CALL(wrapperMock, _digitalWrite(Pin::D4, Low));
/*    EXPECT_CALL(wrapperMock, _pinMode(Pin::D4, Mode::Input));
    EXPECT_CALL(wrapperMock, _pinMode(Pin::D2, Mode::Input));
    EXPECT_CALL(wrapperMock, _pinMode(Pin::D3, Mode::Input));
    EXPECT_CALL(wrapperMock, _pinMode(Pin::D1, Mode::Input)); */

}

