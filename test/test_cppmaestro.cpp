#include "gtest/gtest.h"
#include "CppMaestro/CppMaestro.hpp"

// Change this or all the tests might fail.
std::string device = "/dev/ttyACM0";

TEST(CppMaestroTest, InitializationTest) {
    EXPECT_NO_THROW(CppMaestro maestro(device));
}

TEST(CppMaestroTest, SetTargetTest) {
    CppMaestro maestro(device);
    EXPECT_NO_THROW(maestro.setTarget(0, 6000));
}

TEST(CppMaestroTest, SetSpeedTest) {
    CppMaestro maestro(device);
    EXPECT_NO_THROW(maestro.setSpeed(0, 60));
}

TEST(CppMaestroTest, SetAccelTest) {
    CppMaestro maestro(device);
    EXPECT_NO_THROW(maestro.setAccel(0, 10));
}