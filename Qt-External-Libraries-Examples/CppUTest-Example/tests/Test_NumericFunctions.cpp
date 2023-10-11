#include "CppUTest/TestHarness.h"

#include "NumericFunctions.h"

TEST_GROUP(Numeric)
{
    Logic::Numeric* className;

    void setup()
    {
        className = new Logic::Numeric(2, 0);
    }

    void teardown()
    {
        delete className;
    }
};

TEST(Numeric, Create)
{
    CHECK(className->getFirstNumber() == 2);
    CHECK_TRUE(className->getSecondNumber() == 0);
    CHECK_EQUAL(className->add(), 2);
    CHECK_EQUAL(className->sub(), 2);
    CHECK_EQUAL(className->multi(), 0);
    CHECK_THROWS(std::logic_error, className->div());
}
