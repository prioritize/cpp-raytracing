#include "gtest/gtest.h"
#include "../rays.h"

TEST(BasicTest, TestEqual) {
    ASSERT_EQ(1, 1);
}
TEST(BasicTest, TestNotEqual) {
  ASSERT_NE(1, 2);
}

TEST(MakeRays, RayClass) {
    Rays rays(5, 5);
    ASSERT_EQ(rays.pixels.size(), 5);
}
TEST(MakeRays, TestMoreNonEqual) {
    ASSERT_EQ(2, 2);
}