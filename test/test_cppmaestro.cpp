#include "gtest/gtest.h"
#include "CppMaestro/CppMaestro.hpp"

TEST(CppMaestroTest, InitializationTest) {
    EXPECT_NO_THROW(CppMaestro maestro("/dev/ttyACM0"));
}

TEST(CppMaestroTest, SetTargetTest) {
    CppMaestro maestro("/dev/ttyACM0");
    EXPECT_NO_THROW(maestro.setTarget(0, 6000));
}

TEST(CppMaestroTest, SetSpeedTest) {
    CppMaestro maestro("/dev/ttyACM0");
    EXPECT_NO_THROW(maestro.setSpeed(0, 60));
}

TEST(CppMaestroTest, SetAccelTest) {
    CppMaestro maestro("/dev/ttyACM0");
    EXPECT_NO_THROW(maestro.setAccel(0, 10));
}