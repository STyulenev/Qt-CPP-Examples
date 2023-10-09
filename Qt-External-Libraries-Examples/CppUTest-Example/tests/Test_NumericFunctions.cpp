#include "CppUTest/TestHarness.h"

#include "NumericFunctions.h"

TEST_GROUP(Numeric)
{
    Logic::Numeric* className;

    void setup()
    {
        className = new Logic::Numeric();
    }

    void teardown()
    {
        delete className;
    }
};

TEST(Numeric, Create)
{
//CHECK(0 != className);
    CHECK(true);
    CHECK_EQUAL(1,1);
    LONGS_EQUAL(1,1);
   /* DOUBLES_EQUAL(1.000, 1.001, .01);
    STRCMP_EQUAL("hello", "hello");
    FAIL("The prior tests pass, but this one doesn't");*/
}
