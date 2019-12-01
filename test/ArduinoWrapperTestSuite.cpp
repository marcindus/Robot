#include <gtest/gtest.h>
#include "ArduinoWrapperMock.hpp"
#include "GpioPortMock.hpp"

using ::testing::Return;

TEST(blank, sanityCheck)
{
    ASSERT_EQ(1,9);
}
