
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ArduinoWrapperMock.hpp"
#include "RobotBuilder.hpp"
#include "Robot.hpp"

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
    m_sut->goForward(500);
}
