#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "src/exampleclass.h"

using namespace testing;

TEST(MyTests, ExampleClassTest_sum)
{
    EXPECT_TRUE(ExampleClass::sum(1, 3) == 4);

    EXPECT_EQ(ExampleClass::sum(0, 0), 0);

    EXPECT_EQ(ExampleClass::sum(0.0, 0.0), 0);
}

TEST(MyTests, ExampleClassTest_devide)
{
    ASSERT_ANY_THROW(ExampleClass::devide(0, 0));
}
