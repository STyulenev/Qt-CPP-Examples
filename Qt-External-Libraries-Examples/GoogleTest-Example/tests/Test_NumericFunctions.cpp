#include <gtest/gtest.h>

#include "NumericFunctions.h"

TEST(TestNumericFunctions, add_function)
{
    ASSERT_EQ(Logic::add(1, 2), 3);
    ASSERT_EQ(Logic::add(5, 5), 10);
    ASSERT_EQ(Logic::add(10, 10), 20);
    ASSERT_EQ(Logic::add(12, 12), 24);
}

TEST(TestNumericFunctions, sub_function)
{
    ASSERT_EQ(Logic::sub(1, 2), -1);
    ASSERT_EQ(Logic::sub(5, 5), 0);
    ASSERT_EQ(Logic::sub(10, 0), 10);
    ASSERT_EQ(Logic::sub(12, 22), -10);
}
