#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "NumericFunctions.h"

TEST_CASE("Testing NumericFunctions class")
{
    Logic::Numeric* className = new Logic::Numeric(2, 0);

    CHECK(className->getFirstNumber() == 2);
    CHECK_EQ(className->getSecondNumber(), 0);
    CHECK(className->add() == 2);
    CHECK(className->sub() == 2);
    CHECK(className->multi() == 0);
    CHECK_THROWS(className->div());

    delete className;

    MESSAGE("NumericFunctions class has tested.");
}
